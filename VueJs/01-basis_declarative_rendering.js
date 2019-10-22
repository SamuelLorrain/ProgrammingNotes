//on peut modifier la variable directement
//dans la console JS
let app = new Vue({
    el: '#app',
    data:{ message: 'Hello Vue!' }
});

let app2 = new Vue({
    el: '#app-2',
    data:{
        message: 'You loaded this page on ' + new Date().toLocaleString()
    }
});

let app3 = new Vue({
    el: '#app-3',
    data:{
        seen: true
    }
})

//on peut push des elements dans
//todo directement dans la console JS
let app4 = new Vue({
    el: '#app-4',
    data:{
        todos : [
            {text: 'Learn Javascript'},
            {text: 'Learn Vue.js'},
            {text: 'Build something awesome'}
        ]
    }
})
