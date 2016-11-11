/************************************************
 * Définition de la classe GrenouillolandGraphique. *
 ************************************************/

#include "../presentateur/Presentateur.hpp"

/************************
 * GenerationGraphique. *
 ************************/

GrenouillolandGraphique::GrenouillolandGraphique(const Glib::ustring& titre, Vue& vue):
  Gtk::AspectFrame(titre),
  vue_(vue) {

  // Ajout du gestionnaire dans le contour.
  add(gestionnaire_);

  // Obtention du presentateur associe a la vue proprietaire.
  const Presentateur& presentateur = vue.lirePresentateur();

  // Obtention du modèle via le présentateur.
  const Grenouilloland& modele = presentateur.lireModele();

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
GrenouillolandGraphique::lireVue() const {
  return vue_;
}

/**********************
 * lireVueModifiable. *
 **********************/

Vue&
GrenouillolandGraphique::lireVueModifiable() {
  return vue_;
}

/****************
 * mettreAJour. *
 ****************/

void
GrenouillolandGraphique::mettreAJour(const Presentateur& presentateur) {
  for (NenupharGraphique* ptrNenuphar : nenuphars_) {
    ptrNenuphar->mettreAJour(presentateur);
  }
}

