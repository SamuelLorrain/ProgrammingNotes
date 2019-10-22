# opérateurs

+ - * /

: cons
!! index
++ concat

< == > <= >= /=

odd
even

_ variable qui va être jetée, n'a pas besoin d'être gardée

# opérateurs sur les listes

head premier élément d'une liste
tail liste sans le premier élément
last dernier élément
init une liste sans le dernier élément

length longueur d'une liste
null teste si une liste est vide
reverse renverse une liste
take x prend x premiers éléments d'une liste
drop x enlèves les x premiers éléments d'une liste
minimum prend le min d'une liste
maximum prend le max d'une liste
sum somme d'une liste
product produit d'une liste
elem x test si x est dans une liste

# ranges

[1..20] créé une liste entre 1 et 20
[1,4..40] créé une liste entre 1 et 40 avec un pas de 4
[1..] liste infinie
[1,3..] liste infinie avec un pas
[100,98..0] liste finie avec pas décroissante
[100,98..] liste infinie avec pas décroissante

cycle prend une liste et la cycle à l'inconnu
repeat x repète x à l'infini

-> take 10 (repeat 5)
-> take 10 (cycle [1,2,3])
-> equivalent à replicate 3 10 qui renvoi 10,10,10

# liste en intention

[x**2 | x <- [1..10]]
[x**2 | x<- [1..10], x**2 >= 12]
[x | x <- [50..100], x `mod` 7 == 3]
[x | x <- [10..20], x /= 13, x /= 15, x /= 19]
[x * y | x <- [1..10], y <- [10..20], x > 5]

length' = sum [1 | _ <- xs]

(on peut chainer les listes en intention)

#tuples

(1,2,"a")
fst (1,2) renvoi 1
snd (1,2) renvoi 2

# zip
zip est une fonction qui produit des couples (tuples 2)
à partir de 2 listes

zip [1..] ["apple","orange","cherry","mango"]
renvoi : [(1,"apple"),(2,"orange"),(3,"cherry"),(4,"mango")]

# type
:t x renvoi le type de la variable x

pour donner un type à une fonction
removeNonUpperCase :: [Char] -> [Char]
removeNonUpperCase st = [ c | c <- st, c `elem` ['A'..'Z']]

une fonction qui possède plusieurs arguments
addThree :: Int -> Int -> Int -> Int
addThree a b c = a+b+c

## survol des types

Int entier fini
Integer entier infini
Integral
Float flottant
Double flottant double precision
Floating contient Float et Double
Num inclut tous les nombres
Bool boolean
Char charactère

## variables de type

:t head a pour type head :: [a] -> a
'a' est ici une variable de type
ça fait du duck typing
:t fst (a,b) -> a

## classes de type

:t (==) renvoi (==) :: (Eq a) => a -> a -> Bool

=> est une contrainte de classe. Cela signifie que
a doit être membre de Eq

ex:
:t (>) renvoi (>) :: (Ord a) => a -> a -> Bool

### Classes
Ord:
compare prend 2 Ord et renvoi un Ordering (GT,LT,EQ)

Show: tous les types 'affichages' sont membres de show.
show prend une valeur et renvoi la même en version String

Read: inverse de show. read prend une valeur en String
et renvoi la valeur ("True" renvoi True)

### Annoation de type
read "5" :: Int renvoi 5
read "5" :: Float renvoi 5.0

maxBound et minBound sont de type Bound et demandent une inférence de type


# Filtrage par motif

Forme syntaxique pour "remplacer if et else"


lucky :: (Integral a) => a -> String
lucky 7 = "LUCKY"
lucky x = "NOP"

factorial :: (Integral a) => a -> a
factorial 0 = 1
factorial n = n * factorial(n - 1)

sayMe :: (Integral a) => a -> a
sayMe 1 = 'One'
sayMe 2 = 'Two'
sayMe 3 = 'Three'
sayMe 4 = 'Four'
sayMe x = 'X'

addVectors :: (Num a) => (a,a) -> (a,a) -> (a,a)
addVectors (x1,y1) (x2,y2) = (x1 + x 2, y1 + y2)

first :: (a,b,c) -> a
first (a,_,_) = a

second :: (a,b,c) -> b
second (_,b,_) = b

third :: (a,b,c) -> c
third (_,_,c) = c

x:xs est un motif très utilisé. x represente une tête de liste, et xs le reste de la liste
x:y:z:xs est possible

[] est le motif d'une liste vide

all@(x:xs) est une motif nommé. "all" peut être utilisé dans le corps de la fonction

