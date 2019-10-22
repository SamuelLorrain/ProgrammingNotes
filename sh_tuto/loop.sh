#!/usr/sh

#for
for i in 1 2 3 4 5
do
    echo "Test"
done

for i in hello 1 * 2 goodbye
do
    echo "Test : $i"
done

#while
INPUT_STRING=hello
while [ "$INPUT_STRING" != 'bye' ]
do
    echo "loop, read INPUT_STRING -> $1"
    read INPUT_STRING
done

while :
do
    echo "Infinite loop"
done

#lit dans un fichier
while read f
do
    case $f in
        hello)  echo English;;
        howdy)  echo American;;
        gday)   echo Australien;;
        bonjour) echo Français;;
    esac
done < myfile

