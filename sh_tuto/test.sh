#!/usr/bin
#ATTENTIONS AUX ESPACES SUR LES TESTS
#man test pour d'autres types de tests
if [ $foo = "bar" ]
then
    echo "if"
elif [ $foo = "baz" ];then
    echo "elif"
else
    echo "else"
fi

if [ $foo = "toast" ]; then
    echo "then is on the same line. Need ;"
fi

#number comparaisons
if [ "$X" -lt "0" ];then
    echo "X < 0"
elif [ "$X" -gt "0" ];then
    echo "X > 0"
elif [ "$X" -eq "0" ];then
    echo "X == 0"
elif [ "$X" -ge "10" ];then
    echo "X >= 10"
elif [ "$X" -le "10" ];then
    echo "X <= 10"
fi

#strings comparaisons
if [ "$Y" = "toast" ];then
    echo "Y == 'toast'"
elif [ "$Y" != "toast" ];then
    echo "Y != 'toast'"
fi

#others comparaisons
if [ -n "$Z" ];then
    echo "Z est un string de longueur > 0"
elif [ -f "$Z" ];then
    echo "Z est le path d'un fichier existant"
elif [ -x "$Z" ];then
    echo "Z est le path d'un executable"
elif [ "$Z" -nt "/etc/password" ]; then
    echo "Z est un fichier plus récent que /etc/password"
elif [ "$Z" -ot "/etc/password" ]; then
    echo "Z est un fichier plus ancien que /etc/password"
elif [ "$Z" -d ]; then
    echo "Z un path vers un directory"
elif [ "$Z" -r ]; then
    echo "Z un path vers un fichier readable"
elif [ "$Z" -w ]; then
    echo "Z un path vers un fichier writable"
fi

#shorcut if
[ $X -ne 0 ] && echo "X != 0" || echo "X == 0"

#while test
while [ -n "$X"]; do
    echo "Enter some text (RETURN to quit)"
    read X
    if [ ! -n "$X" ]; then #if the string is non-zero
    echo "You said: $X"
    fi
done

