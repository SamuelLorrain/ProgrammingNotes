let canvas = document.querySelector('canvas');

canvas.width = window.innerWidth;
canvas.height = window.innerHeight;
let context = canvas.getContext('2d');

////draw a line
//context.beginPath();
//context.moveTo(300,50); //c.moveTo(x,y);
//context.lineTo(500,1000);
//context.lineTo(400,800);
//context.lineTo(200,100);
//context.strokeStyle = "#fc0" //css color value
//context.stroke();
//
////Arc / Circle
//context.beginPath();
//context.arc(300,300, 30, Math.PI*2, false);
//context.strokeStyle = "black";
//context.stroke();

function Circle(){
    this.radius = Math.random() * 30;
    this.x = (Math.random() * (window.innerWidth)) % (window.innerWidth - this.radius - 1);
    this.y = (Math.random() * (window.innerHeight)) % (window.innerWidth - this.radius - 1);
    this.speedX = (Math.random() - 0.5) * 8;
    this.speedY = (Math.random() - 0.5) * 8;
    this.draw = function(){
        context.beginPath();
        context.arc(this.x,this.y, this.radius, Math.PI*2, false);
        context.fillStyle = "black";
        context.fill();
        if(this.x + this.radius >= window.innerWidth || this.x - this.radius <= 0){
            this.speedX = -this.speedX;
        }else if(this.y + this.radius >= window.innerHeight || this.y - this.radius <= 0){
            this.speedY = -this.speedY;
        }
        this.x += this.speedX;
        this.y += this.speedY;
    }
}

function createRect(x,y){
    let context = canvas.getContext('2d');
    context.fillStyle = "rgba(255,50,50,0.5)";
    context.fillRect(x,y, 10,10);
}

let c1 = new Circle();

let circleArray = []
for(let i = 0; i < 50; i++){
    circleArray.push(new Circle);
}

//animation
function animate(){
    requestAnimationFrame(animate);
    context.clearRect(0,0,window.innerWidth,window.innerHeight);
    for(let i = 0; i < window.innerWidth; i += 100){
        for(let j = 0; j < window.innerHeight; j += 50){
            createRect(i,j);
        }
    }
    circleArray.forEach(circle => circle.draw());
}

animate();
