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
    
    int plateau[H][H];
    
    Initialiser_plateau(plateau);
    Afficher_plateau_text(plateau);
    
    return 0;
}
