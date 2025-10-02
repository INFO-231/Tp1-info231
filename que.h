#include <stdio.h>
#include <stdlib.h>
#include "liste_ldc.h"

// Créer un nouveau nœud
NoeudLDC* creerNoeudLDC(int donnee) {
    NoeudLDC* nouveau = (NoeudLDC*)malloc(sizeof(NoeudLDC));
    if (!nouveau) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    nouveau->donnee = donnee;
    nouveau->precedent = nouveau->suivant = NULL;
    return nouveau;
}

// Insertion en queue
void insererQueueLDC(ListeLDC* liste, int donnee) {
    NoeudLDC* nouveau = creerNoeudLDC(donnee);

    if (liste->tete == NULL) {
        // Premier élément → pointe sur lui-même
        liste->tete = nouveau;
        nouveau->suivant = nouveau;
        nouveau->precedent = nouveau;
    } else {
        NoeudLDC* queue = liste->tete->precedent;

        nouveau->suivant = liste->tete;
        nouveau->precedent = queue;
        queue->suivant = nouveau;
        liste->tete->precedent = nouveau;
    }
}

// Affichage de la liste
void afficherListeLDC(ListeLDC* liste) {
    if (liste->tete == NULL) {
        printf("Liste doublement chaînée circulaire : Vide\n");
        return;
    }

    NoeudLDC* courant = liste->tete;
    printf("Liste doublement chaînée circulaire : ");
    do {
        printf("%d <-> ", courant->donnee);
        courant = courant->suivant;
    } while (courant != liste->tete);
    printf("(retour à la tête)\n");
}

// Libérer la mémoire
void libererListeLDC(ListeLDC* liste) {
    if (liste->tete == NULL) return;

    NoeudLDC* courant = liste->tete->suivant;
    NoeudLDC* temp;

    while (courant != liste->tete) {
        temp = courant;
        courant = courant->suivant;
        free(temp);
    }
    free(liste->tete);
    liste->tete = NULL;
}