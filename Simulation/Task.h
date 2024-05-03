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
    Task(string name = "", int startTime = 0, int computationTime = 0, int hardDeadline = 0, int period = 0);

    Task &operator=(const Task &task);

    int getPriorityLevel() const {
        return m_priorityLevel;
    } ;

    void setPriorityLevel(int priorityLevel);

    int getStartTime();

    void setStartTime(int startTime);

    int getComputationTime();

    void setComputationTime(int computationTime);

    int getHardDeadline();

    void setHardDeadline(int hardDeadline);

    int getPeriod();

    void setPeriod(int period);

    void printTask();

    void setName(string name);

    string getName();

    void setLaxity(int laxity);

    int getLaxity();

    void incrementCurrPeriod();

    int getCurrPeriod();

    // struct CompareTasks
    // {
    //     bool operator()(const Task &task1, const Task &task2) const;
    // };
    struct CompareTasks
    {
        bool operator()(const Task &task1, const Task &task2){
            return task1.getPriorityLevel() < task2.getPriorityLevel();
        }  ;
    };

    // bool operator<(const Task &task1, const Task &task2)  ;
};

#endif
