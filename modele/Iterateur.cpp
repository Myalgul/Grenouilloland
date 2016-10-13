/**************************************
 * Définition de la classe Iterateur. *
 **************************************/

#include "Iterateur.hpp"
#include "grenouilloland.hpp"

/**************
 * Iterateur. *
 **************/

Iterateur::Iterateur(const Nenuphar& nenuphar, const grenouilloland& proprietaire):
  nenuphar_(nenuphar),
  proprietaire_(proprietaire),
  rang_(0) {
}

/****************
 * lireNenuphar. *
 ****************/

const Nenuphar&
Iterateur::lireNenuphar() const {
  return nenuphar_;
}

/*********************
 * lireProprietaire. *
 *********************/

const grenouilloland&
Iterateur::lireProprietaire() const {
  return proprietaire_;
}

/*************
 * lireRang. *
 *************/

const int&
Iterateur::lireRang() const {
  return rang_;
}

/***********
 * encore. *
 ***********/

bool
Iterateur::encore() const {
  return rang_ < 8;
}

/*************
 * suivante. *
 *************/

const Nenuphar&
Iterateur::suivante() {

  // Obtention de la dimension du jeu.
  const int& dimension = proprietaire_.lireDimension();

  // Calcul du numéro de ligne de la case voisine courante.
  int ligne = nenuphar_.lireLigne() + deltas_[rang_][0];
  if (ligne == dimension) {
    ligne = 0;
  }
  else if (ligne < 0) {
    ligne = dimension - 1;
  }

  // Calcul du numéro de colonne de la case voisine courante.
  int colonne = nenuphar_.lireColonne() + deltas_[rang_][1];
  if (colonne == dimension) {
    colonne = 0;
  }
  else if (colonne < 0) {
    colonne = dimension - 1;
  }

  // Obtention de la voisine correspondante.
  const Nenuphar& voisine = proprietaire_.lireNenuphar(ligne, colonne);

  // Positionnement sur la nenuphar voisine suivante.
  rang_ ++;

  // Retourne la nenuphar voisine courante.
  return voisine;

}

/************
 * deltas_. *
 ************/

const int Iterateur::deltas_[8][2] = {
  { 0, -1 }, // Voisine 0
  { 1, -1 }, // Voisine 1
  { 1,  0 }, // Voisine 2
  { 1,  1 }, // Voisine 3
  { 0,  1 }, // Voisine 4
  {-1,  1 }, // Voisine 5
  {-1,  0 }, // Voisine 6
  {-1, -1 }  // Voisine 7
};

