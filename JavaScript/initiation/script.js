console.log("jefrefnjrenfe");
const boutonClic = document.querySelector(".bouton");
const compteurClic = document.querySelector(".variable");

boutonClic.addEventListener("click", StartClic);

let compteur = 0;

function StartClic (){      //pas de param laisser vide 

    compteur ++;
    compteurClic.innerText = compteur;      // on change la valeur de "variable" ds HTML
}

