//
//  main.c
//  Projet_IA_SUHANA_SOMOULAYLAK
//
//  Created by Sutra Suhana on 14/02/2020.
//  Copyright © 2020 Sutra Suhana. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Othello.h"
#include "Affichage.h"
#include "ArbreMiMa.h"

int main(int argc, const char * argv[]) {
    
    int joueurCourant = NOIR; //Toujours le noir commence
    int plateau[H][H];
    
    char Mmode[20];
    int mode;
    int NbN = 2, NbB = 2;
    PosJouable_t *listeJouable;
    
    int i, j;
    char ii[20];
    char jj[20];
    int Niveau[2];
    
    Initialiser_plateau(plateau);
    do {
        printf("Quelle mode de jeu voulez vous choisir ? ");
        scanf("%s",Mmode);
        mode = (int) strtol(Mmode,NULL ,0);
    } while (mode < 0 || mode > 1);
    
    Dessine_plateau_graph(plateau, joueurCourant);
    
    if (mode == 1) {
        NdMiMa_t *arbre = Construire_arbre(plateau, 2, joueurCourant);
        MinMax(arbre, plateau, EvaluerPlateau_0);

    }
    else {
    while (Partie_terminee(plateau) == 0)
    {
        printf("SCORE : NOIR * : %d  BLANC O : %d | ",NbN,NbB);
        printf("C'est au tour de ");
        printf(joueurCourant == NOIR ? "NOIR *" : "BLANC O");
        printf(" de jouer\n");
        
        if((listeJouable = Trouver_liste_pos_jouables(plateau, joueurCourant))){
            if(mode == 0 ) //|| ( mode == 1 && joueurCourant==NOIR)
            {
                do
                {
//                    Afficher_lPosJouables(listeJouable);
                    printf("--------------------\n");
                    do
                    {
                        printf("Ligne de la case : ");
                        scanf("%s",(ii));
                        printf("Colonne de la case : ");
                        scanf("%s",(jj));
                        i = (int) strtol(ii, NULL, 0);

                        j = (int) strtol(jj, NULL, 0);


                        
                    } while( ((0 > i) || (i >= H)) || ((0 > j) || (j >= H)));
                    
                } while (!Est_dans_liste(listeJouable, i , j));
            }
        }
        
        Jouer_pion(plateau, i, j, joueurCourant);
        Nb_pions(plateau,&NbN,&NbB);
        Dessine_plateau_graph(plateau, joueurCourant);
        listeJouable = Detruire_liste(listeJouable);
        
        joueurCourant = Autre_joueur(joueurCourant);
    }
    
    Nb_pions(plateau, &NbN, &NbB);
    printf("Partie terminee !!! \n");
    if (NbN > NbB)
      printf("Les noirs ont gagne par %d contre %d\n", NbN, NbB);
    else
      {
      if (NbN == NbB)
        printf("Ex-aequo par %d contre %d\n", NbN, NbB);
      else
        printf("Les blancs ont gagne par %d contre %d\n", NbB, NbN);
      }
        
    }
    return 0;
}