initials :: String -> String -> String
initials firstname lastname = [f] ++ ". " ++ [l] ++ "."
    where (f:_) = firstname
    where (l:_) = lastname

# Gardes (guard)

les motifs testent une égalité, les gardes testent une comparaison
bmiTell :: (RealFloat a) => a -> String
bmiTell bmi
    | bmi <= 18.5 = "- 18.5"
    | bmi <= 25.0 = "- 25.0"
    | bmi <= 30.0 = "- 30.0"
    | otherwise = "otherwise"

on peut utiliser plusieurs variables

bmiTell :: (RealFloat a) => a -> a -> String
bmiTell weight height
    | weight / height ^ 2 <= 18.5 = "underweight"
    | weight / height ^ 2 <= 25.0 = "normal"
    | weight / height ^ 2 <= 30.0 = "fat"
    | otherwise = "otherwise"

sur la même ligne
max' :: (Ord a) => a -> a -> a
max' a b | a > b = a | otherwise = b

avec une notation infixe
myCompare :: (Ord a) => a -> a -> Ordering
a `myCompare` b
    | a > b     = GT
    | a == b    = EQ
    | otherwise = LT

on peut utiliser "where"
bmiTell :: (RealFloat a) => a -> a -> String
    | bmi <= skinny = "underweight"
    | bmi <= normal = "normal"
    | bmi <= fat = "fat"
    | otherwise = "otherwise"
    where bmi = weight / height ^ 2
        skinny = 18.5
        normal = 25.0
        fat = 30.0

on peut aussi utiliser des fonctions dans where
calcBmis :: (RealFloat a) => [(a,a)] -> a
calcBmis xs = [bmi w h | (w,h) <- xs]
    where bmi weight height = weight / height ^ 2


# let in

les expressions de let sont visibles dans l'expressions in

cylinder :: (RealFloat a) => a -> a -> a
cylinder r h =
    let sideArea = 2 * pi * r * h
        topArea = pi * r ^ 2
    in sideArea + 2* topArea

# Expression case

head' :: [a] -> a
head' xs = case xs of [] -> error "No head for empty list"
                      (x:_) -> x

equivalent à

head' :: [a] -> a
head' [] = error "No head for empty list"
head' (x:_) = x


_contrairement à un filtrage par motif, une expression case
ne se limite pas à la définition de fonction mais peut
apparaitre partout

# quicksort

quicksort :: (Ord a) => [a] -> a
quicksort [] = []
quicksort (x:xs) =
    let smallerSorted = quicksort [a | a <- xs, a <= x]
        biggerSorted = quicksort [a | a <- xs, a > x]
    in smallerSorted ++ [x] ++ biggerSorted

# fonctions curryfiées

max 4 5  est égal à  (max 4) 5
car les fonctions sont curryfiées

on peut donc faire:
let biggerOrFour = (max 4)
biggerOrFour 10

# fonctions d'ordre (de classe) supérieur

applyTwice :: (a -> a) -> a -> a
applyTwice f x = f (f x)
applyTwice (+3) 10 renvoi 16

(+3) est une fonction infixe, qui attend donc une opérande "à gauche"

isUpperAlphaNum :: Char -> Bool
isUpperAlphaNum = (`elem` ['A'..'Z'])

## définitions de fonctions standard grace aux fonctions d'ordre supérieur

zipWith' :: (a -> b -> c) -> [a] -> [b] -> [c]
zipWith' _ [] _ = []
zipWith' _ _ [] = []
zipWith' f (x:xs) (y:ys) = f x y : zipWith f xs ys

flip' :: (a -> b -> c) -> (a -> b -> c)
flip' f = g
    where g x y = f y x

map :: (a -> b) -> [a] -> [b]
map _ [] = []
map f (x:xs) = f x : map f xs

filter :: (a -> Bool) -> [a] -> [a]
filter _ [] = []
filter p (x:xs)
    | p x = x : filter p xs
    | otherwise = filter p xs

takeWhile p xs retourne tous les éléments de xs tant que p est vrai

# lambda

(\x -> x + 3) fonction lambda qui pour x renvoi x + 3
(\a b -> (a ** 2 + 3) / b) lambda avec plusieurs arguments

# fold

les folds sont des sortes de map qui renvoient une valeur unique à partir
d'une liste et d'une fonction

sum' :: (Num a) => [a] -> a
sum' xs = foldl (\acc x -> acc + x) 0 xs

ou

sum'' :: (Num a) => [a] -> a
sum'' = foldl (+) 0


