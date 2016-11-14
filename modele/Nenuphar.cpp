/************************************
 * Définition de la classe Nenuphar. *
 ************************************/

#include "Grenouilloland.hpp"
#include "Nenuphar.hpp"
#include <string>

/**************
 * lireTaille. *
 **************/
const int&
Nenuphar::lireTaille() const {
    return taille_;
}

/*************
 * vieillir. *
 *************/
bool
Nenuphar::vieillir() {
    taille_--;
    std::string tmp = lireRepresentation();
    tmp.replace(1,1, std::to_string(taille_));
    ecrireRepresentation(tmp);
    return taille_ == 0;
}

/**************************
 * affectationGrenouille. *
 **************************/
void
Nenuphar::affectationGrenouille(Grenouille* grenouille) const {
}

