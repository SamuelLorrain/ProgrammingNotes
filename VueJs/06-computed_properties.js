/*
 * Les computed properties sont
 * mise en cache basé sur leur dépendances
 * reactives (les variables reactives)
 *
 * Ainsi, si une methode dépend d'une grande
 * variable longue à calculer, computed ne sera
 *
 */

/*
 * Une computed property est généralement
 * une meilleure idée qu'un $watch!!!
 */
let app9 = new Vue({
    el: '#app-9',
    data: {
        message: "not reversed message"
    },
    methods:{
        method: function(){
            return this.message.split('').reverse().join('');
        }
    },
    computed: {
        //a computed getter
        reversedMessage: function(){
            // this points to the vm instance
            return this.message.split('').reverse().join('');
        },
        now: function(){
            return Date.now();
        },
    }
})

//getter setter
let app10 = new Vue({
    el: '#app-10',
    data:{
        lastName : 'Doe',
        firstName: 'John'
    },
    computed:{
        fullName: {
            get: function(){
                return this.firstName + ' ' + this.lastName;
            },
            set: function(newValue){
                let names = newValue.split('');
                this.firstName = names[0];
                this.lastName = name[names.length - 1]
            }
        }
    }

})

//watchers
//utilisé pour les fonctions asynchrones ou expensives
let app11 = new Vue({
    el: '#app-11',
    data:{
        question : '',
        answer: ''
    },
    //watch est asynchrone ici
    watch: {
        question: function(newQuestion, oldQuestion){
            this.answer = 'Waiting for you to stop typing...';
            this.debouncedGetAnswer()
        }
    },
    created: function(){
        //_.debounce => lodash, limite le nombre d'une
        //opération particulière.
        this.debouncedGetAnswer = _.debounce(this.getAnswer, 500);
    },
    methods:{
        getAnswer: function(){
            if(this.question.indexOf('?') === -1){
                this.answer = "Question usually contain a question mark."
                return;
            }
            this.answer = 'Thinking...'
            var vm = this;
            axios.get('https://yesno.wtf/api')
                .then(function (response){
                    vm.answer = _.capitalize(response.data.answer)
                })
                .catch(function(error){
                    vm.answer = 'Error! Could not reach the API. ' + error
                });
        }

    }
})
