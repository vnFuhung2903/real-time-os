#include <iostream>
#include <fstream>
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

    // test all methods of TaskSet
    taskSet.printTaskSet();
    taskSet.removeTask();
    taskSet.printTaskSet();
    taskSet.removeTask();
    cout<<"max: "<< taskSet.getHighestPriorityTask().getPriorityLevel()<<endl;
    
    return 0;
}