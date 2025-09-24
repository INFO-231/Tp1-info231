# Membre 5 - Inversion d'un tableau

## Exercice 7 : Inverser l'ordre des éléments d'un tableau

## 🎯 Objectifs
- Implémenter un algorithme efficace pour inverser un tableau
- Travailler sur place sans allocation mémoire supplémentaire
- Gérer les cas particuliers (tableau vide, un seul élément)

## 📁 Fichiers impliqués
- `operations.h` - Déclaration de la fonction
- `operations.c` - Implémentation de l'algorithme  
- `main.c` - Interface utilisateur

## 🧠 Algorithme implémenté

### Code complet
```c
void inverserTableau(Tableau *arr) {
    // Validation des entrées
    if(!arr || !arr->data || arr->size <= 1) {
        return; // Rien à inverser
    }
    
    // Algorithme d'inversion en place
    int debut = 0;
    int fin = arr->size - 1;
    
    // Échange symétrique des éléments
    while(debut < fin) {
        // Échange des éléments aux positions debut et fin
        int temp = arr->data[debut];
        arr->data[debut] = arr->data[fin];
        arr->data[fin] = temp;
        
        // Déplacement vers le centre
        debut++;
        fin--;
    }
}
```

###🔍 Principe de l'algorithme

Approche "two pointers"

L'algorithme utilise deux indices qui se déplacent vers le centre :

· debut part du début et avance
· fin part de la fin et recule

Processus d'inversion

```
Étape 0: [1, 2, 3, 4, 5]   (debut=0, fin=4)
Étape 1: [5, 2, 3, 4, 1]   (debut=1, fin=3) - échange 1↔5
Étape 2: [5, 4, 3, 2, 1]   (debut=2, fin=2) - échange 2↔4
Terminé: debut >= fin
```

**📋 Cas de test**

Cas standards

```c
[1, 2, 3, 4, 5]       → [5, 4, 3, 2, 1] ✓
[10, 20, 30, 40]      → [40, 30, 20, 10] ✓
```

Cas particuliers

```c
[1]                   → [1] (inchangé) ✓
[]                    → [] (inchangé) ✓
[1, 2]                → [2, 1] ✓
```

Cas avec doublons

```c
[1, 2, 2, 3]          → [3, 2, 2, 1] ✓
[5, 5, 5]             → [5, 5, 5] ✓
```

###⚡ Complexité et performance

Analyse de complexité

· Temps : O(n/2) = O(n) - parcours de la moitié du tableau
· Espace : O(1) - utilisation d'une variable temporaire seulement


##🚀 Utilisation dans le programme

Interface utilisateur

```c
void operationInverserTableau() {
    Tableau *arr = creerTableau(taille);
    saisirTableau(arr);
    
    printf("Tableau original: ");
    afficherTableau(arr);
    
    inverserTableau(arr);
    
    printf("Tableau inversé:  ");
    afficherTableau(arr);
    
    libererTableau(arr);
}
```

##💡 Points techniques importants

Échange efficace d'éléments

```c
// Technique classique d'échange avec variable temporaire
int temp = arr->data[debut];
arr->data[debut] = arr->data[fin];
arr->data[fin] = temp;
```

Condition d'arrêt optimale

```c
while(debut < fin)  // S'arrête quand les indices se croisent
```

Pour un tableau de taille paire, les indices se croisent exactement. Pour un tableau de taille impaire,l'élément central reste en place.

Validation robuste

```c
if(!arr || !arr->data || arr->size <= 1) {
    return; // Évite les opérations inutiles ou dangereuses
}
```

### Tests approfondis

Tests de robustesse

```c
// Tableau null
inverserTableau(NULL)              → rien (sans crash) ✓

// Tableau vide  
inverserTableau([])                → rien ✓

// Un élément
inverserTableau([42])              → [42] ✓

// Grand tableau
inverserTableau([1,2,3,...,100])   → [100,99,...,1] ✓
```

Tests fonctionnels

```c
// Vérification de la réversibilité
original = [1, 2, 3, 4, 5]
inverserTableau(original) → [5, 4, 3, 2, 1]
inverserTableau(original) → [1, 2, 3, 4, 5] ✓ (retour à l'original)
```
