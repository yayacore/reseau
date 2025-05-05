console.log("Modal Scroll");

const modal = document.querySelector(".modal");
const section = document.getElementById("end");
const croix = document.getElementById("croix");

window.addEventListener("scroll", scrolling);
croix.addEventListener("click", clicking);

function scrolling () {

    const navWindow = document.documentElement.scrollTop;
    const topSection = end.offsetTop;
    
    if ( navWindow + window.innerHeight >= topSection) {
        modal.style.display = 'flex';
    }
}

function clicking () {
    modal.style.display = 'none';
}