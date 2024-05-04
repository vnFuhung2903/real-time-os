#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <set>

#include "Task.h"
#include "TaskSet.h"

using std::multiset;
using std::string;

int m_numTasks = 0;
int m_numProcessors = 0;
std:: multiset<Task> m_tasks;

TaskSet::TaskSet()
{
    m_numTasks = 0;
    m_numProcessors = 0;
    m_tasks.clear();
}

TaskSet::~TaskSet()
{
    m_numTasks = 0;
    m_numProcessors = 0;
    m_tasks.clear();
}

TaskSet::TaskSet(int numTasks, int numProcessors)
{
    m_numTasks = numTasks;
    m_numProcessors = numProcessors;
}

TaskSet &TaskSet::operator=(const TaskSet &taskSet)
{
    if (this == &taskSet)
    {
        return *this;
    }
    m_numTasks = taskSet.m_numTasks;
    m_numProcessors = taskSet.m_numProcessors;
    m_tasks = taskSet.m_tasks;
    return *this;
}

Task TaskSet::getHighestPriorityTask()
{
    return *m_tasks.begin();
}

Task TaskSet::getLowestPriorityTask()
{
    return *m_tasks.rbegin();
}

void TaskSet::addTask(Task task)
{
    m_tasks.insert(task);
}

void TaskSet::removeTask()
{
    std::multiset<Task>::iterator it = m_tasks.begin();
    m_tasks.erase(it);
}

void TaskSet:: printTaskSet(){
    // print the priority level of each task in the task set
    for (const auto &task : m_tasks)
    {
        std::cout << task.getPriorityLevel() << std::endl;
    }
}

int TaskSet::getNumTasks()
{
    return m_numTasks;
}

void TaskSet::setNumProcessors(int numProcessors)
{
    m_numProcessors = numProcessors;
}

int TaskSet::getNumProcessors()
{
    return m_numProcessors;
}

void TaskSet::setNumTasks(int numTasks)
{
    m_numTasks = numTasks;
}

unsigned long long TaskSet::getLCMPeriod()
{
    
    
    // for (const auto &task : m_tasks)
    // {
    //     periods.push_back(task.getPeriod());
    // }
    // unsigned long long lcm = periods[0];
    // for (int i = 1; i < periods.size(); i++)
    // {
    //     lcm = std::lcm(lcm, (unsigned long long)periods[i]);
    // }
    return 0;
}
#