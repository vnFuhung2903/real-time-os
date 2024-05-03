#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include "Task.h"
#include "TaskSet.h"


int main()
{
    //test the TaskSet class
    TaskSet taskSet;

    // Add tasks to the multiset
    Task task1("Task1", 0, 5, 10, 20);
    Task task2("Task2", 0, 3, 8, 15);
    Task task3("Task3", 0, 7, 12, 25);
    Task task4("Task4", 0, 2, 8, 10);

    taskSet.addTask(task1);
    taskSet.addTask(task2);
    taskSet.addTask(task3);
    taskSet.addTask(task4);
    // taskSet.removeTask();

    // Iterate over the multiset and print tasks
    taskSet.printTaskSet();

    //
    return 0;
}