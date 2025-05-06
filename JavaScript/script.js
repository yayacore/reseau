// @ts-ignore
const popUp = document.querySelector(".popUp");

if (popUp == null) throw Error(".popUp class n'existe pas dans le html");
const saveBtn = document.querySelector(".save_btn");

saveBtn.addEventListener("click", save);

function save() {

    console.log("début");

    const toastinette = document.createElement('div');
    toastinette.classList.add('toast');
    toastinette.innerText = "fichier enregistré";
    popUp.appendChild(toastinette);

    setTimeout(disapear, 3000);
    function disapear() {
        toastinette.remove();
    }
    toastinette.addEventListener("click", disapear);
}