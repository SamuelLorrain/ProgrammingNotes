Vue.component('todo-item', {
    props: ['todo'], //prop ==> custom property
    template: '<li>{{ todo.text }}</li>'
})

let app7 = new Vue({
    el: '#app-7',
    data: {
        groceryList: [
            { id: 0, text: 'Vegetables'},
            { id: 1, text: 'Cheese'},
            { id: 2, text: 'Whatever'}
        ]
    }
})
