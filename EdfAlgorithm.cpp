//
// Created by home on 5/20/2024.
//
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <ctime>
#include <numeric>

#include "Task.h"
#include "TaskSet.h"
#include "EdfAlgorithm.h"

using namespace std;

int lcm_value = 0;
std::multiset<Task> tasks[52];

bool checkEDF(Task task, int curTime) {
    return task.getComputationTimeRemaining() + curTime <= task.getPriorityLevel();
}

void sortTaskSet(TaskSet &taskSet) {
    vector<Task> tasks = taskSet.getTasks();
    int n = tasks.size();
    bool swapped;
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (tasks[j].getStartTime() == tasks[j + 1].getStartTime()) {
                if (tasks[j].getPriorityLevel() > tasks[j + 1].getPriorityLevel()) {
                    std::swap(tasks[j], tasks[j + 1]);
                    swapped = true;
                }
            }
            if (tasks[j].getStartTime() > tasks[j + 1].getStartTime()) {
                std::swap(tasks[j], tasks[j + 1]);
                swapped = true;
            }
        }
        // Nếu không có phần tử nào được hoán đổi trong lần lặp này, mảng đã được sắp xếp
        if (!swapped) {
            break;
        }
    }
    taskSet.setTasks(tasks);
}

void updateProcess(int id, TaskSet &taskSet) {
    if (tasks[id].empty())
        return;

    std::multiset<Task>::iterator it = tasks[id].begin();
    Task newTask = (*it);
    tasks[id].erase(it);
    std::cout << " num task be removed " << id << ": " << tasks[id].size() << std::endl;
    std::cout << "newTask time remaining: " << newTask.getComputationTimeRemaining() << std::endl;
    newTask.reduceComputationTimeRemaining();
    std::cout << "After reducing computation time remaining: " << newTask.getComputationTimeRemaining() << std::endl;

    if (newTask.getComputationTimeRemaining() != 0) {
        tasks[id].insert(newTask);
        std::cout << " num task be added " << id << ": " << tasks[id].size() << std::endl;
        return;
    }

    newTask.incrementCurrPeriod();
    std::cout << "After incrementing current period: " << newTask.getCurrPeriod() << std::endl;

    if (newTask.getCurrPeriod() * newTask.getPeriod() > lcm_value) {
        return;
    }

    newTask.setPriorityLevel(newTask.getPriorityLevel() + newTask.getPeriod());
    std::cout << "After updating priority level: " << newTask.getPriorityLevel() << std::endl;
    newTask.setStartTime(newTask.getStartTime() + newTask.getPeriod());
    std::cout << "After updating start time: " << newTask.getStartTime() << std::endl;
    newTask.setComputationTimeRemaining(newTask.getComputationTime());
    std::cout << "After resetting computation time remaining: " << newTask.getComputationTimeRemaining() << std::endl;

    taskSet.addTask(newTask);
    std::cout << "num task  in taskSet:  " << taskSet.getTasks().size() << endl;
    sortTaskSet(taskSet);
    return;
}

bool backtrackEDF(int curTime, TaskSet taskSet) {
    cout << " step: " << curTime << endl;
    if (curTime == lcm_value) {
        if (!taskSet.getTasks().empty()) {
            std::cout << "Task set is not empty" << std::endl;
            return false;
        }
        for (int i = 0; i < taskSet.getNumProcessors(); ++i)
            if (!tasks[i].empty()) {
                std::cout << "Processor " << i << " is not empty" << std::endl;
                return false;
            }
        return true;
    }

    bool res = false;

    if (!taskSet.getTasks().empty() && curTime == (*taskSet.getTasks().begin()).getStartTime()) {
        Task newTask = *taskSet.getTasks().begin();
        for (int i = 0; i < taskSet.getNumProcessors(); ++i) {
            if (newTask.getProcessor() != -1 && newTask.getProcessor() != i)
                continue;
            bool first_appear = newTask.getProcessor() == -1;
            if (first_appear) newTask.setProcessor(i);
            tasks[i].insert(newTask);
            std::cout << " num task " << i << " after inserting: " << tasks[i].size() << std::endl;
            taskSet.removeTask();
            std::cout << "num taskSet after removing: " << taskSet.getTasks().size() << std::endl;
            res |= backtrackEDF(curTime, taskSet);
            std::cout << "new task: " << newTask.getStartTime() << " " << newTask.getComputationTime() << " "
                      << newTask.getPriorityLevel() << " " << newTask.getPeriod() << std::endl;
            taskSet.addTask(newTask);
            std::cout << "num task after adding: " << taskSet.getTasks().size() << std::endl;
            tasks[i].erase(newTask);
            std::cout << " num task " << i << " after erasing: " << tasks[i].size() << std::endl;
            if (first_appear) newTask.setProcessor(-1);
        }
    } else {
        for (int i = 0; i < taskSet.getNumProcessors(); ++i) {
            if (!tasks[i].empty() && !checkEDF(*tasks[i].begin(), curTime)) {
                std::cout << "Processor " << i << " is not empty and not EDF" << std::endl;
                return false;
            }
            updateProcess(i, taskSet);
        }
        res |= backtrackEDF(curTime + 1, taskSet);
    }

    return res;
}

