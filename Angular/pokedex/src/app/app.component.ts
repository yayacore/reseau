import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';
import { Pokemon } from '../types/Pokemon';

@Component({
  selector: 'app-root',
  imports: [RouterOutlet],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class PokedekComponent {
  prenom = "Yaya";
  clics = 25;
  pokemons : Pokemon[] = [];

  async onclick(){

    const response = await fetch("https://pokebuildapi.fr/api/v1/pokemon/limit/100");
    this.pokemons = await response.json();
  }
}
