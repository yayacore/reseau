console.log("debut");
const pokemonList = document.getElementById("list");
const details = document.getElementById("details");

fetch("https://pokebuildapi.fr/api/v1/pokemon")
    .then(response => response.json())
    .then(pokemons => {
        displayPk(pokemons);
        pokemons.forEach(pokemon => {
            console.log(pokemon.name);
        });
    });

function displayPk(pokemons) {
    pokemons.forEach(pokemon => {
        const div = document.createElement("div");
        div.classList.add("pokemonStack");
        div.dataset.id = pokemon.id;
        div.innerHTML = `
        <span>${pokemon.id}</span>
        <span>${pokemon.name}</span>
        <img src="${pokemon.image}" alt="${pokemon.name}"></img>`;
        addEventListener("click", () => pokemonSpec(pokemon));
        pokemonList.appendChild(div);
    });

    function pokemonSpec(pokemon) {
        details.innerHTML = `
        <p>${pokemon.id}</p>
        <h2>${pokemon.name}</h2>
        <p>${pokemon}</p>


        `
    }

}