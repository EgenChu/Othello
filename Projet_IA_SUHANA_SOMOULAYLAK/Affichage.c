//
//  Affichage.c
//  Projet_IA_SUHANA_SOMOULAYLAK
//
//  Created by Sutra Suhana on 14/02/2020.
//  Copyright © 2020 Sutra Suhana. All rights reserved.
//

#include "Affichage.h"



void Afficher_plateau_text(int plateau[H][H]){
  int i,j;
  printf(" 0|1|2|3|4|5|6|7|\n");
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
