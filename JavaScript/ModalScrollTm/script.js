console.log("Modal Scroll");

const modal = document.querySelector(".modal");
const section = document.getElementById("end");
const croix = document.getElementById("croix");

window.addEventListener("scroll", popUp);
croix.addEventListener("click", clicking);

setTimeout(popUp, 3000);

function popUp() {
    modal.style.display = 'flex';
}

function clicking() {
    modal.style.display = 'none';
}
