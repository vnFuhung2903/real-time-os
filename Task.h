#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>
#include <set>

using namespace std;

class Task
{
protected:
    int m_priorityLevel;
    string m_name;
    int startTime;
    int m_computationTime;
    int m_hardDeadline;
    int m_period;
    int m_currPeriod;
    int m_computationTimeRemaining;
    int m_processor;

public:
    Task(string name = "", int startTime = 0, int computationTime = 0, int hardDeadline = 0, int period = 0)
    {
        m_priorityLevel = hardDeadline;
        m_name = name;
        this->startTime = startTime;
        m_computationTime = computationTime;
        m_hardDeadline = hardDeadline;
        m_period = period;
        m_currPeriod = 1;
        m_computationTimeRemaining = computationTime;
        m_processor = -1;
    }

    Task &operator=(const Task &task)
    {
        if (this == &task)
        {
            return *this;
        }
        m_priorityLevel = task.m_priorityLevel;
        m_name = task.m_name;
        this->startTime = task.startTime;
        m_computationTime = task.m_computationTime;
        m_hardDeadline = task.m_hardDeadline;
        m_period = task.m_period;
        m_currPeriod = task.m_currPeriod;
        m_computationTimeRemaining = task.m_computationTimeRemaining;
        m_processor = task.m_processor;
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
        return startTime;
    }

    void setStartTime(int startTime)
    {
        this->startTime = startTime;
    }

    int getComputationTime()
    {
        return m_computationTime;
    }

    void reduceComputationTimeRemaining()
    {
        --m_computationTimeRemaining;
    }
    int getHardDeadline() const
    {
        return m_hardDeadline;
    }

    int getPeriod() const
    {
        return m_period;
    }

    void printTask()
    {
        cout<<"PriorityLevel: "<< m_priorityLevel << ", Start Time: " << startTime << ", Computation Time: " << m_computationTime << ", Hard Deadline: " << m_hardDeadline << ", Period: " << m_period << endl;
    }

    string getName() const
    {
        return m_name;
    }

    int getComputationTimeRemaining()
    {
        return m_computationTimeRemaining;
    }

    void setComputationTimeRemaining(int computationTimeRemaining)
    {
        m_computationTimeRemaining = computationTimeRemaining;
    }

    void incrementCurrPeriod()
    {
        m_currPeriod++;
    }

    int getCurrPeriod()
    {
        return m_currPeriod;
    }

    int getProcessor() {
        return m_processor;
    }

    void setProcessor(int processor) {
        m_processor = processor;
    }

    bool operator<(const Task &other) const
    {
        return this->getPriorityLevel() < other.getPriorityLevel();
    }
};

#endif
