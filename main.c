#include <stdio.h>
#include <stdlib.h>
#include "fonction_operation.h"

void afficherMenuPrincipal() {
    printf("\n=== MENU PRINCIPAL - OPERATIONS MATHEMATIQUES ===\n");
    printf("1.  Somme de matrices\n");
    printf("2.  Produit de matrices\n");
    printf("3.  Recherche sequentielle dans un tableau\n");
    printf("4.  Multiplication a × b (avec additions uniquement)\n");
    printf("5.  Tester si un tableau est trie\n");
    printf("6.  Mediane d'un tableau\n");
    printf("7.  Inverser un tableau\n");
    printf("8.  Produit vectoriel\n");
    printf("9.  Produit vecteur × matrice\n");
    printf("10. Quitter\n");
    printf("Choix: ");
}

void operationSommeMatrices() {
    printf("\n=== SOMME DE MATRICES ===\n");
    int rows, cols;
    
    printf("Nombre de lignes: ");
    scanf("%d", &rows);
    printf("Nombre de colonnes: ");
    scanf("%d", &cols);
    
    if(rows <= 0 || cols <= 0) {
        printf("Dimensions invalides!\n");
        return;
    }
    
    Matrix *m1 = creerMatrice(rows, cols);
    Matrix *m2 = creerMatrice(rows, cols);
    Matrix *result = NULL;
    
    if(!m1 || !m2) {
        printf("Erreur d'allocation memoire!\n");
        if(m1) libererMatrice(m1);
        if(m2) libererMatrice(m2);
        return;
    }
    
    printf("Matrice 1:\n");
    saisirMatrice(m1);
    printf("Matrice 2:\n");
    saisirMatrice(m2);
    
    printf("\nMatrice 1:\n");
    afficherMatrice(m1);
    printf("Matrice 2:\n");
    afficherMatrice(m2);
    
    result = sommeMatrices(m1, m2);
    if(result) {
        printf("Resultat de la somme:\n");
        afficherMatrice(result);
        libererMatrice(result);
    }
    
    libererMatrice(m1);
    libererMatrice(m2);
}

void operationProduitMatrices() {
    printf("\n=== PRODUIT DE MATRICES ===\n");
    int rows1, cols1, rows2, cols2;
    
    printf("Matrice 1 - Lignes: ");
    scanf("%d", &rows1);
    printf("Matrice 1 - Colonnes: ");
    scanf("%d", &cols1);
    printf("Matrice 2 - Lignes: ");
    scanf("%d", &rows2);
    printf("Matrice 2 - Colonnes: ");
    scanf("%d", &cols2);
    
    if(rows1 <= 0 || cols1 <= 0 || rows2 <= 0 || cols2 <= 0) {
        printf("Dimensions invalides!\n");
        return;
    }
    
    if(cols1 != rows2) {
        printf("Erreur: Nombre de colonnes de M1 doit egal nombre de lignes de M2!\n");
        return;
    }
    
    Matrix *m1 = creerMatrice(rows1, cols1);
    Matrix *m2 = creerMatrice(rows2, cols2);
    Matrix *result = NULL;
    
    if(!m1 || !m2) {
        printf("Erreur d'allocation memoire!\n");
        if(m1) libererMatrice(m1);
        if(m2) libererMatrice(m2);
        return;
    }
    
    printf("Matrice 1:\n");
    saisirMatrice(m1);
    printf("Matrice 2:\n");
    saisirMatrice(m2);
    
    printf("\nMatrice 1:\n");
    afficherMatrice(m1);
    printf("Matrice 2:\n");
    afficherMatrice(m2);
    
    result = produitMatrices(m1, m2);
    if(result) {
        printf("Resultat du produit:\n");
        afficherMatrice(result);
        libererMatrice(result);
    }
    
    libererMatrice(m1);
    libererMatrice(m2);
}

void operationRechercheSequentielle() {
    printf("\n=== RECHERCHE SEQUENTIELLE ===\n");
    int taille, valeur, pos;
    
    printf("Taille du tableau: ");
    scanf("%d", &taille);
    
    if(taille <= 0) {
        printf("Taille invalide!\n");
        return;
    }
    
    Tableau *arr = creerTableau(taille);
    if(!arr) {
        printf("Erreur d'allocation memoire!\n");
        return;
    }
    
    saisirTableau(arr);
    printf("Tableau: ");
    afficherTableau(arr);
    
    printf("Valeur a rechercher: ");
    scanf("%d", &valeur);
    
    pos = rechercheSequentielle(arr, valeur);
    if(pos != -1) {
        printf("✓ Valeur %d trouvee a l'indice %d\n", valeur, pos);
    } else {
        printf("✗ Valeur %d non trouvee dans le tableau\n", valeur);
    }
    
    libererTableau(arr);
}

void operationMultiplicationAddition() {
    printf("\n=== MULTIPLICATION PAR ADDITION ===\n");
    int a, b;
    
    printf("Entrez a (positif): ");
    scanf("%d", &a);
    printf("Entrez b (positif): ");
    scanf("%d", &b);
    
    if(a <= 0 || b <= 0) {
        printf("Erreur: Les deux nombres doivent etre positifs!\n");
        return;
    }
    
    int resultat = multiplication(a, b);
    printf("%d × %d = %d\n", a, b, resultat);
    printf("Verification: %d × %d = %d\n", a, b, a * b);
}