foldl f acc xs
ou
f est une fonction binaire (qui va prendre pour valeur,
l'accumulateur et un élément d'une liste),
acc est la valeur de départ d'un accumulateur
et xs une liste

le pli à droite foldr est comme le
pli à gauche, sauf que la pliure commence sur la droite
par conséquent le foldr peut se faire sur des listes
infinies contrairement au foldl

foldl1 et foldr1
n'ont pas besoin d'accumulateur
mais considèrent que la valeur de départ de l'acc
est le premier élément de la liste

scanl, scanr, scanl1, scanr1
sont comme fold, mais l'acc est mis dans une liste

# $ et .

($) :: (a -> b) -> a -> b
f $ x = f x

$ a une précédence à droite:
f a b c = (((f a) b) c)
sum (map sqrt [1..130]) peut s'écrire sum $ map sqrt [1..130]

. est la composition de fonction
(.) :: (b -> c) -> (a -> b) -> a -> c
f . g = \x -> f (g x)


# Modules

import MODULENAME

import Data.List
import Data.List (nub,sort) importe seulement les fonctions voulues
import Data.List hiding (nub) import tout sauf la fonction nub
import qualified Data.Map force a écrire le nom complet : Data.Map.filter
import qualifier Data.Map as M force à écrire : M.filter

## Data.List

intersperce x xs  met x entre ts les éléments de xs
intercalate xs ys de même avec une liste
transpose [xs] transpose une liste de liste

etc..

## Création d'un module

dans un fichier Geometry.hs :

(déclarer le nom des fonctions)
module Geometry
( sphereVolume
, sphereArea
, cubeVolume
, cubeArea
, cuboidArea
, cuboidVolume
)where

On peut utiliser des dossiers et sous-dossier pour avoir des modules et sous-modules
ex:
dans un dossier Geometry j'ai un fichier Sphere.hs
j'importe donc le module Sphere comme ceci :
import Geometry.Sphere

(il faut aussi le déclarer de la bonne façon)
module Geometry.Sphere
( sphereVolume
, sphereArea
)
where

# Créer types de données

data Bool = False | True
data Shape = Circle Float Float Float | Rectangle Float Float Float
shape membre de la fonction show :
data Point = Point Float Float deriving (Show)

surface :: Shape -> Float
surface (Circle _ _ r) = pi * r 2
surface (Rectangle x1 y1 x2 y2) = (abs $ x2 - x1) * (abs $ y2 - y1)
surface (Rectangle (Point x1 y1) (Point x2 y2)) = (abs $ x2 - x1) * (abs $ y2 - y1)


# enregistrements

data Person = Person String String Int Float String String deriving (Show)
let guy = Person "Buddy" "Finklestein" 43 184.2 "526-2928" "Chocolate"

pour récupérer des informations sur la personne on peut créer des
fonctions :
firstName :: Person -> String
firstName (Person firstname _ _ _ _ _) = firstname
_f

lastname :: Person -> String
lastname (Person _ lastname _ _ _ _) = lastname

_etc...

Mais on peut déclarer aussi
data Person = Person { firstname:: String
                     , lastname :: String
                     , age :: Int
                     , height :: Float
                     , phoneNumber :: String
                     , flavor :: String } deriving (Show)
tous les getters sont pré-créés

data Car = Car {company :: String, model :: String, year :: Int} deriving (Show)

# Paramètre de type

a est un paramètre de type :

data Maybe a = Nothing | Just a

(c'est une sorte de template en Cpp)

/!\ ne pas ajouter de contrainte de classe à un type de donnée
car on doit les ajouter de toute façon aux fonctions

data Vector a = Vector a a a deriving Show()
vplus :: (Num t) => Vector t -> Vector t -> Vector t
(Vector i j k) `vplus` (Vector l m n) = Vector (i+l) (j+m) (k+n)

# instances dérivées

si on veut comparer 2 personnes
data Person = Person {firstName :: String, lastName :: String, age :: Int} deriving (Eq)

on peut comparer l'égalité entre deux personnes (si c'est la même personne)

on peut dériver de plusieurs classes
data Person = Person {firstName :: String, lastName :: String, age :: Int} deriving (Eq, Show, Read)

data Bool = False | True deriving (Ord)
comme False est déclaré avant True, alors False sera toujours plus petit que True

# synonymes de types

on peut créer des synonymes avec le mot clé type :

type String = [Char]
type AssocList k v = [(k,v)]
type IntMap v = Map Int v  est un type partiellement appliqué
ou
type IntMap = Map Int

# structures de données récursives

Basiquement les structures de données récursives sont des types qui
peut avoir des champs qui sont de même type

