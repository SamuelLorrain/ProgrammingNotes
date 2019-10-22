//Compiler theory:
//
//1. Tokenizing/Lexing
//      ==> Séparer une string en tokens utilisables par le langage
//2. Parsing
//      ==> A partir d'un array de token, créer un arbre
//      (AST) "Abstract Syntax Tree"
//3. Code generation
//      ==> AST vers un code executable

//Lexical Scope
function foo(a){
    var b = a*2;
    function bar(c){
        console.log(a,b,c);
    }
    bar(b*3);
}

foo(2);


//
// ATTENTION
// ne pas utiliser eval ou with qui
// trichent avec le lexical scope
//
function foo(str,a){
    eval(str);
    console.log(a,b);
}

var b= 2;
foo("var b = 3", 1);


var obj = {
    a:1,
    b:2,
    c:3
}

with { //DÉPRECIÉ!!!!
    a = 3;
    b = 4;
    c = 5;
}


///Scope pour du variable hiding
//Permet de créer un scope qui execute
//des actions sans pour autant
//créer une fonction nommée
//IIFE
(function foo(){
    var a =3;
    console.log(a);
})();


//Les fonctions sans nom ont certains problèmes
//1. sans nom, difficile d'analyser la stack trace
//2. Sans nom, impossible de faire de la recursion
//   (possible avec arguments.callee, mais déprécié)
//3. un nom peut servir à la doc
setTimeout(function timeoutHandler(){ //<-- à un nom
    console.log("I waited 1 second!");
}, 1000);

//Iife avec argument
(function IIFE(arg){
    //do stuffs
})(42);

//Les variables doivent être placés le plus proche
//du bloc ou elles doivent être utilisées
try{
    undefined();
}catch(err){ //err n'existe que dans le scope de catch
    console.log(err);
}

//let permet de block scoper des variables
//let n'est pas hoisté!

for(let j = 0; j < 10; j++){
    let i = j; //i est re-bindé au scope à chaque définition
}

const a; //constante block-scopée introduite en ES6


/////////////
//HOITSINTG
/////////////
console.log(a); //undefined
var a = 2; //pas de référenceError, car la variable est
           //mise dans le bloc à la compilation
//on appelle ce phénomène hoisting.
//Les assignemnts, et assignements d'expression de fonction (function())
//Ne sont pas hoisted

////////////////
//Scope Closure
////////////////
//Une closure est quand une fonction peut se souvenir de
//l'accès à son lexical scope même quand la fonction est executée
//en dehors de son scope
function foo(){
    var a = 2;
    function bar(){
        console.log(a);
    }
    return bar;
}

var baz = foo();
baz(); //2

//-------------
//time() garde en memoire message
//à l'exterieur du scope
function wait(message){
    setTimeout(function timer(){
        console.log(message)
    }, 1000);
}
wait("Hello closure");

//
//à voir la suite...
