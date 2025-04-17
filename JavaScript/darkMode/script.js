const switchMode = document.querySelector(".toggle-bar");

switchMode.addEventListener("click", bascule);

function bascule (){
    switchMode.classList.add("dark");

}