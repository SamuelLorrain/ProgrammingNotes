//
console.log(encodeURIComponent("Yes?"));
// -> Yes%3F
console.log(decodeURIComponent("Yes%3F"));
// -> Yes?

//fetch (retourne une Promise)
fetch("example/data.txt").then(response => {
    console.log(response.status);
    // -> 200
    console.log(response.headers.get("Content-Type"));
    // -> text/plain
})

fetch("example/data.txt")
    .then(resp => resp.text())
    .then(text => console.log(text));


