//
//  ListePos.c
//  Projet_IA_SUHANA_SOMOULAYLAK
//
//  Created by Sutra Suhana on 14/02/2020.
//  Copyright © 2020 Sutra Suhana. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ListePos.h"
#include "ArbreMiMa.h"

/*Renvoie une Position jouable*/
PosJouable_t *Creer_posJouable(int posi, int posj)
    {
    PosJouable_t *nPos = malloc(sizeof(PosJouable_t));
    nPos->i=posi;
    nPos->j=posj;
    nPos->suiv=NULL;
    nPos->Nd = NULL;;
    return nPos;
    }

/* Affiche les champs donnee des elements de la liste */
void Afficher_lPosJouables(PosJouable_t *liste_pos)
    {
    while (liste_pos)
        {
        printf("(%d,%d) ",liste_pos->i, liste_pos->j);
        liste_pos=liste_pos->suiv;
        }
    putchar('\n');
}

/* Renvoie la liste à laquelle un élément a été ajouté en tete de liste*/
PosJouable_t *Inserer(PosJouable_t *liste_pos, int posi, int posj)
    {
    PosJouable_t *nPos = Creer_posJouable(posi, posj);
    if(liste_pos != NULL) nPos->suiv = liste_pos;
    return nPos;
    }


PosJouable_t *Detruire_liste(PosJouable_t *liste_pos)
    {
    while (liste_pos)
        {
        PosJouable_t *pSuiv = liste_pos->suiv;
        Detruire_arbre(liste_pos->Nd);
        free(liste_pos);

        liste_pos = pSuiv;
        }
    return NULL;
    }

int Est_dans_liste(PosJouable_t *liste_pos, int i, int j)
    {
        while(liste_pos)
        {
            if((i == liste_pos->i) && (j == liste_pos->j)) return 1;
            liste_pos = liste_pos->suiv;
        }
        printf("\nLa position %d,%d n'est pas un coup valide\n",i,j);
        return 0;
    }

