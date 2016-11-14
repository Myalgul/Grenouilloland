
/************************************
 * Définition de la classe NenupharDopant. *
 ************************************/

#include "NenupharDopant.hpp"

/**************************
 * affectationGrenouille. *
 **************************/

void
NenupharDopant::affectationGrenouille(Grenouille grenouille) const {
    grenouille.ecrireVie(grenouille.lireVie()*2);
}

