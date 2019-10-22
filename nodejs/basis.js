//node basis.js pour lancer le prog
let message = "Hello World";
console.log(message);

console.log(process.argv) //liste des arguments

const {reverse} = require("./reverse"); //charger un paquet
let argument = process.argv[2];
console.log(reverse(argument));

//installer un package:
//npm install ini
//
//package.json --> contient les infos sur les packages téléchargés
//
//
const {fs} = require("fs") //file system module
const {http} = require("http") //http module

