
a > b  #met la sortie de la commande a dans le fichier b
       #(supprime le fichier b sans confirmation avant de
       #remplacer son contenu par celui de la commande a!)
a >> b #met la sortie de la commande a à la fin du fichier b

a > /dev/null #met la sortie dans /dev/null (permet d'éviter
              #qu'une commande écrive quelque chose)

a > b 2> c    #redige stdout vers le fichier b, et
              #stderr vers le fichier c
a 2>> c       #redirige stderr à la fin du fichier c

a > b 2>&1    #redirige stderr et stdout vers le fichier b
a >> b 2>&1   #redirige stderr et stdout à la fin du fichier b

a < fichier   #lire depuis un fichier

a << FIN
FIN
             #lit l'entrée standard jusqu'a rencontrer les charactères
             #"FIN" (entrée std --> clavier)
             #on peut remplacer FIN par n'importe quelle chaine sans
             #espace

