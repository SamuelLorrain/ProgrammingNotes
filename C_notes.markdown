# les livres pour apprendre le C

- K&R : The C programming language (!La partie sur les syscall importante)
- build your own Lisp  http://www.buildyourownlisp.com/contents
- c-faq.com
- Hartel & Muller: Functional C
- Jens Gustedt : Modern C
- Linden : Expert C programming Deep C secrets
- norme ?

# Ce qu'on apprend (K&R)
- %.xf %5f %d %5d etc.
- %o : octal, %x : hexadecimal, %c : character, %s : string, %% : %
- getchar() / putchar(char)
- EOF ---> End of File (while(c!= EOF) etc.)
- \<limits.h\> et \<float.h\> contiennent les tailles des types standards
- \ooo ---> écrire un caractère sous forme octale
- \xHH ---> écrire un caractère sous forme hexadecimale
- \a -----> bell
- \f -----> formfeed
- \v -----> vertical tab
- \0 -----> fin de string !
- \<string.h\> ---> Fonctions sur les strings !
- enum name {a,b};
- enum name {a=x, b=y};
- float a = 1.0e-5 ----> écriture scientifique
- if(!true) / if(true) ---> idiome à garder sous le coude
- atoi(char s[]) ---> Convertit string en integer / inversement ?
- lower(int c) / tolower(int c) -----> Lower a character
- \<ctypes.h\> -----> conversion et tests indépendant du charset 
- isdigit(c) -------> return true si le caractère est un digit
- \<math.h\> -------> Fonctions mathématiques
- (type)var --------> conversion explicite
- génération aléatoire : rand() et srand() dans <\math.h\>
- a = f() + g() // la norme ne prévoit pas quel fonction est effectuée en premier
- #undef
- ## concaténation de symboles dans une macro ?
- #define macro(A,B) //macro avec arguments A B
- #if
- #elif
- #else
- #endif
- #ifdef
- #ifndef
- void * ---> pointeur générique
- * et ++ fonctionnent de droite à gauche
ainsi, ++*p fonctionne mais il faut faire (*p)++ pas *p++

- int a[10];
- int *pa;
- pa = &a[0]; ---> équivalent à pa = a;
- a[i] == *(a+1) ---> True
- *(pa+1) == a[1]; ---> True
- a s'appelle un "array name"
- char s[] == char s* ---> True (string)
- On peut passer une partie d'un tableau à une fonction en faisant :
- f(&a[2]) ou f(a+2) !
- char mes[] = "aaaaaa"; //alloue la bonne taille de tableau
- char *mes = "aaaaaaa"; //alloue un pointeur sur un tableau de la bonne taille
int a[10][10] = {
   {1,1,1,1,1,1,1,1,1,1},
   {1,1,1,1,1,1,1,1,1,1}
}

- sizeof(objet) //fonction pour connaitre le nom d'un type/struct
- //renvoi un size_t, type défini dans <stddef.h>
- char *name[] = {"a","b","c"} ---> Crée un tableau de pointeurs
- référencant des String
- argv[argc] est un pointeur NULL
- int (*comp)(void *, void *) ---> pointeur sur une fonction
- int *comp(void *, void *) ---> fonction qui renvoi un pointeur
- exemple:
- int fonction(int){}
- int (*pointeur_sur_fonction)(int);
- pointeur_sur_fonction = fonction;
- (*pointeur_sur_fonction)(a) //appel d'un pointeur sur une fonction
- //On peut donc faire un callback en envoyant un
- //pointeur sur une fonction en paramètre
- struct {...} x,y,z; //déclare x,y,z comme des structures décrires avant
- struct a {...} x,z; //déclare 2 struct de type a
- struct a {...}; //décrit la struct a
- struct a xz; //déclare une var xz de type struct a
- struct a {} *pa; //déclare un pointeur pa sur struct a 
- a.test //attibut d'une struct
- on peut utiliser un pointeur sur une structure, plutôt qu'une structure.
- int st, *pst;
- *pst = &st;
- (*pst).x ou (*pst).y //équivalent à :
- pst->x ou pst->y
 
