#ifndef Presentateur_hpp
#define Presentateur_hpp

#include "../modele/Grenouilloland.hpp"
#include "../vue/Vue.hpp"

/**
 * @class Presentateur Presentateur.hpp
 *
 * Déclaration de la classe Presentateur représentant le présentateur dans le
 * modèle d'architecture graphique MVP.
 *
 * @note Une instance de cette classe ne peut être dupliquée implicitement.
 */
class Presentateur {
public:

  /**
   * Constructeur logique.
   *
   * @param[in] dimensionMinimum - la valeur de @ref dimensionMinimum_.
   * @param[in] dimensionMaximum - la valeur de @ref dimensionMaximum_.
   * @param[in] dimension - la résolution initiale.
   */
  Presentateur(const int& dimensionMinimum,
	       const int& dimensionMaximum,
	       const int& resolution);

  /**
   * Constructeur par recopie.
   *
   * @param[in] autre - l'instance à recopier.
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
   * @return la valeur pointée par @ref ptrModele_.
   */
  const Grenouilloland& lireModele() const;

  /**
   * Accesseur.
   *
   * @return la valeur pointée par @ref ptrVue_.
   */
  const Vue& lireVue() const;

public:

  /**
   * Retourne la dimension du modèle associé à ce presentateur.
   *
   * @return la dimension du modèle associé à ce présentateur.
   */
  const int& dimension() const;

  /**
   * Démarre ce presentateur.
   */
  void demarrer();

  /**
   * Indique si le nenuphar du modèle dont les numéros de ligne et de colonne
   * sont fournis en arguments, est vivante.
   *
   * @param[in] ligne - le numéro de ligne.
   * @param[in] colonne - le numéro de colonne.
   * @return @c true si le nenuphar du modèle correspondante est vivante sinon
   *   @c false.
   */
  bool estVivante(const int& ligne, const int& colonne) const;

  /**
   * Fait basculer l'état du nenuphar du modèle dont les numéros de ligne et
   * de colonnes sont fournis en arguments.
   *
   * @param[in] ligne - le numéro de ligne.
   * @param[in] colonne - le numéro de colonne.
   */
  void basculer(const int& ligne, const int& colonne);

  /**
   * Calcule la génération de nenuphars suivante.
   */
  void suivante();

  /**
   * Réinitialise toutes les nenuphars du modèle avec des nenuphars morts.
   */
  void reinitialiser();

  /**
   * Change le modèle associé à ce presentateur.
   *
   * @param[in] dimension - la dimension souhaitée.
   */
  void nouveauModele(const int& dimension);

public:

  /**
   * Opérateur d'affectation.
   *
   * @param[in] autre - l'instance à recopier.
   * @return cette instance après recopie.
   */
  Presentateur& operator=(const Presentateur& autre) = delete;

protected:

  /**
   * Dimension minimum du modèle.
   */
  const int dimensionMinimum_;

  /**
   * Dimension maximum du modèle.
   */
  const int dimensionMaximum_;

  /**
   * Modèle associé à ce presentateur.
   */
  std::unique_ptr< Grenouilloland > ptrModele_;

  /**
   * Vue associée à ce présentateur.
   */
  std::unique_ptr< Vue > ptrVue_;

};

#endif

