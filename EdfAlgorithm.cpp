#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <numeric>

#include "Task.h"
#include "TaskSet.h"
#include "EdfAlgorithm.h"

using namespace std;

// To check functions, all functions will return 0 after testing.

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


