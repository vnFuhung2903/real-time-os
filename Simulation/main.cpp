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

    output.close();
    return 0;
}