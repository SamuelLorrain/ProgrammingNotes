import numpy as np

#
#L'objet numpy.array est l'objet le plus important
#de Numpy. Il permet de stocker des tableaux de N
#dimension d'un même type.
#
#numpy.array(
#object,            #
#dtype = None,      #optionel, type de l'array
#copy = True,       #constructeur par copie par défaut
#order = None,      #C(row),F(column),A(any) (A par defaut)
#subok = False,     #si Vrai, on peut retourner des sous classes
                    #de l'objet
#ndmin = 0          #minimum dimension
#)
#

a = np.array([1,2,3]) #tableau à une dimension
print(a)

a = np.array([[1,2],[3,4]])#tableau à deux dimensions
print(a)

a = np.array([1,2,3,4], ndmin=2) #tableau à 2 dimensions mini
print(a) #[[1,2,3,4]]

a = np.array([1,2,3], dtype=complex)
print(a) #[1.+0.j 2.+0.j 3.+0.j]


#shape
a = np.array([[1,2,3],[1,2,3]])
print(a.shape) #(2,3)
a.shape = (3,2) #OU a.reshape(3,2)
print(a) #[[1,2], [3,4], [5,6]]

#ndim (renvoi le nombre de dimensions)
a= np.arange(24) #range
print(a.ndim) #1
b = a.reshape(2,4,3)
print(b.ndim) #3

#itemsize
a= np.array([1,2,3], dtype=np.int8)
print(a.itemsize) #renvoi la taille d'un élément d'un array
               #ici 1

#nflag
print(a.flags) #affiche des informations sur le tableau

