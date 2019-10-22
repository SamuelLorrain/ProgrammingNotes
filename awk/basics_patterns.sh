
awk 'pattern {action}' #syntaxe de base de awk

#exemples basiques de patterns
awk 'BEGIN {print "START"}' #affiche "START" avant la première ligne
awk 'END {print "STOP"}' #affiche "STOP" après la dernière ligne
awk '{print $5}' #affiche la 5eme colonne de texte de l'entrée.

awk "BEGIN {x=5}
    {print x, $x}" #affiche 5, puis la valeur du 5eme champ (création de variable)


