# Test si un tableau est trié

## Exercice 5 : Vérifier si un tableau est trié (croissant ou décroissant)

## 🎯 Objectifs
- Implémenter un algorithme pour détecter l'ordre d'un tableau
- Distinguer entre ordre croissant, décroissant ou non trié
- Gérer les cas particuliers (tableau vide, un seul élément)

## 📁 Fichiers impliqués
- `operations.h` - Déclaration de la fonction
- `operations.c` - Implémentation de l'algorithme
- `main.c` - Interface utilisateur

## 🧠 Algorithme implémenté

### Code complet
```c
int estTableauTrie(Tableau *arr) {
    // Cas particuliers
    if(!arr || !arr->data || arr->size <= 1) 
        return 1;
    
    int croissant = 1;  // Supposé trié croissant
    int decroissant = 1; // Supposé trié décroissant
    
    // Parcours du tableau pour vérifier l'ordre
    for(int i = 1; i < arr->size; i++) {
        // Vérifier ordre croissant
        if(arr->data[i] < arr->data[i-1]) 
            croissant = 0;
        
        // Vérifier ordre décroissant  
        if(arr->data[i] > arr->data[i-1])
            decroissant = 0;
            
        // Optimisation: si ni l'un ni l'autre, on peut arrêter
        if(!croissant && !decroissant)
            break;
    }
    
    return croissant || decroissant;
}
```

###🔍 Principe de l'algorithme

Approche à double vérification

L'algorithme maintient deux flags :

· croissant : reste vrai si chaque élément ≥ précédent
· decroissant : reste vrai si chaque élément ≤ précédent

Processus de vérification

1. Initialisation : Les deux flags sont vrais
2. Parcours : Pour chaque paire d'éléments consécutifs
3. Mise à jour : Les flags sont invalidés si l'ordre n'est pas respecté
4. Terminaison : Retourne vrai si au moins un flag est vrai

**📋 Cas de test**

Tableaux triés croissants

```c
[1, 2, 3, 4, 5]       → retourne 1 ✓
[1, 1, 2, 3, 3]       → retourne 1 ✓ (doublons autorisés)
[5]                   → retourne 1 ✓ (un seul élément)
[]                    → retourne 1 ✓ (tableau vide)
```

Tableaux triés décroissants

```c
[5, 4, 3, 2, 1]       → retourne 1 ✓
[3, 3, 2, 1, 1]       → retourne 1 ✓ (doublons autorisés)
```

Tableaux non triés

```c
[1, 3, 2, 4, 5]       → retourne 0 ✓
[5, 1, 4, 2, 3]       → retourne 0 ✓
[1, 2, 1, 3, 4]       → retourne 0 ✓
```

###⚡ Optimisations

Arrêt anticipé

```c
if(!croissant && !decroissant)
    break; // Inutile de continuer si déjà non trié
```

Cette optimisation permet de terminer le parcours dès qu'on sait que le tableau n'est ni croissant ni décroissant.

###Complexité

· Meilleur cas : O(1) (tableau vide ou un élément)
· Pire cas : O(n) (tableau trié, doit parcourir tout le tableau)
· Cas moyen : O(n) (parcours partiel ou complet)


##🚀 Utilisation dans le programme

Interface utilisateur

```c
void operationTestTableauTrie() {
    Tableau *arr = creerTableau(taille);
    saisirTableau(arr);
    
    printf("Tableau: ");
    afficherTableau(arr);
    
    if(estTableauTrie(arr)) {
        printf("✓ Le tableau est trié\n");
        
        // Déterminer l'ordre exact pour l'affichage
        if(arr->size > 1) {
            if(arr->data[0] <= arr->data[arr->size-1])
                printf("  (ordre croissant)\n");
            else
                printf("  (ordre décroissant)\n");
        }
    } else {
        printf("✗ Le tableau n'est pas trié\n");
    }
    
    libererTableau(arr);
}
```

##💡 Points techniques importants

Gestion des doublons

· Les doublons sont autorisés dans les deux ordres
· [1, 2, 2, 3] est considéré croissant ✓
· [3, 2, 2, 1] est considéré décroissant ✓

Cas limites

· Tableau vide : considéré comme trié
· Un seul élément : toujours trié
· Deux éléments : vérification simple de l'ordre

Validation des entrées

· Vérification des pointeurs nuls
· Gestion des tableaux non initialisés

## Tests approfondis

**Tests de robustesse**

```c
// Cas particuliers
estTableauTrie(NULL)              → 1 (par sécurité)
estTableauTrie(tableau_vide)      → 1 ✓
estTableauTrie([1])               → 1 ✓

// Cas standards
estTableauTrie([1, 2, 2, 3])      → 1 ✓ (croissant avec doublon)
estTableauTrie([3, 2, 2, 1])      → 1 ✓ (décroissant avec doublon)
estTableauTrie([1, 3, 2])         → 0 ✓ (non trié)
```

**📊 Analyse de performance**

*Scenario possible et Complexité*
Tableau vide [ ] O(1)
Un élément [1 0] O(1)
Trié croissant [n n+1] O(n)
Trié décroissant [n n-1] O(n)
Non trié n < n-1 O(k) où k < n 
