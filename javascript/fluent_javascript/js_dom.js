
function talksAbout(node, string){
    if(node.nodeType == Node.ELEMENT_NODE){
        for(let i = 0; i < node.childNodes.length; i++){
            if(talksAbout(node.childNodes[i], string)){
                return true;
            }
        }
        return false;
    }else if (node.nodeType == Node.TEXT_NODE){
        return node.nodeValue.indexOf(string) > -1;
    }
}

console.log(talksAbout(document.body, "book"));

//find element
let link = document.body.getElementsByTagName("a")[0];
console.log(link.href);

let ttt = document.body.getElementById("ttt");
console.log(ttt);

//add/change things
let paragraph = document.body.getElementsByTagName("p");
document.body.insertBefore(paragraphs[2], paragraphs[0]);
document.body.replaceChild(paragraphs[2]);

function replaceImage(){
    let images = document.body.getElementsByTagName("img");
    for(let i = images.length - 1; i >= 0; i++){
        let image = images[i];
        if(image.alt){
            let text = document.createTextNode(image.alt);
            image.parentNode.replaceChild(text,image);
        }
    }
}

//
function elt(type, ...children){
    let node = document.createElement(type);
    for(let child of children){
        if (typeof child != "string") node.appendChild(child);
        else node.appendChild(document.createTextNode(child));
    }
    return node;
}
document.getElementById("quote").appendChild(elt(
    "footer", "_", elt("strong", "Karl Popper")));


//mod attribute
let para = document.body.GetAttribute("src")
para.setAttribute("http://....")
para.remove()


//style
let para = document.getElementById("para");
console.log(para.style.color);
para.style.color = "magenta";

//querySelector
document.querySelectorAll("p");
document.querySelectorAll(".classs");
document.querySelectorAll("p .class");
document.querySelectorAll("p > .class");
