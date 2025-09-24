#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction_operation.h"

// Fonctions d'allocation de mémoire
Matrix* creerMatrice(int rows, int cols) {
    if(rows <= 0 || cols <= 0) return NULL;
    
    Matrix *m = (Matrix*)malloc(sizeof(Matrix));
    if(!m) return NULL;
    
    m->rows = rows;
    m->cols = cols;
    
    m->data = (int**)malloc(rows * sizeof(int*));
    if(!m->data) {
        free(m);
        return NULL;
    }
    
    for(int i = 0; i < rows; i++) {
        m->data[i] = (int*)malloc(cols * sizeof(int));
        if(!m->data[i]) {
            // Libérer la mémoire allouée précédemment en cas d'erreur
            for(int j = 0; j < i; j++) {
                free(m->data[j]);
            }
            free(m->data);
            free(m);
            return NULL;
        }
        // Initialiser à zéro
        memset(m->data[i], 0, cols * sizeof(int));
    }
    
    return m;
}

void libererMatrice(Matrix *m) {
    if(!m) return;
    
    if(m->data) {
        for(int i = 0; i < m->rows; i++) {
            if(m->data[i]) {
                free(m->data[i]);
            }
        }
        free(m->data);
    }
    free(m);
}

Tableau* creerTableau(int size) {
    if(size <= 0) return NULL;
    
    Tableau *arr = (Tableau*)malloc(sizeof(Tableau));
    if(!arr) return NULL;
    
    arr->data = (int*)malloc(size * sizeof(int));
    if(!arr->data) {
        free(arr);
        return NULL;
    }
    
    arr->size = size;
    memset(arr->data, 0, size * sizeof(int));
    
    return arr;
}

void libererTableau(Tableau *arr) {
    if(!arr) return;
    
    if(arr->data) {
        free(arr->data);
    }
    free(arr);
}

void saisirMatrice(Matrix *m) {
    if(!m || !m->data) {
        printf("Erreur: Matrice non initialisee!\n");
        return;
    }
    
    printf("Saisir les elements de la matrice %dx%d:\n", m->rows, m->cols);
    for(int i = 0; i < m->rows; i++) {
        for(int j = 0; j < m->cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &m->data[i][j]);
        }
    }
}

void afficherMatrice(Matrix *m) {
    if(!m || !m->data) {
        printf("Matrice non initialisee!\n");
        return;
    }
    
    for(int i = 0; i < m->rows; i++) {
        for(int j = 0; j < m->cols; j++) {
            printf("%4d", m->data[i][j]);
        }
        printf("\n");
    }
}

Matrix* sommeMatrices(Matrix *m1, Matrix *m2) {
    if(!m1 || !m2 || !m1->data || !m2->data) {
        printf("Erreur: Matrices non initialisees!\n");
        return NULL;
    }
    
    if(m1->rows != m2->rows || m1->cols != m2->cols) {
        printf("Erreur: Les matrices doivent avoir les memes dimensions!\n");
        return NULL;
    }
    
    Matrix *result = creerMatrice(m1->rows, m1->cols);
    if(!result) {
        printf("Erreur d'allocation memoire!\n");
        return NULL;
    }
    
    for(int i = 0; i < m1->rows; i++) {
        for(int j = 0; j < m1->cols; j++) {
            result->data[i][j] = m1->data[i][j] + m2->data[i][j];
        }
    }
    
    return result;
}

Matrix* produitMatrices(Matrix *m1, Matrix *m2) {
    if(!m1 || !m2 || !m1->data || !m2->data) {
        printf("Erreur: Matrices non initialisees!\n");
        return NULL;
    }
    
    if(m1->cols != m2->rows) {
        printf("Erreur: Nombre de colonnes de M1 doit egal nombre de lignes de M2!\n");
        return NULL;
    }
    
    Matrix *result = creerMatrice(m1->rows, m2->cols);
    if(!result) {
        printf("Erreur d'allocation memoire!\n");
        return NULL;
    }
    
    for(int i = 0; i < m1->rows; i++) {
        for(int j = 0; j < m2->cols; j++) {
            result->data[i][j] = 0;
            for(int k = 0; k < m1->cols; k++) {
                result->data[i][j] += m1->data[i][k] * m2->data[k][j];
            }
        }
    }
    
    return result;
}

