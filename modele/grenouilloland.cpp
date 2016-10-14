/***************************************
 * Définition de la classe grenouilloland. *
 ***************************************/

#include "grenouilloland.hpp"

/***************
 * grenouilloland. *
 ***************/

grenouilloland::grenouilloland(const int& dimension):
  dimension_(dimension) {

  // La méthode push_back invoque implicitement l'opérateur d'affectation par
  // défaut de la classe Nenuphar. C'est pour cette raison que les attributs
  // représentant les numeros de ligne et de colonne de la classe Nenuphar ne
  // sont pas déclarés constants (même s'ils ne changent pas).
  nenuphars_.reserve(dimension * dimension);
  for (int i = 0; i < dimension; i ++) {
    for (int j = 0; j < dimension; j ++) {
      nenuphars_.push_back(Nenuphar(i, j));
    }
  }

}

/******************
 * lireDimension. *
 ******************/

const int&
grenouilloland::lireDimension() const {
  return dimension_;
}

/****************
 * lireNenuphar. *
 ****************/

const Nenuphar&
grenouilloland::lireNenuphar(const int& ligne, const int& colonne) const {
  return nenuphars_[ligne * dimension_ + colonne];
}

/*************
 * basculer. *
 *************/

void
grenouilloland::basculer(const int& ligne, const int& colonne) {
  nenuphars_[ligne * dimension_ + colonne].basculer();
}

/******************
 * reinitialiser. *
 ******************/

void
grenouilloland::reinitialiser() {
  for (Nenuphar& nenuphar : nenuphars_) {
    if (nenuphar.estVivante()) {
      nenuphar.basculer();
    }
  }
}

/*************
 * calculer. *
 *************/

void
grenouilloland::calculer(const int& iterations) {
  for (int i = 0; i < iterations; i ++) {
    suivante();
  }
}

/*************
 * suivante. *
 *************/

void
grenouilloland::suivante() {

  // Premier balayage des nenuphars pour archivage.
  for (Nenuphar& nenuphar : nenuphars_) {
    nenuphar.archiver();
  }

  // Second balayage des nenuphars pour mise à jour.
  for (Nenuphar& nenuphar : nenuphars_) {
    nenuphar.mettreAJour(*this);
  }

}

