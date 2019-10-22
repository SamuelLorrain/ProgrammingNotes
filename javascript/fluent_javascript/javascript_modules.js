//CommonJS modules.
//Une norme pour gérer les modules en ECMAScript < 2015
//
//--> une fonction appellée "require" permet de
//charger des modules dans des scopes particuliers
//
//exports est un objet qui est exporté dans les autres requires
//ci-dessous si on exporte le module courant,
//formatDate sera une fonction exportée
//
const ordinal = require("ordinal") //import du module ordinal
                                   //dans le scope ordinal
const {days,months} = require("date-names")

exports.formatDate = function(date, format){
    return format.replace(/YYYY|M(MMM)?|Do?|dddd/g, tag =>{
        if (tag == "YYYY") return date.getFullYear();
        if (tag == "M") return date.getMonth();
        if (tag == "MMMM") return months[date.getMonth()];
        if (tag == "D") return date.getDate();
        if (tag == "Do") return ordinal(date.getDate());
        if (tag == "dddd") return days[date.getDay()];
    });
};

//dans un autre fichier:
const {formatDate} = require("./format-date");
console.log(formatDate(new Date(2018, 9, 13), "dddd the Do"));
//-> Friday the 13th

//ECMA2015 modules
import ordinal from "ordinal";
import {days, months} from "date-names";

export function formatDate(date, format){ /* ... */ }
export default ["Winter", "Spring","Summer","Autumn"];

import {days as dayNames} from "date-names";
