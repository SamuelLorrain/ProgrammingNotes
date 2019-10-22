import numpy as np

#empty, crée un array non initialisé
#numpy.empty(shape, dtype, order='C')
a = np.empty([3,2], dtype=int)

#zeros, crée un array initialisé à 0
a = np.zeros(5, dtype=float)
#ones, crée un array initialisé à 0
a = np.ones(5, dtype=[('i1','i4'),('i2','i2')])

#asarray, convertit un array en nparray
#numpy.asarray(shape, dtype, order='C')
x = [1,2,3]
a = np.asarray(x)

#frombuffer, interprète un buffer comme un array à 1 dimension
x = "Hello world"
a = np.frombuffer(s, dtype='S1') #S, type bit_character

#fromiter, interprète un itérateur comme un array à 1 dimension
x= iter(range(5))
a = np.fromiter(x, dtype=float)

#arange(start,stop,step, dtype)
a  = np.arange(5, dtype=float) #[0. 1. 2. 3. 4. ]
a  = np.arange(10, 20, 2, dtype=float) #[10 12 14 16 18]

#linspace, similaire à arange, mais avec un espacement linéaire
#linspace(start, stop, num, endpoint, retstep, dtype)
a = np.linspace(10,20,5) #[10. 12.5 15. 17.5 20.]
a = np.linspace(10,20, 5, endpoint = False) #[10. 12. 14. 16. 18.]
#retstep renvoi le pas entre les éléments
a = np.linspace(1,2,5, retstep=True) #(array([1. , 1.25, 1.5, 1.75, 2 ]), 0.25)

#logspace, similaire à log, avec un espacement logarithmique
#logspace(start, stop, num, endpoint, base, dtype)
#base -> base du logarithme
a = np.logspace(1, 10, 10, base = 2)
    #[ 2.     4.     8.    16.    32.    64.   128.   256.    512.   1024.]







