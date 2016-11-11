#ifndef Presentateur_hpp
#define Presentateur_hpp

#include "../modele/Grenouilloland.hpp"
#include "../vue/Vue.hpp"

/**
 * @class Presentateur Presentateur.hpp
 *
 * D�claration de la classe Presentateur repr�sentant le pr�sentateur dans le
 * mod�le d'architecture graphique MVP.
 *
 * @note Une instance de cette classe ne peut �tre dupliqu�e implicitement.
 */
class Presentateur {
public:

  /**
   * Constructeur logique.
   *
   * @param[in] dimensionMinimum - la valeur de @ref dimensionMinimum_.
   * @param[in] dimensionMaximum - la valeur de @ref dimensionMaximum_.
   * @param[in] dimension - la r�solution initiale.
   */
  Presentateur(const int& dimensionMinimum,
	       const int& dimensionMaximum,
	       const int& resolution);

  /**
   * Constructeur par recopie.
   *
   * @param[in] autre - l'instance � recopier.
   */
  Presentateur(const Presentateur& autre) = delete;

public:

  /**
   * Accesseur.
   *
   * @return la valeur de @ref dimensionMinimum_.
   */
  const int& lireDimensionMinimum() const;

  /**
   * Accesseur.
   *
   * @return la valeur de @ref dimensionMaximum_.
   */
  const int& lireDimensionMaximum() const;

  /**
   * Accesseur.
   *
   * @return la valeur point�e par @ref ptrModele_.
   */
  const Grenouilloland& lireModele() const;

  /**
   * Accesseur.
   *
   * @return la valeur point�e par @ref ptrVue_.
   */
  const Vue& lireVue() const;

public:

  /**
   * Retourne la dimension du mod�le associ� � ce presentateur.
   *
   * @return la dimension du mod�le associ� � ce pr�sentateur.
   */
  const int& dimension() const;

  /**
   * D�marre ce presentateur.
   */
  void demarrer();

  /**
   * Indique si le nenuphar du mod�le dont les num�ros de ligne et de colonne
   * sont fournis en arguments, est vivante.
   *
   * @param[in] ligne - le num�ro de ligne.
   * @param[in] colonne - le num�ro de colonne.
   * @return @c true si le nenuphar du mod�le correspondante est vivante sinon
   *   @c false.
   */
  bool estVivante(const int& ligne, const int& colonne) const;

  /**
   * Fait basculer l'�tat du nenuphar du mod�le dont les num�ros de ligne et
   * de colonnes sont fournis en arguments.
   *
   * @param[in] ligne - le num�ro de ligne.
   * @param[in] colonne - le num�ro de colonne.
   */
  void basculer(const int& ligne, const int& colonne);

  /**
   * Calcule la g�n�ration de nenuphars suivante.
   */
  void suivante();

  /**
   * R�initialise toutes les nenuphars du mod�le avec des nenuphars morts.
   */
  void reinitialiser();

  /**
   * Change le mod�le associ� � ce presentateur.
   *
   * @param[in] dimension - la dimension souhait�e.
   */
  void nouveauModele(const int& dimension);

public:

  /**
   * Op�rateur d'affectation.
   *
   * @param[in] autre - l'instance � recopier.
   * @return cette instance apr�s recopie.
   */
  Presentateur& operator=(const Presentateur& autre) = delete;

protected:

  /**
   * Dimension minimum du mod�le.
   */
  const int dimensionMinimum_;

  /**
   * Dimension maximum du mod�le.
   */
  const int dimensionMaximum_;

  /**
   * Mod�le associ� � ce presentateur.
   */
  std::unique_ptr< Grenouilloland > ptrModele_;

  /**
   * Vue associ�e � ce pr�sentateur.
   */
  std::unique_ptr< Vue > ptrVue_;

};

#endif

