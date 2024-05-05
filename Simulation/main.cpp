#include <iostream>
#include <fstream>
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
    fstream input("BasicInput.txt");
    std::string line;

    if (file.is_open())
    {
        while (std::getline(file, line))
        { // Đọc từng dòng của file
            std::stringstream ss(line);
            std::string token;

            while (std::getline(ss, token, ','))
            { // Tách dữ liệu bằng dấu phẩy
                std::cout << token << std::endl;
            }
        }
        file.close(); // Đóng file
    }
    else
    {
        std::cerr << "Unable to open file!" << std::endl;
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
        int theNumberOfTasksAcrossTheDeadline;
        theNumberOfTasksAcrossTheDeadline = runEDF(taskSetList[i]);
        clock_t end = clock();
        double elapsed_ticks = difftime(end, start);
        double milliseconds = elapsed_ticks * (1000.0 / CLOCKS_PER_SEC);
        output << milliseconds << ",";
    }
    output << endl;

    // output.close();
    return 0;
}