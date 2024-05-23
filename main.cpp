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
            std::stringstream ss2(line);
            std::string numTasksStr;
            std::getline(ss2, numTasksStr);
            int numTasks = std::stoi(numTasksStr);

            std::getline(file, line);
            std::stringstream ss3(line);
            std::string numProcessorsStr;
            std::getline(ss3, numProcessorsStr);
            int numProcessors = std::stoi(numProcessorsStr);

            std::getline(file, line);
            std::stringstream ss4(line);
            std::string preemptive;
            std::getline(ss4, preemptive);

            TaskSet taskSet(numTasks, numProcessors);
            for (int i = 0; i < numTasks; i++)
            {
                std::getline(file, line);
                std::string startTime;
                std::string computationTime;
                std::string softDeadline;
                std::string hardDeadline;
                std::string period;
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
    }
    // run EDF and define output file
    std::ofstream output; // Use ofstream for output operations
    output.open("Result.csv", ios ::out);
    /*
    Task sets TaskSet
    TrEDF time runEDf
    NtEDF the number of tasks across the deadline in EDf
    TrEDFminT time runEDFminTime
    NtEDFminT the number of tasks across the deadline in runEDFminTime
    TrEDFmaxT time runEDFmaxTime
    NtEDFmaxT the number of tasks across the deadline in runEDFmaxTime
    TrEDFminOP time runEDFminOverdueProcesses
    NtEDFminOP the number of tasks across the deadline in runEDFminOverdueProcesses
    TrEDFmaxOP time runEDFmaxOverdueProcesses
    NtEDFmaxOP the number of tasks across the deadline in runEDFmaxOverdueProcesses
    */
    // output << "TaskSet,TrEDF,NtEDF,TrEDFminT,NtEDFminT,TrEDFmaxT,NtEDFmaxT,TrEDFminOP,NtEDFminOP,TrEDFmaxOP,NtEDFmaxOP" << endl;
    for (int i = 0; i < taskSetList.size() ; i++)
    {
        output << "TaskSet" << i << ",";
        // cout << backtrackEDF(0,taskSetList[i]) << '\n';
        // cout<< checkEDF(taskSetList[i],0) << '\n';

        // change time to milliseconds
        
    }
    // if (backtrackEDF(0,taskSetList[0])== true &&  backtrackEDF(0,taskSetList[1])== true && backtrackEDF(0, taskSetList[2])== true && backtrackEDF(0, taskSetList[3])== true && backtrackEDF(0, taskSetList[4])== true && backtrackEDF(0, taskSetList[5])== false)
    // {
    //     cout << "pass";
    // }
    // else
    //     cout<< " error";
    // cout<< taskSetList[5].getNumProcessors();
    
    // updateProcess(1,taskSetList[0]);
    // for (int i = 0; i < taskSetList[0].getNumTasks(); i++)
    // {
    //     cout <<taskSetList[0].getTasks()[i].getPriorityLevel()<<endl;
    // }
    
    cout<< runEDF(taskSetList[0]) << '\n';


    // output.close();
    return 0;
}