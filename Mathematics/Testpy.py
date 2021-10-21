import numpy as np

li = range(3)
li = np.array(li)
arr1 = np.zeros((10,15))
arr2 = np.zeros((10,3))
for i in range(10):
    np.append(arr2, li)

print arr2
print li