Vue.component('button-counter', {
    //dans un component,
    //data doit être une fonction
    data: function(){
        return {
            count: 0
        }
    },
    template: `
    <button v-on:click="count++">
    You clicked me {{ count }} times.
    </button>
    `
})

let app19 = new Vue({
    el: '#app-19'
})

Vue.component('blog-post', {
    props:['title'],
    template:'<h3>{{ title }}</h3>'
})

let app20 = new Vue({
    el: '#app-20',
    data:{
        posts:[
            {id: 1, title: 'My first blog post'},
            {id: 2, title: 'My second blog post'},
            {id: 3, title: 'My third blog post'}
        ]
    }
})

//component avec objets
Vue.component('blog-post-plus', {
    props:['post'],
    template:`
        <div class="blog-post">
        <h3>{{ post.title }}</h3>
        <div v-html="post.content"></div>
        </div>
    `
})

let app21 = new Vue({
    el: '#app-21',
    data:{
        p:{
            title: "AAAA",
            content: "content content"
        }
    }
})

