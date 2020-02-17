//
//  ArbreMiMa.h
//  Projet_IA_SUHANA_SOMOULAYLAK
//
//  Created by Sutra Suhana on 14/02/2020.
//  Copyright © 2020 Sutra Suhana. All rights reserved.
//

#ifndef ArbreMiMa_h
#define ArbreMiMa_h

#include <stdio.h>

#include "Othello.h"

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

typedef struct _NdMiMa_t
    {
    int Couleur; // Blanc ou noir joue
    struct _posJouables_t *liste_pos;
    struct _NdMiMa_t *JoueurBloque;
    }  NdMiMa_t;

NdMiMa_t *Construire_arbre(int plateau[H][H], int prof, int couleurQuiJoue);
int MeilleurPos(NdMiMa_t *arbre, int plateau[H][H], int (*EvaluerPlateau)(int plateau[H][H]),int *pi, int *pj);
int MinMax(NdMiMa_t *arbre, int plateau[H][H], int (*EvaluerPlateau)(int plateau[H][H]));
NdMiMa_t *Detruire_arbre(NdMiMa_t *arbre);
int EvaluerPlateau_0(int plateau[H][H]);
int EvaluerPlateau_1(int plateau[H][H]);

#endif /* ArbreMiMa_h */
