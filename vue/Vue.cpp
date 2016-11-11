/********************************
 * Définition de la classe Vue. *
 ********************************/

#include "../presentateur/Presentateur.hpp"

/****************
 * initialiser. *
 ****************/

void
Vue::initialiser() {

  // Créations des pixbufs.
  images_["grenouilloland"] =
    Gdk::Pixbuf::create_from_file(cheminImages_ + "coeur.png");
  images_["morte"] =
    Gdk::Pixbuf::create_from_file(cheminImages_ + "grand-nenuphare-rouge-96x96.png");
  images_["vivante"] =
    Gdk::Pixbuf::create_from_file(cheminImages_ + "grand-nenuphare-jaune-96x96.png");

}

/*****************
 * lireTitreVue. *
 *****************/

const Glib::ustring
Vue::lireTitreVue() {
  return titreVue_;
}

/************************
 * lireTitregrenouilloland. *
 ************************/

const Glib::ustring
Vue::lireTitreGrenouilloland() {
  return titregrenouilloland_;
}

/***********************
 * lireTitreDimension. *
 ***********************/

const Glib::ustring
Vue::lireTitreDimension() {
  return titreDimension_;
}

/**************
 * lireImage. *
 **************/

const Glib::RefPtr< Gdk::Pixbuf>&
Vue::lireImage(const Glib::ustring& nom) {
  return images_[nom];
}

/********
 * Vue. *
 ********/

Vue::Vue(Presentateur& presentateur):
  presentateur_(presentateur),
  ptrgrenouillolandGraphique_(new GrenouillolandGraphique(titregrenouilloland_, *this)),
  dimension_(titreDimension_, *this) {

  // Titre de la vue.
  set_title(titreVue_);

  // Gestionnaire de mise en forme associé à la fenêtre principale.
  Gtk::VBox* gestionnaire = Gtk::manage(new Gtk::VBox());
  add(*gestionnaire);

  // Construction de la barre de menus et d'outils.
  construireBarreMenusEtOutils(*gestionnaire);

  // Construction de la partie centrale de la fenêtre principale.
  construirePartieCentrale(*gestionnaire);

  // Construction de la partie inférieure de la fenêtre principale.
  construirePartieInferieure(*gestionnaire);

  // La fenêtre principale est rendue non redimensionnable. Cela permettra de
  // forcer le recalcul des dimensions lorsque la dimension du jeu de la vie
  // sera modifiée.
  set_resizable(false);

  // Affichage de tous les composants graphiques.
  show_all_children();

}

/*********************
 * lirePresentateur. *
 *********************/

const Presentateur&
Vue::lirePresentateur() const {
  return presentateur_;
}

/*******************************
 * lirePresentateurModifiable. *
 *******************************/

Presentateur&
Vue::lirePresentateurModifiable() {
  return presentateur_;
}

/*********************************
 * construireBarreMenusEtOutils. *
 *********************************/

void
Vue::construireBarreMenusEtOutils(Gtk::VBox& gestionnaire) {

  // Groupe d'actions.
  Glib::RefPtr< Gtk::ActionGroup > groupe = Gtk::ActionGroup::create();
  groupe->add(Gtk::Action::create("CommandesMenu",
				  "Commandes"));

  // Action "Suivante".
  {
    Glib::RefPtr< Gtk::Action > action =
      Gtk::Action::create("CommandesSuivante",
			  Gtk::Stock::EXECUTE,
			  "Suivante",
			  "Calculer la génération suivante.");
    auto crochet = sigc::mem_fun(*this, &Vue::cbSuivante);
    groupe->add(action, crochet);
  }

  // Action "Nouveau".
  {
    Glib::RefPtr< Gtk::Action > action =
      Gtk::Action::create("CommandesNouveau",
			  Gtk::Stock::NEW,
			  "Nouvelle partie",
			  "Préparer une nouvelle simulation.");
    auto crochet = sigc::mem_fun(*this, &Vue::cbNouveau);
    groupe->add(action, crochet);
  }

  // Action "A propos ...".
  {
    Glib::RefPtr< Gtk::Action > action =
      Gtk::Action::create("CommandesAPropos",
			  Gtk::Stock::ABOUT,
			  "À propos ...",
			  "Présenter l'application.");
    auto crochet = sigc::mem_fun(*this, &Vue::cbAPropos);
    groupe->add(action, crochet);
  }

  // Action "Quitter".
  {
    Glib::RefPtr< Gtk::Action > action =
      Gtk::Action::create("CommandesQuitter",
			  Gtk::Stock::QUIT,
			  "Quitter",
			  "Quitter l'application.");
    auto crochet = sigc::mem_fun(*this, &Vue::cbQuitter);
    groupe->add(action, crochet);
  }

  // Manager des groupes d'actions.
  Glib::RefPtr< Gtk::UIManager > manager = Gtk::UIManager::create();
  manager->insert_action_group(groupe);
  add_accel_group(manager->get_accel_group());

  // Structures XML des barres de menus et d'outils.
  const Glib::ustring structures =
    "<ui>"
    "  <menubar name='BarreMenus'>"
    "    <menu action='CommandesMenu'>"
    "      <menuitem action='CommandesSuivante'/>"
    "      <menuitem action='CommandesNouveau'/>"
    "      <menuitem action='CommandesAPropos'/>"
    "      <separator/>"
    "      <menuitem action='CommandesQuitter'/>"
    "    </menu>"
    "  </menubar>"
    "  <toolbar  name='BarreOutils'>"
    "    <toolitem action='CommandesSuivante'/>"
    "    <toolitem action='CommandesNouveau'/>"
    "    <toolitem action='CommandesAPropos'/>"
    "    <toolitem action='CommandesQuitter'/>"
    "  </toolbar>"
    "</ui>";
  manager->add_ui_from_string(structures);

  // Ajout des barres de menus et d'outils dans le gestionnaire. Chacun
  // occupe une ligne complète de la grille.
  Gtk::Widget* ptrBarreMenus = manager->get_widget("/BarreMenus");
  if (ptrBarreMenus != nullptr) {
    gestionnaire.pack_start(*ptrBarreMenus, Gtk::PACK_SHRINK);
  }
  Gtk::Widget* ptrBarreOutils = manager->get_widget("/BarreOutils");
  if(ptrBarreOutils != nullptr) {
    gestionnaire.pack_start(*ptrBarreOutils, Gtk::PACK_SHRINK);
  }

}

