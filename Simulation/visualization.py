import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# read a csv file
data = pd.read_csv("Result.csv")
print(data.head())

# plot the data


plt.figure(figsize=(10, 6))
plt.plot(data['time'], data['num'], marker='o')
plt.xlabel('time')
plt.ylabel('num')
plt.title('Biến thiên của "num" theo thời gian')
plt.grid(True)
plt.show()