#ifndef EDF_ALGORITHM_H
#define EDF_ALGORITHM_H

#include <iostream>
#include <fstream>
#include <string>
#include <set>

#include "Task.h"
#include "TaskSet.h"

int runEDF(TaskSet taskSet);

int runEDFminTime(TaskSet taskSet);
int runEDFmaxTime(TaskSet taskSet);
int runEDFminOverdueProcesses(TaskSet taskSet);
int runEDFmaxOverdueProcesses(TaskSet taskSet);

#endif