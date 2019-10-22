//callback
setTimeout(() => console.log("Tick"), 500); //affiche Tick après 500ms

//Promise
//promise est une action asynchrone qui peut
//finir et retourner une valeur
let fifteen = Promise.resolve(15)
//then est une méthode de Promise qui prend une f en
//paramètre est est appelée quand l'action est finie
//
//then retourne une autre Promise qui peut aussi attendreune valeur
fifteen.then(value => console.log(`Got ${value}`))

function storage(nest, name){
    return new Promise(resolve => {
        nest.readStorage(name, result => resolve(result));
    });
}

storage(bigOak, "ennemies")
    .then(value => console.log("Got", value));

//les actions dans then sont appelées quand une requête
//est réussie.
//En cas de failure, la failure est machinée
//à tous les then
//catch permet de faire une erreur
Promise.reject() //crée une promise rejetée

new Promise((_,reject) => reject(new Error("Fail")))
    .then(value => console.log("Handler 1"))
    .catch(reason => {
        console.log("Caught failure " + reason);
        return "nothing";
    })
    .then(value => console.log("Handler 2", value));
//-> Caught failure Error: fail
//-> Handler 2 Nothing

class Timeout extends Error {}

function request(nest, target, type, content){
    return new Promise((resolve,reject) => {
        let done = false;
        function attempt(n){
            nest.send(target, type, content, (failed,value) => {
                done = true;
                if (failed) reject(failed);
                else resolve(value);
            });
            setTimeout(() => {
                if (done) return;
                else if (n < 3) attempt(n + 1);
                else reject(new Timeout("Timed out"));
            }, 250);
        }
        attempt(1);
    });
}

//async
//function*
//à voir...
