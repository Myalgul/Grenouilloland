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
    elementSurface_.reserve(dimension * dimension);
    for (int i = 0; i < dimension; i ++) {
        for (int j = 0; j < dimension; j ++) {
//            int t = i * dimension_ + j;
//            std::string ty = std::to_string(t);
            elementSurface_.push_back(new Eau(i, j, "e"));
        }
    }

    generationChemin(dimension-1, 0);

    changeElement(0, dimension-1, new NenupharImmortel(0, dimension-1, "i"));
    changeElement(dimension-1, 0, new NenupharImmortel(dimension-1, 0, "i"));
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
    int position = ligne * dimension_ + colonne;
    elementSurface_.erase(elementSurface_.begin()+position);
    elementSurface_.insert(elementSurface_.begin()+position, element);
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

    int num_rand = rand();

    switch(num_rand%5) {
        case 0 : changeElement(ligne, colonne, new Nenuphar(ligne, colonne, "n"));
                 break;
        case 1 : changeElement(ligne, colonne, new NenupharDopant(ligne, colonne, "d"));
                 break;
        case 2 : changeElement(ligne, colonne, new NenupharMortel(ligne, colonne, "m"));
                 break;
        case 3 : changeElement(ligne, colonne, new NenupharNutritif(ligne, colonne, "N"));
                 break;
        case 4 : changeElement(ligne, colonne, new NenupharVeneneux(ligne, colonne, "v"));
                 break;
    }
}

/**************************
 * affectationGrenouille. *
 **************************/

void
Grenouilloland::modification(Grenouille* grenouille) const {
    lireElement(grenouille->lireLigne(), grenouille->lireColonne())->affectationGrenouille(grenouille);
//    std::cout << lireElement(grenouille->lireLigne(), grenouille->lireColonne())->lireLigne() << std::endl;
//    std::cout << lireElement(grenouille->lireLigne(), grenouille->lireColonne())->lireColonne() << std::endl;
//    std::cout << lireElement(grenouille->lireLigne(), grenouille->lireColonne())->lireRepresentation() << std::endl;
}

/***********
 * gagner. *
 ***********/

bool
Grenouilloland::gagner(Grenouille grenouille) const {
    if ((grenouille.lireLigne() == 0) && (grenouille.lireColonne() == dimension_-1)) {
        return true;
    }
    return false;
}

/**********
 * perdu. *
 **********/

bool
Grenouilloland::perdu(Grenouille grenouille) const {
    return grenouille.estMorte();
}
