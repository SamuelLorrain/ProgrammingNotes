//AVEC this:
function identify(){
    return this.name.toUpperCase();
}

function speak(){
    var greeting = "Hello I'm " + identify.call(this);
    console.log(greeting);
}

var me = {
    name: "Kyle"
}

var you = {
    name: "Reader"
};

//call permet de binder
//une fonction sur un objet
identify.call(me);
identify.call(you);

speak.call(me);
speak.call(you);

//Sans this
function identify(context){
    return context.name.toUpperCase();
}

function speak(context){
    var greeting = "Hello, I'm " + identify(context);
}

identify(you);
speak(me);

//////////////////
//QU'EST CE QUE THIS N'EST PAS ?
//////////////////
//this ne fait pas une référence directe à la fonction!
//-----------------------------
function foo(num) {
	console.log( "foo: " + num );
	// keep track of how many times `foo` is called
	this.count++;
}
foo.count = 0;
var i;
for (i=0; i<10; i++) {
	if (i > 5) {
		foo( i );
	}
}
// foo: 6
// foo: 7
// foo: 8
// foo: 9
// how many times was `foo` called?
console.log( foo.count ); // 0 -- WTF?
//----> this ne pointe pas sur la fonction!
function foo(){
    foo.count = 4; //référence la fonction elle même
}// ---> si on remplace "this" par "foo", le code marche.
///
for (i=0; i<10; i++) {
	if (i > 5) {
        //call permet de faire pointer this sur la fonction
		foo.call( foo, i );
	}
}

// --> this ne référence par le lexical scope d'une fonction
function foo(){
    var a = 2;
    this.bar();
}

function bar(){
    console.log(this.a);
}

foo(); //undefined
//---> "there is no bridge possible between lexical scopes"

///////////////
//THIS
//////////////
//this est un runtime binding.
//this existe contextuellement en fonction
//de l'invocation de la fonction
//this n'a rien avoir avec comment la fonction
//est déclarée, mais comment elle est appelée.
//
//--> Quand une fonction est executé, un contexte
//d'execution est créé. Une des informations dans le
//contexte (le call-site) est ce que this référence.
//
//Pour comprendre, il faut comprendre la call-stack
//--> Le call-site est dans l'invocation juste avant
//--> d'executer une fonction
function baz(){/* call-stack:baz, call-site:global*/ bar();}
function bar(){/* call-stack:baz->bar, call-size:baz*/ foo();}
function foo(){/* call-stack:baz->bar->foo, call-size:bar*/ }
baz();

////////////////////////////////////////
function foo(){ console.log(this.a); }
var a=2;
foo(); //2

///// strict mode <---- empêche this de
///// référencer le global scope
function foo(){ "use strict" console.log(this.a); }
var a=2;
foo(); //TypeError: this is undefined
/////
function foo(){ console.log(this.a); }
var a = 2;
(function(){ "use strict" foo();/*2*/ })();
/////

//Implicit binding
/////////////////////////////////////////
function foo(){ console.log(this.a);}
var obj = { a:2, foo:foo};
obj.foo(); //2 <<----- this dans un objet référence les attributs de l'objet
/////////////////////////////////////////
function foo(){ console.log(this.a);}
var obj2 = { a:42, foo:foo};
var obj1 = { a:"aaa", obj2:obj2};
obj1.obj2.foo(); // 42
/////////////////////////////////////////

//Implicitly Lost
function foo(){ console.log(this.a); }
var obj = {a:2, foo:foo};
var bar = obj.foo;
var a = "global"
bar(); //"global" <--------------- DEPEND DE L'APPEL PAR DU LEXICAL BLOC
       // <----------------------  obj.foo est une référence à foo
       // <----------------------  donc quand bar est appelé, foo est appelé
//<<------------ En référencant des trucs, on peut perdre le callback

//Explicit Binding
//call permet de référencer explicitement un scope
function foo(){ console.log(this.a); }
var obj = { a: 2 };
foo.call(obj); //2

