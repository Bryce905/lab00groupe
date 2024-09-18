#!/usr/bin/env python3
import pandas as pd
from matplotlib import pyplot as plt

df = pd.read_csv('Some_Opt.csv')
plt.plot(df['size'], df['throughput'], label = 'Some_Opt')
df1 = pd.read_csv('Some_Opt_t2.csv')
plt.plot(df1['size'], df1['throughput'], label = 'Some_Opt_t2')
df2 = pd.read_csv('QuickSort.csv')
plt.plot(df2['size'], df2['throughput'], label = 'QuickSort')
plt.legend()
plt.show()


