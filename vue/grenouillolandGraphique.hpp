#ifndef GrenouillolandGraphique_hpp
#define GrenouillolandGraphique_hpp

#include "NenupharGraphique.hpp"
#include <gtkmm/aspectframe.h>
#include <gtkmm/grid.h>
#include <vector>

// D�claration incompl�te de la classe Vue.
class Vue;

/**
 * @class grenouillolandGraphique grenouillolandGraphique.hpp
 *
 * D�claration de la classe grenouillolandGraphique repr�sentant une g�n�ration
 * de Nenuphars graphiques.
 *
 * @note Une instance de cette classe ne peut �tre dupliqu�e implicitement.
 */
class GrenouillolandGraphique: public Gtk::AspectFrame {
public:

  // D�clarations d'amiti� envers les classes Vue et NenupharGraphique.
  friend class Vue;
  friend class NenupharGraphique;

public:

  /**
   * Constructeur logique.
   *
   * @param[in] titre - le titre du contour.
   * @param[in,out] vue - la valeur de @ref vue_.
   */
  GrenouillolandGraphique(const Glib::ustring& titre, Vue& vue);

public:

  /**
   * Accesseur.
   *
   * @return la valeur de @ref vue_.
   */
  const Vue& lireVue() const;

protected:

  /**
   * Accesseur.
   *
   * @return la valeur de @ref vue_.
   */
  Vue& lireVueModifiable();

protected:

  /**
   * Met � jour l'ensemble des Nenuphars graphiques de ce jeu de la vie
   * graphique.
   *
   * @param[in] presentateur - le pr�sentateur a invoquer.
   */
  void mettreAJour(const Presentateur& presentateur);

protected:

  /**
   * Vue propri�taire de ce jeu de la vie graphique.
   */
  Vue& vue_;

  /**
   * Gestionnaire de mise en forme de ce jeu graphique.
   */
  Gtk::Grid gestionnaire_;

  /**
   * Nenuphars graphiques de ce jeu de la vie graphique.
   */
  std::vector< NenupharGraphique* > nenuphars_;

};

#endif

