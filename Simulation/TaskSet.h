#ifndef TASKSEt_H
#define TASKSEt_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include "Task.h"

using std::set;
using std::string;

class TaskSet
{
private:
    int m_numTasks;
    int m_numProcessors;
    multiset<Task> m_tasks;

public:
    TaskSet();
    ~TaskSet();

    TaskSet(int numTasks, int numProcessors);

    TaskSet &operator=(const TaskSet &taskSet);

    Task getHighestPriorityTask();
    Task getLowestPriorityTask();

    void printTaskSet();
    void addTask(Task task);
    int getNumTasks();
    int getNumProcessors();

    void setNumProcessors(int numProcessors);
    void setNumTasks(int numTasks);
    void removeTask();// remove the highest priorityLevel task

    unsigned long long getLCMPeriod();

};
#endif
