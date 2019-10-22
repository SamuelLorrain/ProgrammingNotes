#!/bin/sh

add_a_user(){
    USER=$1
    PASSWORD=$2
    shift; shift;
    COMMENTS=$@
    echo "Adding user $USER"
    echo useradd -c "$COMMENTS" $USER
    echo passwd $USER $PASSWORD
    echo added user $USER ($COMMENT) with pass $PASSWORD
}

show_test(){
    echo test
}

show_test #lancer la commande
echo "attention, il n'y a pas de scope en SH"
echo '$PASSWORD : ' $PASSWORD

