# Calcul de la médiane d'un tableau

## Exercice 6 : Trouver la valeur médiane d'un tableau

## 🎯 Objectifs
- Implémenter le calcul de la médiane d'un tableau numérique
- Gérer les cas pairs et impairs de taille de tableau
- Utiliser un algorithme de tri pour ordonner les données

## 📁 Fichiers impliqués
- `operations.h` - Déclaration de la fonction
- `operations.c` - Implémentation de l'algorithme
- `main.c` - Interface utilisateur

## 📊 Définition mathématique

### Médiane d'un ensemble de valeurs
- **Tableau impair** : Valeur centrale quand ordonné
```

[1, 3, 3, 6, 7, 8, 9] → Médiane = 6 (4ème élément)

```
- **Tableau pair** : Moyenne des deux valeurs centrales
```

[1, 2, 3, 4, 5, 6, 8, 9] → Médiane = (4 + 5) / 2 = 4.5

```

## 🧠 Algorithme implémenté

### Code complet
```c
float medianTableau(Tableau *arr) {
    // Validation des entrées
    if(!arr || !arr->data || arr->size == 0) {
        printf("Erreur: Tableau invalide ou vide!\n");
        return 0.0f;
    }
    
    // Création d'une copie pour ne pas modifier l'original
    int *copie = (int*)malloc(arr->size * sizeof(int));
    if(!copie) {
        printf("Erreur d'allocation mémoire!\n");
        return 0.0f;
    }
    
    // Copie des données
    memcpy(copie, arr->data, arr->size * sizeof(int));
    
    // Tri du tableau copié (tri par sélection)
    triParSelection(copie, arr->size);
    
    // Calcul de la médiane selon la parité de la taille
    float mediane;
    if(arr->size % 2 == 1) {
        // Taille impaire: élément central
        mediane = (float)copie[arr->size / 2];
    } else {
        // Taille paire: moyenne des deux éléments centraux
        int indice1 = arr->size / 2 - 1;
        int indice2 = arr->size / 2;
        mediane = (float)(copie[indice1] + copie[indice2]) / 2.0f;
    }
    
    // Libération de la copie
    free(copie);
    return mediane;
}
```

###🔧 Algorithme de tri utilisé

Tri par sélection (implémentation)

```c
void triParSelection(int *tab, int taille) {
    for(int i = 0; i < taille - 1; i++) {
        int indice_min = i;
        
        // Recherche du minimum dans la partie non triée
        for(int j = i + 1; j < taille; j++) {
            if(tab[j] < tab[indice_min]) {
                indice_min = j;
            }
        }
        
        // Échange des éléments
        if(indice_min != i) {
            int temp = tab[i];
            tab[i] = tab[indice_min];
            tab[indice_min] = temp;
        }
    }
}
```

**📋 Cas de test détaillés**

Cas impairs

```c
[5, 3, 1, 4, 2]       → trié: [1, 2, 3, 4, 5] → médiane = 3 ✓
[10, 20, 30]          → trié: [10, 20, 30]    → médiane = 20 ✓
[7]                   → trié: [7]             → médiane = 7 ✓
```

Cas pairs

```c
[4, 2, 1, 3]         → trié: [1, 2, 3, 4]    → médiane = (2+3)/2 = 2.5 ✓
[6, 2, 8, 4]         → trié: [2, 4, 6, 8]    → médiane = (4+6)/2 = 5.0 ✓
[1, 3]               → trié: [1, 3]          → médiane = (1+3)/2 = 2.0 ✓
```

Cas avec doublons

```c
[3, 1, 3, 2]         → trié: [1, 2, 3, 3]    → médiane = (2+3)/2 = 2.5 ✓
[5, 5, 5]            → trié: [5, 5, 5]       → médiane = 5 ✓
```

###⚡ Complexité et performance

Analyse de complexité

· Tri par sélection : O(n²) dans tous les cas
· Calcul médiane : O(1) après le tri
· Total : O(n²) dominé par le tri


##🚀 Utilisation dans le programme

Interface utilisateur

```c
void operationMedianeTableau() {
    Tableau *arr = creerTableau(taille);
    saisirTableau(arr);
    
    printf("Tableau original: ");
    afficherTableau(arr);
    
    float mediane = medianTableau(arr);
    printf("Médiane: %.2f\n", mediane);
    
    // Affichage du tableau trié pour vérification
    printf("Tableau trié: ");
    afficherTableauTrié(arr); // Fonction utilitaire
    
    libererTableau(arr);
}
```

##💡 Points techniques importants

Préservation des données originales

· Copie du tableau avant tri pour ne pas modifier l'original
· Utilisation de memcpy() pour une copie efficace

Gestion de la mémoire

· Allocation et libération de la copie
· Vérification des succès d'allocation

Précision numérique

· Utilisation de float pour la médiane
· Conversion explicite en float pour la division
· Affichage avec 2 décimales

**Tests de robustesse**

Cas limites

```c
// Tableau vide
medianTableau([])                    → 0.0 (avec message d'erreur) ✓

// Tableau null
medianTableau(NULL)                  → 0.0 (avec message d'erreur) ✓

// Un seul élément
medianTableau([42])                  → 42.0 ✓

// Deux éléments
medianTableau([10, 20])              → 15.0 ✓

// Éléments négatifs
medianTableau([-5, -1, -3])          → -3.0 ✓
```

