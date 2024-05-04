#ifndef EDF_ALGORITHM_H
#define EDF_ALGORITHM_H

#include <iostream>
#include <fstream>
#include <string>
#include <set>

#include "Task.h"
#include "TaskSet.h"

int runEDF(TaskSet taskSet);

int runEDFplus(TaskSet taskSet);

unsigned long long gcd( unsigned long long a, unsigned long long b);

unsigned long long getLCMPeriod(TaskSet taskSet);

#endif