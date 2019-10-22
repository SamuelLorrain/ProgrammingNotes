Object.keys({x: 0, y: 0, z: 2});
//-> [x,y,z]

let objectA = {a:1, b:2};
Object.assign(objectA, {b:3, c:4});
//-> {a:1, b:3,c:4}
//
for(let i of objectA){ //for of
    console.log(i);
}

function max(...numbers){
    let result = -Infinity;
    for(let number of numbers){
        if(number > result) result = number;
    }
    return result;
}

max(4,1,-2,9) //appel de la fonction
let numbers = [4,1,-2,9];
max(...numbers) //appel de la fonction avec un tableau

["A","B"].forEach(value => console.log(value)); //foreach

let rabbit = {}
rabbit.speak = function(line){
    console.log(`The rabbit says '${line}'`);
}
rabbit.speak("hello")
//-> The rabbit says 'hello'

function speak(line){
    console.log(`The ${this.type} rabbit says '${line}'`);
}
let whiteRabbit = {type: "white", speak};
let hungryRabbit = {type: "hungry", speak};


//Object.prototype
console.log(Object.getPrototypeOf({}) == Object.prototype);
//-> true
console.log(Object.getPrototypeOf(Object.prototype));
//-> null

//Function.prototype
console.log(Object.getPrototypeOf(Math.max) == Function.prototype);
//-> true
console.log(Object.getPrototypeOf([]) == Array.prototype);
//-> true


//prototype
let protoRabbit = {
    speak(line){
        console.log(`The ${this.type} rabbit says '${line}'`);
    }
};
//object creation
let killerRabbit = Object.create(protoRabbit);
killerRabbit.type = "killer";
killerRabbit.speak("SkREEE!");


//utilisation de classe et constructeurs
//ECMA < 2015
function Rabbit(type){
    this.type = type;
}
Rabbit.prototype.speak = function(line){
    console.log(`The ${this.type} rabbit says '${line}'`);
};

let weirdRabbit = new Rabbit("weird");

//class notation
//ECMA >= 2015
class Rabbit{
    constructor(type){
        this.type = type;
    };
    speak(line){
        console.log(`The ${this.type} rabbit says '${line}'`);
    }
}

let killerRabbit = new Rabbit("killer");

//class expression
let object = new class { getWord() { return "hello";} };
console.log(object.getWord());

//map data structure
let ages ={
    Boris: 39,
    Liang: 22,
    Julia: 62
}

let ages = new Map();
ages.set("Boris", 39);
ages.set("Liang", 22);
ages.set("Julia", 62);
console.log(ages.get("Julia")); // 62
console.log(ages.has("Jack")); // false
console.log(ages.has("toString")); // false

//hasOwnProperty
console.log({x:1}.hasOwnProperty("x")); //true
console.log({x:1}.hasOwnProperty("toString")); //false

//polymorphism
Rabbit.prototype.toString = function(){
    return `a ${this.type} rabbit`;
}

console.log(String(blackRabbit));

//Symbols
let sym = Symbols("name"); //unique
console.log(sym == Symbol("name")) //false
Rabbit.prototype[sym] = 55;
console.log(blackRabbit[sym]) //55


//Iterator interface
let okIterator = "OK"[Symbol.iterator]();
console.log(okIterator.next()); //-> {value: "O", done: false}
console.log(okIterator.next()); //-> {value: "K", done: false}
console.log(okIterator.next()); //-> {value: undefined, done: true}
//à voir pour créer un iterator

//getter setters statics
class Temperature{
    constructor(celsius){
        this.celsius = celsius
    }
    get fahrenheit(){
        return this.celsius * 1.8 + 32;
    }
    set fahrenheit(value){
        this.celsius = (value - 32) * 1.8;
    }
    statuc fromFahrenheit(value){
        return new Temperature((value - 32) / 1.8);
    }

}

//heritage
class a extends b{
    constructor(){
        super()
    }
}

//instance of
console.log(new a instanceof a) //true
console.log(new b instanceof a) //false
console.log(new a instanceof b) //true (héritage)

//Données persistances (immutables)
let object = Object.freeze({value:5})
object.value = 10
console.log(object.value) // 5 (n'a pas changé


//re
let re1 = new RegExp("abc");
let re2 = /abc/;
console.log(/abc/.test("abcde")) //true
console.log(/abc/.test("cde")) //false

let match = /\d+/.exec("one two 100");
console.log(match) //["100"]
console.log(match.index) //8

console.log("papa".replace(/[ab]/, "o")) //popa
console.log("papa".replace(/[ab]/g, "o")) //popo

"  word".search(/\S/) //2

