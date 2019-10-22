#Test de pénétration

- Est différent de l'audit de sécurité qui ne fait que tester
les failles, sans les exploiter (nessus etc.)
- Internet augmente la surface d'attaque

## Méthodologies de test de pénétration

- Plusieurs méthodologies et types de test

### Etablir une portée
- Il faut définir la portée du test de pénétration
Ce qui s'oppose de connaitre l'infrastructure.

#### Guide pour établir une portée

- Définition du système cible (paperasse) -> ramener sur papier les connaissances sur une cible
- Time Frame (durée du test)
- Comment la cible sera évaluée -> les points explorés dans le test
- Les outils utilisés pour chaque point
- La partie prenante
- L'état de départ
- Identification des SPOF (Single Point Of Failures) -> points qui,
si ils tombent, tout le réseau tombe. Souvent les plus souvent
attaqués par des hackers
- Le Flag
- Le livrable
- Correction et amélioration (Optionnel)

### Types d'états de départ

- Black Box : aucune connaissance sur l'entreprise ->
meilleure pour les tests de vulnérabilité "comme un hacker"
- Grey Box :  Accès à quelques informations -> si l'entreprise
possède beaucoup de documentation accessible en externe
- White Box : Accès à toutes les données de l'entreprise -> si l'entreprise
a beaucoup de soucis internes

## Méthodologies : 
### OSSTMM

- ISECOM
- Test et Analyse
- Day-to-day
- Portée -> Channel -> Index -> Vecteur
- Blind, Double Blind, Gray Box, Double Gray Box (white box), Tandem, reversal

### ISSAF
- Open Source
- Test et Analyse
- Framework
- Niveau technique et analyse

### OWASP
- Secure Coding et meilleurs pratiques
- Evaluation de risques
- Plusieurs guideline (developpeur, test etc. )

### Wasc-tc
- Identification des riques de sécurté
- Procédures de test
- Developpement liveCycle
- Similaire à OWASP
- Enumeration view, Developpement view, Taxonomy cross-reference view

### Penetration Testing Execution Standard

- Efficace sur n'importe quel environnement
1. Pré-engagement
2. Intelligence gathering
3. Threat Modeling
4. Vulnerability Analysis
5. Exploitation
6. Post-exploitation
7. Report

### Kali linux méthodologie 

1. Target Scoping
2. Information gathering
3. Enumerating Target 
4. Vulnerability Mapping
5. Social engineering
6. Target exploitation
7. Privilege Escalation
8. Maintaining Access
9. Documentation & Reporting
