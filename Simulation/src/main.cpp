#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include "Task.h"
#include "TaskSet.h"

int main()
{
    std::multiset<Task, Task::CompareTasks> taskSet;

    // Add tasks to the multiset
    Task task1("Task1", 0, 5, 10, 20);
    Task task2("Task2", 0, 3, 8, 15);
    Task task3("Task3", 0, 7, 12, 25);
    Task task4("Task4", 0, 2, 8, 10);

    taskSet.insert(task1);
    taskSet.insert(task2);
    taskSet.insert(task3);
    taskSet.insert(task4);

    // Iterate over the multiset and print tasks
    for (const auto &task : taskSet)
    {
        std::cout << "Task Name: " << task.getPriorityLevel() << ", Priority Level: " << task.getPriorityLevel() << std::endl;
    }
     return 0;
}