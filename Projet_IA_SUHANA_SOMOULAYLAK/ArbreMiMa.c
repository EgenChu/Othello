//
//  ArbreMiMa.c
//  Projet_IA_SUHANA_SOMOULAYLAK
//
//  Created by Sutra Suhana on 14/02/2020.
//  Copyright © 2020 Sutra Suhana. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include "ArbreMiMa.h"
#include "ListePos.h"

int EvaluerPlateau_0(int plateau[H][H])
    {
    int i,j;
    int res = 0;
    /*A Completer*/
    return res;
    }

NdMiMa_t *Construire_arbre(int plateau[H][H], int prof, int couleurQuiJoue)
    {
        if(prof <= 0 || Partie_terminee(plateau)) return NULL;
        
        printf("=== PROFONDEUR %d ===\n", prof);
        printf("Couleur qui joue : ");
        switch (couleurQuiJoue) {
            case NOIR:
                printf("NOIR\n");
                break;
                
            case BLANC:
                printf("BLANC\n");
                break;
        }
        
        NdMiMa_t *noeud = malloc(sizeof(NdMiMa_t));
        noeud->Couleur = couleurQuiJoue;
        noeud->liste_pos = Trouver_liste_pos_jouables(plateau, couleurQuiJoue);
        
        PosJouable_t *temp = noeud->liste_pos;
        //Si la liste des positions jouable est null, le joueur en question est donc bloque
        if(!temp){
            printf("Je suis bloqué ...\n");
            switch (couleurQuiJoue) {
                case NOIR:
                    noeud->JoueurBloque = Construire_arbre(plateau, prof-1, BLANC);
                    break;
                case BLANC:
                    noeud->JoueurBloque = Construire_arbre(plateau, prof-1, NOIR);
                    break;
                default:
                    printf("Il y a une erreur dans Construire_ArbreMiMa.C");
                    break;
            }
        }
        else {
            printf("Listes des positions jouables : \n");
            Afficher_lPosJouables(temp);
            while (temp) {
                int copie_tab[H][H];
                Copier_plateau(copie_tab, plateau);
                Jouer_pion(copie_tab, temp->i, temp->j, couleurQuiJoue);
                switch (couleurQuiJoue) {
                    case NOIR:
                        temp->Nd = Construire_arbre(copie_tab, prof - 1, BLANC);
                        break;
                    case BLANC:
                        temp->Nd = Construire_arbre(copie_tab, prof - 1, NOIR);
                        break;
                    default:
                        printf("Il y a une erreur dans Construire_ArbreMiMa.C");
                        break;
                }
                temp = temp->suiv;
            }
        }
        
    return noeud;
    }

int MinMax(NdMiMa_t *arbre, int plateau[H][H], int (*EvaluerPlateau)(int plateau[H][H]))
    {
    /*A Completer*/
    int min = 0;
    return min;
    }

int MeilleurPos(NdMiMa_t *arbre, int plateau[H][H], int (*EvaluerPlateau)(int plateau[H][H]),int *pi, int *pj)
    {
    *pi = 0;
    *pj = 0;

    /*A Completer*/
    return 0;
    }

NdMiMa_t *Detruire_arbre(NdMiMa_t *arbre)
    {
    if (arbre)
        {
        Detruire_liste(arbre->liste_pos);
        free(arbre);
        }
    return NULL;
    }

