# Attaques Server-side

# Recherches de vulnerabilité

## nmap

nmap -sV <ip> ----> récupérer la version des différents services
à partir de la version, on peut chercher un exploit sur www.exploit-db.com
ou dans metasploit

## nessus

## owasp DirBuster (web application brute forcing)

- Brute force des dossiers et fichiers (enumeration)

## skipfish

skipfish -o <sortie> -W <wordlist> <site.com>

## WebSlayer

fuzzing pour découvrir des repertoires

# BruteForcing

- Méthode de cryptanalyse pour trouver un mot de passe, il s'agit de tester une à une
toutes les clés
- Méthode la plus simple à mettre en oeuvre
- Lente, dépend de la complexité et la longueur du mot de passe
- Est souvent combinée avec une attaque par dictionnaire et par rainbow-table

## Hydra

- Outil de bruteforce sur la plupart protocoles (cisco, ftp, ssh smb mysql etc.)

hydra ---> affiche l'aide
hydra -l <login>
hydra -p <motdepasse>
hydra -L <fichierlogin>
hydra -P <fichiermotdepasse>
hydra -x MIN:MAX:CHARSET (brutforce pur)
hydra service

## Attaque par authentification

- Burpsuite, facilite la tache pour construire une commande avec hydra
- Utiliser la requete html de l'authentification

hydra http-get-form ---> commande hydra pour attaque web

## Cracking de mot de passe OS
 
- John The Ripper

john --> aide de JTR

unshadow PASSWORD-FILE SHADOW-FILE > sortie ----> rassemble le fichier passwd et shadow dans sortie

john --list=format ---> renvoi les hash disponibles
john <fichiermotsdepasse> ---> detecte le hash automatiquement et bruteforce le fichier

john <fichiermotdepasse> --format=<type> -----> crack en spécifiant le type de hash
