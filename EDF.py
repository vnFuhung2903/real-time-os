import math
from sortedcontainers import SortedList

import matplotlib.pyplot as plt
import numpy as np
import tkinter as tk
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg


# C - D - T - process me? - remaining time? - next activation time - priority?
# 0   1   2        3               4                    5                6
def lcm(a, b):
    return abs(a * b) // math.gcd(a, b)


numberOfTasks = input("Please Enter Number of Input Tasks: ")
LCM = 1
task = [0] * int(numberOfTasks)

for i in range(0, int(numberOfTasks)):
    print(f"Enter Task {i + 1} Profile:")
    start_time = int(input("Start Time: "))
    computation_time = int(input("Computation Time: "))
    deadline = int(input("Deadline: "))
    period = int(input("Period: "))
    task[i] = {
        "Task Number": i,
        "Start Time": start_time,
        "Computation Time": computation_time,
        "priorityLevel": deadline,
        "Deadline": deadline,
        "Period": period,
        "TimeRemaining": computation_time,
        "Current Period": 0
    }
LCM = task[0]["Period"]
for i in range(1, int(numberOfTasks)):
    LCM = lcm(LCM, task[i]["Period"])
print(LCM)

sorted_tasks = SortedList(key=lambda task: task["Deadline"])

fig, gnt = plt.subplots()
gnt.set_ylim(0, (int(numberOfTasks) + 1) * 10 + 1)
gnt.set_xlim(0, 2 * LCM)
gnt.set_xlabel('Time Steps')
gnt.set_ylabel('Task Number')
gnt.set_title('EDF Scheduling')
gnt.set_yticks(np.arange(10, 10 * int(numberOfTasks) + 1, 10))
gnt.set_yticklabels(np.arange(int(numberOfTasks), 0, -1)[::-1])
gnt.set_xticks(np.arange(0, LCM + 5 , 1))

gnt.grid(True)
# for j in range(0, int(numberOfTasks)):
#     if task[j]["Start Time"] == 0:
#         sorted_tasks.add(task[j])
#         task[j]["Current Period"] += 1
#
# if sorted_tasks:
#     top_element = sorted_tasks[0]
#     print(top_element["Task Number"])
#     sorted_tasks.remove(top_element)
#     Ntop_element = sorted_tasks[0]
#     print(Ntop_element["Task Number"])

# gnt.broken_barh([(0, 3)], (10, 3), facecolors=('tab:blue'))
for step in range(0, LCM + 1):
    for j in range(0, int(numberOfTasks)):
        if task[j]["Start Time"] == step:
            sorted_tasks.add(task[j])
            task[j]["Current Period"] += 1

    if sorted_tasks:
        top_element = sorted_tasks[0]
        if step <= top_element["Deadline"]:
            gnt.broken_barh([(step, 1)], (10+top_element['Task Number']*10, 3), facecolors=('tab:blue'))
            top_element["TimeRemaining"] -= 1
        else:
            gnt.broken_barh([(step, 1)], (10+top_element['Task Number']*10, 3), facecolors='tab:red')
        if top_element["TimeRemaining"] == 0:
            sorted_tasks.remove(top_element)
            top_element["Start Time"] += top_element["Period"]
            top_element["TimeRemaining"] = top_element["Computation Time"]
            top_element["Deadline"] += top_element["Period"]
            sorted_tasks.add(top_element)

    step += 1
plt.show()
