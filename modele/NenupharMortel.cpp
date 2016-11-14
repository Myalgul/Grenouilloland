
/************************************
 * Définition de la classe NenupharMortel. *
 ************************************/

#include "NenupharMortel.hpp"

/**************************
 * affectationGrenouille. *
 **************************/

void
NenupharMortel::affectationGrenouille(Grenouille* grenouille) const {
    grenouille->ecrireVie(0);
}

