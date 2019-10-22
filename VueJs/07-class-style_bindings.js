/*
 * Voir dans le html computed pour voir les changements
 */
let app12 = new Vue({
    el: '#app-12',
    data:{
        isActive: false,
        hasError: false,
        classObject: {
            active: true,
            'text-danger': true
        },
        activeClass: 'active',
        errorClass: 'danger'
    }
})

Vue.component('my-component', {
    template: '<p class="foo bar">Hi</p>'
});

let app13 = new Vue({
    el: '#app-13',
    data:{
        activeColor: 'red',
        fontSize: 30,
        styleObject:{
            color: 'blue',
            fontSize: '45px'
        },
        baseStyles:{
            color: 'green',
            fontSize: '45px'
        },
        overridingStyles:{
            color: 'yellow',
            fontSize: '50px'
        },
    }
})
