#include <iostream>
#include <string>

#include "Task.h"

using namespace std;

Task::Task(string name, int startTime, int computationTime, int hardDeadline, int period)
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

Task &Task::operator=(const Task &task)
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

// define the comparison operator for the Task class

// int Task::getPriorityLevel()
// {
//     return m_priorityLevel;
// }

void Task::setPriorityLevel(int priorityLevel)
{
    m_priorityLevel = priorityLevel;
}

int Task::getStartTime()
{
    return m_startTime;
}

void Task::setStartTime(int startTime)
{
    m_startTime = startTime;
}

int Task::getComputationTime()
{
    return m_computationTime;
}

void Task::setComputationTime(int computationTime)
{
    m_computationTime = computationTime;
}

int Task::getHardDeadline()
{
    return m_hardDeadline;
}

void Task::setHardDeadline(int hardDeadline)
{
    m_hardDeadline = hardDeadline;
}

int Task::getPeriod()
{
    return m_period;
}

void Task::setPeriod(int period)
{
    m_period = period;
}

void Task::printTask()
{
    cout<<"PriorityLevel: "<< m_priorityLevel << ", Start Time: " << m_startTime << ", Computation Time: " << m_computationTime << ", Hard Deadline: " << m_hardDeadline << ", Period: " << m_period << endl;
}

void Task::setName(string name)
{
    m_name = name;
}

string Task::getName()
{
    return m_name;
}

void Task::setLaxity(int laxity)
{
    m_laxity = laxity;
}

int Task::getLaxity()
{
    return m_laxity;
}

void Task::incrementCurrPeriod()
{
    m_currPeriod++;
}

int Task::getCurrPeriod()
{
    return m_currPeriod;
}
bool Task::operator<(const Task& other) const {
    return this->getPriorityLevel() < other.getPriorityLevel();
}
// bool Task::CompareTasks::operator()(const Task &task1, const Task &task2) const
// {
//     return task1.getPriorityLevel() < task2.getPriorityLevel();
// }
// bool Task:: CompareTasks::operator()(const Task &task1, const Task &task2) const  {
//     return task1.getPriorityLevel() < task2.getPriorityLevel();
// }
