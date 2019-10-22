#Utilisation des environnements virtuels.
"""

python3 -m venv PATH_TO_PROJECT
OU
virtualenv PATH_TO_PROJECT
#pour créer un environnement virtuel

source PATH_TO_PROJECT/bin/activate
#pour activer l'environnement virtuel

deactivate
#pour desactiver l'environnement virtuel

"""

#Quelques options
"""
--no-site-package #python vierge (uniquement lib std)
--system-site-package #python avec les package installé sur l'envrionnement
                      #global
-p PATH_TO_PYTHON #choisir la version de python utilisé dans le venv
"""

#Activer un script du venv sans rentrer dans le venv
"""
PATH_TO_PROJECT/bin/python script.py
"""

#virtualenvwrapper
"""
#Installer virtualenvwrapper
pip install --user virtualenvwrapper

#Ajouter dans ~/.bashrc
export WORKON_HOME=~/.virtualenvs
mkdir -p $WORKON_HOME
source ~/.local/bin/virtualenvwrapper.sh

#commandes de virtualenvwrapper
mkvirtualenv nom_env #créer un env dans le dossier ~/.virtualenvs
workon nom_env #active automatiquement un env
rmvirtualenv nom_env #supprimer l'env du même nom
"""
