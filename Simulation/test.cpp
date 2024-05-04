#include <iostream>
#include <fstream>
#include <set>
#include <string>

#include "Task.h"
#include "TaskSet.h"
#include "EdfAlgorithm.h"

using namespace std;


int main()
{
    // test the TaskSet class
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
    // taskSet.printTaskSet();
    cout << task1.getPriorityLevel() << endl;
    cout << task2.getPriorityLevel() << endl;
    cout << task3.getPriorityLevel() << endl;
    cout << task4.getPriorityLevel() << endl;
    // task1.printTask();
    // taskSet.printTaskSet();
    if (task1<task2)
    {
        cout<< "ok";
    }
    else
    {
        cout<< "not ok";
    }
    cout<< endl;

    taskSet.printTaskSet();
    taskSet.removeTask();
    taskSet.printTaskSet();
    
    cout<< "lcm: " << getLCMPeriod(taskSet) << endl;


    

    //
    return 0;
}