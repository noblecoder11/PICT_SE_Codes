import numpy as np
import pandas as pd

file=pd.read_csv("D:\PICT COLLEGE\Semester 3\PICT_SE_Codes\Pokemon (1).csv")

print(file.shape)
print(file.size)
print(file.head())
file.set_index("Name")
file=file.drop(columns='#')
print(file.head())
print(file.unique('Type 1'))