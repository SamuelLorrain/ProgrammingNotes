# Introduction aux attaques web

## Calcul de risque

- Triangle CISSP :
- Confidentialité
- Intégrité
- Disponibilité
- Risk = Asset Value * Threat * Vulnerability * Impact

## Scanning

- BurpSuite
- SqlMap
- Analyse à main nue -> CSRF
- Scripting


- nikto -host [cible] -port [port] -ssl (protocole) : scan d'une cible.
- Plus une machine est vulnerable, plus on peut trouver des informations dessus
- L'intéret est le nom de dossier, les versions des logiciels etc.

- sslscan [cible] : check la sécurité ssl d'un hote (hearthbleed etc.)
- sslyze [cible] --regular : scan normal avec sslyze, récup des certificats etc.
- sslyze [cible] --tlsv1_2 : information sur des versions de ssl en particulier etc.
 
 - owasp zap (proxy): spider ajax attack (énumération ajax)
 - owasp zap (proxy): balayage actif avancé 
 - owasp zap (proxy): fuzzing (file fuzzer) jbrofuzz etc.
(bref, faire un truc complet sur owasp zap)

- arachni : scan -> new

- sqlmap : test injection sql (GET & POST)
