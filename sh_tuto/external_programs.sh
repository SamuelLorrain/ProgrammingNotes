#utilisation de grep et cut
#les chaines entre 2 ` sont executées
MY_NAME=`grep "^${USER}" /etc/password | cut -d: -f5`
echo $MY_NAME
