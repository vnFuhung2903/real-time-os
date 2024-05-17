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

unsigned long long lcm = 0;
double res = 0.0;


bool checkEDF(Task task, int curTime) {
    return task.getComputationTimeRemaining() + curTime <= task.getPriorityLevel();
}

void sortTaskSet(TaskSet taskSet) {
    sort(taskSet.getTasks().begin(), taskSet.getTasks().end(), [](const Task &x1, const Task &x2)->bool {
        if(x1.getStartTime() == x2.getStartTime())
            return x1.getPriorityLevel() < x2.getPriorityLevel();
        return x1.getStartTime() < x2.getStartTime();
    });
}

void updateProcess(std::multiset<Task> tasks, TaskSet taskSet) {
    std::multiset<Task>::iterator it = tasks.begin();
    if((*it).getComputationTimeRemaining() != 0)
        return;
    Task newTask = (*it);
    tasks.erase(it);
    newTask.incrementCurrPeriod();
    if(newTask.getCurrPeriod() * newTask.getPeriod() > lcm) {
        res += (double) newTask.getComputationTime() / newTask.getPeriod();
        return;
    }
    newTask.setPriorityLevel(newTask.getPriorityLevel() + newTask.getPeriod());
    newTask.setStartTime(newTask.getStartTime() + newTask.getPeriod());
    newTask.setComputationTimeRemaining(newTask.getComputationTime());
    taskSet.addTask(newTask);
    sortTaskSet(taskSet);
    return;
}


bool backtrackEDF(int curTime, std::vector<Task>::iterator it, vector<std::multiset<Task>> tasks, TaskSet taskSet) {
    if(curTime == lcm) {
        if(it < taskSet.getTasks().end())
            return false;
        for(int i = 0; i < taskSet.getNumProcessors(); ++i) 
            if(!tasks[i].empty())
                return false;
        return true;
    }

    bool added = false;

    if(it < taskSet.getTasks().end() && curTime == (*it).getStartTime()) {
        ++it;
        added = true;
    }

    bool res = false;

    if(added) {
        for(int i = 0; i < taskSet.getNumProcessors(); ++i) {
            tasks[i].insert((*it));
            res |= backtrackEDF(curTime, it, tasks, taskSet);
        }
    }

    else {
        for(int i = 0; i < taskSet.getNumProcessors(); ++i) {
            if(!tasks[i].empty() && !checkEDF(*tasks[i].begin(), curTime))
                return false;
            updateProcess(tasks[i], taskSet);
        }
        res |= backtrackEDF(curTime + 1, it, tasks, taskSet);
    }
    
    return res;
}


bool runEDF(TaskSet taskSet)
{
    lcm = taskSet.getLCMPeriod();
    res = 0.0;
    // sortTaskSet(taskSet);
    // std::vector<Task>::iterator it = taskSet.getTasks().begin();
    // std :: vector<std::multiset<Task>> solutionSet;

    // return backtrackEDF(0, it, solutionSet, taskSet);
    return false;
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


