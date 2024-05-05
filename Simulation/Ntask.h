#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>
#include <set>

using namespace std;

class Task
{
private:
    int m_priorityLevel;
    string m_name;
    int m_startTime;
    int m_computationTime;
    int m_hardDeadline;
    int m_period;
    int m_currPeriod;
    int m_laxity;

public:
    Task(string name = "", int startTime = 0, int computationTime = 0, int hardDeadline = 0, int period = 0)
    {
        m_priorityLevel = hardDeadline;
        m_name = name;
        m_startTime = startTime;
        m_computationTime = computationTime;
        m_hardDeadline = hardDeadline;
        m_period = period;
        m_currPeriod = 1;
        m_laxity = hardDeadline - startTime - computationTime;
    }

    Task &operator=(const Task &task)
    {
        if (this == &task)
        {
            return *this;
        }
        m_priorityLevel = task.m_priorityLevel;
        m_name = task.m_name;
        m_startTime = task.m_startTime;
        m_computationTime = task.m_computationTime;
        m_hardDeadline = task.m_hardDeadline;
        m_period = task.m_period;
        m_currPeriod = task.m_currPeriod;
        m_laxity = task.m_laxity;
        return *this;
    }

    int getPriorityLevel() const
    {
        return m_priorityLevel;
    }

    void setPriorityLevel(int priorityLevel)
    {
        m_priorityLevel = priorityLevel;
    }

    int getStartTime()
    {
        return m_startTime;
    }

    void setStartTime(int startTime)
    {
        m_startTime = startTime;
    }

    int getComputationTime()
    {
        return m_computationTime;
    }

    void setComputationTime(int computationTime)
    {
        m_computationTime = computationTime;
    }

    int getHardDeadline()
    {
        return m_hardDeadline;
    }

    void setHardDeadline(int hardDeadline)
    {
        m_hardDeadline = hardDeadline;
    }

    int getPeriod() const
    {
        return m_period;
    }

    void setPeriod(int period)
    {
        m_period = period;
    }

    void printTask()
    {
        cout<<"PriorityLevel: "<< m_priorityLevel << ", Start Time: " << m_startTime << ", Computation Time: " << m_computationTime << ", Hard Deadline: " << m_hardDeadline << ", Period: " << m_period << endl;
    }

    void setName(string name)
    {
        m_name = name;
    }

    string getName()
    {
        return m_name;
    }

    void setLaxity(int laxity)
    {
        m_laxity = laxity;
    }

    int getLaxity()
    {
        return m_laxity;
    }

    void incrementCurrPeriod()
    {
        m_currPeriod++;
    }

    int getCurrPeriod()
    {
        return m_currPeriod;
    }

    bool operator<(const Task &other) const
    {
        return this->getPriorityLevel() < other.getPriorityLevel();
    }
};

#endif
