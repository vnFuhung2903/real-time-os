#include <iostream>
#include <fstream>
#include <sstream>

#include <set>
#include <string>
#include <vector>
#include <time.h>

#include "Task.h"
#include "TaskSet.h"
#include "EdfAlgorithm.h"

int main()
{
    // import data
    vector<TaskSet> taskSetList;
    //    std::ifstream file("RTaskSets.txt"); // Open file
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

        for (int i = 0; i < taskSetList.size(); i++)
        {
            TaskSet taskSet = taskSetList[i];
            cout << "TaskSet " << i << endl;
            cout << "NumTasks: " << taskSet.getNumTasks() << endl;
            cout << "NumProcessors: " << taskSet.getNumProcessors() << endl;
            cout << "CheckNumTasks: " << taskSet.getTasks().size() << endl;
        }
    }
    else
    {
        std::cerr << "Unable to open file!" << std::endl;
    }

    cout << "TaskSetList size: " << taskSetList.size() << endl;

    cout << "lcm: " << taskSetList[0].getLCMPeriod() << endl;
    cout << "lcm: " << taskSetList[1].getLCMPeriod() << endl;

    /*
     ghi thời gian chạy của mỗi taskset vào file csv
     dùng csv vẽ đồ thị miêu tả sự khác nhau khi sử dụng kỹ thuật phân loại yêu cầu  avf khi không sử dụng
    */

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
    output << "TaskSet,TrEDF,NtEDF,TrEDFminT,NtEDFminT,TrEDFmaxT,NtEDFmaxT,TrEDFminOP,NtEDFminOP,TrEDFmaxOP,NtEDFmaxOP" << endl;
    // for (int i = 0; i < taskSetList.size(); i++)
    // {
    //     output << "TaskSet" << i << ",";

    //     clock_t startEDf = clock();
    //     int NtEDF = runEDF(taskSetList[i]);
    //     clock_t endEDF = clock();

    //     clock_t startEDFminT = clock();
    //     int NtEDFminT = runEDFminTime(taskSetList[i]);
    //     clock_t endEDFminT = clock();

    //     clock_t startEDFmaxT = clock();
    //     int NtEDFmaxT = runEDFmaxTime(taskSetList[i]);
    //     clock_t endEDFmaxT = clock();

    //     clock_t startEDFminOP = clock();
    //     int NtEDFminOP = runEDFminOverdueProcesses(taskSetList[i]);
    //     clock_t endEDFminOP = clock();

    //     clock_t startEDFmaxOP = clock();
    //     int NtEDFmaxOP = runEDFmaxOverdueProcesses(taskSetList[i]);
    //     clock_t endEDFmaxOP = clock();

    //     // change time to milliseconds
    //     double elapsed_ticks_EDf = difftime(endEDF, startEDf);
    //     double milliseconds_EDf = elapsed_ticks_EDf * (1000.0 / CLOCKS_PER_SEC);

    //     double elapsed_ticks_EDFminT = difftime(endEDFminT, startEDFminT);
    //     double milliseconds_EDFminT = elapsed_ticks_EDFminT * (1000.0 / CLOCKS_PER_SEC);

    //     double elapsed_ticks_EDFmaxT = difftime(endEDFmaxT, startEDFmaxT);
    //     double milliseconds_EDFmaxT = elapsed_ticks_EDFmaxT * (1000.0 / CLOCKS_PER_SEC);

    //     double elapsed_ticks_EDFminOP = difftime(endEDFminOP, startEDFminOP);
    //     double milliseconds_EDFminOP = elapsed_ticks_EDFminOP * (1000.0 / CLOCKS_PER_SEC);

    //     double elapsed_ticks_EDFmaxOP = difftime(endEDFmaxOP, startEDFmaxOP);
    //     double milliseconds_EDFmaxOP = elapsed_ticks_EDFmaxOP * (1000.0 / CLOCKS_PER_SEC);

    //     output << milliseconds_EDf << "," << NtEDF << ","
    //            << milliseconds_EDFminT << "," << NtEDFminT << ","
    //            << milliseconds_EDFmaxT << "," << NtEDFmaxT << ","
    //            << milliseconds_EDFminOP << "," << NtEDFminOP << ","
    //            << milliseconds_EDFmaxOP << "," << NtEDFmaxOP << endl;
    // }

    output.close();
    return 0;
}