
/************************************
 * Définition de la classe Eau. *
 ************************************/

#include "Eau.hpp"
#include "Grenouille.hpp"

void
Eau::affectationGrenouille(Grenouille* grenouille) const {
    grenouille->ecrireVie(0);
}

bool
Eau::vieillir() {
    return false;
}
