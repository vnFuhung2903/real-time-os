#ifndef TASKSET_H
#define TASKSET_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>


using std::set;
using std::string;

class TaskSet
{
private:
    int m_numTasks;
    int m_numProcessors;
    std::multiset<Task> m_tasks;

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
        m_tasks.insert(task);
    }

    void removeTask()
    {
        std::multiset<Task>::iterator it = m_tasks.begin();
        m_tasks.erase(it);
    }

    void printTaskSet()
    {
        // print the priority level of each task in the task set
        for (const auto &task : m_tasks)
        {
            std::cout << task.getPriorityLevel() << std::endl;
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

    std::multiset<Task> getTasks()
    {
        return m_tasks;
    }

    void setNumTasks(int numTasks)
    {
        m_numTasks = numTasks;
    }
};

#endif
