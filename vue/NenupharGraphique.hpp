#ifndef NenupharGraphique_hpp
#define NenupharGraphique_hpp

#include <gtkmm/eventbox.h>
#include <gtkmm/image.h>
#include <map>
#include <memory>

// D�clarations incompl�tes des classes Presentateur et grenouillolandGraphique.
class Presentateur;
class grenouillolandGraphique;

/**
 * @class NenupharGraphique NenupharGraphique.hpp
 *
 * D�claration de la classe NenupharGraphique repr�sentant graphiquement une
 * nenuphar du mod�le.
 *
 * @note Une instance de cette classe ne peut �tre dupliqu�e implicitement.
 * @note Chaque instance de cette classe est son propre listener.
 */
class NenupharGraphique: public Gtk::EventBox {
public:

  // D�claration d'amiti� envers la classe grenouillolandGraphique.
  friend class grenouillolandGraphique;

public:

  /**
   * Constructeur logique.
   *
   * @param[in,out] grenouilloland - la valeur de @ref grenouillolandGraphique_.
   * @param[in] ligne - la valeur de @ref ligne_.
   * @param[in] colonne - la valeur de @ref colonne_.
   */
  NenupharGraphique(grenouillolandGraphique& grenouillolandGraphique,
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
   * @return la valeur de @ref jeuDeLaVieGraphique_.
   */
  const grenouillolandGraphique& liregrenouillolandGraphique() const;

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
   * Demande � cette nenuphar graphique de se mettre � jour en fonction de l'�tat
   * de la nenuphar correspondante du mod�le.
   *
   * @param[in] presentateur - le pr�sentateur � invoquer.
   */
  void mettreAJour(const Presentateur& presentateur);

  /**
   * Callback invoqu� lors d'un click de souris sur cette nenuphar graphique.
   *
   * @param[in] evt - l'�v�nement associ� au click.
   * @return la valeur @c true.
   */
  bool cbClickSouris(GdkEventButton* evt);

protected:

  /**
   * Repr�sentation graphique du jeu de la vie propri�taire de cette nenuphar
   * graphique.
   */
  grenouillolandGraphique& grenouillolandGraphique_;

  /**
   * Num�ro de ligne de cette nenuphar dans le mod�le.
   */
  const int ligne_;

  /**
   * Num�ro de colonne de cette nenuphar dans le mod�le.
   */
  const int colonne_;

  /**
   * Pixmaps repr�sentant les deux �tats possibles d'une nenuphar.
   *
   * @note En toute rigueur, cette map devrait �tre d�finie en tant
   *   qu'attribut de classe et non d'instance. Cependant, GTK ne supporte pas
   *   qu'un widget puisse appartenir � plusieurs conteneurs. Par cons�quent,
   *   nous devons r�pliquer les images, d'ou un gaspillage de m�moire.
   */
  std::map< bool, std::unique_ptr< Gtk::Image > > etats_;

};

#endif

