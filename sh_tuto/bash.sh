#!/bin/bash

##EQUIVALENT!
echo 'test' |& grep '^t'
#equivalent de :
echo 'test' 2>&1 | grep '^t'
#(permet de piper stderr)

a=5
((a+=a))
#equivalent de:
let "a+=a"



[[ ]]
#equivalent de:
[]
#mais performe des expansions arithmétiques, tilde, variable,
#substituion de commande, de process et de quote removal
#Aussi, permet d'utiliser pas mal de trucs

coproc date #permet de faire une commande de façon asynchrone
