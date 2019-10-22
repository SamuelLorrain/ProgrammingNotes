//Conversion
let a = "1";
let b = Number(a);


/*
 * Values type:
 * string
 * number
 * boolean
 * null / undefined
 * object
 * symbol (ES6)
 *
 */

typeof a; //string
typeof b; //number

function foo(){
    return 42;
}

typeof foo; //function
typeof foo(); //number

let a = "42"; //string
let b = a * 1; //42 --> coercion to number

a == b; //check la valeur (true)
a === b; //check la valeur et le type (false)
// ->
"42" == 42; //true
"42" === 42; //false

//--> Si une valeur de comparaison est un boolean utiliser ===
//--> Si une valeur est 0 "" ou [] utiliser ===
//--> Sinon on peut utiliser ==

[1,2,3] == "1,2,3" //true
[1,2,3] == [1,2,3] //false
41 < "42" //true
"42" < "43" //true
42 < "foo" //false


//Hoisting
var a = 1; //hosté --> variable mise en haut d'un scope


{
    "use strict" //strict mode dans le scope
    a = 1; //error var or let missing, Reference Error
}

//Immediately Invoked Function expression
(function IIFE(){
    console.log("Hello");
})();

//Closure
function makeAdder(x){
    //add utilise "x", elle est
    //donc enclosée au return
    function add(y){
        return y + x;
    };
    return add
}

let plus5 = makeAdder(5);
plus5(10) //15

///Module pattern (utilisation de closure)
function User(){
    var username, password;
    function doLogin(user,pw){
        username = user;
        password = pw;
    }
    var publicApi = {
        login: doLogin
    }
    return publicApi;
}

var fred = User();
fred.login("fred","12Battery34!");

//this
//Contraiement aux autres langages
//en JS this n'est pas directement relié à l'OO
function foo(){
    console.log(this.bar);
}

var bar = "global";
var obj1= {
    bar: "obj1",
    foo: foo
};
var obj2 = {
    bar: "obj2"
};

foo(); //global
obj1.foo(); //obj1
foo.call(obj2); //obj2
new foo(); //undefined

//Prototype
var foo = {
    a:42;
};
var bar = Object.create(foo);
bar.b = "hello world";
bar.b;   //hello world
bar.a;  //42 <-- deletate to foo

