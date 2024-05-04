#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <vector>
#include <time.h>

#include "Task.h"
#include "TaskSet.h"
#include "EDF_Algotithm.h"

int main()
{
    // import data
    vector<TaskSet> taskSetList;
    fstream input("BasicInput.txt");
    if (!input.is_open()) {
        cout << "fail!" << endl;
        return 0;
    }

    string line;
    while (getline(input, line)) {
        if (line == "Begin") {
            int numTasks;
            int numProcessors;
            bool isPreemptive;




            TaskSet taskSet;
            input >> ;

            getline(input, line); // Bỏ qua dòng chứa count

            for (int i = 0; i < count; i++) {
                getline(input, line); // Bỏ qua dòng chứa kích thước tập công việc
                int taskSetSize;
                input >> taskSetSize;
                getline(input, line); // Bỏ qua dòng trống sau kích thước

                TaskSet taskSet;
                for (int j = 0; j < taskSetSize; j++) {
                    Task task;
                    char comma;
                    input >> comma >> task.field1 >> comma >> task.field2 >> comma >> task.field3 >> comma >> task.field4 >> comma >> task.field5;
                    taskSet.push_back(task);
                }
                taskSetList.push_back(taskSet);
                getline(input, line); // Bỏ qua dòng "Begin" hoặc "End"
            }
        }
    }

    input.close();

    /*
     ghi thời gian chạy của mỗi taskset vào file csv
     dùng csv vẽ đồ thị miêu tả sự khác nhau khi sử dụng kỹ thuật phân loại yêu cầu  avf khi không sử dụng
    */

    fstream output;
    output.open("Result.csv", ios ::out);
    for (int i = 0; i < taskSetList.size(); i++)
    {
        clock_t start = clock();
        runEDF(taskSetList[i]);
        clock_t end = clock();
        double elapsed_ticks = difftime(end, start);
        double milliseconds = elapsed_ticks * (1000.0 / CLOCKS_PER_SEC);
        output << milliseconds << ",";
    }
    output << endl;

    

    // output.close();
    return 0;
}