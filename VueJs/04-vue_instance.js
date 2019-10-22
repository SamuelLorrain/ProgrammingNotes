data = {a:1};
//vue instance:
let vm = new Vue({
    el: '#example',
    data: data //data added to vue Instance
})

vm.a == data.a //==> true
vm.a = 2 //reactive
vm.b = 1 //non réactive car non existant au rendu
         //si des data sont inutiles au rendu, il faut quand même
         //les déclarer avant le rendu!

//les données peuvent changer tant qu'il n'y a pas eu d'Object freeze

//properties $ (voir la doc pour d'autres properties/methods $)
vm.$data == data //==> true
vm.$el === document.getElementById('example') //==> true

//methode $watch, permet
//de créer un callback quand la valeur de a change
vm.$watch('a', function(newValue, oldValue){
    Console.log("newValue : " + newValue);
    Console.log("oldValue : " + oldValue);
})


//hook
//ATTENTION NE PAS UTILISER D'ARROW FUNCTION DANS LES HOOK OU $WATCH
//(ils ne contiennent pas this, qui est utilisé par Vue.js)
new Vue({
    data:{
        a: 1
    },
    created: function(){ //created est appelé quand l'instance de Vue est créé
        console.log('a is: ' + this.a)
    }
})


