import matplotlib.pyplot as plt
import tkinter as tk
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import subprocess
import pandas as pd
import numpy as np
import os

# compile the c++ code
# subprocess.call(["g++", "main.cpp", "EdfAlgorithm.cpp","-o", "main"])
# subprocess.call(["./main"])
#
data = pd.read_csv("Result.csv")

root = tk.Tk()
root.title("Controller")
label = tk.Label(root, text="control panel", font=("Arial", 24), fg="blue" ,padx=10, pady=10)
label.pack(pady=5)  # Add vertical padding

def create_new_window1():
    new_window = tk.Toplevel()
    new_window.title("Comparison tables")
    new_window.geometry("800x600")
    # create an image by matplotlib
    fig, ax = plt.subplots(figsize=(10, 6))

    # Plot the data
    ax.plot(data['TaskSet'], data['TrEDF'], marker='o')
    ax.plot(data['TaskSet'], data['TrEDFminT'], marker='o')
    ax.plot(data['TaskSet'], data['TrEDFmaxT'], marker='o')
    ax.plot(data['TaskSet'], data['TrEDFminOP'], marker='o')
    ax.plot(data['TaskSet'], data['TrEDFmaxOP'], marker='o')

    # Set the labels and title
    ax.set_xlabel('TaskSet')
    ax.set_ylabel('Time')
    ax.set_title('Time running of EDFs')
    ax.grid(True)

    # Create a new canvas and add it to the window
    canvas = FigureCanvasTkAgg(fig, master=new_window)
    canvas.draw()
    canvas.get_tk_widget().pack(side=tk.TOP, fill=tk.BOTH, expand=1)


def create_new_window2():
    new_window = tk.Toplevel()
    new_window.title("Comparison tables")
    new_window.geometry("800x600")
    # create an image by matplotlib
    fig, ax = plt.subplots(figsize=(10, 6))

    # Plot the data
    ax.plot(data['TaskSet'], data['NtEDF'], marker='o')
    ax.plot(data['TaskSet'], data['NtEDFminT'], marker='o')
    ax.plot(data['TaskSet'], data['NtEDFmaxT'], marker='o')
    ax.plot(data['TaskSet'], data['NtEDFminOP'], marker='o')
    ax.plot(data['TaskSet'], data['NtEDFmaxOP'], marker='o')

    # Set the labels and title
    ax.set_xlabel('TaskSet')
    ax.set_ylabel('num Tasks')
    ax.set_title('The number of tasks across deadline ')
    ax.grid(True)

    # Create a new canvas and add it to the window
    canvas = FigureCanvasTkAgg(fig, master=new_window)
    canvas.draw()
    canvas.get_tk_widget().pack(side=tk.TOP, fill=tk.BOTH, expand=1)

def create_new_window3():
    os.system('start cmd /k python EDF.py')

button1 = tk.Button(root, text="Comparison time processes", command=create_new_window1, width=30, height=3, wraplength=200)
button1.pack(pady=5, padx=15)

button2 = tk.Button(root, text="Comparison number of off deadline processes", command=create_new_window2, width=30, height=3, wraplength=200)
button2.pack(pady=5, padx=15)

button3 = tk.Button(root, text="processes management", command=create_new_window3, width=30, height=3, wraplength=200)
button3.pack(pady=5, padx=15)

buttonQuit = tk.Button(root, text="Quit", command=root.quit, width=30, height=3, wraplength=200)
buttonQuit.pack(pady=10, padx=15)
root.mainloop()