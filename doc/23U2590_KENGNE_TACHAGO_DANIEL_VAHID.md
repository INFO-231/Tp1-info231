#  Opérations vectorielles

## Exercice 8 : Produit vectoriel
## Exercice 9 : Produit vecteur × matrice

## 🎯 Objectifs
- Implémenter les opérations vectorielles en 3D
- Calculer le produit vectoriel entre deux vecteurs
- Multiplier un vecteur par une matrice 3×3
- Comprendre les applications géométriques

## 📁 Fichiers impliqués
- `operations.h` - Déclarations des structures et fonctions
- `operations.c` - Implémentation des algorithmes
- `main.c` - Interface utilisateur

## 🏗️ Structures de données

### Structure Vector
```c
typedef struct {
    int x, y, z;  // Composantes du vecteur en 3D
} Vector;
```

##Exercice 8 : Produit vectoriel

Définition mathématique

Le produit vectoriel de deux vecteurs u et v donne un vecteur w perpendiculaire au plan formé par u et v.

```
w = u × v = (u_y*v_z - u_z*v_y, 
             u_z*v_x - u_x*v_z, 
             u_x*v_y - u_y*v_x)
```

Algorithme implémenté

```c
Vector* produitVectoriel(Vector *v1, Vector *v2) {
    if(!v1 || !v2) return NULL;
    
    Vector *result = (Vector*)malloc(sizeof(Vector));
    if(!result) return NULL;
    
    // Calcul des composantes selon la formule
    result->x = v1->y * v2->z - v1->z * v2->y;
    result->y = v1->z * v2->x - v1->x * v2->z;
    result->z = v1->x * v2->y - v1->y * v2->x;
    
    return result;
}
```

Propriétés importantes

· Anti-commutatif : u × v = - (v × u)
· Orthogonal : w ⊥ u et w ⊥ v
· Norme : ||w|| = ||u||·||v||·sin(θ)

##Exercice 9 : Produit vecteur × matrice

Définition mathématique

Multiplication d'un vecteur ligne par une matrice 3×3 :

```
[v'] = [v] × M = [v_x, v_y, v_z] × [m11 m12 m13]
                                    [m21 m22 m23]
                                    [m31 m32 m33]

v'_x = v_x*m11 + v_y*m21 + v_z*m31
v'_y = v_x*m12 + v_y*m22 + v_z*m32  
v'_z = v_x*m13 + v_y*m23 + v_z*m33
```

###Algorithme implémenté

```c
Vector* produitVecteurMatrice(Vector *v, Matrix *m) {
    // Validation des entrées
    if(!v || !m || !m->data) return NULL;
    
    if(m->rows != 3 || m->cols != 3) {
        printf("Erreur: La matrice doit être 3x3!\n");
        return NULL;
    }
    
    Vector *result = (Vector*)malloc(sizeof(Vector));
    if(!result) return NULL;
    
    // Calcul selon la formule matricielle
    result->x = v->x * m->data[0][0] + v->y * m->data[1][0] + v->z * m->data[2][0];
    result->y = v->x * m->data[0][1] + v->y * m->data[1][1] + v->z * m->data[2][1];
    result->z = v->x * m->data[0][2] + v->y * m->data[1][2] + v->z * m->data[2][2];
    
    return result;
}
```

**📋 Cas de test détaillés**

Produit vectoriel - Tests

```c
// Vecteurs unitaires sur les axes
i = (1, 0, 0), j = (0, 1, 0)
i × j = (0, 0, 1) = k ✓

// Vecteurs quelconques
u = (1, 2, 3), v = (4, 5, 6)
u × v = (2*6-3*5, 3*4-1*6, 1*5-2*4) = (-3, 6, -3) ✓

// Vecteurs parallèles
u = (1, 2, 3), v = (2, 4, 6)
u × v = (0, 0, 0) ✓ (vecteurs colinéaires)
```

Produit vecteur×matrice - Tests

```c
// Matrice identité
v = (1, 2, 3), M = [[1,0,0],[0,1,0],[0,0,1]]
v × M = (1, 2, 3) ✓ (vecteur inchangé)

// Matrice de rotation 90° autour de z
M = [[0,-1,0],[1,0,0],[0,0,1]]
v = (1, 0, 0) × M = (0, 1, 0) ✓

// Matrice d'échelle
M = [[2,0,0],[0,3,0],[0,0,1]]  
v = (1, 1, 1) × M = (2, 3, 1) ✓
```

##🚀 Utilisation dans le programme

Interface produit vectoriel

```c
void operationProduitVectoriel() {
    Vector v1, v2;
    printf("Vecteur 1 (x y z): ");
    scanf("%d %d %d", &v1.x, &v1.y, &v1.z);
    
    Vector *result = produitVectoriel(&v1, &v2);
    if(result) {
        printf("Produit vectoriel: (%d, %d, %d)\n", 
               result->x, result->y, result->z);
        free(result);
    }
}
```

Interface produit vecteur×matrice

```c
void operationProduitVecteurMatrice() {
    Vector v;
    Matrix *m = creerMatrice(3, 3);
    
    Vector *result = produitVecteurMatrice(&v, m);
    if(result) {
        printf("Résultat: (%d, %d, %d)\n", result->x, result->y, result->z);
        free(result);
    }
    
    libererMatrice(m);
}
```

## Tests de performance

Complexité

· Produit vectoriel : O(1) - nombre constant d'opérations
· Produit vecteur×matrice : O(1) - 9 multiplications + 6 additions

Robustesse

```c
// Vecteurs nuls
produitVectoriel((0,0,0), (1,2,3)) → (0,0,0) ✓

// Matrice non carrée
produitVecteurMatrice(v, matrice_2x3) → erreur ✓
```