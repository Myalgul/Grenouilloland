/***************************************
 * Définition de la classe Grenouilloland. *
 ***************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include "Grenouilloland.hpp"

/*******************
 * Grenouilloland. *
 *******************/
Grenouilloland::Grenouilloland(const int& dimension):
    dimension_(dimension) {

    // La méthode push_back invoque implicitement l'opérateur d'affectation par
    // défaut de la classe Cellule. C'est pour cette raison que les attributs
    // représentant les numeros de ligne et de colonne de la classe Cellule ne
    // sont pas déclarés constants (même s'ils ne changent pas).
    ptrGrenouille_ = new Grenouille(dimension-1, 0);
    elementSurface_.reserve(dimension * dimension);
    for (int i = 0; i < dimension; i ++) {
        for (int j = 0; j < dimension; j ++) {
//            int t = i * dimension_ + j;
//            std::string ty = std::to_string(t);
            elementSurface_.push_back(new Eau(i, j, "e0"));
        }
    }

    generationChemin(dimension-1, 0);

    changeElement(0, dimension-1, new NenupharImmortel(0, dimension-1, "i0"));
    changeElement(dimension-1, 0, new NenupharImmortel(dimension-1, 0, "i0"));
}

/******************
 * lireDimension. *
 ******************/
const int&
Grenouilloland::lireDimension() const {
    return dimension_;
}

/****************
 * lireCellule. *
 ****************/
const ElementSurface*
Grenouilloland::lireElement(const int& ligne, const int& colonne) const {
    return elementSurface_[ligne * dimension_ + colonne];
}

/******************
 * changeElement. *
 ******************/

void
Grenouilloland::changeElement(const int& ligne, const int& colonne, ElementSurface* element) {
    if (lireElement(ligne, colonne)->lireRepresentation() != "i0") {
        int position = ligne * dimension_ + colonne;
        elementSurface_.erase(elementSurface_.begin()+position);
        elementSurface_.insert(elementSurface_.begin()+position, element);
    }
}

/*********************
 * generationChemin. *
 *********************/
void
Grenouilloland::generationChemin(const int& ligne, const int& colonne) {

    if (ligne == 0) {
        for (int i = colonne; i < dimension_; i++) {
            generationNenuphar(ligne, i);
        }
    } else if (colonne == dimension_) {
        for (int i = 0; i < ligne; i++) {
            generationNenuphar(i, dimension_-1);
        }
    } else {
        for (int i = 0; i < ligne; i++) {
            generationNenuphar(i, colonne);
            generationNenuphar(i, dimension_-1);
        }
        for (int j = colonne; j < dimension_; j++) {
            generationNenuphar(0, j);
            generationNenuphar(ligne, j);
        }
    }
}

/***********************
 * generationNenuphar. *
 ***********************/
void
Grenouilloland::generationNenuphar(const int& ligne, const int& colonne) {

    if (lireElement(ligne, colonne)->lireRepresentation() == "e0") {
        int num_rand = rand();

        switch(num_rand%5) {
            case 0 : changeElement(ligne, colonne, new Nenuphar(ligne, colonne, "n3"));
                     break;
            case 1 : changeElement(ligne, colonne, new NenupharDopant(ligne, colonne, "d3"));
                     break;
            case 2 : changeElement(ligne, colonne, new NenupharMortel(ligne, colonne, "m3"));
                     break;
            case 3 : changeElement(ligne, colonne, new NenupharNutritif(ligne, colonne, "N3"));
                     break;
            case 4 : changeElement(ligne, colonne, new NenupharVeneneux(ligne, colonne, "v3"));
                     break;
        }
    }
}

/**************************
 * affectationGrenouille. *
 **************************/
void
Grenouilloland::modification() const {
    lireElement(ptrGrenouille_->lireLigne(), ptrGrenouille_->lireColonne())->affectationGrenouille(ptrGrenouille_);
//    std::cout << lireElement(ptrGrenouille_->lireLigne(), ptrGrenouille_->lireColonne())->lireLigne() << std::endl;
//    std::cout << lireElement(ptrGrenouille_->lireLigne(), ptrGrenouille_->lireColonne())->lireColonne() << std::endl;
//    std::cout << lireElement(ptrGrenouille_->lireLigne(), ptrGrenouille_->lireColonne())->lireRepresentation() << std::endl;
}

/********
 * maj. *
 ********/
void
Grenouilloland::maj() {
    generationChemin(ptrGrenouille_->lireLigne(), ptrGrenouille_->lireColonne());
    for (std::vector<ElementSurface*>::iterator it = elementSurface_.begin() ; it != elementSurface_.end(); ++it) {
        ElementSurface* elem = *it;

        if (estSurChemin(elem)) {
            if (elem->vieillir()) {
                changeElement(elem->lireLigne(), elem->lireColonne(), new Eau(elem->lireLigne(), elem->lireColonne(), "e0"));
            }
        }
    }
}

/*****************
 * estSurChemin. *
 *****************/
bool
Grenouilloland::estSurChemin(const ElementSurface* element) const {
    int ligne = element->lireLigne();
    int colonne = element->lireColonne();
    return (ligne > ptrGrenouille_->lireLigne() || colonne < ptrGrenouille_->lireColonne());
}

/***********
 * gagner. *
 ***********/
bool
Grenouilloland::gagner() const {
    if ((ptrGrenouille_->lireLigne() == 0) && (ptrGrenouille_->lireColonne() == dimension_-1)) {
        return true;
    }
    return false;
}

/**********
 * perdu. *
 **********/
bool
Grenouilloland::perdu() const {
    return ptrGrenouille_->estMorte();
}

/*******************
 * lireGrenouille. *
 *******************/
Grenouille*
Grenouilloland::lireGrenouille() {
    return ptrGrenouille_;
}
