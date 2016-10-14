/************************************************
 * Définition de la classe grenouillolandGraphique. *
 ************************************************/

#include "../presentateur/Presentateur.hpp"

/************************
 * GenerationGraphique. *
 ************************/

grenouillolandGraphique::grenouillolandGraphique(const Glib::ustring& titre, Vue& vue):
  Gtk::AspectFrame(titre),
  vue_(vue) {

  // Ajout du gestionnaire dans le contour.
  add(gestionnaire_);

  // Obtention du presentateur associe a la vue proprietaire.
  const Presentateur& presentateur = vue.lirePresentateur();

  // Obtention du modèle via le présentateur.
  const grenouilloland& modele = presentateur.lireModele();

  // Obtention de dimension du modèle.
  const int& dimension = modele.lireDimension();

  // Boucle de création des Nenuphars graphiques.
  for (int i = 0; i < dimension; i ++) {
    for (int j = 0; j < dimension; j ++) {
      NenupharGraphique* nenuphar =
	Gtk::manage(new NenupharGraphique(*this, i, j));
      gestionnaire_.attach(*nenuphar, i, j, 1, 1);
      nenuphars_.push_back(nenuphar);
    }
  }

}

/************
 * lireVue. *
 ************/

const Vue&
grenouillolandGraphique::lireVue() const {
  return vue_;
}

/**********************
 * lireVueModifiable. *
 **********************/

Vue&
grenouillolandGraphique::lireVueModifiable() {
  return vue_;
}

/****************
 * mettreAJour. *
 ****************/

void
grenouillolandGraphique::mettreAJour(const Presentateur& presentateur) {
  for (NenupharGraphique* ptrNenuphar : Nenuphars_) {
    ptrNenuphar->mettreAJour(presentateur);
  }
}

