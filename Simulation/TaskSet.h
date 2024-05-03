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
    multiset<Task, Task::CompareTasks> m_tasks;

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

    void setNumProcessors(int numProcessors);
    void setNumTasks(int numTasks);
    void removeTask();// remove the highest priorityLevel task

    unsigned long long getLCMPeriod();


    // unsigned long long getLCM(){
    //     unsigned long long lcm = 1;
    //     for (const auto &task : m_tasks)
    //     {
    //         lcm = std:: accumulate(lcm, task.getPeriod());
    //     }
    //     return lcm;
    // }


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
