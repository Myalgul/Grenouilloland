
/************************************
 * Définition de la classe Nenuphar. *
 ************************************/

#include "grenouilloland.hpp"
#include "Iterateur.hpp"

/************
 * Nenuphar. *
 ************/

Nenuphar::Nenuphar(const int& ligne, const int& colonne):
  ligne_(ligne),
  colonne_(colonne),
  archive_(false),
  etat_(false) {
}

/**************
 * lireLigne. *
 **************/

const int&
Nenuphar::lireLigne() const {
  return ligne_;
}

/****************
 * lireColonne. *
 ****************/

const int&
Nenuphar::lireColonne() const {
  return colonne_;
}

/*****************
 * etaitVivante. *
 *****************/

const bool&
Nenuphar::etaitVivante() const {
  return archive_;
}

/***************
 * estVivante. *
 ***************/

const bool&
Nenuphar::estVivante() const {
  return etat_;
}

/*************
 * basculer. *
 *************/

void
Nenuphar::basculer() {
  etat_ = ! etat_;
}

/*************
 * archiver. *
 *************/

void
Nenuphar::archiver() {
  archive_ = etat_;
}

/****************
 * mettreAJour. *
 ****************/

void
Nenuphar::mettreAJour(grenouilloland& proprietaire) {

  // Itérateur permettant de parcourir les huit voisines.
  Iterateur it(*this, proprietaire);

  // Décompte des voisines vivantes.
  int decompte = 0;
  while (it.encore()) {
    const Nenuphar& voisine = it.suivante();
    if (voisine.etaitVivante()) {
      decompte ++;
    }
  }

  // Mise à jour de l'état de cette nenuphar.
  if (estVivante()) {
    etat_ = decompte == 2 || decompte == 3;
  }
  else {
    etat_ = decompte == 3;
  }

}
