#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <numeric>

#include "Ntask.h"
#include "NtaskSet.h"
#include "EdfAlgorithm.h"

using namespace std;

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
 * xác định thời gian chạy ngắn nhất và dài nhất và số tiến trình lỡ deadline tương ứng
 * vẽ được đồ thị tương quan
 * @return the number of tasks across the deadline.
 */
int runEDFminTime(TaskSet taskSet)
{
    /*
    chạy EDF với giải thuật backtracking trường hợp chạy ít thời gian nhất
    */
    return 0;
}

int runEDFmaxTime(TaskSet taskSet)
{
    /*
    chạy EDF với giải thuật backtracking trường hợp chạy nhiều thời gian nhất
    */
    return 0;
}

int runEDFminOverdueProcesses(TaskSet taskSet)
{
    /*
    chạy EDF với giải thuật backtracking trường hợp chạy ít tiến trình quá deadline nhất
    */
    return 0;
}

int runEDFmaxOverdueProcesses(TaskSet taskSet)
{
    /*
    chạy EDF với giải thuật backtracking trường hợp chạy nhiều tiến trình quá deadline nhất
    */
    return 0;
}

unsigned long long getLCMPeriod(TaskSet taskSet)
{
    // find least common multiple of the periods of the tasks
    unsigned long long lcm = 1;
    auto tasks = taskSet.getTasks();

    for (auto &task : tasks)
    {
        lcm = (task.getPeriod() * lcm) / gcd((unsigned long long)task., lcm);
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
