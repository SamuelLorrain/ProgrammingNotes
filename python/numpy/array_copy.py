a = np.arange(6).reshape(3,2)
b = a.view() #shallow copy
c = a.copy() #deep copy
