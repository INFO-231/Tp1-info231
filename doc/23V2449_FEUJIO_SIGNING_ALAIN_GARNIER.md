# Recherche séquentielle et Multiplication par addition

### Exercice 3 : Recherche séquentielle dans un tableau
### Exercice 4 : Multiplication a × b utilisant uniquement l'addition

## 🎯 Objectifs
- Implémenter un algorithme de recherche linéaire efficace
- Créer une multiplication utilisant seulement l'opérateur +
- Gérer les tableaux avec allocation dynamique

## 📁 Fichiers impliqués
- `operations.h` - Déclaration de la structure Tableau
- `operations.c` - Implémentation des algorithmes
- `main.c` - Interface utilisateur pour ces fonctions

## 🏗️ Structure de données

### Structure Tableau
```c
typedef struct {
    int *data;     // Pointeur vers le tableau (allocation dynamique)
    int size;      // Taille du tableau
} Tableau;
```

## 🔧 Fonctions de gestion mémoire

Création et libération

```c
Tableau* creerTableau(int size) {
    Tableau *arr = (Tableau*)malloc(sizeof(Tableau));
    arr->size = size;
    arr->data = (int*)malloc(size * sizeof(int));
    memset(arr->data, 0, size * sizeof(int)); // Initialisation à zéro
    return arr;
}

void libererTableau(Tableau *arr) {
    if(arr) {
        if(arr->data) free(arr->data);
        free(arr);
    }
}
```

## 🔍 Exercice 3 : Recherche séquentielle

Algorithme implémenté

```c
int rechercheSequentielle(Tableau *arr, int valeur) {
    if(!arr || !arr->data) return -1;
    
    // Parcours linéaire du tableau
    for(int i = 0; i < arr->size; i++) {
        if(arr->data[i] == valeur) {
            return i; // Retourne l'indice si trouvé
        }
    }
    return -1; // Retourne -1 si non trouvé
}
```

Caractéristiques de l'algorithme

· Type : Recherche linéaire
· Complexité : O(n) dans le pire cas
· Meilleur cas : O(1) (élément en première position)
· Pire cas : O(n) (élément en dernière position ou absent)

Exemple d'utilisation

```c
Tableau *arr = creerTableau(5);
// Remplissage: [10, 20, 30, 40, 50]
int pos = rechercheSequentielle(arr, 30); // Retourne 2
int pos2 = rechercheSequentielle(arr, 99); // Retourne -1
```

## Exercice 4 : Multiplication par addition

Algorithme implémenté

```c
int multiplication(int a, int b) {
    if(a <= 0 || b <= 0) return 0; // Validation des entrées
    
    int result = 0;
    // Addition répétée de 'a', 'b' fois
    for(int i = 0; i < b; i++) {
        result += a;
    }
    return result;
}
```

Principe mathématique

```
a × b = a + a + a + ... + a (b fois)
Exemple: 4 × 3 = 4 + 4 + 4 = 12
```

Contraintes et validation

· Entrées : a > 0 et b > 0 (nombres naturels)
· Complexité : O(b) (dépend de la valeur de b)
· Validation : Vérification des paramètres en entrée

Exemple d'utilisation

```c
printf("5 × 4 = %d\n", multiplication(5, 4)); // Affiche 20
printf("3 × 7 = %d\n", multiplication(3, 7)); // Affiche 21
```

## Exemple de Tests 

Tests pour la recherche séquentielle

```c
// Tableau: [5, 3, 8, 1, 9]
rechercheSequentielle(arr, 8)  → retourne 2  ✓
rechercheSequentielle(arr, 5)  → retourne 0  ✓  
rechercheSequentielle(arr, 9)  → retourne 4  ✓
rechercheSequentielle(arr, 99) → retourne -1 ✓
```

Tests pour la multiplication

```c
multiplication(4, 5)   → 20 ✓
multiplication(7, 3)   → 21 ✓
multiplication(1, 100) → 100 ✓
multiplication(0, 5)   → 0  ✓ (entrée invalide)
multiplication(5, -2)  → 0  ✓ (entrée invalide)
```

## ⚠️ Gestion des erreurs

Pour la recherche séquentielle

· Vérification que le tableau est bien alloué
· Gestion des pointeurs nuls
· Retour de -1 pour "non trouvé"

Pour la multiplication

· Validation des paramètres d'entrée
· Protection contre les valeurs négatives ou nulles
· Gestion des cas limites

## 💡 Points techniques importants relevé 

Optimisation de la recherche

· Parcours séquentiel simple mais efficace pour petits tableaux
· Pas de prérequis de tri
· Adapté aux tableaux de petite et moyenne taille

Efficacité de la multiplication

· Algorithme conceptuellement simple mais peu efficace pour grands nombres
· Convient pour l'apprentissage des boucles
· Démonstration de la relation entre addition et multiplication

## 🚀 Utilisation dans le programme principal

Interface recherche séquentielle

```c
void operationRechercheSequentielle() {
    Tableau *arr = creerTableau(taille);
    saisirTableau(arr);
    
    int pos = rechercheSequentielle(arr, valeur);
    if(pos != -1) {
        printf("✓ Valeur trouvée à l'indice %d\n", pos);
    }
    
    libererTableau(arr);
}
```

Interface multiplication

```c
void operationMultiplicationAddition() {
    int a, b;
    // Saisie et validation
    int resultat = multiplication(a, b);
    printf("%d × %d = %d\n", a, b, resultat);
}
```

## 📊 Analyse de performance

**Recherche séquentielle**

Description de la complexité de la recherche dans 3 cas:
	💠Meilleur O(1) Élément en première position
	💠Moyen O(n/2) Élément au milieu
	💠Pire O(n) Élément en dernière position ou absent

**Multiplication par addition**

Evaluation de l'efficacité de la multiplication par addition successives par rapport à b:
	💠Pour b petit, O(b) Acceptable
	💠Pour b grand, O(b) Peu efficace
 
