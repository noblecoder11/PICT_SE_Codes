import numpy as np
import pandas as pd

poke=pd.read_csv("D:\PICT COLLEGE\Semester 3\PICT_SE\#DataScience\Pokemon (1).csv")

# print(file.shape)
# print(file.size)
# print(file.head())
# file.set_index("Name")
# file=file.drop(columns='#')
# print(file.head())
# print(file.unique('Type 1'))

# Contains type 1 list a=[poison, psychic, etc.]
a=poke['Type 1'].unique()
# Contains type 2 list b=[poison, leaf, nan, etc.]
b=poke['Type 2'].unique()
# Union of a and b
c=list(a)+list(b)
#'nan' was found at index 19 in c
del c[19]

max=0
for type in c:
  meanType=poke.loc[(poke['Type 1']==type) | (poke['Type 2']==type)].HP.mean()
  print(meanType, type)
  if meanType > max:
    max=meanType
    # print(meanType)
