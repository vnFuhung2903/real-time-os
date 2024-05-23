import math

from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from sortedcontainers import SortedList
import matplotlib.pyplot as plt
import numpy as np
import tkinter as tk


def lcm(a, b):
    return abs(a * b) // math.gcd(a, b)


numberOfTasks = int(input("Please Enter Number of Input Tasks (Start time, computation time, deadline, period ): "))
LCM = 1
task = [0] * numberOfTasks

for i in range(0, numberOfTasks):
    print(f"Enter Task {i + 1} Profile:", end=" ")
    start_time, computation_time, deadline, period = map(int, input().split())
    task[i] = {
        "Task Number": i + 1,
        "Start Time": start_time,
        "Computation Time": computation_time,
        "priorityLevel": deadline,
        "Deadline": deadline,
        "Period": period,
        "TimeRemaining": computation_time,
        "Current Period": 0
    }
LCM = task[0]["Period"]
for i in range(0, numberOfTasks):
    LCM = lcm(LCM, task[i]["Period"])

root = tk.Tk()
root.withdraw()


def show_plot():
    new_window = tk.Toplevel(root)
    new_window.title("EDF Scheduling")

    fig, gnt = plt.subplots()
    gnt.set_ylim(0, (numberOfTasks + 1) * 10 + 1)
    gnt.set_xlim(0, LCM + 1)
    gnt.set_xlabel('Time Steps')
    gnt.set_ylabel('Task Number')
    gnt.set_title('EDF Scheduling')
    gnt.set_yticks(np.arange(10, 10 * numberOfTasks + 1, 10))
    gnt.set_yticklabels(np.arange(int(numberOfTasks), 0, -1)[::-1])
    gnt.set_xticks(np.arange(0, LCM + 1, 1))
    gnt.grid(True)

    sorted_tasks = SortedList(key=lambda task: task["Deadline"])

    for i in range(0, numberOfTasks):
        n = 0
        m = 0
        while task[i]["Deadline"] + n * task[i]["Period"] <= LCM:
            gnt.arrow(task[i]["Deadline"] + n * task[i]["Period"], 10 * (task[i]["Task Number"]), 0, -4.5,
                      head_width=0.2, head_length=0.5, fc='red', ec='red')
            n += 1
        while task[i]["Period"] + m * task[i]["Period"] <= LCM:
            gnt.arrow(task[i]["Period"] + m * task[i]["Period"], 10 * (task[i]["Task Number"]), 0, 5, head_width=0.2,
                      head_length=0.5, fc='black', ec='black')
            m += 1

    for step in range(0, LCM):
        for i in range(0, int(numberOfTasks)):
            if task[i]["Start Time"] == step:
                sorted_tasks.add(task[i])
                task[i]["Current Period"] += 1
        if sorted_tasks:
            top_element = sorted_tasks[0]
            if step <= top_element["Deadline"]:
                gnt.broken_barh([(step, 1)], (10 * top_element["Task Number"], 5), facecolors='blue')
                top_element["TimeRemaining"] -= 1
            else:
                gnt.broken_barh([(step, 1)], (10 * top_element["Task Number"], 5), facecolors='red')
                top_element["TimeRemaining"] -= 1
                continue
            if top_element["TimeRemaining"] == 0:
                task[top_element["Task Number"] - 1]["Start Time"] += task[top_element["Task Number"] - 1]["Period"]
                task[top_element["Task Number"] - 1]["TimeRemaining"] = task[top_element["Task Number"] - 1][
                    "Computation Time"]
                task[top_element["Task Number"] - 1]["Deadline"] += task[top_element["Task Number"] - 1]["Period"]
                if sorted_tasks:
                    first_element = sorted_tasks.pop(0)

    canvas = FigureCanvasTkAgg(fig, master=new_window)  # A tk.DrawingArea.
    canvas.draw()
    canvas.get_tk_widget().pack(side=tk.TOP, fill=tk.BOTH, expand=1)


CpuUtilization = 0
for i in range(0, numberOfTasks):
    CpuUtilization += task[i]["Computation Time"] / task[i]["Period"]
show_plot()

if CpuUtilization <= 1:
    print("The system is schedule with cpu utilization: " + str(CpuUtilization))
else:
    print("The system is not schedule")
root.mainloop()
