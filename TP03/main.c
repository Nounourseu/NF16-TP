#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"

int main() {


    matrice_creuse * m = (matrice_creuse *) malloc(sizeof (matrice_creuse));
    m->tab_lignes = NULL;

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

        switch (choix) {
            case '1' :

                printf("\n\nVeuillez donner la taille de votre matrice\n");
                int N, M;
                printf("Nombre de lignes : ");
                scanf("%d", &N);
                printf("\nNombre de colonnes : ");
                scanf("%d", &M);
                printf("\n");

                remplirMatrice(m,N,M);

                printf("Matrice remplie");
                break;

            case '2' :
                if(m->tab_lignes == NULL){
                    printf("Veuillez d'abord remplir une matrice\n");
                }
                else{
                    printf("Voici votre matrice\n");
                    afficherMatrice(*m);
                }
                break;

            case '3' :
                if(m->tab_lignes == NULL){
                    printf("Veuillez d'abord remplir une matrice\n");
                }
                else{
                    printf("Voici votre matrice\n");
                    afficherMatriceListes(*m);
                }
                break;

            case '4' :
                if(m->tab_lignes == NULL){
                    printf("Veuillez d'abord remplir une matrice\n");
                }
                else{
                    printf("Quelle est la position de l'element que vous voulez\n");
                    int i = -1, j = -1;
                    printf("Ligne : ");
                    scanf("%d", &i);

                    printf("\nColonne : ");
                    scanf("%d", &j);
                    printf("\n");

                    if (i>m->Nlignes || j>m->Ncolonnes) {
                        printf("\nErreur : ligne ou colonne invalide\n");
                    }

                    printf("Voici votre element : %d", rechercherValeur(*m,i,j));
                }
                break;

            case '5' :
                if(m->tab_lignes == NULL){
                    printf("Veuillez d'abord remplir une matrice\n");
                }
                else{
                    int val;
                    printf("Quel element voulez vous placer : ");
                    scanf("%d", &val);
                    printf("\nOu voulez vous le placer\n");
                    int i,j;
                    printf("Ligne : ");
                    scanf("%d", &i);
                    printf("\nColonne : ");
                    scanf("%d", &j);
                    printf("\n");

                    if (i>m->Nlignes || j>m->Ncolonnes) {
                        printf("\nErreur : ligne ou colonne invalide\n");
                    }

                    affecterValeur(*m,i,j,val);
                    printf("Element place\n");
                }
                break;

            case '6' :
                printf("\n\nAddition de deux matrices creuses\n\n");
                matrice_creuse m1;
                matrice_creuse m2;

                printf("\nMatrice 1 :\n");
                remplirMatrice(&m1, 3, 3);


                printf("\nMatrice 2 :\n");
                remplirMatrice(&m2, 3, 3);

                printf("\n");
                afficherMatrice(m1);
                printf("\n  +\n\n");
                afficherMatrice(m2);
                printf("\n  =\n\n");

                additionerMatrices(m1, m2);

                afficherMatrice(m1);

                break;

            case '7' :
                if(m->tab_lignes == NULL){
                    printf("Veuillez d'abord remplir une matrice\n");
                }
                else{
                    printf("Octets gagnes : %d", nombreOctetsGagnes(*m));
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
