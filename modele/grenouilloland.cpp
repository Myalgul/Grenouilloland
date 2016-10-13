/***************************************
 * D�finition de la classe grenouilloland. *
 ***************************************/

#include "grenouilloland.hpp"

/***************
 * grenouilloland. *
 ***************/

grenouilloland::grenouilloland(const int& dimension):
  dimension_(dimension) {

  // La m�thode push_back invoque implicitement l'op�rateur d'affectation par
  // d�faut de la classe Cellule. C'est pour cette raison que les attributs
  // repr�sentant les numeros de ligne et de colonne de la classe Cellule ne
  // sont pas d�clar�s constants (m�me s'ils ne changent pas).
  cellules_.reserve(dimension * dimension);
  for (int i = 0; i < dimension; i ++) {
    for (int j = 0; j < dimension; j ++) {
      cellules_.push_back(Cellule(i, j));
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
 * lireCellule. *
 ****************/

const Cellule&
grenouilloland::lireCellule(const int& ligne, const int& colonne) const {
  return cellules_[ligne * dimension_ + colonne];
}

/*************
 * basculer. *
 *************/

void
grenouilloland::basculer(const int& ligne, const int& colonne) {
  cellules_[ligne * dimension_ + colonne].basculer();
}

/******************
 * reinitialiser. *
 ******************/

void
grenouilloland::reinitialiser() {
  for (Cellule& cellule : cellules_) {
    if (cellule.estVivante()) {
      cellule.basculer();
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

  // Premier balayage des cellules pour archivage.
  for (Cellule& cellule : cellules_) {
    cellule.archiver();
  }

  // Second balayage des cellules pour mise � jour.
  for (Cellule& cellule : cellules_) {
    cellule.mettreAJour(*this);
  }

}

