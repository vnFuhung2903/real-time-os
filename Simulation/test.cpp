#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <string>

#include "Task.h"
#include "TaskSet.h"

using namespace std;

int main()
{

    // TaskSet taskSet;

    // // Add tasks to the multiset
    // Task task1("Task1", 0, 5, 10, 20);
    // Task task2("Task2", 0, 3, 8, 15);
    // Task task3("Task3", 0, 7, 12, 25);
    // Task task4("Task4", 0, 2, 8, 10);
    // Task task5("Task5", 0, 4, 10, 20);

    // taskSet.addTask(task1);
    // taskSet.addTask(task2);
    // taskSet.addTask(task3);
    // taskSet.addTask(task4);
    // taskSet.addTask(task5);

    cout << "data:" << endl;

    vector<TaskSet> taskSetList;
    std::ifstream file("BasicInput.txt"); // Open file

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
            
        }

        
    }
    else
    {
        std::cerr << "Unable to open file!" << std::endl;
    }


    return 0;
}