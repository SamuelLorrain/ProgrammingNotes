echo 'variables spéciales:'
echo '$# :' "$# parametres passés au script"
echo '$0 :' "$0 est le nom du script"
echo '$1 :' "$1 premier paramètre passé"
echo '$2 :' "$2 premier paramètre passé"
echo "fonctionne de \$1 à \$9"
echo '$@ :' "$@ tous les paramètres passés"
echo '$? :' "$? code de sortie de la dernière commande"
echo '$$ :' "$$ pid du shell"
echo '$! :' "$$ pid du dernier background process"
echo '$_ :' "$_ dernier argument de la dernière commande"
echo '$RANDOM :' "$RANDOM toujours évalué différement"

echo 'variables d'environnement
echo '$IFS : ' "${IFS} est une liste de charactères considérés"
"comme des caractères de fin de mot (Internal field separator). On peut le changer"

#boucle sur les paramètres d'entrée avec shift
while [ "$#" -gt "0" ]; do
    echo "\$1 is $1"
    shift
done

#utilisation des {}
foo="sun"
echo '$foo :' "$fooshine"
echo '${foo} :' "${foo}shine"

echo '${foo:-'moon'} :' "${foo:-'moon'} affiche la valeur de foo, moon si la variable n'existe pas"
/bin/bash: q : commande introuvable
echo '$(whoami)' '$(whoami) == `whoami`'

#arithmétique
a="5"
let "a += 1"
echo $a #6
