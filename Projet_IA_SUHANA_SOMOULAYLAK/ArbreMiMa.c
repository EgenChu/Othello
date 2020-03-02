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
    for(i = 0; i < H;i++){
        for(j = 0;j<H;j++){
            if (plateau[i][j] == NOIR) {
                res++;
                //                    printf("H");
            }
            else if(plateau[i][j] == BLANC){
                res--;
                //                    printf("E");
            }
        }
    }
    return res;
}

NdMiMa_t *Construire_arbre(int plateau[H][H], int prof, int couleurQuiJoue)
{
    if(prof <= 0 || Partie_terminee(plateau)) return NULL;
    
    //        printf("=== PROFONDEUR %d ===\n", prof);
    //        printf("Couleur qui joue : ");
    //        switch (couleurQuiJoue) {
    //            case NOIR:
    //                printf("NOIR\n");
    //                break;
    //
    //            case BLANC:
    //                printf("BLANC\n");
    //                break;
    //        }
    
    NdMiMa_t *noeud = malloc(sizeof(NdMiMa_t));
    noeud->Couleur = couleurQuiJoue;
    noeud->liste_pos = Trouver_liste_pos_jouables(plateau, couleurQuiJoue);
    
    PosJouable_t *temp = noeud->liste_pos;
    //Si la liste des positions jouable est null, le joueur en question est donc bloque
    if(!temp){
        //            printf("Je suis bloqué ...\n");
        switch (couleurQuiJoue) {
            case NOIR:
                noeud->JoueurBloque = Construire_arbre(plateau, prof-1, BLANC);
                printf("Le joueur Noir est bloqué");
                break;
            case BLANC:
                noeud->JoueurBloque = Construire_arbre(plateau, prof-1, NOIR);
                printf("Le joueur Blanc est bloqué");
                break;
            default:
                printf("Il y a une erreur dans Construire_ArbreMiMa.C");
                break;
        }
    }
    else {
        //            printf("Listes des positions jouables : \n");
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
    int min;
    int max;
    int eval;
    //        printf(arbre == NULL ? "OUI NULL\n" : "NON PAS NULL\n");
    PosJouable_t *temp = arbre->liste_pos;
    Afficher_lPosJouables(temp);
    
    if(arbre->Couleur == NOIR){
        max = -1000;
        while(temp){
            int copie_tab[H][H];
            Copier_plateau(copie_tab, plateau);
            //                printf("(NOIR) on evalue : %d,%d\n",temp->i,temp->j);
            //                printf(temp->suiv ? "Oui\n" : "Non\n");
            Jouer_pion(copie_tab, temp->i, temp->j, arbre->Couleur);
            if(temp->Nd) {
                eval = MinMax(temp->Nd, copie_tab, *EvaluerPlateau);
                max = MAX(eval, max);
                //              printf("max : %d\n",max);
            }
            else {
                //                    printf("%d\n",EvaluerPlateau(plateau));
                eval = EvaluerPlateau(copie_tab);
                max = MAX(eval, max);
            }
            temp = temp->suiv;
        }
        //            printf("Je suis sortie !!\n");
        return max;
    }
    else {
        min = 1000;
        while(temp){
            int copie_tab[H][H];
            Copier_plateau(copie_tab, plateau);
            //                printf("(BLANC) on evalue : %d,%d\n",temp->i,temp->j);
            Jouer_pion(copie_tab, temp->i, temp->j, arbre->Couleur);
            if(temp->Nd) {
                eval = MinMax(temp->Nd, copie_tab, *EvaluerPlateau);
                min = MAX(eval, min);
                //              printf("min : %d",min);
            }
            else{
                //                    printf("%d\n",EvaluerPlateau(plateau));
                eval = EvaluerPlateau(copie_tab);
                min = MAX(eval, min);
            }
            temp = temp->suiv;
        }
        //            printf("Je suis sortie d'un fils!! \n");
        return min;
    }
}

int MeilleurPos(NdMiMa_t *arbre, int plateau[H][H], int (*EvaluerPlateau)(int plateau[H][H]),int *pi, int *pj)
{
    *pi = 0;
    *pj = 0;
    
    int min;
    int max;
    int eval;
    
    PosJouable_t *temp = arbre->liste_pos;
    
    if(arbre->Couleur == NOIR){
        max = -1000;
        while(temp){
            eval = MinMax(temp->Nd, plateau, EvaluerPlateau);
            if(eval > max) {
                max = eval;
                *pi = temp->i;
                *pj = temp->j;
            }
            temp = temp->suiv;
        }
        return max;
    }
    else {
        min = 1000;
        while(temp){
            eval = MinMax(temp->Nd, plateau, EvaluerPlateau);
            if(eval < min) {
                min = eval;
                *pi = temp->i;
                *pj = temp->j;
            }
            temp = temp->suiv;
        }
        return min;
    }
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

