#ifndef GrenouillolandGraphique_hpp
#define GrenouillolandGraphique_hpp

#include "NenupharGraphique.hpp"
#include <gtkmm/aspectframe.h>
#include <gtkmm/grid.h>
#include <vector>

// Déclaration incomplète de la classe Vue.
class Vue;

/**
 * @class grenouillolandGraphique grenouillolandGraphique.hpp
 *
 * Déclaration de la classe grenouillolandGraphique représentant une génération
 * de Nenuphars graphiques.
 *
 * @note Une instance de cette classe ne peut être dupliquée implicitement.
 */
class GrenouillolandGraphique: public Gtk::AspectFrame {
public:

  // Déclarations d'amitié envers les classes Vue et NenupharGraphique.
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
   * Met à jour l'ensemble des Nenuphars graphiques de ce jeu de la vie
   * graphique.
   *
   * @param[in] presentateur - le présentateur a invoquer.
   */
  void mettreAJour(const Presentateur& presentateur);

protected:

  /**
   * Vue propriétaire de ce jeu de la vie graphique.
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

