//
//  Affichage.h
//  Projet_IA_SUHANA_SOMOULAYLAK
//
//  Created by Sutra Suhana on 14/02/2020.
//  Copyright © 2020 Sutra Suhana. All rights reserved.
//

#ifndef Affichage_h
#define Affichage_h
#include  "Othello.h"

#include <stdio.h>

void Afficher_plateau_text(int plateau[H][H]);
void Dessine_plateau_graph(int plateau[H][H], int joueurCourant);
void clear_screen();

#endif /* Affichage_h */
