import numpy as np


#----------------------------
#calcul
#----------------------------
#calculs sur des array de même shape
a = np.array([1,2,3,4])
b = np.array([10,20,30,40])
c = a * b
print(c)

#broadcasting
#capacité de numpy à faire des opérations sur
#des array de shape différente
#le plus petit array est "broadcasté"
#pour pouvoir les faire intéragir a = np.array([[0,0,0],[10,10,10],[20,20,20],[30,30,30]]) b = np.array([1,2,3])
print(a+b) #b est stretché dans une dimension
#[[ 1  2  3]
# [11 12 13]
# [21 22 23]
# [31 32 33]]

#----------------------------
#nditer
#----------------------------

#iterateur
a = np.arange(0,60,5)
a = a.reshape(3,4)
for x in np.nditer(a):
    print(x, end=" ")
print()

#transpose
b = a.T #utilisation de l'ordre 'T' (column)
print(b)

b = a.copy(order='F')
for x in np.nditer(b):
    print(x, end=" ")
print()

for x in np.nditer(a, order='F'): #sans copier l'élément
    print(x, end=" ")
print()

#nditer writable:
for x in np.nditer(a, op_flags= ['readwrite']):
    x[...] = 2*x
print(a)


#nditer flags
for x in np.nditer(a, flags=['external_loop'], order='F'):
    print(x, end=" ")
print()

#broadcast iter
b = np.array([1,2,3,4], dtype=int)
for x,y in np.nditer([a,b]):
    print(x,':',y, end=" ")
print()

