
/************************************
 * Définition de la classe NenupharVeneneux. *
 ************************************/

#include "NenupharVeneneux.hpp"
#include <iostream>

/**************************
 * affectationGrenouille. *
 **************************/

void
NenupharVeneneux::affectationGrenouille(Grenouille grenouille) const {
    int vieActuelle = grenouille.lireVie();
    if (grenouille.estMalade()) {
        grenouille.ecrireVie(0);
    } else {
        grenouille.tombeMalade();
        vieActuelle%2 == 1 ? grenouille.ecrireVie((vieActuelle-1)/2) : grenouille.ecrireVie(vieActuelle/2);
    }
    std::cout << grenouille.lireVie() << std::endl;
}

