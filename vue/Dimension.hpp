#ifndef Dimension_hpp
#define Dimension_hpp

#include <gtkmm/frame.h>
#include <gtkmm/scrollbar.h>
#include <gtkmm/adjustment.h>

// D�claration incompl�te de la classe Vue.
class Vue;

/**
 * @class Dimension Dimension.hpp
 *
 * D�claration de la classe Dimension repr�sentant un contr�leur de la dimension
 * du jeu de la vie. Le Widget utilis� est une barre de d�filement.
 *
 * @note Une instance de cette classe ne peut �tre dupliqu�e implicitement.
 * @note Chaque instance de cette classe est son propre listener.
 */
class Dimension: public Gtk::Frame {
public:

  /**
   * Constructeur logique.
   *
   * @param[in] titre - le titre du contour.
   * @param[in,out] vue - la valeur de @ref ptrVue_.
   */
  Dimension(const Glib::ustring& titre, Vue& vue);

  /**
   * Constructeur par recopie.
   *
   * @param[in] autre - l'instance � recopier.
   */
  Dimension(const Dimension& autre) = delete;

public:

  /**
   * Accesseur.
   *
   * @return la valeur point�e par @ref _ptrVue.
   */
  const Vue& lireVue() const;

public:

  /**
   * Retourne la dimension actuelle.
   *
   * @return la dimension actuelle.
   */
  int valeur() const;

protected:

  /**
   * Callback associ� au changement de valeur.
   */
  void cbChangementDeValeur();

public:

  /**
   * Op�rateur d'affectation.
   *
   * @param[in] autre - l'instance � recopier.
   * @return cette instance apr�s recopie.
   */
  Dimension& operator=(const Dimension& autre) = delete;

protected:

  /**
   * Unique vue propri�taire de ce controleur.
   */
  Vue* const ptrVue_;

  /**
   * Barre de d�filement.
   */
  Gtk::HScrollbar barreDeDefilement_;

};

#endif

