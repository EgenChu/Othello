//
//  main.c
//  Projet_IA_SUHANA_SOMOULAYLAK
//
//  Created by Sutra Suhana on 14/02/2020.
//  Copyright © 2020 Sutra Suhana. All rights reserved.
//

#include <stdio.h>
#include "Othello.h"
#include "Affichage.h"

int main(int argc, const char * argv[]) {
    
    int joueurCourant = NOIR; //Toujours le noir commence
    int plateau[H][H];
    
    int Mode = 0;
    int NbN, NbB;
    PosJouable_t *listeJouable;
    
    int i, j;
    int Niveau[2];
    
    Initialiser_plateau(plateau);
    printf("Quelle mode de jeu voulez vous choisir ? ");
    scanf("%d",&Mode);
    
    Dessine_plateau_graph(plateau, joueurCourant);
    
    while (Partie_terminee(plateau) == 0)
    {
        printf("C'est au tour de ");
        printf(joueurCourant == NOIR ? "NOIR *" : "BLANC O");
        printf(" de jouer\n");
        
        if((listeJouable = Trouver_liste_pos_jouables(plateau, joueurCourant))){
            if(Mode == 0 || ( Mode == 1 && joueurCourant==NOIR))
            {
                do
                {
                    Afficher_lPosJouables(listeJouable);
                    printf("--------------------\n");
                    printf("Ligne de la case : ");
                    scanf("%d",&i);
                    printf("Colonne de la case : ");
                    scanf("%d",&j);
                    
                } while (!Est_dans_liste(listeJouable, i , j));
            }
        }
        
        Jouer_pion(plateau, i, j, joueurCourant);
        Dessine_plateau_graph(plateau, joueurCourant);
        listeJouable = Detruire_liste(listeJouable);
        
        Afficher_lPosJouables(listeJouable);
        joueurCourant = Autre_joueur(joueurCourant);
    }
    
    
    return 0;
}
