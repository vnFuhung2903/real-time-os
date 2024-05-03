#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <vector>
#include "Task.h"
#include "TaskSet.h"

int main()
{
    // import data
    vector<TaskSet> taskSetList;
    fstream input("BasicInput.txt");
    fstream output;
    output.open("Result.csv", ios ::out);

        
    input.close();
    output.close();


    return 0;
}