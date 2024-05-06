import pandas as pd
import matplotlib.pyplot as plt
import subprocess


# compile the c++ code
subprocess.call(["g++", "main.cpp", "EdfAlgorithm.cpp","-o", "main"])
subprocess.call(["./main"])

# read a csv file
data = pd.read_csv("Result.csv")
# print(data.head())
# print(data['TaskSet']);
# print(data.columns)

# plot the data

plt.subplot(2, 1, 1)
plt.figure(figsize=(10, 6))
plt.plot(data['TaskSet'], data['TrEDF'], marker='o')
plt.plot(data['TaskSet'], data['TrEDFminT'], marker='o')
plt.plot(data['TaskSet'], data['TrEDFmaxT'], marker='o')
plt.plot(data['TaskSet'], data['TrEDFminOP'], marker='o')
plt.plot(data['TaskSet'], data['TrEDFmaxOP'], marker='o')

plt.xlabel('TaskSet')
plt.ylabel('Time')
plt.title('Time running of EDFs')
plt.grid(True)
plt.show()

# create new diagram
plt.subplot(2, 1, 2)
plt.figure(figsize=(10, 6))
plt.plot(data['TaskSet'], data['NtEDF'], marker='o')
plt.plot(data['TaskSet'], data['NtEDFminT'], marker='o')
plt.plot(data['TaskSet'], data['NtEDFmaxT'], marker='o')
plt.plot(data['TaskSet'], data['NtEDFminOP'], marker='o')
plt.plot(data['TaskSet'], data['NtEDFmaxOP'], marker='o')

plt.xlabel('TaskSet')
plt.ylabel('num Tasks')
plt.title('The number of tasks across deadline ')
plt.grid(True)
plt.show()




