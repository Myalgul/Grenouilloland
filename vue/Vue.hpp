#ifndef Vue_hpp
#define Vue_hpp

#include "grenouillolandGraphique.hpp"
#include "Dimension.hpp"
#include <gtkmm/main.h>
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/action.h>
#include <gtkmm/actiongroup.h>
#include <gtkmm/stock.h>
#include <gtkmm/uimanager.h>
#include <gtkmm/aboutdialog.h>
#include <gtkmm/cellrendererpixbuf.h>
#include <map>

// D�claration incompl�te de la classe Presentateur.
class Presentateur;

/**
 * @class Vue Vue.hpp
 *
 * D�claration de la classe Vue repr�sentant l'interface graphique de
 * l'application
 *
 * @note Une instance de cette classe ne peut �tre dupliqu�e implicitement.
 */
class Vue: public Gtk::Window {
public:

  // D�clarations d'amiti� envers les classes NenupharGraphique et Dimension.
  friend class NenupharGraphique;
  friend class Dimension;

public:

  /**
   * Initialise cette classe.
   *
   * @note cette m�thode doit �tre appel�e avant toutes les autres.
   */
  static void initialiser();

public:

  /**
   * Accesseur.
   *
   * @return la valeur de @ref titreVue_.
   */
  static const Glib::ustring lireTitreVue();

  /**
   * Accesseur.
   *
   * @return la valeur de @ref titregrenouilloland_.
   */
  static const Glib::ustring lireTitregrenouilloland();

  /**
   * Accesseur.
   *
   * @return la valeur de @ref titreDimension_.
   */
  static const Glib::ustring lireTitreDimension();

protected:

  /**
   * Retourne l'image dont le nom est fourni en argument.
   *
   * @param[in] nom - le nom de l'image.
   * @return l'image correspondante.
   */
  static const Glib::RefPtr< Gdk::Pixbuf>& lireImage(const Glib::ustring& nom);

public:

  /**
   * Constructeur logique.
   *
   * @param[in] presentateur - la valeur de @ref presentateur_.
   */
  Vue(Presentateur& presentateur);

  /**
   * Constructeur par recopie.
   *
   * @param[in] autre - l'instance � recopier.
   */
  Vue(const Vue& autre) = delete;

public:

  /**
   * Accesseur.
   *
   * @return la valeur de @ref presentateur_.
   */
  const Presentateur& lirePresentateur() const;

public:

  /**
   * Op�rateur d'affectation.
   *
   * @param[in] autre - l'instance � recopier.
   * @return cette instance apr�s recopie.
   */
  Vue& operator=(const Vue& autre) = delete;

protected:

  /**
   * Accesseur.
   *
   * @return la valeur de @ref presentateur_.
   */
  Presentateur& lirePresentateurModifiable();

protected:

  /**
   * Construit les barre de menus et d'outils.
   *
   * @param[in,out] gestionnaire - le gestionnaire de mise en forme associ� �
   *   la fen�tre principale.
   */
  void construireBarreMenusEtOutils(Gtk::VBox& gestionnaire);

  /**
   * Construit la partie centrale de la fen�tre principale qui contient un jeu
   * de la vie graphique.
   *
   * @param[in,out] gestionnaire - le gestionnaire de mise en forme associ� �
   *   la fen�tre principale.
   */
  void construirePartieCentrale(Gtk::VBox& gestionnaire);

  /**
   * Construit la partie inf�rieure de la fen�tre principale qui contient le
   * contr�leur de dimension du jeu de la vie.
   *
   * @param[in,out] gestionnaire - le gestionnaire de mise en forme associ� �
   *   la fen�tre principale.
   */
  void construirePartieInferieure(Gtk::VBox& gestionnaire);

protected:

  /**
   * Callback permettant de calculer la g�n�ration de cellules suivante.
   *
   * @note Cette m�thode est invoqu�e suite � un click sur l'entr�e "Demarrer"
   * du menu "Commandes ou bien sur le bouton correspondant dans la barre
   * d'outils.
   */
  void cbSuivante();

  /**
   * Callback permettant de pr�parer le jeu de la vie pour une nouvelle
   * simulation.
   *
   * @note Cette m�thode est invoqu�e suite � un click sur l'entr�e "Nouveau" du
   * menu "Commandes" ou bien sur le bouton correspondant dans la barre
   * d'outils.
   */
  void cbNouveau();

  /**
   * Callback permettant de changer la r�solution du jeu de la vie.
   *
   * @note Cette m�thode est invoqu�e par le contr�leur de la r�solution du jeu
   *   de la vie.
   */
  void cbChangerModele();

  /**
   * Callback permettant de pr�senter l'application et ses auteurs.
   *
   * @note Cette m�thode est invoqu�e suite � un click sur l'entr�e
   *   "A propos ..." du menu "Commandes" ou bien sur le bouton correspondant
   *   dans la barre d'outils.
   */
  void cbAPropos();

  /**
   * Callback permettant de quitter proprement l'application.
   *
   * @note Cette m�thode est invoqu�e suite � un click sur l'entr�e "Quitter" du
   *   menu "Commandes" ou bien sur le bouton correspondant dans la barre
   *   d'outils.
   */
  void cbQuitter();

protected:

  /**
   * Titre de cette vue.
   */
  static const Glib::ustring titreVue_;

  /**
   * Titre du jeu de la vie graphique.
   */
  static const Glib::ustring titregrenouilloland_;

  /**
   * Titre du contr�leur de la dimension du jeu de la vie.
   */
  static const Glib::ustring titreDimension_;

  /**
   * Chemins d'acc�s au r�pertoire contenant les images.
   */
  static const Glib::ustring cheminImages_;

  /**
   * Map permettant de stocker les images manipul�es par cette vue.
   */
  static std::map< Glib::ustring, Glib::RefPtr< Gdk::Pixbuf> > images_;

protected:

  /**
   * Pr�sentateur associ� � cette vue.
   */
  Presentateur& presentateur_;

  /**
   * Jeu de la vie graphique de cette vue.
   */
  std::unique_ptr< grenouillolandGraphique > ptrgrenouillolandGraphique_;

  /**
   * Contr�leur de la dimension du jeu de la vie de cette vue.
   */
  Dimension dimension_;

  /**
   * Gestionnaire de mise en forme associ� � la partie centrale de la
   * fen�tre principale. Cette partie contient le jeu de la vie graphique qui
   * change avec le mod�le. C'est pour cette raison que nous la d�finissons en
   * tant qu'attribut de cette vue.
   */
  Gtk::HBox gestionnaireCentre_;

};

#endif

