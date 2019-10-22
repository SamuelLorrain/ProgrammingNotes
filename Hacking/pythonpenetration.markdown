# Intro

##HTTP proxies (man-in-the-middle proxies)
- Protswigger blurp
- Zed Attack Proxy Project (ZAPP)
- mitmproxy

##Crawlers
- scrapy
- httrack
- wget

##vulnerability scanners
- w3af
- acutenix
- arachni-scanner

##web brute forcers
- dirb.sourceforge.net
- fuzzdb
- wfuzz

##specific tasks tools
- Encodes/Decoders
- Per type vulnerability
- Post Exploitation
- Others...

##

# Http protocole
- port 80
- <types de requete> <adresse> <version > (version HTTP/1.0 ou HTTPS/1.0)

## HTTP 1.0
### Types de requètes
    - GET : standard methode pour choper le contenu d'une adresse
    - POST : methode utilisée pour envoyer des données à un serveur
    - HEAD : retourne le header de l'adresse sans son contenu
## HTTP 1.1
### Types de requètes
    - OPTIONS : ajoute des options à la connection
    - PUT : requete une ressource
    - DELETE : supprimer le contenu de la ressource
    - TRACE : echo une requete poru savoir les échanges effectués entre les machines
    - PATCH : modifie une ressource 
    - CONNECT : établie un tunnel vers le serveur avec HTTPS

## http headers
- donne des informations sur la transaction entre
un serveur et un client.

### Information coté client
- User agent
- Accept language
- Content type
- Accept encoding
- Host
- Referer (lien vers la page)
- Cookie

### Information coté serveur
- cache control
- content type
- location
- set cookie
- www-authenticate
- custom headers

# library request python


