#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"

int main() {


    matrice_creuse m1;
    m1.tab_lignes = NULL;
    matrice_creuse m2;
    m2.tab_lignes = NULL;

    // ============= MENU UTILISATEUR ============= */
    char choix = '0';
    while (choix != '8') {
        printf("\n======================================");
        printf("\n1. Remplir une matrice creuse");
        printf("\n2. Afficher une matrice creuse sous forme de tableau");
        printf("\n3. Afficher une matrice creuse sous forme de listes");
        printf("\n4. Donner la valeur d'un element d'une matrice creuse");
        printf("\n5. Affecter une valeur � un �l�ment d�une matrice creuse");
        printf("\n6. Additionner deux matrices creuses");
        printf("\n7. Calculer le gain");
        printf("\n8. Quitter");
        printf("\n======================================");
        printf("\n   Votre choix ? ");
        choix = getchar();
        char sousChoix;
        int i,j;

        switch (choix) {
            case '1' :
                printf("Matrice 1 ou matrice 2 (rentrez 1 ou 2) : ");
                viderBuffer();
                sousChoix = getchar();

                int N, M;
                switch (sousChoix) {
                    case '1' : printf("\n\nVeuillez donner la taille de votre matrice\n");

                        printf("Nombre de lignes : ");
                        scanf("%d", &N);
                        printf("\nNombre de colonnes : ");
                        scanf("%d", &M);
                        printf("\n");

                        remplirMatrice(&m1,N,M);

                        printf("Matrice remplie");
                        break;
                    case '2':
                        printf("\n\nVeuillez donner la taille de votre matrice\n");
                        printf("Nombre de lignes : ");
                        scanf("%d", &N);
                        printf("\nNombre de colonnes : ");
                        scanf("%d", &M);
                        printf("\n");

                        remplirMatrice(&m2,N,M);

                        printf("Matrice remplie");
                        break;
                    default:
                        printf("Ce numero n'est pas valide\n");
                        break;
                }


                break;

            case '2' :
                printf("Matrice 1 ou matrice 2 (rentrez 1 ou 2) : ");
                viderBuffer();
                sousChoix = getchar();

                switch (sousChoix) {
                    case '1' :
                        if(m1.tab_lignes == NULL){
                            printf("Veuillez d'abord remplir la matrice 1\n");
                        }
                        else{
                            printf("Voici votre matrice\n");
                            afficherMatrice(m1);
                        }
                        break;
                    case '2':
                        if(m2.tab_lignes == NULL){
                            printf("Veuillez d'abord remplir la matrice 2\n");
                        }
                        else{
                            printf("Voici votre matrice\n");
                            afficherMatrice(m2);
                        }
                        break;
                    default:
                        printf("Ce numero n'est pas valide\n");
                        break;
                }


                break;

            case '3' :
                printf("Matrice 1 ou matrice 2 (rentrez 1 ou 2) : ");
                viderBuffer();
                sousChoix = getchar();

                switch (sousChoix) {
                    case '1' :
                        if(m1.tab_lignes == NULL){
                            printf("Veuillez d'abord remplir la matrice 1\n");
                        }
                        else{
                            printf("Voici votre matrice\n");
                            afficherMatriceListes(m1);
                        }
                        break;
                    case '2':
                        if(m2.tab_lignes == NULL){
                            printf("Veuillez d'abord remplir la matrice 2\n");
                        }
                        else{
                            printf("Voici votre matrice\n");
                            afficherMatriceListes(m2);
                        }
                        break;
                    default:
                        printf("Ce numero n'est pas valide\n");
                        break;
                }
                break;

            case '4' :
                printf("Matrice 1 ou matrice 2 (rentrez 1 ou 2) : ");
                viderBuffer();
                sousChoix = getchar();

                switch (sousChoix) {
                    case '1' :
                        if(m1.tab_lignes == NULL){
                            printf("Veuillez d'abord remplir la matrice 1\n");
                        }
                        else{
                            printf("Quelle est la position de l'element que vous voulez\n");
                            printf("Ligne : ");
                            scanf("%d", &i);

                            printf("\nColonne : ");
                            scanf("%d", &j);
                            printf("\n");

                            if (i>m1.Nlignes || j>m1.Ncolonnes) {
                                printf("\nErreur : ligne ou colonne invalide\n");
                            }

                            printf("Voici votre element : %d", rechercherValeur(m1,i,j));
                        }
                        break;
                    case '2':
                        if(m2.tab_lignes == NULL){
                            printf("Veuillez d'abord remplir la matrice 2\n");
                        }
                        else{
                            printf("Quelle est la position de l'element que vous voulez\n");

                            printf("Ligne : ");
                            scanf("%d", &i);

                            printf("\nColonne : ");
                            scanf("%d", &j);
                            printf("\n");

                            if (i>m2.Nlignes || j>m2.Ncolonnes) {
                                printf("\nErreur : ligne ou colonne invalide\n");
                            }

                            printf("Voici votre element : %d", rechercherValeur(m2,i,j));
                        }
                        break;
                    default:
                        printf("Ce numero n'est pas valide\n");
                        break;
                }


                break;

            case '5' :

                printf("Matrice 1 ou matrice 2 (rentrez 1 ou 2) : ");
                viderBuffer();
                sousChoix = getchar();

                switch (sousChoix) {
                    case '1' :
                        if(m1.tab_lignes == NULL){
                            printf("Veuillez d'abord remplir la matrice 1\n");
                        }
                        else{
                            int val;
                            printf("Quel element voulez vous placer : ");
                            scanf("%d", &val);
                            printf("\nOu voulez vous le placer\n");
                            printf("Ligne : ");
                            scanf("%d", &i);
                            printf("\nColonne : ");
                            scanf("%d", &j);
                            printf("\n");

                            if (i>m1.Nlignes || j>m1.Ncolonnes) {
                                printf("\nErreur : ligne ou colonne invalide\n");
                            }

                            affecterValeur(m1,i,j,val);
                            printf("Element place\n");
                        }
                        break;
                    case '2':
                        if(m2.tab_lignes == NULL){
                            printf("Veuillez d'abord remplir la matrice 2\n");
                        }
                        else{
                            int val;
                            printf("Quel element voulez vous placer : ");
                            scanf("%d", &val);
                            printf("\nOu voulez vous le placer\n");
                            printf("Ligne : ");
                            scanf("%d", &i);
                            printf("\nColonne : ");
                            scanf("%d", &j);
                            printf("\n");

                            if (i>m2.Nlignes || j>m2.Ncolonnes) {
                                printf("\nErreur : ligne ou colonne invalide\n");
                            }

                            affecterValeur(m2,i,j,val);
                            printf("Element place\n");
                        }
                        break;
                    default:
                        printf("Ce numero n'est pas valide\n");
                        break;
                }

                break;

            case '6' :
                printf("\n\nAddition de deux matrices creuses\n\n");

                if(m1.tab_lignes == NULL){
                    printf("Veuillez d'abord remplir la matrice 1\n");
                }
                else if(m2.tab_lignes == NULL){
                    printf("Veuillez d'abord remplir la matrice 2\n");
                }
                else if(m1.Nlignes != m2.Nlignes || m1.Ncolonnes != m2.Ncolonnes){
                    printf("Addition non possible, taille des matrices differentes");
                }
                else {
                    printf("\n");
                    afficherMatrice(m1);
                    printf("\n  +\n\n");
                    afficherMatrice(m2);
                    printf("\n  =\n\n");

                    additionerMatrices(m1, m2);

                    afficherMatrice(m1);
                }
                break;

            case '7' :
                printf("Matrice 1 ou matrice 2 (rentrez 1 ou 2) : ");
                viderBuffer();
                sousChoix = getchar();

                switch (sousChoix) {
                    case '1' :
                        if(m1.tab_lignes == NULL){
                            printf("Veuillez d'abord remplir la matrice 1\n");
                        }
                        else{
                            printf("Octets gagnes : %d", nombreOctetsGagnes(m1));
                        }
                        break;
                    case '2':
                        if(m2.tab_lignes == NULL){
                            printf("Veuillez d'abord remplir la matrice 2\n");
                        }
                        else{
                            printf("Octets gagnes : %d", nombreOctetsGagnes(m2));
                        }
                        break;
                    default:
                        printf("Ce numero n'est pas valide\n");
                        break;
                }
                break;

            case '8' :
                printf("\n======== PROGRAMME TERMINE ========\n");
                break;

            default :
                printf("\n\nERREUR : votre choix n'est valide ! ");
        }
        printf("\n\n\n");
        viderBuffer();
    }

    return 0;
}
