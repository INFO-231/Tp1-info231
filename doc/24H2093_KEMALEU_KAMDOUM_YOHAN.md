# - Opérations sur les Matrices

## Exercice 1 : Somme de Matrices
## Exercice 2 : Produit de Matrices

## 🎯 Objectifs
- Implémenter les opérations de somme et produits sur les matrices
- Gérer l'allocation dynamique de mémoire pour les matrices
- Valider les dimensions des matrices avant les opérations

## 📁 Fichiers impliqués
- `operations.h` - Déclarations des structures et fonctions
- `operations.c` - Implémentation des algorithmes
- `main.c` - Interface utilisateur

## 🏗️ Structures de données

### Structure Matrix (Allocation dynamique)
```c
typedef struct {
    int rows;       // Nombre de lignes
    int cols;       // Nombre de colonnes  
    int **data;     // Pointeur vers données (allocation dynamique 2D)
} Matrix;
```

##🔧 Fonctions implémentées

1. Création et destruction de matrices

```c
// Allocation d'une matrice rows x cols
Matrix* creerMatrice(int rows, int cols) {
    Matrix *m = (Matrix*)malloc(sizeof(Matrix));
    m->rows = rows;
    m->cols = cols;
    
    // Allocation du tableau de pointeurs pour les lignes
    m->data = (int**)malloc(rows * sizeof(int*));
    
    // Allocation de chaque ligne
    for(int i = 0; i < rows; i++) {
        m->data[i] = (int*)malloc(cols * sizeof(int));
        memset(m->data[i], 0, cols * sizeof(int)); // Initialisation à zéro
    }
    return m;
}

// Libération complète de la mémoire
void libererMatrice(Matrix *m) {
    if(m && m->data) {
        for(int i = 0; i < m->rows; i++) {
            free(m->data[i]);  // Libération de chaque ligne
        }
        free(m->data);         // Libération du tableau de pointeurs
        free(m);               // Libération de la structure
    }
}
```

2. Saisie et affichage

```c
void saisirMatrice(Matrix *m) {
    for(int i = 0; i < m->rows; i++) {
        for(int j = 0; j < m->cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &m->data[i][j]);
        }
    }
}

void afficherMatrice(Matrix *m) {
    for(int i = 0; i < m->rows; i++) {
        for(int j = 0; j < m->cols; j++) {
            printf("%4d", m->data[i][j]);
        }
        printf("\n");
    }
}
```

## Algorithmes implémentés

1. Somme de matrices (Exercice 1)

```c
Matrix* sommeMatrices(Matrix *m1, Matrix *m2) {
    // Vérification des dimensions
    if(m1->rows != m2->rows || m1->cols != m2->cols) {
        printf("Erreur: Dimensions incompatibles!\n");
        return NULL;
    }
    
    Matrix *result = creerMatrice(m1->rows, m1->cols);
    
    // Algorithme de somme
    for(int i = 0; i < m1->rows; i++) {
        for(int j = 0; j < m1->cols; j++) {
            result->data[i][j] = m1->data[i][j] + m2->data[i][j];
        }
    }
    return result;
}
```

Complexité : O(n²) où n est la dimension maximale

2. Produit de matrices (Exercice 2)

```c
Matrix* produitMatrices(Matrix *m1, Matrix *m2) {
    // Vérification compatibilité dimensions
    if(m1->cols != m2->rows) {
        printf("Erreur: Nombre de colonnes de M1 ≠ nombre de lignes de M2!\n");
        return NULL;
    }
    
    Matrix *result = creerMatrice(m1->rows, m2->cols);
    
    // Algorithme de multiplication matricielle
    for(int i = 0; i < m1->rows; i++) {
        for(int j = 0; j < m2->cols; j++) {
            result->data[i][j] = 0; // Initialisation
            for(int k = 0; k < m1->cols; k++) {
                result->data[i][j] += m1->data[i][k] * m2->data[k][j];
            }
        }
    }
    return result;
}
```

Complexité : O(n³) pour des matrices carrées n×n

🧪 Tests et validation

Cas de test pour la somme

```c
// Matrices 2x2
Matrix A:    Matrix B:    Résultat attendu:
[1, 2]       [5, 6]       [6, 8]
[3, 4]       [7, 8]       [10, 12]
```

Cas de test pour le produit

```c
// Matrices 2x3 et 3x2
Matrix A:    Matrix B:    Résultat attendu:
[1, 2, 3]    [7, 8]       [58, 64]
[4, 5, 6]    [9, 10]      [139, 154]
             [11, 12]
```

⚠️ Gestion des erreurs

1. Dimensions incompatibles : Vérification avant chaque opération
2. Allocation mémoire : Vérification des retours de malloc()
3. Pointeurs nuls : Validation avant utilisation

💡 Points techniques importants

Allocation dynamique

· Allocation en deux étapes : tableau de pointeurs + données
· Libération dans l'ordre inverse : données → pointeurs → structure

Validation des dimensions

· Somme : mêmes dimensions requises
· Produit : nombre de colonnes M1 = nombre de lignes M2

Optimisation mémoire

· Utilisation de memset() pour l'initialisation
· Libération immédiate après utilisation

🚀 Utilisation dans le programme

```c
// Exemple d'utilisation complète
Matrix *m1 = creerMatrice(2, 2);
Matrix *m2 = creerMatrice(2, 2);
saisirMatrice(m1);
saisirMatrice(m2);

Matrix *somme = sommeMatrices(m1, m2);
Matrix *produit = produitMatrices(m1, m2);

afficherMatrice(somme);
afficherMatrice(produit);

// Nettoyage mémoire
libererMatrice(m1);
libererMatrice(m2);
libererMatrice(somme);
libererMatrice(produit);
```
