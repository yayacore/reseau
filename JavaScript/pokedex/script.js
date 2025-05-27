console.log("debut");
const pokemonList = document.getElementById("list");
const details = document.getElementById("details");
const searchInput = document.getElementById("search");
let pokemons = [];

// requete pokebuild récup données json 

// requête pokebuild récup données json 
fetch("https://pokebuildapi.fr/api/v1/pokemon")
    .then(response => response.json())
    .then(data => {
        pokemons = data;  // Mets à jour la variable globale ici
        displayPk(pokemons);
        pokemons.forEach(pokemon => {
            console.log(pokemon.name);
        });
});

// barre de recherche
searchInput.addEventListener("input", () => {
    const search = searchInput.value.toLowerCase();
    const found = pokemons.find(pokemon => pokemon.name.toLowerCase().includes(search));
    if (found) {
        pokemonSpec(found); // afficher détails du pokémon
    }
});


function displayPk(pokemons) {
    pokemons.forEach(pokemon => {
        const div = document.createElement("div");
        div.classList.add("pokemonStack");
        div.dataset.id = pokemon.id;
        div.innerHTML = `
        <span>${pokemon.id}</span>
        <span>${pokemon.name}</span>
        <img src="${pokemon.image}" alt="${pokemon.name}"></img>
        `;
        div.addEventListener("click", () => pokemonSpec(pokemon));
        pokemonList.appendChild(div);
    });

    function pokemonSpec(pokemon) {
        details.innerHTML = `
        <p>n°${pokemon.id}</p>
        <img src="${pokemon.image}" alt="image du pokemon" />
        <h2>${pokemon.name}</h2>
        ${pokemon.apiTypes.map(type => `<img src="${type.image}" alt="${type.name}" />`).join("")}
        
        <div class="evolution">
            <h3>Évolution</h3>
            ${pokemon.apiEvolutions.length
                ? pokemon.apiEvolutions.map(evo => `
                    <div class="evolution-item" data-id="${evo.pokedexId}">
                        <span>${evo.pokedexId}</span>
                        <span>${evo.name}</span>
                    </div>
                `).join("")
                : "<p>Aucune évolution</p>"
            }
        </div>
    `;
    }

}

