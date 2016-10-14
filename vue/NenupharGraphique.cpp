/*********************************************
 * Définition de la classe NenupharGraphique. *
 *********************************************/

#include "../presentateur/Presentateur.hpp"

/*********************
 * NenupharGraphique. *
 *********************/

NenupharGraphique::NenupharGraphique(grenouillolandGraphique& grenouillolandGraphique,
				   const int& ligne,
				   const int& colonne):
  grenouillolandGraphique_(grenouillolandGraphique),
  ligne_(ligne),
  colonne_(colonne) {

  // Obtention de la vue.
  const Vue& vue = grenouillolandGraphique.lireVue();

  // Obtention du présentateur.
  const Presentateur& presentateur = vue.lirePresentateur();

  // Création des pixmaps représentants les états d'une nenuphar.
  {

    // Renommage de type local.
    typedef std::unique_ptr< Gtk::Image > Pointer;

    // La nenuphar est morte.
    etats_[false] = Pointer(new Gtk::Image(vue.lireImage("morte")));

    // La nenuphar est vivante.
    etats_[true] = Pointer(new Gtk::Image(vue.lireImage("vivante")));

  }

  // Connection du callback associé au click de souris.
  {
    auto crochet = sigc::mem_fun(*this, &NenupharGraphique::cbClickSouris);
    signal_button_press_event().connect(crochet);
  }

  // Mise à jour de cette nenuphar graphique.
  mettreAJour(presentateur);

}

/****************************
 * liregrenouillolandGraphique. *
 ****************************/

const grenouillolandGraphique&
NenupharGraphique::liregrenouillolandGraphique() const {
  return grenouillolandGraphique_;
}

/**************
 * lireLigne. *
 **************/

const int&
NenupharGraphique::lireLigne() const {
  return ligne_;
}

/****************
 * lireColonne. *
 ****************/

const int&
NenupharGraphique::lireColonne() const {
  return colonne_;
}

/****************
 * mettreAJour. *
 ****************/

void
NenupharGraphique::mettreAJour(const Presentateur& presentateur) {

  // Obtention du nouvel état de la nenuphar du modèle correspondante via le
  // présentateur.
  const bool etat = presentateur.estVivante(ligne_, colonne_);

  // Obtention du pixmap correspondant.
  Gtk::Image& image = *etats_[etat];

  // Si l'état de cette nenuphar n'a pas changé, il n'y a rien à faire.
  if (&image == get_child()) {
    return;
  }

  // Sinon, suppression de l'ancien pixmap et affichage du nouveau.
  remove();
  add(image);
  image.show();

}

/******************
 * cbClickSouris. *
 ******************/

bool
NenupharGraphique::cbClickSouris(GdkEventButton* evt) {

  // Obtention de la vue modifiable.
  Vue& vue = grenouillolandGraphique_.lireVueModifiable();

  // Obtention du présentateur modifiable associé à la vue.
  Presentateur& presentateur = vue.lirePresentateurModifiable();

  // Demander au présentateur de bien vouloir faire basculer la nenuphar du
  // modèle correspondante.
  presentateur.basculer(ligne_, colonne_);

  // Mise à jour de cette nenuphar graphique.
  mettreAJour(presentateur);

  // Systématiquement retourner la valeur vrai.
  return true;

}

