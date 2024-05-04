#include <iostream>
#include <fstream>
#include <string>
#include <set>

#include "Task.h"
#include "TaskSet.h"
#include "EdfAlgorithm.h"

/**
 * Runs the Earliest Deadline First (EDF) algorithm on the given task set.
 *
 * @param taskSet The task set to be scheduled using EDF algorithm.
 * input: TaskSet include "m_numTasks" tasks
 * output:  the number of tasks across the deadline
 * exception: print "fail process management"
 */

int runEDF(TaskSet taskSet)
{
    return 0;
}

/**
 * Runs the Earliest Deadline First (EDF) algorithm on the given task set.
 * phiên bản cải tiến của EDF áp dụng giải thuật backtracking
 *
 * @param taskSet The task set to be scheduled.
 * có nhưng tiến trình có cùng priorityLevel áp dụng giải thuật backtracking
 * xác định thời gian chạy ngắn nhất và dài nhất và số tiến trình gặp deadline trong mỗi trường hợp
 * vẽ được đồ thị tương quan
 * @return An integer representing the status of the algorithm execution.
 */
int runEDFplus(TaskSet taskSet)
{
    return 0;
}


unsigned long long getLCMPeriod(TaskSet taskSet)
{

    // find the least common multiple of the periods of the tasks
    unsigned long long lcm = 1;
    for (auto &taskE : taskSet.getTasks())
    {
        unsigned long long period = (unsigned long long) taskE.getPeriod();
        lcm = (period * lcm) / gcd(period, lcm);
    }

    return 0;
}

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
    // find the greatest common divisor
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}