#ifndef TASKSEt_H
#define TASKSEt_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include "Task.h"

using std::set;
using std::string;

class TaskSet
{
private:
    int m_numTasks;
    int m_numProcessors;
    // std::vector<Task> m_tasks;
    multiset<Task, Task::CompareTasks> m_tasks;

public:
    TaskSet()
    {
        m_numTasks = 0;
        m_numProcessors = 0;
        m_tasks.clear();
    };

    ~TaskSet()
    {
        m_numTasks = 0;
        m_numProcessors = 0;
        m_tasks.clear();
    };

    TaskSet(int numTasks, int numProcessors)
    {
        m_numTasks = numTasks;
        m_numProcessors = numProcessors;
    };

    TaskSet &operator=(const TaskSet &taskSet)
    {
        if (this == &taskSet)
        {
            return *this;
        }
        m_numTasks = taskSet.m_numTasks;
        m_numProcessors = taskSet.m_numProcessors;
        m_tasks = taskSet.m_tasks;
        return *this;
    };


    Task getHighestPriorityTask()
    {
        return *m_tasks.begin();
    };

    Task getLowestPriorityTask()
    {
        return *m_tasks.rbegin();
    };

    // multiset<Task> getTasks()
    // {
    //     return m_tasks;
    // };

    void addTask(Task task)
    {
        m_tasks.insert(task);
        if (m_numTasks < m_tasks.size())
        {
            m_numTasks++;
        }
    };

    int getNumTasks()
    {
        return m_numTasks;
    };

    int getNumProcessors()
    {
        return m_numProcessors;
    };

    double calculateUtilizationRate(Task task)
    {
        return (double)task.getComputationTime() / (double)task.getPeriod();
    };

    // double calculateTotalUtilizationRate()
    // {
    //     double totalUtilizationRate = 0;
    //     for (int i = 0; i < m_tasks.size(); i++)
    //     {
    //         totalUtilizationRate += calculateUtilizationRate(m_tasks[i]);
    //     }
    //     return totalUtilizationRate;
    // };

    void setNumProcessors(int numProcessors)
    {
        m_numProcessors = numProcessors;
    };

    void setNumTasks(int numTasks)
    {
        m_numTasks = numTasks;
    };

    void removeTask()
    {
        std::multiset<Task, Task::CompareTasks>::iterator it = m_tasks.begin();
        m_tasks.erase(it);
    };

    // int EUSI(){
    //     int EUSI = 0;
    //     for (int i = 0; i < m_tasks.size(); i++)
    //     {
    //         EUSI += m_tasks[i].getComputationTime() / m_tasks[i].getPeriod();
    //     }
    //     return EUSI;
    // };

    // int USI(){
    //     int USI = 0;
    //     for (int i = 0; i < m_tasks.size(); i++)
    //     {
    //         USI += m_tasks[i].getComputationTime();
    //     }
    //     return USI;
    // };

    // bool checkProcessors(){
    //     for (int i = 0; i < m_tasks.size(); i++)
    //     {
    //         if (m_tasks[i].getComputationTime() > m_numProcessors)
    //         {
    //             return false;
    //         }
    //     }
    //     return true;
    // };
};
#endif
