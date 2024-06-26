#ifndef TASKSET_H
#define TASKSET_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <numeric>
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
    std::vector<Task> m_tasks;

public:
    TaskSet()
    {
        m_numTasks = 0;
        m_numProcessors = 0;
        m_tasks.clear();
    }

    ~TaskSet()
    {
        m_numTasks = 0;
        m_numProcessors = 0;
        m_tasks.clear();
    }

    TaskSet(int numTasks, int numProcessors)
    {
        m_numTasks = numTasks;
        m_numProcessors = numProcessors;
    }

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
    }

    Task getHighestPriorityTask()
    {
        return *m_tasks.begin();
    }

    Task getLowestPriorityTask()
    {
        return *m_tasks.rbegin();
    }

    void addTask(Task task)
    {
        m_tasks.push_back(task);
        // m_numTasks++;
    }

    void removeTask()
    {
        std::vector<Task>::iterator it = m_tasks.begin();
        m_tasks.erase(it);
        m_numTasks--;
    }

    void removeLastTask(){
        m_tasks.pop_back();
        m_numTasks--;
    }

    void printTaskSet()
    {
        // print the priority level of each task in the task set
        for ( auto &task : m_tasks)
        {
            std::cout<<task.getStartTime()<<" " << task.getPriorityLevel() << std::endl;
        }
    }

    int getNumTasks()
    {
        return m_numTasks;
    }

    void setNumProcessors(int numProcessors)
    {
        m_numProcessors = numProcessors;
    }

    int getNumProcessors()
    {
        return m_numProcessors;
    }

    std::vector<Task> getTasks()
    {
        return m_tasks;
    }

    void setTasks(std::vector<Task> _tasks)
    {
        m_tasks.clear();
        m_tasks = _tasks;
    }

    void setNumTasks(int numTasks)
    {
        m_numTasks = numTasks;
    }

    // unsigned long long gcd(unsigned long long a, unsigned long long b)
    // {
    //     // find the greatest common divisor
    //     if (b == 0)
    //     {
    //         return a;
    //     }
    //     return gcd(b, a % b);
    // }

    unsigned long long getLCMPeriod()
    {
        // find least common multiple of the periods of the tasks
        unsigned long long lcm = 1;
        for (auto &task : m_tasks)
        {
            unsigned long long period = task.getPeriod();
            lcm = (lcm / __gcd(period, lcm)) * period;
        }
        if (lcm>1000|| lcm<0) return 1000;
        return lcm;
    }

    bool checkEdfOneProcessor(){
        double res = 0;
        for(Task &task : m_tasks) {
            res +=(double ) task.getComputationTime()/task.getPeriod();
        }
        if (res>1){
            return false;
        } else{
            return true;
        }
    }
    double getUtilization(){
        double res = 0;
        for(Task &task : m_tasks) {
            res +=(double ) task.getComputationTime()/task.getPeriod();
        }
        return res;
    }
};
#endif
