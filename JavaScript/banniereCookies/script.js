console.log("test 1 2");

const banniere = document.querySelector(".cookies");
const cta = document.querySelector(".boutonA");

cta.addEventListener("click", disappearBanner);

function disappearBanner () {
    banniere.classList.add("disappear");
}



