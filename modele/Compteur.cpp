/***************************************
 * Définition de la classe Compteur. *
 ***************************************/

#include "Compteur.hpp"
#include <iostream>
#include <stdio.h>
#include <time.h>

Compteur::Compteur(){
}

void
Compteur::demarrer(Grenouilloland* jeu) {
    while(!estFini()) {
        jeu->maj();
        attendre(tempsAttente);
        depart++;
    }
}
Compteur::~Compteur(){
}

void
Compteur::attendre(const float& temps) {
    clock_t attente = clock() + (temps * CLOCKS_PER_SEC);

    while(clock() < attente);
}

bool
Compteur::estFini() const {
    return depart == 1;
}

void
Compteur::reset() {
    depart = 0;
}
