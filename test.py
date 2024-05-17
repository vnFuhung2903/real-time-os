import matplotlib.pyplot as plt
import numpy as np
import tkinter as tk

from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg

numberOfTasks = input("Please Enter Number of Input Tasks: ")
Task_Matrix = np.zeros((int(numberOfTasks), 7))
# C - D - T - process me? - remaining time? - next activation time - priority?
# 0   1   2        3               4                    5                6

maxT = 0
for i in range(0, int(numberOfTasks)):
    print("Enter Task ", i + 1, " Profile (Execution Time, Deadline, Period)")
    temp = input()
    temp = temp.split(" ")
    Task_Matrix[i][0] = int(temp[0])
    Task_Matrix[i][1] = int(temp[1])
    Task_Matrix[i][2] = int(temp[2])
    Task_Matrix[i][3] = int(temp[1])
    Task_Matrix[i][4] = int(temp[0])
    Task_Matrix[i][5] = 0
    if Task_Matrix[i][2] > maxT:
        maxT = int(Task_Matrix[i][2])

root = tk.Tk()
root.withdraw()  # Hide the root window
def show_plot():

    new_window = tk.Toplevel(root)
    new_window.title("EDF Scheduling")

    stack = list()

    fig, gnt = plt.subplots()
    gnt.set_ylim(0, (int(numberOfTasks) + 1) * 10 + 1)
    gnt.set_xlim(0, 2 * maxT)
    gnt.set_xlabel('Time Steps')
    gnt.set_ylabel('Task Number')
    gnt.set_title('EDF Scheduling')
    gnt.set_yticks(np.arange(10, 10 * int(numberOfTasks) + 1, 10))
    gnt.set_yticklabels(np.arange(int(numberOfTasks), 0, -1))
    gnt.set_xticks(np.arange(-1, 2 * maxT, 1))

    gnt.grid(True)

    for i in range(0, 2 * maxT):
        for j in range(0, int(numberOfTasks)):
            if (i == Task_Matrix[j][5]):
                Task_Matrix[j][5] = Task_Matrix[j][5] + Task_Matrix[j][2]
                gnt.arrow(task, 10 * (int(numberOfTasks) - Task_Matrix[j][6] + 1), 0, 4.5, head_width=0.2, head_length=0.5,
                          fc='k', ec='k')
                # gnt.arrow(i + Task_Matrix[j][3], 10 * (int(numberOfTasks) - Task_Matrix[j][6] + 1), 0, -4.5,
                #           head_width=0.2, head_length=0.5, fc='r', ec='r')
                stack.append(list(Task_Matrix[j]))
                Task_Matrix[j][1] = Task_Matrix[j][1] + Task_Matrix[j][2]

        if (len(stack) != 0):
            stack = sorted(stack, key=lambda x: x[1])

            for j in range(0, len(stack)):
                if (stack[j][4] == 0):
                    del stack[j]
                    break

            if (len(stack) != 0):
                current_task = stack[0]
                if (i >= current_task[5] - current_task[2] + current_task[1]):
                    gnt.broken_barh([(i, 1)], (10 * (int(numberOfTasks) - current_task[6] + 1) - 4, 8),
                                    facecolors=('tab:red'))
                    isSchedulable = False
                else:
                    gnt.broken_barh([(i, 1)], (10 * (int(numberOfTasks) - current_task[6] + 1) - 4, 8),
                                    facecolors=('tab:blue'))
                stack[0][4] = stack[0][4] - 1

    canvas = FigureCanvasTkAgg(fig, master=new_window)  # A tk.DrawingArea.
    canvas.draw()
    canvas.get_tk_widget().pack(side=tk.TOP, fill=tk.BOTH, expand=1)

isSchedulable = True
Ub = 1
Uti = 0

for j in range(0, int(numberOfTasks)):
    Uti = Uti + Task_Matrix[j][0] / Task_Matrix[j][2]

Task_Matrix = Task_Matrix[Task_Matrix[:, 1].argsort()]
for i in range(0, int(numberOfTasks)):
    Task_Matrix[i][6] = i + 1

show_plot()

print("########################################")
print("U_bound = " + str(Ub))
print("Utilization = " + str(Uti))
if (Uti <= Ub):
    print("Scheduling Prediction: Schedulable!")
else:
    print("Scheduling Prediction: Un-Schedulable!")

if (isSchedulable == False):
    print("It's Not Schedulable!!! See The Output:")
print("########################################")
root.mainloop()