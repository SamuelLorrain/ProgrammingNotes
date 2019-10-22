# deni de service

- empêche l'accès à une ressource (serveur, site web, application)
- difficile à stopper
- plusieurs types de Ddos et plusieurs menaces
- a partir du moment où une ressource est disponible
sur internet, elle est vulnerable au ddos
- pour la prévenir, il faut rétrecir la surface d'attaque

# Catégories de DOS/DDOS
- Abus de session
- Attaques basées sur le volume (icmp proof etc.)
- Attaques basées sur les protocoles  (smurf)
- Attaques basées sur la couche applicative (buffer overflow)

# Outils du ddos 

- low orbit ion cannon
- thc ssl dos
- scapy
- slowloris
- www.upordown.org


## THC-SSL-DOS

commande dans kali linux.

thc-ssl-dos [-options] <ip> <port>
thc-ssl-dos <ip> --accept (il faut utiliser --accept pour confirmer le dos)

--> Deni de service par rapport à une faille pendant le handshake ssl

## scapy

send(IP(dst="10.0.0.1", ttl="0")/TCP(),iface="eth0",count=2000)
---> ttl=0 confus le serveur, count= utilise plutôt une boucle infinie,
2000 n'est pas assez.

pas mal de façon de faire avec Scapy

#slowloris

./slowloris -dns <adresse.com>

##Low orbit ion cannon (LOIC)

utilisé par les anonymous

##Siege

stress-test pour des appli-web

siege <site.com> 
renvoi un rapport, plusieurs options disponibles

# Botnet

pc-zombie pour faire des ddos
un pc-zombie est généralement infesté par un cheval de troie ou vers
utile pour cacher son identité et gagner en puissance d'attaque

## beef-xss

/usr/share/beef-xss/modules/persistence/confirm_close_tab/config.yaml ---> reglage d'un module persistance
/usr/share/beef-xss/modules/network/DOSer/config.yaml ---> réglage module attaque