/*****************************
 * construirePartieCentrale. *
 *****************************/

void
Vue::construirePartieCentrale(Gtk::VBox& gestionnaire) {

  // Ajout du gestionnaire de mise en forme pour la partie centrale.
  gestionnaire.add(gestionnaireCentre_);

  // Ajout du jeu de la vie graphique dans le gestionnaire de la partie
  // centrale.
  gestionnaireCentre_.pack_start(*ptrgrenouillolandGraphique_);

}

/*******************************
 * construirePartieInferieure. *
 *******************************/

void
Vue::construirePartieInferieure(Gtk::VBox& gestionnaire) {
  gestionnaire.add(dimension_);
}

/***************
 * cbSuivante. *
 ***************/

void
Vue::cbSuivante() {

  // Passage à la génération suivante via le présentateur.
  presentateur_.suivante();

  // Demander au jeu de la vie graphique de bien vouloir se mettre à jour.
  ptrgrenouillolandGraphique_->mettreAJour(presentateur_);

}

/**************
 * cbNouveau. *
 **************/

void
Vue::cbNouveau() {

  // Réinitialisation du modèle via le présentateur associé à cette vue.
  presentateur_.reinitialiser();

  // Demander au jeu de la vie graphique de bien vouloir se mettre à jour.
  ptrgrenouillolandGraphique_->mettreAJour(presentateur_);

}

/********************
 * cbChangerModele. *
 ********************/

void
Vue::cbChangerModele() {


  // Création, via le présentateur, d'un nouveau modèle avec la dimension
  // souhaitée.
  presentateur_.nouveauModele(dimension_.valeur());

  // Suppression de l'ancien jeu de la vie graphique et remplacement par le
  // nouveau.
  gestionnaireCentre_.remove(*ptrgrenouillolandGraphique_);
  ptrgrenouillolandGraphique_.reset(new GrenouillolandGraphique(titregrenouilloland_,
							*this));
  gestionnaireCentre_.pack_start(*ptrgrenouillolandGraphique_);

  // Réaffichage de tous les composants de la fenêtre principale. Le fait que
  // cette dernière soit non redimensionnable entraîne le recalcul des
  // dimensions de tous ses composants.
  show_all_children();

}

/****************
 * cbAPropos(). *
 ****************/

void
Vue::cbAPropos() {

  // Construction du dialogue.
  Gtk::AboutDialog apropos;
  apropos.set_transient_for(*this);
  apropos.set_program_name("Jeu de la vie");
  apropos.set_version("0.1");
  apropos.set_copyright("Emmanuel Cagniot - emmanuel.cagniot@ensicaen.fr");
  apropos.set_comments("TP C++/Gtkmm du M1 Info.");
  //apropos.set_authors({ "Emmanuel Cagniot" });
  apropos.set_logo(images_["jeudelavie"]);

  // Affichage du dialogue.
  apropos.run();

  // Effacement du dialogue.
  apropos.hide();

}

/**************
 * cbQuitter. *
 **************/

void
Vue::cbQuitter() {
  hide();
}

/**************
 * titreVue_. *
 **************/

const Glib::ustring Vue::titreVue_("Le jeu de la vie");

/*********************
 * titreGeneration_. *
 *********************/

const Glib::ustring Vue::titregrenouilloland_("Génération");

/********************
 * titreDimension_. *
 ********************/

const Glib::ustring Vue::titreDimension_("Dimension");

/******************
 * cheminImages_. *
 ******************/

const Glib::ustring Vue::cheminImages_("Icones/");

/************
 * images_. *
 ************/

std::map< Glib::ustring, Glib::RefPtr< Gdk::Pixbuf> > Vue::images_;

