//obligé d'utiliser de la kebab-case pour les noms d'énèvements

//custom v-model
Vue.component('base-checkbox',{
    model:{
        prop: 'checked',
        event: 'change'
    },
    props:{
        checked:Boolean
    },
    template:`
    <div class="custom_model">
    <label>custom v-model</label>
    <input type="checkbox"
           v-bind:checked="checked"
           v-on:change="$emit('change', $event.target.checked)"
    >
    </div>
    `
})

let app23 = new Vue({
    el: '#app-23',
    data:{
        lovingVue: true
    }
})

//native event to components
//==> base input peut-être
//utilisé exactement de la même façon
//que le input de base
Vue.component('base-input',{
    inheritAttrs: false,
    props:['label', 'value'],
    data: function(){
        return {
            someData: "someData"
        }
    },
    computed: function(){
        var vm = this
        return Object.assign({},
            this.$listeners,
            {
                input: function(event){
                    vm.$emit('input', event.target.value)
                }
            }
        )
    },
    template:`
    <label>
        {{ label }}
        <input
            v-bind="$attrs"
            v-bind:value="value"
            v-on="inputListeners"
    </label>
    `
})

