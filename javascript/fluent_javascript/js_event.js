//ajouter un Event Listener sur un
//element du dom
window.addEventListener("click", () => {
    console.log("You knocked");
});

let button = document.querySelector("button");
button.addEventListener("click", () => {
    console.log("Button Clicked");
});

button.removeEventListener("click", handler);

button.addEventListener("mousedown", event => {
    if(event.button == 0){
        console.leg("Left button");
    }else if(event.button == 1){
        console.leg("Middle button");
    }else if(event.button == 2){
        console.leg("Right button");
    }
});

//Propagation des evenements
//Ici il y a deux handlers,
//Un sur le paragraph et un
//sur le button
//<p>dkflsdkjfldsjqf<button>b</button></p>
let para = document.querySelector("p");
let button  = document.querySelector("button");
para.addEventListener("mousedown",() => {
    console.log("Handler for paragraph");
});
para.addEventListener("mousedown" event => {
    console.log("Handler for button.");
    if (event.button == 2) event.stopPropagation();
});


//connaitre le target d'un element
document.body.addEventListener("click", event =>{
    if(event.target.nodeName == "BUTTON"){
        console.log("clicked", event.target.textContent);
    }
});

//Prevent défault
//ici, on fait en sorte que le
//lien n'ouvre pas une nouvelle pas internet
let link = document.querySelector("a");
link.addEventListener("click", event =>{
    console.log("Nope");
    event.preventDefault();
});


//Key Event
window.addEventListener("keydown", event =>{
    if(event.key == "v"){
        document.body.style.background = "violet";
    }
});
window.addEventListener("keyup", event => {
    if(event.key == "v"){
        document.body.style.background = "";
    }
});

/*
 *
 * Mouse event ...
 * Scroll event ...
 * Focus Event ...
 */


