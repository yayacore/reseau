const menu = document.querySelector(".menuIcon");

const nav = document.querySelector(".nav");

menu.addEventListener("click", openNav);

function openNav () {
    nav.classList.add("navOp");
    nav.classList.add("navContent");
}