- typedef nom synonyme;
- ex:
- typedef int Integer;
- typedef struct{...} a;
 
- union a {...} u;  //une union permet de stocker différents types de données
- //dans un seul emplacement mémoire.
- //On ne peut utiliser qu'un des types décrit à la fois. Les
- //différentes variables partagent la même mémoire
 
- struct a{
-     unsigned int a : 1;
-     unsigned int b : 1;
-     unsigned int c : 1;
-     }
- //bitfield, crée un système de flag en gros
 
- sprintf(string, "", [var])
 
- //arguments variables
- // besoin d'inclure <stdarg.h>
- f(a, ...) //arguments variables (...)
- va_list b; //déclare une variable de type va_list qui contient les
- //arguments variables
- va_start(a,b); //initialise les arguments, besoin de donner le dernier argument nommé
- va_end(b)); //routine de fin arguments variables
- va_arg(b, type) //l'accès se fait séquentiellement avec l'appel de va_arg(
- nom de la variable va_list, type de la variable voulue)
 
- //scanf
- le premier argument peut contenir des espaces, qui seront ignorées,
- aussi, on peut getter plusieurs variables.
 
- //Fichiers
- FILE *fp; //créer un pointeur de type fichier
- fp = fopen("nom", mode_douverture); //ouvre un fichier nom
- mode_douverture : w,a,r (b peut être ajouté à la fin, mode binaire)
 
- getc(FILE *fp); //retourne le caractère suivant du fichier
- putc(int c,FILE *fp); //met le caractère c dans le fichier fp et retourne ce
- //caractère
 
- stdin
- stdout
- stderr
 
- fprintf(FILE *, "", ...);
- fscanf(FILE *, "", ...);
- ferror(FILE *); //renvoi != 0 si il y a une erreur
- feof(FILE *);//renvoi != 0 si c'est la fin du fichier
- fgets(str, size, FILE *); //lit size-1 char dans FILE et le met dans str
- fputs(line,FILE *); //put line in FILE
- fclose(FILE *); //ferme un fichier
 
- exit(code) //exit et renvoi un code (EXIT_SUCCESS ou EXIT_FAILURE) ?
 
- //fonctions sur les strings à connaitre :
- strcat(s,t) //concat t à la fin de s
- strncat(s,t,n) //concat n char de t à la fin de s
- strcmp(s,t) // renvoi -1 si s < t, 1 si s > t, 0 si s == t
- strncmp(s,t,n) //comme strcmp mais seulement sur les n premirs characters
- strcpy(s,t) //copy t dans s
- strncpy(s,t,n) //copy n char de t dans s
- strlen(s) //renvoi la longeur de s
- strchr(s,c) //retourne pointeur du premier c de s, ou NULL sinon
- strrchr(s,c) //retourne pointeur du dernier c de s, ou NULL sinon
 
- //executer fonction system
- system("commande") //effectue une fonction systeme (non interoperable)
 
- int ungetc(int c, FILE *fp) //??????
 
- //
- malloc(size_t n);
- calloc(size_t n, size_t size); //pointeur d'un tableau de n * size
- free(p) //free un pointeur créé avec malloc

#Modern C
- type bool définie dans <stdbool.h> (true/false)
- size_t définie dans <stddef.h> %zu %zx
- size_t va de 0 à SIZE_MAX (unsigned integer)
- SIZE_MAX dépend de la plateforme, sur un x64, vaut (2^64)-1 etc.
- signed / unsigned sont des types, ceux à utiliser ?
- ptrdiff_t ---> sorte de double
- double complex ---> type pour les calculs avec des nombres complexes
- time_t et clock_t ont un rapport avec le temps et dépendent de l'implémentation
- Strings litterales consécutifs sont concaténés!
- Les nombres littéraux ne sont jamais négatifs. L'opérateur '-' y est juste appliqué

