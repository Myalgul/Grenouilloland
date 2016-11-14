
/************************************
 * Définition de la classe Eau. *
 ************************************/

#include "Eau.hpp"
#include "Grenouille.hpp"

/**************
 * lireLigne. *
 **************/

void
Eau::affectationGrenouille(Grenouille grenouille) const {
    grenouille.ecrireVie(0);
}