double runEDF(TaskSet taskSet) {
    lcm_value = (int) taskSet.getLCMPeriod();
    double res = 0;
    for (Task &task: taskSet.getTasks()) {
        res += task.getComputationTime();
    }
    res = (double) res / (taskSet.getNumProcessors() * taskSet.getNumTasks());
    sortTaskSet(taskSet);
    for (int i = 0; i < taskSet.getNumProcessors(); ++i) {
        tasks[i].clear();
    }
    if (backtrackEDF(0, taskSet))
        return res;
    return -1.0;
}

bool backTrackTasks(TaskSet &taskSet, vector<TaskSet> &result, int index) {
    if (index == (taskSet.getTasks().size())) {
        for (int i = 0; i < taskSet.getNumProcessors(); ++i) {
            cout << "check processor " << i << endl;
            if (!result[i].checkEdfOneProcessor()) return false;
        }
        cout << "true" << endl;
//        exit(0);
        return true;
    }
    double rate = (double) taskSet.getTasks()[index].getComputationTime() / taskSet.getTasks()[index].getPeriod();
    for (int i = 0; i < taskSet.getNumProcessors(); ++i) {
        if (result[i].getUtilization() + rate <= 1) {
            result[i].addTask(taskSet.getTasks()[index]);
            // Print all tasks in the result
            std::cout << "Processor " << i << " tasks: ";
            for (const auto &task: result[i].getTasks()) {
                std::cout << task.getName() << " ";
            }
            std::cout << std::endl;
            if (backTrackTasks(taskSet, result, index + 1)) return true;
            result[i].removeLastTask();
            std::cout << "Processor " << i << " tasks: ";
            for (const auto &task: result[i].getTasks()) {
                std::cout << task.getName() << " ";
            }
            std::cout << std::endl;

        }
    }
    return false;
}

vector<TaskSet> divideTasks(TaskSet &taskSet) {
    vector<TaskSet> result(taskSet.getNumProcessors());
    if (backTrackTasks(taskSet, result, 0)) {
        return result;
    } else {
        return {}; // return an empty vector
    }
}

bool runOneEDF(TaskSet taskSet) {
//    run taskSet 1 processor
    std::multiset<Task> tasksN;
    int lcm_value = (int) taskSet.getLCMPeriod();
    for (int step = 0; step < lcm_value; ++step) {
        for (Task &task: taskSet.getTasks()) {
            if (task.getStartTime() == step) {
                tasksN.insert(task);
            }
        }
        if (!tasksN.empty()) {
            Task task = *tasksN.begin();
            tasksN.erase(tasksN.begin());
            if (step < task.getPriorityLevel()) {
                task.reduceComputationTimeRemaining();
                if (task.getComputationTimeRemaining() != 0) {
                    tasksN.insert(task);
                } else {
                    task.incrementCurrPeriod();
                    if (task.getCurrPeriod() * task.getPeriod() <= lcm_value) {
                        task.setPriorityLevel(task.getPriorityLevel() + task.getPeriod());
                        task.setStartTime(task.getStartTime() + task.getPeriod());
                        task.setComputationTimeRemaining(task.getComputationTime());
                        taskSet.addTask(task);
                    }
                }
            }
        }

    }
    if (tasksN.empty()){
        return true;

    } else
        return false;
}

double runNewEDFs(TaskSet taskSet) {
    clock_t start = clock();

    vector<TaskSet> taskSets = divideTasks(taskSet);

    for(TaskSet &taskSet: taskSets) {
        if (!runOneEDF(taskSet)) {
            return -1.0;
        }
    }
    clock_t end = clock();
    double time = ((double) (end - start) / CLOCKS_PER_SEC) * 1000;
    return time / (taskSet.getNumTasks() * taskSet.getNumProcessors());
}
