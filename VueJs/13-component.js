//les components peuvent être enregistrées globalements
Vue.component('global',{
    template: '<p>global</p>'
})

//local
let app22 = new Vue({
    el: '#app-22',
    components:{
        'local-a': {
            template:'<p>local-a</p>'
        },
        'local-b': {
            template:'<p>local-b</p>'
        }
    }
})

//prop in object
Vue.component('aaa', {
    props:{
        title: String,
        likes: Number,
        isPublished: Boolean,
        commentIds: {
            type: Number,
            required: true, //required
            default: 100 //default
        }
        author: [Object, String], //multiple types
        callback: Function,
        contactsPromise: Promise,
        a{
            validator: function(input){
                return input > 5; //fonction validator
            }
        }
    }
    //...
})

//attribute inheritance
//==> $attrs
Vue.component('my-component',{
    inheritAttrs: false,
    props:['label','value'],
    template:`
        <label>
        {{label}}
        <input
            v-bind="$attrs"
            v-bind:value="value"
            v-on:input="$emit('input', $event.target.value)"
        >
        </label>
        `
    }
})
