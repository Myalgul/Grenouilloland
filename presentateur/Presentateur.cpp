/*****************************************
 * Définition de la classe Presentateur. *
 *****************************************/

#include "Presentateur.hpp"

/*****************
 * Presentateur. *
 *****************/

Presentateur::Presentateur(const int& dimensionMinimum,
			   const int& dimensionMaximum,
			   const int& dimension):
  dimensionMinimum_(dimensionMinimum),
  dimensionMaximum_(dimensionMaximum),
  ptrModele_(new grenouilloland(dimension)),
  ptrVue_(new Vue(*this)) {
}

/*************************
 * lireDimensionMinimum. *
 *************************/

const int&
Presentateur::lireDimensionMinimum() const {
  return dimensionMinimum_;
}

/*************************
 * lireDimensionMaximum. *
 *************************/

const int&
Presentateur::lireDimensionMaximum() const {
  return dimensionMaximum_;
}

/***************
 * lireModele. *
 ***************/

const JeuDeLaVie&
Presentateur::lireModele() const {
  return *ptrModele_;
}

/************
 * lireVue. *
 ************/

const Vue&
Presentateur::lireVue() const {
  return *ptrVue_;
}

/**************
 * dimension. *
 **************/

const int&
Presentateur::dimension() const {
  return ptrModele_->lireDimension();
}

/*************
 * demarrer. *
 *************/

void
Presentateur::demarrer() {
  Gtk::Main::run(*ptrVue_);
}

/***************
 * estVivante. *
 ***************/

bool
Presentateur::estVivante(const int& ligne, const int& colonne) const {
  return ptrModele_->lireNenuphar(ligne, colonne).estVivante();
}

/*************
 * basculer. *
 *************/

void
Presentateur::basculer(const int& ligne, const int& colonne) {
  ptrModele_->basculer(ligne, colonne);
}

/******************
 * void suivante. *
 ******************/

void
Presentateur::suivante() {
  ptrModele_->suivante();
}

/******************
 * reinitialiser. *
 ******************/

void
Presentateur::reinitialiser() {
  ptrModele_->reinitialiser();
}

/******************
 * nouveauModele. *
 ******************/

void
Presentateur::nouveauModele(const int& dimension) {
  ptrModele_.reset(new grenouilloland(dimension));
}

