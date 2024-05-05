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
    std::ifstream file("RTaskSets.txt"); // Open file
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
                std:: string startTime;
                std:: string computationTime;
                std:: string softDeadline;
                std:: string hardDeadline;
                std:: string period;
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
    /*
     ghi thời gian chạy của mỗi taskset vào file csv
     dùng csv vẽ đồ thị miêu tả sự khác nhau khi sử dụng kỹ thuật phân loại yêu cầu  avf khi không sử dụng
    */

    // fstream output;
    // output.open("Result.csv", ios ::out);
    // for (int i = 0; i < taskSetList.size(); i++)
    // {
    //     clock_t start = clock();
    //     int theNumberOfTasksAcrossTheDeadline;
    //     theNumberOfTasksAcrossTheDeadline = runEDF(taskSetList[i]);
    //     clock_t end = clock();
    //     double elapsed_ticks = difftime(end, start);
    //     double milliseconds = elapsed_ticks * (1000.0 / CLOCKS_PER_SEC);
    //     output << milliseconds << ",";
    // }
    // output << endl;

    // output.close();
    return 0;
}