
#ifndef Grenouilloland_hpp
#define Grenouilloland_hpp

#include "Nenuphar.hpp"
#include <vector>

/**
 * @class Grenouilloland Grenouilloland.hpp
 *
 * Déclaration de la classe Grenouilloland représentant une implémentation
 * séquentielle du jeu de la vie.
 */
class Grenouilloland {
public:

  /**
   * Constructeur logique initialisant ce jeu avec des nenuphars morts.
   *
   * @param[in] dimension - la valeur de @ref dimension_.
   */
  Grenouilloland(const int& dimension);

  /**
   * Destructeur redéfinissable.
   */
  virtual ~Grenouilloland() = default;

public:

  /**
   * Accesseur.
   *
   * @return la valeur de @ref dimension_.
   */
  const int& lireDimension() const;

  /**
   * Retourne le nenuphar (en lecture seule) dont les numeros de lignes et de
   * colonnes sont fournis en arguments.
   *
   * @param[in] ligne - le numero de ligne.
   * @param[in] colonne - le numero de colonne.
   * @return le nenuphar (en lecture seule) correspondante.
   */
  const Nenuphar& lireNenuphar(const int& ligne, const int& colonne) const;

public:

  /**
   * Fait basculer le nenuphar dont les numeros de ligne et de colonne sont
   * fournis en arguments, d'un état a un autre.
   *
   * @param[in] ligne - le numéro de ligne.
   * @param[in] colonne - le numéro de colonne.
   */
  void basculer(const int& ligne, const int& colonne);

  /**
   * Réinitialise ce jeu a partir de nenuphars morts.
   */
  void reinitialiser();

public:

  /**
   * Calcule le nombre de générations fourni en argument.
   *
   * @param[in] iterations - le nombre d'itérations à effectuer.
   * @note Cette méthode est redéfinissable afin de laisser aux classes dérivées
   *   la possibilité d'implémenter un autre algorithme de mise à jour
   *   (éventuellement parallèle).
   */
  virtual void calculer(const int& iterations);

  /**
   * Calcule la génération suivante.
   *
   * @note Cette méthode est redéfinissable afin de laisser aux classes dérivées
   *   la possibilité d'implémenter un autre algorithme de mise à jour
   *   (éventuellement parallèle).
   */
  virtual void suivante();

protected:

  /**
   * Dimension de ce jeu.
   */
  const int dimension_;

  /**
   * Nenuphars de ce jeu.
   */
  std::vector< Nenuphar > nenuphar_;

};

#endif
