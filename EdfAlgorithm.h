#ifndef EDF_ALGORITHM_H
#define EDF_ALGORITHM_H

#include <iostream>
#include <fstream>
#include <string>
#include <set>

#include "Task.h"
#include "TaskSet.h"

void sortTaskSet(TaskSet &taskSet);
void updateProcess(int id, TaskSet &taskSet);
bool checkEDF(Task task, int curTime);
bool backtrackEDF(int curTime, TaskSet taskSet);

double runEDF(TaskSet taskSet);
bool backTrackTasks(TaskSet &taskSet, vector<TaskSet> &result, int index);
vector<TaskSet> divideTasks(TaskSet &taskSet);
bool runOneEDF(TaskSet taskSet);
bool runNewONeEDFs(TaskSet taskSet);
#endif