void operationTestTableauTrie() {
    printf("\n=== TEST TABLEAU TRIE ===\n");
    int taille;
    
    printf("Taille du tableau: ");
    scanf("%d", &taille);
    
    if(taille <= 0) {
        printf("Taille invalide!\n");
        return;
    }
    
    Tableau *arr = creerTableau(taille);
    if(!arr) {
        printf("Erreur d'allocation memoire!\n");
        return;
    }
    
    saisirTableau(arr);
    printf("Tableau: ");
    afficherTableau(arr);
    
    if(estTableauTrie(arr)) {
        printf("✓ Le tableau est trie\n");
    } else {
        printf("✗ Le tableau n'est pas trie\n");
    }
    
    libererTableau(arr);
}

void operationMedianeTableau() {
    printf("\n=== MEDIANE D'UN TABLEAU ===\n");
    int taille;
    
    printf("Taille du tableau: ");
    scanf("%d", &taille);
    
    if(taille <= 0) {
        printf("Taille invalide!\n");
        return;
    }
    
    Tableau *arr = creerTableau(taille);
    if(!arr) {
        printf("Erreur d'allocation memoire!\n");
        return;
    }
    
    saisirTableau(arr);
    printf("Tableau original: ");
    afficherTableau(arr);
    
    float mediane = medianTableau(arr);
    printf("Mediane: %.2f\n", mediane);
    
    libererTableau(arr);
}

void operationInverserTableau() {
    printf("\n=== INVERSION DE TABLEAU ===\n");
    int taille;
    
    printf("Taille du tableau: ");
    scanf("%d", &taille);
    
    if(taille <= 0) {
        printf("Taille invalide!\n");
        return;
    }
    
    Tableau *arr = creerTableau(taille);
    if(!arr) {
        printf("Erreur d'allocation memoire!\n");
        return;
    }
    
    saisirTableau(arr);
    printf("Tableau original: ");
    afficherTableau(arr);
    
    inverserTableau(arr);
    printf("Tableau inverse:  ");
    afficherTableau(arr);
    
    libererTableau(arr);
}

void operationProduitVectoriel() {
    printf("\n=== PRODUIT VECTORIEL ===\n");
    Vector v1, v2;
    
    printf("Vecteur 1 (x y z): ");
    scanf("%d %d %d", &v1.x, &v1.y, &v1.z);
    printf("Vecteur 2 (x y z): ");
    scanf("%d %d %d", &v2.x, &v2.y, &v2.z);
    
    printf("Vecteur 1: (%d, %d, %d)\n", v1.x, v1.y, v1.z);
    printf("Vecteur 2: (%d, %d, %d)\n", v2.x, v2.y, v2.z);
    
    Vector *result = produitVectoriel(&v1, &v2);
    if(result) {
        printf("Produit vectoriel: (%d, %d, %d)\n", result->x, result->y, result->z);
        free(result);
    } else {
        printf("Erreur lors du calcul du produit vectoriel!\n");
    }
}

void operationProduitVecteurMatrice() {
    printf("\n=== PRODUIT VECTEUR × MATRICE ===\n");
    Vector v;
    Matrix *m = creerMatrice(3, 3);
    
    if(!m) {
        printf("Erreur d'allocation memoire!\n");
        return;
    }
    
    printf("Vecteur (x y z): ");
    scanf("%d %d %d", &v.x, &v.y, &v.z);
    
    printf("Matrice 3x3:\n");
    saisirMatrice(m);
    
    printf("Vecteur: (%d, %d, %d)\n", v.x, v.y, v.z);
    printf("Matrice:\n");
    afficherMatrice(m);
    
    Vector *result = produitVecteurMatrice(&v, m);
    if(result) {
        printf("Resultat vecteur × matrice: (%d, %d, %d)\n", result->x, result->y, result->z);
        free(result);
    } else {
        printf("Erreur lors du calcul!\n");
    }
    
    libererMatrice(m);
}

int main() {
    int choix;
    
    printf("=== TP D'INFO 231: OPERATION SUR TABLEAU, MATRICES ET VECTEUR ===\n");
    printf("Gestion memoire amelioree - Allocation dynamique\n");
    
    do {
        afficherMenuPrincipal();
        if(scanf("%d", &choix) != 1) {
            printf("Entree invalide! Veuillez entrer un nombre.\n");
            while(getchar() != '\n'); // Vider le buffer
            continue;
        }
        
        switch(choix) {
            case 1: operationSommeMatrices(); break;
            case 2: operationProduitMatrices(); break;
            case 3: operationRechercheSequentielle(); break;
            case 4: operationMultiplicationAddition(); break;
            case 5: operationTestTableauTrie(); break;
            case 6: operationMedianeTableau(); break;
            case 7: operationInverserTableau(); break;
            case 8: operationProduitVectoriel(); break;
            case 9: operationProduitVecteurMatrice(); break;
            case 10: printf("Au revoir!\n"); break;
            default: printf("Choix invalide! Veuillez choisir entre 1 et 10.\n");
        }
        
        if(choix != 10) {
            printf("\nAppuyez sur Entree pour continuer...");
            while(getchar() != '\n'); // Vider le buffer
            getchar(); // Attendre Entrée
        }
    } while(choix != 10);
    
    return 0;
}