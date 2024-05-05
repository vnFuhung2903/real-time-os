#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <string>

// #include "Task.h"
#include "Ntask.h"
#include "NtaskSet.h"
// #include "TaskSet.h"
// #include "EdfAlgorithm.h"

using namespace std;

int main()
{
    // test the TaskSet class
    // TaskSet taskSet;
    TaskSet taskSet;

    // Add tasks to the multiset
    Task task1("Task1", 0, 5, 10, 20);
    Task task2("Task2", 0, 3, 8, 15);
    Task task3("Task3", 0, 7, 12, 25);
    Task task4("Task4", 0, 2, 8, 10);
    Task task5("Task5", 0, 4, 10, 20);

    taskSet.addTask(task1);
    taskSet.addTask(task2);
    taskSet.addTask(task3);
    taskSet.addTask(task4);
    taskSet.addTask(task5);

    cout << "period: " << task1.getPriorityLevel() << endl;

    // test all methods of TaskSet
    taskSet.printTaskSet();
    taskSet.removeTask();
    taskSet.printTaskSet();
    taskSet.removeTask();
    cout << "max: " << taskSet.getHighestPriorityTask().getPriorityLevel() << endl;

    cout << "data:" << endl;

    vector<TaskSet> taskSetList;
    // fstream input("BasicInput.txt");
    std::ifstream file("BasicInput.txt"); // Mở file

    std::string line;

    if (file.is_open())
    {
        while (std::getline(file, line))
        { // Đọc từng dòng của file
            std::stringstream ss(line);
            std::string token;

            while (std::getline(ss, token, ','))
            { // Tách dữ liệu bằng dấu phẩy
                if (token == "Begin" || token == "N")
                {
                    std::cout << "Value: " << token << ", Type: " << typeid(token).name() << std::endl;
                }
                else
                {
                    try
                    {
                        int ok = 1;
                        int intValue = std::stoi(token); // Chuyển đổi thành số nguyên
                        std::cout << "Value: " << intValue + ok << ", Type: " << typeid(intValue).name() << std::endl;
                    }
                    catch (...)
                    {
                        std::cerr << "Error converting string to integer!" << std::endl;
                    }
                }
            }
            std::cout << " new" << endl;
        }
        file.close(); // Đóng file
    }
    else
    {
        std::cerr << "Unable to open file!" << std::endl;
    }

    // input.close();

    return 0;
}