int rechercheSequentielle(Tableau *arr, int valeur) {
    if(!arr || !arr->data) return -1;
    
    for(int i = 0; i < arr->size; i++) {
        if(arr->data[i] == valeur) {
            return i;
        }
    }
    return -1;
}

int estTableauTrie(Tableau *arr) {
    if(!arr || !arr->data || arr->size <= 1) return 1;
    
    int croissant = 1, decroissant = 1;
    
    for(int i = 1; i < arr->size; i++) {
        if(arr->data[i] < arr->data[i-1]) croissant = 0;
        if(arr->data[i] > arr->data[i-1]) decroissant = 0;
    }
    
    return croissant || decroissant;
}

float medianTableau(Tableau *arr) {
    if(!arr || !arr->data || arr->size == 0) return 0.0f;
    
    // Copie du tableau pour le tri
    int *copie = (int*)malloc(arr->size * sizeof(int));
    if(!copie) {
        printf("Erreur d'allocation memoire!\n");
        return 0.0f;
    }
    
    memcpy(copie, arr->data, arr->size * sizeof(int));
    
    // Tri par sélection
    for(int i = 0; i < arr->size-1; i++) {
        int min_idx = i;
        for(int j = i+1; j < arr->size; j++) {
            if(copie[j] < copie[min_idx]) min_idx = j;
        }
        int temp = copie[i];
        copie[i] = copie[min_idx];
        copie[min_idx] = temp;
    }
    
    float mediane;
    if(arr->size % 2 == 1) {
        mediane = (float)copie[arr->size/2];
    } else {
        mediane = (float)(copie[arr->size/2 - 1] + copie[arr->size/2]) / 2.0f;
    }
    
    free(copie);
    return mediane;
}

void inverserTableau(Tableau *arr) {
    if(!arr || !arr->data || arr->size <= 1) return;
    
    for(int i = 0; i < arr->size/2; i++) {
        int temp = arr->data[i];
        arr->data[i] = arr->data[arr->size - 1 - i];
        arr->data[arr->size - 1 - i] = temp;
    }
}

int multiplication(int a, int b) {
    if(a <= 0 || b <= 0) return 0;
    
    int result = 0;
    for(int i = 0; i < b; i++) {
        result += a;
    }
    return result;
}

Vector* produitVectoriel(Vector *v1, Vector *v2) {
    if(!v1 || !v2) return NULL;
    
    Vector *result = (Vector*)malloc(sizeof(Vector));
    if(!result) return NULL;
    
    result->x = v1->y * v2->z - v1->z * v2->y;
    result->y = v1->z * v2->x - v1->x * v2->z;
    result->z = v1->x * v2->y - v1->y * v2->x;
    
    return result;
}

Vector* produitVecteurMatrice(Vector *v, Matrix *m) {
    if(!v || !m || !m->data) return NULL;
    
    if(m->rows != 3 || m->cols != 3) {
        printf("Erreur: La matrice doit etre 3x3!\n");
        return NULL;
    }
    
    Vector *result = (Vector*)malloc(sizeof(Vector));
    if(!result) return NULL;
    
    result->x = v->x * m->data[0][0] + v->y * m->data[1][0] + v->z * m->data[2][0];
    result->y = v->x * m->data[0][1] + v->y * m->data[1][1] + v->z * m->data[2][1];
    result->z = v->x * m->data[0][2] + v->y * m->data[1][2] + v->z * m->data[2][2];
    
    return result;
}

void afficherTableau(Tableau *arr) {
    if(!arr || !arr->data) {
        printf("Tableau non initialise!\n");
        return;
    }
    
    for(int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

void saisirTableau(Tableau *arr) {
    if(!arr || !arr->data) {
        printf("Erreur: Tableau non initialise!\n");
        return;
    }
    
    printf("Saisir les %d elements:\n", arr->size);
    for(int i = 0; i < arr->size; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &arr->data[i]);
    }
}

void copierTableau(const int *source, int *destination, int taille) {
    if(!source || !destination) return;
    memcpy(destination, source, taille * sizeof(int));
}