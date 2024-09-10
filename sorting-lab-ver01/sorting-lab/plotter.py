#!/usr/bin/env python3
import pandas as pd
from matplotlib import pyplot as plt

df = pd.read_csv('sorting-lab-ver01/sorting-lab/example.csv')
plt.plot(df['size'], df['throughput'])
plt.show()

