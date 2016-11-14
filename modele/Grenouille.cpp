
/************************************
 * Définition de la classe Grenouille. *
 ************************************/

#include "Grenouille.hpp"

Grenouille::Grenouille(const int& ligne, const int& colonne):
    ligne_(ligne),
    colonne_(colonne){

    ecrireVie(1);
    malade_ = false;
}

const int&
Grenouille::lireLigne() const {
    return ligne_;
}

const int&
Grenouille::lireColonne() const {
    return colonne_;
}

const int&
Grenouille::lireVie() const {
    return vie_;
}

//const ElementSurface*
//Grenouille::lireElementSurface() const {
//    return ptrElementSurface_;
//}

bool
Grenouille::estMalade() const {
    return malade_;
}

bool
Grenouille::estMorte() const {
    return vie_ == 0;
}

void
Grenouille::ecrireVie(const int& vie) {
    vie_ = vie;
}

void
Grenouille::ecrireLigne(const int& ligne) {
    ligne_ = ligne;
}

void
Grenouille::ecrireColonne(const int& colonne) {
    colonne_ = colonne;
}

//void
//Grenouille::ecrireElementSurface(const ElementSurface* element) {
//    ptrElementSurface_ = element;
//}

void
Grenouille::guerison() {
    malade_ = false;
}

void
Grenouille::tombeMalade() {
    malade_ = true;
}

//void
//Grenouille::modification() {
//    ptrElementSurface_->affectationGrenouille(this);
//}
