//
//  Othello.h
//  Projet_IA_SUHANA_SOMOULAYLAK
//
//  Created by Sutra Suhana on 14/02/2020.
//  Copyright © 2020 Sutra Suhana. All rights reserved.
//

#ifndef Othello_h
#define Othello_h

#include "ListePos.h"
#include <stdio.h>

#define H 8 //Taille du plateau

#define VIDE 0
#define NOIR 1
#define BLANC 2



int Autre_joueur(int joueur);
void Initialiser_plateau(int plateau[H][H]);
int Partie_terminee(int plateau[H][H]);
void Copier_plateau(int dst[H][H], int src[H][H]);
PosJouable_t *Trouver_liste_pos_jouables(int plateau[H][H], int couleurQuiJoue);
void Jouer_pion(int plateau[H][H], int iLigne, int iCol, int couleurQuiJoue);
void Nb_pions(int plateau[H][H], int *NbB, int *NbN);

void Joueur_Auto_2(int plateau[H][H], int *pi, int*pj,PosJouable_t *listeJouable);

#endif /* Othello_h */
