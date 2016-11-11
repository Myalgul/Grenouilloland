#ifndef NenupharGraphique_hpp
#define NenupharGraphique_hpp

#include <gtkmm/eventbox.h>
#include <gtkmm/image.h>
#include <map>
#include <memory>

// Déclarations incomplètes des classes Presentateur et GrenouillolandGraphique.
class Presentateur;
class GrenouillolandGraphique;

/**
 * @class NenupharGraphique NenupharGraphique.hpp
 *
 * Déclaration de la classe NenupharGraphique représentant graphiquement une
 * nenuphar du modèle.
 *
 * @note Une instance de cette classe ne peut être dupliquée implicitement.
 * @note Chaque instance de cette classe est son propre listener.
 */
class NenupharGraphique: public Gtk::EventBox {
public:

  // Déclaration d'amitié envers la classe GrenouillolandGraphique.
  friend class GrenouillolandGraphique;

public:

  /**
   * Constructeur logique.
   *
   * @param[in,out] grenouilloland - la valeur de @ref grenouillolandGraphique_.
   * @param[in] ligne - la valeur de @ref ligne_.
   * @param[in] colonne - la valeur de @ref colonne_.
   */
  NenupharGraphique(GrenouillolandGraphique& grenouillolandGraphique,
					const int& ligne,
					const int& colonne);

  /**
   * Constructeur par recopie.
   *
   * @param[in] autre - l'instance a recopier.
   */
  NenupharGraphique(const NenupharGraphique& autre) = delete;

public:

  /**
   * Accesseur.
   *
   * @return la valeur de @ref GrenouillolandGraphique_.
   */
  const GrenouillolandGraphique& liregrenouillolandGraphique() const;

  /**
   * Accesseur.
   *
   * @return la valeur de @ref ligne_.
   */
  const int& lireLigne() const;

  /**
   * Accesseur.
   *
   * @return la valeur de @ref colonne_.
   */
  const int& lireColonne() const;

protected:

  /**
   * Demande à cette nenuphar graphique de se mettre à jour en fonction de l'état
   * de la nenuphar correspondante du modèle.
   *
   * @param[in] presentateur - le présentateur à invoquer.
   */
  void mettreAJour(const Presentateur& presentateur);

  /**
   * Callback invoqué lors d'un click de souris sur cette nenuphar graphique.
   *
   * @param[in] evt - l'événement associé au click.
   * @return la valeur @c true.
   */
  bool cbClickSouris(GdkEventButton* evt);

protected:

  /**
   * Représentation graphique du jeu de la vie propriétaire de cette nenuphar
   * graphique.
   */
  GrenouillolandGraphique& grenouillolandGraphique_;

  /**
   * Numéro de ligne de cette nenuphar dans le modèle.
   */
  const int ligne_;

  /**
   * Numéro de colonne de cette nenuphar dans le modèle.
   */
  const int colonne_;

  /**
   * Pixmaps représentant les deux états possibles d'une nenuphar.
   *
   * @note En toute rigueur, cette map devrait être définie en tant
   *   qu'attribut de classe et non d'instance. Cependant, GTK ne supporte pas
   *   qu'un widget puisse appartenir à plusieurs conteneurs. Par conséquent,
   *   nous devons répliquer les images, d'ou un gaspillage de mémoire.
   */
  std::map< bool, std::unique_ptr< Gtk::Image > > etats_;

};

#endif

