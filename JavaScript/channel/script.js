const buttons = document.querySelector(".like");
const abonnement = document.querySelector("button.subscribe");

buttons.addEventListener("click", applyEffectB);

abonnement.addEventListener("click", applyEffectA);


function applyEffectB() {
    buttons.classList.add("animationLike");
}

function applyEffectA() {
    abonnement.classList.add("subscribeButton");
    abonnement.innerText="Abonné";
    
}