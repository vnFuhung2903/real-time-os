multiset<Task, Task::CompareTasks> taskSet;

    // Add tasks to the multiset
    taskSet.insert(Task("Task1", 0, 5, 10, 20));
    taskSet.insert(Task("Task2", 2, 3, 8, 15));
    taskSet.insert(Task("Task3", 1, 4, 12, 25));
    taskSet.insert(Task("Task4", 3, 2, 6, 10));

    // Print the list of tasks sorted by priority level in ascending order
    cout<< taskSet.begin()->getName() << " " << taskSet.begin()->getPriorityLevel() << endl;