//Hard Binding
function foo(){ console.log(this.a); }
var obj = { a:2 };
var bar = { foo.call(obj); };
bar(); //2
setTimeout(bar, 100); //2
// `bar` hard binds `foo`'s `this` to `obj`
// so that it cannot be overriden
bar.call(window); //2


//New Binding
//New n'est pas l'équivalent d'un New dans Cpp etc. !!!
//(pas de type spécifique etc.)
//--> new modifie l'appel d'une fonction pour en faire
//un appel constructeur
//
//à l'utilisation de new:
//1. Un nouvel objet est créee
//2. l'objet créé est [[Prototype]]-linked
//3. l'objet créé est considéré comme le this binding, pour le constructeur appelé
//4. a moins que l'objet retourne un objet alternatif, le constructeur renvoi
//l'objet nouvellement créé
function foo(a){ this.a = a; }
var bar = new foo(2);
bar.a; //2
///===> new modifie le this pour qu'il pointe dans l'objet nouvellement créé

//this & arrow functions
//les arrow fonction adoptent le this du scope dans le
//quel ils se trouvent
function foo(){ return (a) => {console.log(this.a);}}; //scope de foo (call-site global)
var obj1 = {a:2};
var obj2 = {a:3};
var bar = foo.call(obj1);
bar.call(obj2); //2

//avant les arrow:
function foo() { var self = this; setTimeout( function(){ console.log( self.a ); }, 100 ); }
var obj = { a: 2 };
foo.call( obj ); // 2

/////////////////////////////
//Object
/////////////////////////////
var obj = new Object();
obj.key = value;

var strPrimitive = "I am a string";
typeof strPrimitive; //"string"
strPrimitive instanceof String; //false

var strObject = new String("I am a String");
typeof strObject; //object
strObject instanceof String; //true

Object.prototype.toString.call(strObject); //[object String]

//Array
var myArray = ["foo", 42 , "bar"];
myArray.length //3
myArray[0] //"foo"
myArray[2] //"bar"

//Property Descriptor
var myObject = { a:2 }
Object.getOwnPropertyDescriptor(myObject, "a");
//{
//  value:2,
//  writable:true,
//  enumerable:true,
//  configurable:true
//}

Object.defineProperty(myObject, "a",{
    value:2,
    writable:true,
    configuration:true,
    enumerable:true
});

Object.preventExtensions(myObject);
myObject.b = 3;
myObject.b; //undefined

Object.seal() //
Object.freeze() //


///////////////////
//Getter & Setters
///////////////////
var myObject = {
    get a(){ //getter
        return 2;
    }
    set a(val){
        this._a_ = val * 2;
    }
};
Object.defineProperty(myObject, "b",{
    get: function(){return this.a *2}, //créer un getter
    enumerable:true
});

("a" in myObject); //true
("b" in myObject); //false
myObject.hasOwnProperty("a"); //true
myObject.hasOwnProperty("b"); //false

myObject.propertyIsEnumerable("a"); //voir si une property est enumerable
Object.keys(myObject); // ["a"]
Object.getOwnPropertyNames(myObject) //["a","b"]

var myArray = [1,2,3];
for (var v of myArray){ //foreach
    console.log(v);
}

var it = myArray[Symbol.iterator]();
it.next(); //iterator
it.next();

///////////////////
//Class
///////////////////
class CoolGuy{
    specialTrick = nothing;
    constructor(trick){ specialTrick = trick; }
    showOff(){output("Here's my trick: ", specialTrick);} }
Joe = new CoolGuy("jumping rope");
Joe.showOff();
class BestCoolGuy inherits CoolGuy{
    showOff(){ inherited:showOff() output("Best!"); } }

//Mixins ...


///////////////////
//Prototypes
///////////////////
//tous les objets javascript ont une propriété appelée [[Prototype]]
//qui est une référence à un autre objet
anotherObject = {a:2};
var myObject = Object.create(anotherObject); //myObject est linké à `anotherObject`
for(var k in myObject){ console.log("found: "+k); } //
("a" in myObject); //true


