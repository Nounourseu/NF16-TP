#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"


/*==============  FONCTIONS DEMANDEES ===============*/

// 1.	Ecrire une fonction qui permet de remplir une matrice creuse
void remplirMatrice(matrice_creuse *m, int N, int M) {
    int val;

    if(m == NULL){
        m = (matrice_creuse *) malloc(sizeof (matrice_creuse));
    }

    m->tab_lignes = (liste_ligne*) malloc(sizeof(liste_ligne) * N);

    m->Nlignes = N;
    m->Ncolonnes = M;

    for(int i = 0; i < N; i++){
        m->tab_lignes[i] = NULL;
    }

    for(int i = 0; i < N; i++){
        element * current = m->tab_lignes[i];
        for(int j = 0; j < M; j++){
            printf("Donnez la valeur en %d,%d : ", i,j);
            scanf("%d", &val);

            if(val != 0){
                element * newEl = creerElement(j,val);

                if(current == NULL){
                    m->tab_lignes[i] = newEl;
                }
                else{
                    current->suivant = newEl;
                }
                current = newEl;
            }

        }

    }
}




// 2.	Ecrire une fonction qui permet d’afficher une matrice creuse sous forme de tableau
void afficherMatrice(matrice_creuse m){
    for(int i = 0; i < m.Nlignes; i++){

        element * current =  m.tab_lignes[i];

        //Si la ligne est vide j'affiche que des 0
        if(current == NULL){
            for(int j = 0; j < m.Ncolonnes; j++){
                printf("0 ");
            }
        }
        else{
            element * old = current;
            current = current->suivant;

            //Affiche les 0 avant le premier element de la liste chainée
            for(int j = 0; j < old->col; j++){
                printf("0 ");
            }

            while (current){
                //afficher la valeur de old
                printf("%d ", old->val);

                //Si les colonnes ne se succedent pas c'est qu'il faut ajouter des 0
                for(int j = 0; j < current->col - old->col - 1; j++){
                    printf("0 ");
                }


                old = current;
                current = current->suivant;

                }

            printf("%d ", old->val);

            //Afficher les 0 apres le dernier element s'il y a
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
    for(int i = 0; i < m.Nlignes; i++){
        element * current = m.tab_lignes[i];
        printf("\ni=%d ", i);
        while(current!=NULL){
            printf("-> [val=%d, col=%d] ", current->val, current->col);
            current = current->suivant;
        }
        printf("\n");
    }
}



//  4.	Ecrire une fonction qui renvoie la valeur de l'élément de la ligne i et la colonne j
int rechercherValeur(matrice_creuse m, int i, int j) {
    int result = 0;

    element* elem = m.tab_lignes[i];

    while (elem!=NULL && elem->col<j) {
        elem = elem->suivant;
    }
    if (elem!=NULL && elem->col==j) {
        result = elem->val;
    }

    return result;
}



// 5.	Ecrire une fonction qui affecte une valeur donnée à l'élément de la ligne i et la colonne j
void affecterValeur(matrice_creuse m, int i, int j, int val) {

    if(i >= m.Nlignes || j >= m.Ncolonnes){
        printf("outOfRange");
        return;
    }

    if(val == 0){
        element * current = m.tab_lignes[i];
        element * old = NULL;

        int done = 1;

        while(current && done){
            //Si j'ai à remplacer une valeur je le fais
            if(current->col == j){

                if(old == NULL){
                    m.tab_lignes[i] = current->suivant;
                }
                else{
                    old->suivant = current->suivant;
                }

                free(current);
                current = NULL;
                done = 0;
            }
            else{
                old = current;
                current = current->suivant;
            }
        }
    }
    //Si c'est pas un 0
    else{
        //Si la ligne est vide, je mets le nouvel élément avec la valeur
        if(m.tab_lignes[i] == NULL){
            m.tab_lignes[i] = creerElement(j,val);
        }
        else{
            element * current = m.tab_lignes[i];
            element * old = NULL;

            int done = 1;

            while(current && done){
                //S'il faut ecraser une valeur
                if(current->col == j){
                    current->val = val;
                    done = 0;
                }
                //Si il faut inserer une valeur
                else if(current->col > j){
                    element * newEl = creerElement(j,val);

                    //Si c'est au début
                    if(old != NULL){
                        old->suivant = newEl;
                        newEl->suivant = current;
                    }
                    else{
                        newEl->suivant = current;
                        m.tab_lignes[i] = newEl;
                    }
                    done = 0;
                }
                else{
                    old = current;
                    current = current->suivant;
                }

            }

            //Si je suis arrivé à la fin de la liste
            if((old != NULL) && old->col < j){
                element * newEl = creerElement(j,val);
                old->suivant = newEl;
            }
        }
    }




}



// 6.	Ecrire une fonction qui réalise la somme de deux matrices
void additionerMatrices(matrice_creuse m1, matrice_creuse m2) {

    element* current1;
    element* current2;
    element* previous1;

    for (int i=0; i<m1.Nlignes; i++) {
        current1 = m1.tab_lignes[i];
        current2 = m2.tab_lignes[i];
        previous1 = NULL;

        while(current1!=NULL && current2!=NULL) {

            if (current1->col == current2->col) {
                //On additionne les deux valeurs, si le résultat est nul on supprime l'element.

                current1->val += current2->val;

                if (current1->val == 0) {
                //On supprime current1 si la somme est nulle

                    if (previous1 == NULL) {
                        m1.tab_lignes[i] = current1->suivant;
                    }
                    else {
                        previous1->suivant = current1->suivant;
                    }
                    element* supr = current1;
                    current1 = current1->suivant;
                    free(supr);
                }
                else {
                    previous1 = current1;
                    current1 = current1->suivant;
                }

                current2 = current2->suivant;
            }
            else if (current1->col > current2->col) {
                //On ajoute current2 devant current1.

                element* newNode = creerElement(current2->col, current2->val);
                newNode->suivant = current1;

                if (previous1==NULL) {
                //Cas où current1 est le premier element de la liste
                    m1.tab_lignes[i] = newNode;
                }
                else {
                    previous1->suivant = newNode;
                }

                previous1 = previous1->suivant;
                current2 = current2->suivant;

            }
            else {
            //Cas où current1->col < current2->col
                previous1 = current1;
                current1 = current1->suivant;
            }

        }

        if (current1 == NULL) {
        //On ajoute les elements restants de la liste 2 à la liste 1

            if (previous1==NULL) {
            //Si la liste 1 est vide, on crée son premier element

                m1.tab_lignes[i] = creerElement(current2->col, current2->val);
                previous1 = m1.tab_lignes[i];
                current1 = previous1->suivant;
                current2 = current2->suivant;
            }
            while(current2!=NULL) {
                previous1->suivant = creerElement(current2->col, current2->val);

                previous1 = previous1->suivant;
                current2 = current2->suivant;
            }
        }

    }

}



// 7.	Ecrire une fonction qui retourne le nombre d’octets gagnés
int nombreOctetsGagnes(matrice_creuse m) {
    /* JSP SI J'AI LE BON RESULTAT*/
    int tailleTab = m.Ncolonnes * m.Nlignes * sizeof(int);

    int tailleMat = sizeof(m) + m.Nlignes * sizeof(liste_ligne*);

    int nb_elem = 0;

    for (int i=0; i<m.Nlignes; i++) {
        element* current = m.tab_lignes[i];
        while (current!=NULL) {
            nb_elem+=1;
            current = current->suivant;
        }
    }

    tailleMat+= nb_elem*sizeof(element);

    return tailleTab - tailleMat;
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
