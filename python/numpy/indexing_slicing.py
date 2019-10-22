import numpy as np

#fonctionne de la même façon que le
#slicing et l'indexing en python de base

a = np.arange(10)
s = slice(2,7,2)
print(a[s]) #[2 4 6]
print(a[2:7:2]) #equivalent, [2 4 6]

print(a[2:5]) #[2 3 4
print(a[5]) #4

#...
a = np.array([1,2,3],[4,5,6],[7,8,9])
print(a[...,1]) #affiche la 2eme colonne
print(a[1,...]) #affiche la 2eme ligne
print(a[...,1:]) #slice la première colone


#integer indexing
a = np.array([[1,2],[3,4],[5,6]])
print(a[[0,1,2], [0,1,0]]) #[1 4 5]
#selectionne les éléments (0,0)(1,1) et (2,0)

#boolean indexing
a = np.array([[0,1,2],[3,4,5],[6,7,8],[9,10,11]])
print(a[a > 5]) #affiche tous les éléments supérieurs à 5

a = np.array([np.nan,1,2,np.nan,3,4,5])
print(a[~np.isnan(a)]) #~ pour l'inverse
a = np.array([1,2+6j, 5, 3.5+5j])
print(a[np.iscomplex(a)]) #nombres complexes

