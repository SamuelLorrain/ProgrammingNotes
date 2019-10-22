from numpy import np
#manipulations methods
a.reshape(3,4) #nouvelle shape
a.flat() #flatten array
a.ravel() #flatten contiguous array

a.transpose() #permute les dimensions de l'array
a.rollaxis() 
a.swapaxes

a.broadcast()
a.broadcast_to()
a.expand_dims()
a.squeeze()

a.concatenate()
a.stack()
a.hstack()
a.vstack()

a.split()
a.hsplit()
a.vsplit()

a.resize()
a.append()
a.insert()
a.delete()
a.unique()

a.bitwise_and()
a.bitwize_or()
a.invert() #bitwise_not
a.left_shift()
a.right_shift()

#strings methods
#il existe des méthodes pour les
#types numpy.string_ et numpy.unicodes
#on peut voir ça sur le site.
#Elles sont similaires aux
#methodes python de base

#------------------------
#fonctions mathématiques:
#------------------------
#trigo
a = np.array([0,30,45,60,90])
print(np.sin(a*np.pi/180))
print(np.cos(a*np.pi/180))
print(np.tan(a*np.pi/180))
print(np.arcsin(a*np.pi/180))
print(np.arcos(a*np.pi/180))
print(np.arctan(a*np.pi/180))
inv = pn.arcsin(np.sin(a*np.pi/180))
print(np.degrees(inv)) #par défaut les valeurs sont en radian

#rounding
print(np.around(a))
print(np.around(a, decimals= 1))
print(np.around(a, decimals= -1))

print(np.floor(a))
print(np.ceil(a))

#arithmétiques
np.add(a,b)
np.substract(a,b)
np.multiply(a,b)
np.divide(a,b)
np.reciprocal(a)
np.power(a,2)
np.power(a,b)
np.mod(a,b)

#statistiques
np.amin(a,1) #minimum
np.amax(a,axis=0) #maximum

np.ptp(a) #range de la fonction
np.ptp(a,axis=1) #range de la fonction, utilisant un axe de 1

np.percentile(a,q,axis)
np.median(a, axis)
np.mean(a, axis)
np.average(a)
np.std(a) #std déviation
np.var(a) #variance

#Tri
np.sort(a, axis, kind, order)
np.argsort()
np.lexsort()
np.argmax()
np.argmin()
np.where()
np.extract()

