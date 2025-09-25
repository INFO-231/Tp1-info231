# Projet – Implémentation du TP1 INFO231_EC2  en C

**Exercice : en C / Tp INF 231_EC2: STRUCTURE DE DONNEES II**

1. Somme de matrices
2. Produit de matrices
3. Recherche séquentiel dans un tableau 
4. a × b pour a,b > 0 utiliser exclusivement+1
5. Tester si un tableau es trié 
6. le médian dans un tableau 
7. Inverser un tableau 
8. Produits vectoriel
9. Produits vecteur × matrices

Ce projet contient plusieurs fichiers C permettant d’implémenter des opérations sur :
- Les **matrices** (somme et produit)
- Les **tableaux** (recherche séquentielle, inversion, médiane, test de tri)
- Les **opérations arithmétiques** (multiplication avec uniquement des additions)
- Les **vecteurs** (produit vectoriel et produit vecteur × matrice)

## 📂 Contenu
- `main.c` : programme principal (interface utilisateur mode terminal )
- `fonction_operation.c` : implémentation des fonctions
- `fonction_operation.h` : bibliothèque des fonctions crée et structures de données
- `makefile` : makefile pour compiler automatiquement
- `/doc` : explications des partie des different membre

---

## ⚙️ Compilation sous **Ubuntu (mode terminal)**

1. Ouvrir un terminal dans le dossier du projet :
   ```bash
   cd chemin/vers/le/projet
2. compiler avec **make**
   ```bash
		make
3. Lancer l'exécutable généré
   ```bash
		./main

## 🖥️ Compilation sous **Visual Studio (Windows)**

1. Ouvrir Visual Studio.


2. Créer un nouveau projet C (Console Application).


3. Ajouter les fichiers suivants au projet :

main.c

fonction_operation.c

fonction_operation.h



4. Vérifier que dans Propriétés du projet :

Le langage est bien réglé en C (pas C++).

Le répertoire contenant fonction_operation.h est inclus dans les Include Directories.



5. Cliquer sur Build → Build Solution (ou Ctrl+Shift+B).


6. Exécuter le projet avec Ctrl+F5.




---


