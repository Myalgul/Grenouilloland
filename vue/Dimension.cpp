/****************************
 * Définition de la classe. *
 ****************************/

#include "../presentateur/Presentateur.hpp"
#include "Dimension.hpp"

/**************
 * Dimension. *
 **************/

Dimension::Dimension(const Glib::ustring& titre, Vue& vue):
   Gtk::Frame(titre),
   ptrVue_(&vue) {

  // Obtention du présentateur.
  const Presentateur& presentateur = vue.lirePresentateur();

  // Ajustement basé sur les dimension minimum, maximum et initiale du modèle.
  const int minimum = presentateur.lireDimensionMinimum();
  const int maximum = presentateur.lireDimensionMaximum();
  const int initiale = presentateur.dimension();
  const double incrPas = 1.0;
  const double incrPage = 2.0;
  const double taillePage = 0.0;
  /*Glib::RefPtr< Gtk::Adjustment > ajustement =
    Gtk::Adjustment::create(initiale,
			    minimum,
			    maximum,
			    incrPas,
			    incrPage,
			    taillePage);

  // Finalisation de la barre de défilement et ajout dans le contour.
  barreDeDefilement_.set_adjustment(ajustement);
  add(barreDeDefilement_);

  // Connection de l'événement value_changed à son callback.
  auto crochet = sigc::mem_fun(*this, &Dimension::cbChangementDeValeur);
  ajustement->signal_value_changed().connect(crochet);*/

}

/************
 * lireVue. *
 ************/

const Vue&
Dimension::lireVue() const {
  return *ptrVue_;
}

/***********
 * valeur. *
 ***********/

int
Dimension::valeur() const {
  return barreDeDefilement_.get_value();
}

/*************************
 * cbChangementDeValeur. *
 *************************/

void
Dimension::cbChangementDeValeur() {

  // Effacement de ce contrôle pour pouvoir être réaffichée par sa vue
  // propriétaire tout à l'heure.
  hide();

  // Changement du modèle.
  ptrVue_->cbChangerModele();

}

