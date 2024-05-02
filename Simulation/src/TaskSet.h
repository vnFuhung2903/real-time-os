/************************************************************************
 * TaskSet.h
 * Author: Stephen Thomson
 * Date: 2/8/2024
 * Description: This file contains the declaration of the TaskSet class. This class
 *             is used to store a list of tasks and perform operations on them.
 * *********************************************************************/

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Task.h"

using std::string;
using std::vector;

class TaskSet
{
private:
    int m_numTasks;
    int m_numProcessors;
    bool m_preemptive;
    std::vector<Task> m_tasks;

public:
    TaskSet()
    {
        m_numTasks = 0;
        m_numProcessors = 0;
        m_tasks.clear();
        m_preemptive = false;
    };

    ~TaskSet()
    {
        m_numTasks = 0;
        m_numProcessors = 0;
        m_tasks.clear();
    };

    TaskSet(int numTasks, int numProcessors, bool preemptive)
    {
        m_numTasks = numTasks;
        m_numProcessors = numProcessors;
        m_preemptive = preemptive;
    };

    TaskSet &operator=(const TaskSet &taskSet)
    {
        if (this == &taskSet)
        {
            return *this;
        }
        m_numTasks = taskSet.m_numTasks;
        m_numProcessors = taskSet.m_numProcessors;
        m_preemptive = taskSet.m_preemptive;
        m_tasks = taskSet.m_tasks;
        return *this;
    };

    Task getTask(int index)
    {
        return m_tasks[index];
    };

    vector<Task> getTasks()
    {
        return m_tasks;
    };

    void addTask(Task task)
    {
        m_tasks.push_back(task);
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

    double calculateTotalUtilizationRate()
    {
        double totalUtilizationRate = 0;
        for (int i = 0; i < m_tasks.size(); i++)
        {
            totalUtilizationRate += calculateUtilizationRate(m_tasks[i]);
        }
        return totalUtilizationRate;
    };

    void setNumProcessors(int numProcessors)
    {
        m_numProcessors = numProcessors;
    };

    void setNumTasks(int numTasks)
    {
        m_numTasks = numTasks;
    };

    void removeTask(int index)
    {
        m_tasks.erase(m_tasks.begin() + index);
    };

    void printTasks()
    {
        std::cout << "Tasks: " << m_numTasks << std::endl;
        std::cout << "Processors: " << m_numProcessors << std::endl;
        std::cout << "Preemptive: " << (m_preemptive ? "True" : "False") << std::endl;
        for (int i = 0; i < m_numTasks; i++)
        {
            // Print Task: i, then call m_tasks[i].printTask() all on the same line.
            std::cout << m_tasks[i].getName() << ", ";
            m_tasks[i].printTask();
        }
    };

    void setPreemptive(bool preemptive)
    {
        m_preemptive = preemptive;
    };

    bool getPreemptive()
    {
        return m_preemptive;
    };

    int EUSI(){
        int EUSI = 0;
        for (int i = 0; i < m_tasks.size(); i++)
        {
            EUSI += m_tasks[i].getComputationTime() / m_tasks[i].getPeriod();
        }
        return EUSI;
    };

    int USI(){
        int USI = 0;
        for (int i = 0; i < m_tasks.size(); i++)
        {
            USI += m_tasks[i].getComputationTime();
        }
        return USI;
    };

    bool checkProcessors(){
        for (int i = 0; i < m_tasks.size(); i++)
        {
            if (m_tasks[i].getComputationTime() > m_numProcessors)
            {
                return false;
            }
        }
        return true;
    };

    unsigned long long getLCM(){
        unsigned long long lcm = 1;
        for (int i = 0; i < m_tasks.size(); i++)
        {
            lcm = lcm * m_tasks[i].getPeriod() / std::__gcd(lcm, (unsigned long long)m_tasks[i].getPeriod());
        }
        return lcm;
    };
};