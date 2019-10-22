let app17 = new Vue({
    el: '#app-17',
    data:{
        counter: 0,
        name: 'John'
    },
    methods:{
        greet:function(event){
            console.log('Hello ' + this.name + '!');
            if(event){
                console.log(event.target.name);
            }
        },
        say: function(message){
            console.log(message);
        },
        submit:function(){
            console.log('submit')
        }
    }
})
