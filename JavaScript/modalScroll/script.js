const blocs = document.querySelector("section");

const popUp = document.querySelector(".end button");

blocs.addEventListener("scroll", fonction); 

blocs.offsetTop;
blocs.documentElement.scrollTop;

function scrollLimit() {
    popUp.classList.add("popUp");
}