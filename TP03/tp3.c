#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"


/*==============  FONCTIONS DEMANDEES ===============*/

// 1.	Ecrire une fonction qui permet de remplir une matrice creuse
void remplirMatrice(matrice_creuse *m, int N, int M) {
    int val;

    m->tab_lignes = (matrice_creuse *) malloc(sizeof(element) * N);

    m->Nlignes = N;
    m->Ncolonnes = M;

    for(int i = 0; i < N; i++){
        m->tab_lignes[i] = NULL;
    }

    for(int i = 0; i < N; i++){

        for(int j = 0; j < M; j++){
            printf("Donnez la valeur en %d,%d : ", i,j);
            scanf("%d", &val);

            if(val != 0){
                element * newEl = creerElement(j,val);

                if(m->tab_lignes[i] == NULL){
                    m->tab_lignes[i] = newEl;
                }
                else{
                    element * current = m->tab_lignes[i];

                    while(current->suivant){
                        current = current->suivant;
                    }
                    current->suivant = newEl;
                }
            }

        }

    }
}




// 2.	Ecrire une fonction qui permet d’afficher une matrice creuse sous forme de tableau
void afficherMatrice(matrice_creuse m){
    for(int i = 0; i < m.Nlignes; i++){

        element * current =  m.tab_lignes[i];

        if(current == NULL){
            for(int j = 0; j < m.Ncolonnes; j++){
                printf("0 ");
            }
        }
        else{
            element * old = current;
            current = current->suivant;

            for(int j = 0; j < old->col; j++){
                printf("0 ");
            }

            while (current){
                printf("%d ", old->val);

                for(int j = 0; j < current->col - old->col - 1; j++){
                    printf("0 ");
                }


                old = current;
                current = current->suivant;

                }

            printf("%d ", old->val);

            if(old->col < m.Ncolonnes){
                for(int j = 0; j < m.Ncolonnes - old->col - 1; j++){
                    printf("0 ");
                    }
                }
            }

            printf("\n");
        }

    }



// 3.	Ecrire une fonction qui permet d’afficher toutes les listes chaînées
void afficherMatriceListes(matrice_creuse m) {
    /*
    * TO DO : Ecrire ici votre code
    */
}



//  4.	Ecrire une fonction qui renvoie la valeur de l'élément de la ligne i et la colonne j
int rechercherValeur(matrice_creuse m, int i, int j) {
    int result = 0;
    /*
    * TO DO : Ecrire ici votre code
    */
    return result;
}



// 5.	Ecrire une fonction qui affecte une valeur donnée à l'élément de la ligne i et la colonne j
void affecterValeur(matrice_creuse m, int i, int j, int val) {
    /*
    * TO DO : Ecrire ici votre code
    */
}



// 6.	Ecrire une fonction qui réalise la somme de deux matrices
void additionerMatrices(matrice_creuse m1, matrice_creuse m2) {
    /*
    * TO DO : Ecrire ici votre code
    */
}



// 7.	Ecrire une fonction qui retourne le nombre d’octets gagnés
int nombreOctetsGagnes(matrice_creuse m) {
    int result = 0;
    /*
    * TO DO : Ecrire ici votre code
    */
    return result;
}



/*==============  FONCTIONS SUPPLEMENTAIRES ===============*/

// fonction qui renvoie un nouvel élément de liste
element *creerElement(int colonne, int valeur) {
    element *nouvelElement = malloc(sizeof(element));
    nouvelElement->col = colonne;
    nouvelElement->val = valeur;
    nouvelElement->suivant = NULL;
    return nouvelElement;
}


// fonction qui permet de vider le buffer d'entrée clavier
void viderBuffer (){
    char c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
