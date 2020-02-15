//
//  Affichage.c
//  Projet_IA_SUHANA_SOMOULAYLAK
//
//  Created by Sutra Suhana on 14/02/2020.
//  Copyright © 2020 Sutra Suhana. All rights reserved.
//

#include "Affichage.h"



void Afficher_plateau_text(int plateau[H][H])
{
  int i,j;
  printf("\n 0|1|2|3|4|5|6|7|\n");
  for(i=0;i<H;i++){
    printf("%d", i);
    for(j=0;j<H; j++){
      switch(plateau[i][j]){
        case VIDE: printf(" |"); break;
        case NOIR: printf("*|"); break;
        case BLANC: printf("O|"); break;
        default: printf("Unknown character in game board\nEXITING\n"); exit(1);
      }
    }
    printf("*\n");
  }
  printf("-----------------\n");
}

void Dessine_plateau_graph(int plateau[H][H], int joueurCourant)
{
//    clear_screen();
    Afficher_plateau_text(plateau);
}

void clear_screen()
{
  printf("\x1b[2J\x1b[1;1H");  /* code ANSI X3.4 pour effacer l'ecran */
}
