import numpy.matlib
from numpy import np

#numpy.matlib.empty(shape, dtype, order)
print(np.matlib.zeros((2,2)))

#numpy.matlib.eye(n, M,k, dtype)
#n = nombre de rows
#M = nombre de columns
#k = index de la diagonale
#dtype = date type of the ouput
print(np.matlib.eye(n = 3, M = 4, k = 0, dtype = float))

#numpy.matlib.identity(size, dtype)
#matrice identitée
print(np.matlib.identiy(5, float))

#numpy.matlib.rand(
print(np.matlib.rand(3,3))

#matrice
a = np.matrix('1,2:3,4')
print(a) #[[1 2] [3 4]]

