const bouton = document.getElementById("bouton");
const popUp = document.querySelector(".popUp");

bouton.addEventListener("click", save);

function save() {
    console.log("début");
    popUp.classList.remove("displayNone");
}

setTimeout(disapear, 3000);

function disapear() {
    popUp.classList.add("fadeOut");
}

popUp.addEventListener("click", disapear);

// pour que le télécharchement se fasse en boucle mettre un foreach