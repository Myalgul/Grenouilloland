
/************************************
 * Définition de la classe ElementSurface. *
 ************************************/

#include "ElementSurface.hpp"
#include "Grenouille.hpp"

/*******************
 * ElementSurface. *
 *******************/
ElementSurface::ElementSurface(const int& ligne, const int& colonne, const std::string& representation):
    ligne_(ligne),
    colonne_(colonne),
    representation_(representation){
}
ElementSurface::~ElementSurface(){
}

/**************
 * lireLigne. *
 **************/
const int&
ElementSurface::lireLigne() const {
    return ligne_;
}

/****************
 * lireColonne. *
 ****************/
const int&
ElementSurface::lireColonne() const {
    return colonne_;
}

/***********************
 * lireRepresentation. *
 ***********************/
const std::string&
ElementSurface::lireRepresentation() const {
    return representation_;
}

/*************************
 * ecrireRepresentation. *
 *************************/
void
ElementSurface::ecrireRepresentation(const std::string& new_rep) {
    representation_ = new_rep;
}

/**************************
 * affectationGrenouille. *
 **************************/
//void
//ElementSurface::affectationGrenouille(Grenouille* grenouille) const {
//    std::cout << "surface" << std::endl;
//}

