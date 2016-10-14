/*********************************************
 * D�finition de la classe NenupharGraphique. *
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

  // Obtention du pr�sentateur.
  const Presentateur& presentateur = vue.lirePresentateur();

  // Cr�ation des pixmaps repr�sentants les �tats d'une nenuphar.
  {

    // Renommage de type local.
    typedef std::unique_ptr< Gtk::Image > Pointer;

    // La nenuphar est morte.
    etats_[false] = Pointer(new Gtk::Image(vue.lireImage("morte")));

    // La nenuphar est vivante.
    etats_[true] = Pointer(new Gtk::Image(vue.lireImage("vivante")));

  }

  // Connection du callback associ� au click de souris.
  {
    auto crochet = sigc::mem_fun(*this, &NenupharGraphique::cbClickSouris);
    signal_button_press_event().connect(crochet);
  }

  // Mise � jour de cette nenuphar graphique.
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

  // Obtention du nouvel �tat de la nenuphar du mod�le correspondante via le
  // pr�sentateur.
  const bool etat = presentateur.estVivante(ligne_, colonne_);

  // Obtention du pixmap correspondant.
  Gtk::Image& image = *etats_[etat];

  // Si l'�tat de cette nenuphar n'a pas chang�, il n'y a rien � faire.
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

  // Obtention du pr�sentateur modifiable associ� � la vue.
  Presentateur& presentateur = vue.lirePresentateurModifiable();

  // Demander au pr�sentateur de bien vouloir faire basculer la nenuphar du
  // mod�le correspondante.
  presentateur.basculer(ligne_, colonne_);

  // Mise � jour de cette nenuphar graphique.
  mettreAJour(presentateur);

  // Syst�matiquement retourner la valeur vrai.
  return true;

}

