let app8 = new Vue({
    el : '#app-8',
    data : {
        msg : "Message!",
        rawHtml: '<span style="color:red">This should be red.</span>',
        dynamicId: 'test',
        isButtonDisabled: true,
        seen : true,
        url: 'http://www.google.com'
    },
    methods:{
        doSomething: function(){
            console.log("doSomething");
        }
    }
})
