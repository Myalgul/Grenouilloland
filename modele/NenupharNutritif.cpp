
/************************************
 * Définition de la classe NenupharNutritif. *
 ************************************/

#include "NenupharNutritif.hpp"

/**************************
 * affectationGrenouille. *
 **************************/

void
NenupharNutritif::affectationGrenouille(Grenouille* grenouille) const {
    grenouille->ecrireVie(grenouille->lireVie()+1);
    if (grenouille->estMalade()) {
        grenouille->guerison();
    }
}

