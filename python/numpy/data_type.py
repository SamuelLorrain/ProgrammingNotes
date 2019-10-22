import numpy as np

#
# beaucoup plus de type que python:
# bool_         #bool stockés sur 1 bit
# int_          #int de type C long
# intc          #int de type C
# intp          #int de type ssize_t
# int8          #int de 8 bits
# int16         #int de 16 bits
# int32         #int de 32 bits
# int64         #int de 64 bits
# uint8         #uint de 8 bits
# uint16        #uint de 16 bits
# uint32        #uint de 32 bits
# uint64        #uint de 64 bits
# float_        #equivalent float64
# float16       #half precision : 5 bits d'exposant, 10 bits mantisse
# float32       #single precision : 8 bits d'exposant, 23 bits mantisse
# float64       #double precision : 11 bits d'exposant, 52 bits mantisse
# complex_      #equivalent complex128
# complex64     #32 bits réels, 32 bits imaginaires
# complex128    #64 bits réels, 64 bits imaginaires
#

#Les types sont accessibles comme-ci:
np.int32
np.complex128

#objet dtype:
#numpy.dtype(object, align, copy)
dt = np.dtype(np.int32)
print(dt) #int32

dt = np.dtype('i4') #notation équivalente : (i1, i2, i4 ...)
dt = np.dtype('>i4') #endian notation

#création d'un type
dt = np.dtype([('age', np.int8)])
a = np.array([(10,),(20,),(30,)], dtype=dt)
print(a) #[(10,),(20,),(30,)]
print(a['age']) #[10 20 30]

#U => unicode string
student = np.dtype([('name', 'U20'), ('age', 'i1'), ('marks', 'f4')])
b = np.array([('abc', 21, 50),('xyz', 18,75)], dtype=student)
print(b) #[('abc', 21, 50.) ('xyz', 18, 75.)]




