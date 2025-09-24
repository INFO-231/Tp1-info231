#ifndef FONCTION_OPERATION_H
#define FONCTION_OPERATION_H

#include <stddef.h>

// Structures avec allocation dynamique
typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

typedef struct {
    int x, y, z;
} Vector;

typedef struct {
    int *data;
    int size;
} Tableau;

// Prototypes des fonctions
// Allocation et libération de mémoire
Matrix* creerMatrice(int rows, int cols);
void libererMatrice(Matrix *m);
Tableau* creerTableau(int size);
void libererTableau(Tableau *arr);

// Opérations sur matrices
void saisirMatrice(Matrix *m);
void afficherMatrice(Matrix *m);
Matrix* sommeMatrices(Matrix *m1, Matrix *m2);
Matrix* produitMatrices(Matrix *m1, Matrix *m2);

// Opérations sur tableaux
int rechercheSequentielle(Tableau *arr, int valeur);
int estTableauTrie(Tableau *arr);
float medianTableau(Tableau *arr);
void inverserTableau(Tableau *arr);

// Opérations mathématiques
int multiplication(int a, int b);
Vector* produitVectoriel(Vector *v1, Vector *v2);
Vector* produitVecteurMatrice(Vector *v, Matrix *m);

// Utilitaires
void afficherTableau(Tableau *arr);
void saisirTableau(Tableau *arr);
void copierTableau(const int *source, int *destination, int taille);

#endif