[1:2:4:5] == (1:(2:(4:(5:[]))))
data List a = Empty | Cons a (List a) deriving (Show, Read, Eq, Ord)

Cons est un autre nom pour :

## déclaration d'infixité
infixr 5 :-:
data List a = Empty | a :-: (List a) deriving (Show, Read, Eq, Ord)

infixr défini la priorité d'un opérateur en notation infixe

3 :-: 4 :-: 5 :-: Empty renvoi (:-:) 3 ((:-:) 4 ((:-:) Empty))

## implémentation d'un arbre binaire

data Tree a = EmptyTree | Node a (Tree a) (Tree a) deriving (Show, Read, Eq)

singleton :: a -> Tree a
singleton x = Node x EmptyTree EmptyTree

treeInsert :: (Ord a) => a -> Tree a -> Tree a
treeInsert x EmptyTree = singleton x
treeInsert x (Node a left right)
    | x == a = Node x left right
    | x < a  = Node a (treeInsert x left) right
    | x > a  = Node a left (treeInsert x right)

treeElem :: (Ord a) => a -> Tree a -> Bool
treeElem x EmptyTree = False
treeElem x (Node a left right)
    | x == a = True
    | x < a = treeElem x left
    | x > a = treeElem x right

tout ce qui traverse une liste et retourne une
valeur peut être implémenté avec un pli.
On peut donc créer un arbre binaire de cette façon.
let nums = [8,6,4,1,7,3,5]
let numsTree = foldr treeInsert EmptyTree nums


# Classes de type 2
Les classes de type n'ont rien à voir avec les classes
dans les langages objets !

class Eq a where
    (==) :: a -> a -> Bool
    (/=) :: a -> a -> Bool
    x == y = not (x /= y)
    x /= y = not (x == y)

data TrafficLight = Red | Yellow | Green
instance Eq TrafficLight where
    Red == Red = True
    Green == Green = True
    Red == Red = True
    _ == _ = False

instance Show TrafficLight where
    show Red = "Red light"
    show Green = "Green light"
    show Yellow = "Yellow light"

## sous-classes:

class (Eq a) => Num a where
...

instance (Eq m) => Eq (Maybe m) where
    Just x == Just y = x == y
    Nothing == Nothing = True
    _ == _ = False


on peut utiliser :info type dans Ghci pour
avoir des informations sur un type



# Etiquettes de type

:k Int renvoi Int :: *
* signifie que int est concret

:k Maybe renvoi Maybe :: * -> *
:k Maybe Int renvoi Maybe Int :: *

# Entrées sorties

si on compile le fichier :

main = PutStrLn "Hello world"


main = do
    putStrLn "Hello"
    name <- getLine
    putStrLn ("Hey " ++ name ++ ", you rock !")

la construction do utilise l'indentation comme en python

putStrLn et getLine ont pour type IO
On ne peut pas mélanger les IO et les autres types ainsi
let f = "Truc" ++ getLine est impossible puisque "Truc" est
de type String et getLine est de type IO String

IO est un type qui comprend des effets de bords contrairement
aux autres types

 lorsqu'une fonction IO ne renvoi pas de valeur, elle renvoi ()


main = do
    return ()
    return "hahaha"
    line <- getLine
    return "BLAH BLAH BLAH"
    return 4
    putStrLn line

return fonctionne différeent que dans les autres langages
il créé une action IO, on peut s'en servir pour encapsuler des trucs

main = do
    a <- return "hell"
    b <- return "hey"
    putStrLn $ a ++ " " ++ b

est l'équivalent de

main = do
    let a = "hell"
        b = "hey"
    putStrLn $ a ++ " " ++ b

il y a plusieurs fonctions pour afficher du texte : PutChar PutStr PutStrLn
print (prend n'importe quelle instance de show)

getChar

# Fichiers et Flots

getContents lit un charactère d'une entrée standard
avant de rencontrer une fin de fichier
getContents est paresseuse

import Data.Char

main = do
       contents <- getContents
       putStr (map toUpper contents)


interact prend une fonction de type String -> String et retourne une action IO
qui va lire une entree, lancer la fonction dessus et afficher le résultat

main = interact shortLinesOnly

shortLinesOnly :: String -> String
shortLinesOnly input =
        let allLines = lines input
            shortlines = filter (\line -> length line < 10) allLines
            result = unlines shorLines
        in  result

on peut l'écrire aussi:
main = interact $ unlines . filter ((<10) . length) . lines

(continuer le chapitre 9)


# Classe Functor

class Functor f where
    fmap :: (a -> b) -> f a -> f b

