


📌 Liste Doublement Chaînée Circulaire en C (Insertion en Queue)

📖 Description

Ce projet implémente en C modulaire (avec séparation en fichiers .h et .c) une liste doublement chaînée circulaire.
L’opération principale est l’insertion en queue : ajouter un élément à la fin de la liste tout en conservant la circularité et le chaînage double (avant ↔ arrière).

Une liste doublement chaînée circulaire possède les caractéristiques suivantes :

Chaque élément (nœud) pointe vers son précédent et son suivant.

Le dernier élément pointe vers le premier, et inversement.

Il est possible de parcourir la liste dans les deux sens, sans jamais atteindre NULL.





⚙️ Fonctionnalités

Insertion en queue : ajoute un nouvel élément à la fin de la liste.

Affichage : affiche tous les éléments de la liste en montrant le retour vers la tête.

Libération mémoire : supprime tous les nœuds pour éviter les fuites.





📂 Organisation du projet

/projet_liste_ldc
│── main.c          # Programme principal (tests et exécution)
│── liste_ldc.h     # Définitions de structures et prototypes
│── liste_ldc.c     # Implémentation des fonctions
│── Makefile        # (optionnel) Compilation automatisée


---

📜 Structure des fichiers

🔹 liste_ldc.h

Déclare la structure du nœud et de la liste.

Contient les prototypes des fonctions :

creerNoeudLDC(int)

insererQueueLDC(ListeLDC*, int)

afficherListeLDC(ListeLDC*)

libererListeLDC(ListeLDC*)



🔹 liste_ldc.c

Implémente les fonctions déclarées dans le .h.


🔹 main.c

Programme de test qui insère des éléments en queue et affiche la liste.




▶️ Exemple d’exécution

Code de test (main.c)

int main() {
    ListeLDC liste = {NULL};

    insererQueueLDC(&liste, 10);
    insererQueueLDC(&liste, 20);
    insererQueueLDC(&liste, 30);
    insererQueueLDC(&liste, 40);

    afficherListeLDC(&liste);

    libererListeLDC(&liste);
    return 0;
}

Sortie attendue

Liste doublement chaînée circulaire : 10 <-> 20 <-> 30 <-> 40 <-> (retour à la tête)


 Compilation & Exécution

Sans Makefile

gcc main.c liste_ldc.c -o prog
./prog

Avec Makefile

make
./prog



🌏 Concepts clés

Circularité : aucun NULL, le dernier nœud pointe sur la tête et vice versa.

Doublement chaînée : navigation possible dans les deux sens (precedent ↔ suivant).

Gestion mémoire : allocation dynamique avec malloc, libération avec free.





