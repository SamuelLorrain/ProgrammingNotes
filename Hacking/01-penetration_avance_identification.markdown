# Identification
## Objectif de l'identification

Découverte de:
    - Background de la cible
    - Accociés de la cible
    - Investissement en sécurité de la cible
    - Business & politique de sécurité de la cible
    - Personne en contact avec la cible (social engeenering)
    - Définir la(les) cible(s)
    - Réseaux de la cible
    - Défenses de la cible
    - Technologies de la cible

Soit rassembler le plus d'infos possibles
pour faciliter l'exploitation.
Il est important d'essayer de faire grandir la surface d'attaque.

Plus il y a d'intéraction avec la cible, plus il y a de chance de se faire detecter
Mais plus les données sont exploitables pour une attaque

Le plus grand risque est de se faire repérer
Il existe pas mal de techniques pour se camoufler : modifier stackIP, Nmap, ProxyChains & réseau
  TOR etc.

# Recherches initiales

- Doivent se baser sur les personnes et le business lié à la cible
- Analyser tous les aspects pour augmenter la surface d'attaque

## Outils

- Shodan
- Regional Internet Registries (RIR) -> registres internet publiques
- Electronic Data Gathering, Analysis, and Retrieval (EDGAR) -> infos publiques d'entreprises
- Google Hacking Database -> (google dork etc.)

## Commencer par le site web de l'entreprise
-> site.com/robot.txt
## BDD publiques
-> www.exploit-db.com/google-hacking-database  :: beaucoup d'informations ici, (dossiers sensibles
etc.)
-> www.arin.net :: informations sur des entreprises
-> www.sec.gov/edgar/ :: informations sur des entreprises
-> web.archive.org :: wayback machine
-> www.shodan.io :: recherche IoT
---> peut aider au social engeenering

## Scanning

### Nmap

- nmap [ip(/cidr)] > montre les ports ouverts "évidents"
- nmap [ip(/cidr)] -p [port,...] > spécifier les ports à scanner de x,y
- nmap [ip(/cidr)] -v > verbose verbose
- nmap [ip(/cidr)] -vv > verbose verbose (resolution dns des ip)
- nmap [ip(/cidr)] -F > Fast scan
- nmap [ip(/cidr)] -exclude [ip(/cidr)] > exclure des ip
- nmap [ip(/cidr)] -sL > envoi des pings, permet de savoir si une adresse est en ligne
- nmap [ip(/cidr)] -sP > savoir si l'adresse est up dans le réseau + adresse MAC (via arp)
- nmap [ip(/cidr)] -PE > ping avant de scanner un poste
- nmap [ip(/cidr)] -PP > envoi un icmp pour récupérer le time stamp
- nmap [ip(/cidr)] -PM > envoi un icmp pour récupérer le masque réseau
- nmap [ip(/cidr)] -sA > 
- nmap [ip(/cidr)] -sW > envoi un ack
- nmap [ip(/cidr)] -sN > tous les ack à 0
- nmap [ip(/cidr)] --scanflags SYNPSHURG -p [port,...] > craft paquet
- nmap [ip(/cidr)] --traceroute > traceroute
- nmap [ip(/cidr)] -sV -p [port] > renvoi bannière de l'application du port scanné
- nmap [ip(/cidr)] -sV -p [port] --version-trace > informations sur l'appli du port en fonction de
  sa bannière
- nmap [ip(/cidr)] -O -vv > Informations sur l'OS de l'adresse grace à une empreinte
- nmap [ip(/cidr)] -g [port] > scan si un port est dispo en source et en destination
- nmap [ip(/cidr)] --data-length x >  ajoute x octets dans les paquets du scan
- nmap [ip(/cidr)] --ttl x >  règle la ttl du paquet de scan
- nmap [ip(/cidr)] -r -n -T2 --packet-trace -p [port,...] > tous les détails sur les paquets
  échangés
- nmap --iflist > liste des interface avec les routes
- nmap [ip(/cidr)] -sS -n -d1 > ?

### msfconsole

search auxiliary > liste des scanner metasploit
use [scanner] > utiliser un scanner
use auxiliary/scanner/ftp/anonymous > scanner ftp
show options > voir les options du scanner
