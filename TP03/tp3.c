#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"


/*==============  FONCTIONS DEMANDEES ===============*/

// 1.	Ecrire une fonction qui permet de remplir une matrice creuse
void remplirMatrice(matrice_creuse *m, int N, int M) {
    /*
    * TO DO : Ecrire ici votre code
    */
    struct Element *elem;
    int valeur;
    element* temp;

    for (int i=0; i<N; i++){
        printf("\nLigne %d:\n", i);
        liste_ligne *current = m[i];
        for (int j=0; j<M; j++) {
            if (current->col!=j){
                printf("\nColonne %d:\n", i);
                scanf("%d", &elem);
                if (valeur!=0) {
                    elem = (element*)malloc(sizeof(element));
                    elem->col = j;
                    elem->val = valeur;
                }
            }
            current = current->suivant;

        }
    }
}



// 2.	Ecrire une fonction qui permet d�afficher une matrice creuse sous forme de tableau
void afficherMatrice(matrice_creuse m){
    /*
    * TO DO : Ecrire ici votre code
    */
}



// 3.	Ecrire une fonction qui permet d�afficher toutes les listes cha�n�es
void afficherMatriceListes(matrice_creuse m) {
    /*
    * TO DO : Ecrire ici votre code
    */
}



//  4.	Ecrire une fonction qui renvoie la valeur de l'�l�ment de la ligne i et la colonne j
int rechercherValeur(matrice_creuse m, int i, int j) {
    int result = 0;
    /*
    * TO DO : Ecrire ici votre code
    */
    return result;
}



// 5.	Ecrire une fonction qui affecte une valeur donn�e � l'�l�ment de la ligne i et la colonne j
void affecterValeur(matrice_creuse m, int i, int j, int val) {
    /*
    * TO DO : Ecrire ici votre code
    */
}



// 6.	Ecrire une fonction qui r�alise la somme de deux matrices
void additionerMatrices(matrice_creuse m1, matrice_creuse m2) {
    /*
    * TO DO : Ecrire ici votre code
    */
}



// 7.	Ecrire une fonction qui retourne le nombre d�octets gagn�s
int nombreOctetsGagnes(matrice_creuse m) {
    int result = 0;
    /*
    * TO DO : Ecrire ici votre code
    */
    return result;
}



/*==============  FONCTIONS SUPPLEMENTAIRES ===============*/

// fonction qui renvoie un nouvel �l�ment de liste
element *creerElement(int colonne, int valeur) {
    element *nouvelElement = malloc(sizeof(element));
    nouvelElement->col = colonne;
    nouvelElement->val = valeur;
    nouvelElement->suivant = NULL;
    return nouvelElement;
}


// fonction qui permet de vider le buffer d'entr�e clavier
void viderBuffer (){
    char c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
