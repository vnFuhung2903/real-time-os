#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <string>
#include <vector>
#include <time.h>
#include <ctime>

#include "Task.h"
#include "TaskSet.h"
#include "EdfAlgorithm.h"
int main()
{
    // import data
    vector<TaskSet> taskSetList;
    // std::ifstream file("RTaskSets.txt"); // Open file
    std::ifstream file("TestTaskSet.txt"); // Open file
    std::string line;

    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            std::stringstream ss(line);
            std::string title;
            std::getline(ss, title); // read "begin"

            std::getline(file, line);
            int numTasks = std::stoi(line);

            std::getline(file, line);
            int numProcessors = std::stoi(line);

            std::getline(file, line);
            std::stringstream ss4(line);
            std::string preemptive;
            std::getline(ss4, preemptive);

            TaskSet taskSet(numTasks, numProcessors);

            for (int i = 0; i < numTasks; i++)
            {
                std::getline(file, line);
                std::string startTime, computationTime, softDeadline, hardDeadline, period;
                std::stringstream ss5(line);
                std::getline(ss5, startTime, ',');
                std::getline(ss5, computationTime, ',');
                std::getline(ss5, softDeadline, ',');
                std::getline(ss5, hardDeadline, ',');
                std::getline(ss5, period, ',');
                Task task("Task" + std::to_string(i), std::stoi(startTime), std::stoi(computationTime), std::stoi(hardDeadline), std::stoi(period));
                taskSet.addTask(task);
            }
            taskSetList.push_back(taskSet);
        }
    }
    else
    {
        std::cerr << "Unable to open file!" << std::endl;
        return 1;
    }
    // run EDF and define output file
    std::ofstream output;
    output.open("Result.csv", ios ::out);
    output << "Num Task Set,Num Tasks,Time running,Cpu utilization" << endl;
    clock_t start = clock();
    int totalTasKs = 0;
    for (int i = 0; i < taskSetList.size(); i++)
    {
        totalTasKs += taskSetList[i].getTasks().size();
    }
    double cpuUtilization = 0;

    for (int i = 0; i < taskSetList.size(); i++)
    {
        // cout<<taskSetList[i].getLCMPeriod()<< endl;
        vector<TaskSet> result = divideTasks(taskSetList[i]);
        // cout << result.size() << endl;
        for (TaskSet &taskSet : result)
        {
            taskSet.setNumTasks(taskSet.getTasks().size());
            taskSet.setNumProcessors(1);
        }
        for (TaskSet &taskSet : result)
        {
            runOneEDF(taskSet);
        }
        double m = 0;
        for (TaskSet &taskSet : result)
        {
            n += (double)taskSet.getUtilization();
        }
        cpuUtilization += n / taskSetList[i].getTasks().size();
    }
    clock_t end = clock();
    double time = ((double)(end - start) / CLOCKS_PER_SEC) * 1e12;
    output << "200," << totalTasKs << "," << time << "," << cpuUtilization / 200 << endl;
    output.close();
    return 0;
}