import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';
import { Pokemon } from './types/pokemon';

@Component({
  selector: 'app-root',
  imports: [],
  templateUrl: './pokedex.component.html',
  styleUrl: './pokedex.component.css'
})
export class PokedexComponent {
  prenom = "Yaya";
  clics = 25;
  pokemons : Pokemon[] = [];

  async onclick(){

    const response = await fetch("https://pokebuildapi.fr/api/v1/pokemon/limit/100");
    this.pokemons = await response.json();
  }
}
