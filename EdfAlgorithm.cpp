#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>
#include <numeric>

#include "Task.h"
#include "TaskSet.h"
#include "EdfAlgorithm.h"

using namespace std;

// To check functions, all functions will return 0 after testing.

/**
 * Runs the Earliest Deadline First (EDF) algorithm on the given task set.
 *
 * @param taskSet The task set to be scheduled using EDF algorithm.
 * input: TaskSet include "m_numTasks" tasks
 * output:  the number of tasks across the deadline
 * exception: print "fail process management"
 */

int lcm = 0;
TaskSet taskSet;


bool checkEDF(Task task, int curTime) {
    return task.getComputationTimeRemaining() + curTime <= task.getPriorityLevel();
}

void sortTaskSet(TaskSet &taskSet) {
    
    vector<Task> tasks = taskSet.getTasks();

    sort(tasks.begin(), tasks.end(), [](const Task &x1, const Task &x2)->bool {
        if(x1.getStartTime() == x2.getStartTime())
            return x1.getPriorityLevel() < x2.getPriorityLevel();
        return x1.getStartTime() < x2.getStartTime();
    });


    taskSet.setTasks(tasks);
}

void updateProcess(std::multiset<Task> &tasks, TaskSet &taskSet) {
    if(tasks.empty())
        return;

    std::multiset<Task>::iterator it = tasks.begin();
    Task newTask = (*it);
    tasks.erase(it);
    newTask.reduceComputationTimeRemaining();
    if(newTask.getComputationTimeRemaining() != 0) {
        tasks.insert(newTask);
        return;
    }

    newTask.incrementCurrPeriod();
    if(newTask.getCurrPeriod() * newTask.getPeriod() > lcm) {
        return;
    }

    newTask.setPriorityLevel(newTask.getPriorityLevel() + newTask.getPeriod());
    newTask.setStartTime(newTask.getStartTime() + newTask.getPeriod());
    newTask.setComputationTimeRemaining(newTask.getComputationTime());
    taskSet.addTask(newTask);

    sortTaskSet(taskSet);
    return;
}


bool backtrackEDF(int curTime, std::multiset<Task> tasks[], TaskSet taskSet) {
    if(curTime == lcm) {
        if(!taskSet.getTasks().empty())
            return false;
        for(int i = 0; i < taskSet.getNumProcessors(); ++i) 
            if(!tasks[i].empty())
                return false;
        return true;
    }

    bool res = false;

    if(!taskSet.getTasks().empty() && curTime == (*taskSet.getTasks().begin()).getStartTime()) {
        Task newTask = *taskSet.getTasks().begin();
        for(int i = 0; i < taskSet.getNumProcessors(); ++i) {
            tasks[i].insert(newTask);
            // cout << i << ' ' << newTask.getName() << '\n';
            taskSet.removeTask();
            res |= backtrackEDF(curTime, tasks, taskSet);
            taskSet.addTask(newTask);
        }
    }

    else {
        for(int i = 0; i < taskSet.getNumProcessors(); ++i) {
            if(!tasks[i].empty() && !checkEDF(*tasks[i].begin(), curTime))
                return false;
            updateProcess(tasks[i], taskSet);
        }
        res |= backtrackEDF(curTime + 1, tasks, taskSet);
    }
    
    return res;
}


double runEDF(TaskSet taskSet)
{
    lcm = (int) taskSet.getLCMPeriod();
    double res = 0;
    for(Task &task : taskSet.getTasks()) {
        res += task.getComputationTime();
    }
    res = (double) res / (taskSet.getNumProcessors() * taskSet.getNumTasks());
    // taskSet.printTaskSet();
    sortTaskSet(taskSet);
    // taskSet.printTaskSet();
    std::multiset<Task> solutionSet[taskSet.getNumProcessors()];
    if(backtrackEDF(0, solutionSet, taskSet))
        return res;
    return -1.0;
    // for(int curTime = 0; curTime <= lcm; ++curTime) {
    //     while(it < taskSet.getTasks().end() && curTime == (*it).getStartTime()) {
    //         ++it;
    //         solutionSet.insert(*it);
    //     }
    //     if(solutionSet.empty())
    //         continue;
    //     if(!checkEDF(*solutionSet.begin(), curTime))
    //         return false;
    //     (*solutionSet.begin()).reduceComputationTimeRemaining();
    //     updateProcess(solutionSet, taskSet);
    // }
    // return solutionSet.empty() && it == taskSet.getTasks().end();
}

/**
 * Runs the Earliest Deadline First (EDF) algorithm on the given task set.
 * phiên bản cải tiến của EDF áp dụng giải thuật backtracking
 *
 * @param taskSet The task set to be scheduled.
 * có nhưng tiến trình có cùng priorityLevel áp dụng giải thuật backtracking
 * xác định thời gian chạy ngắn nhất và dài nhất và số tiến trình lỡ deadline tương ứng
 * vẽ được đồ thị tương quan
 * @return the number of tasks across the deadline.
 */
int runEDFminTime(TaskSet taskSet)
{
    /*
    chạy EDF với giải thuật backtracking trường hợp chạy ít thời gian nhất
    */
    return 0;
}

int runEDFmaxTime(TaskSet taskSet)
{
    /*
    chạy EDF với giải thuật backtracking trường hợp chạy nhiều thời gian nhất
    */
    return 0;
}

int runEDFminOverdueProcesses(TaskSet taskSet)
{
    /*
    chạy EDF với giải thuật backtracking trường hợp chạy ít tiến trình quá deadline nhất
    */
    return 0;
}

int runEDFmaxOverdueProcesses(TaskSet taskSet)
{
    /*
    chạy EDF với giải thuật backtracking trường hợp chạy nhiều tiến trình quá deadline nhất
    */
    return 0;
}


