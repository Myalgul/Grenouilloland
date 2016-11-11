
#ifndef Grenouilloland_hpp
#define Grenouilloland_hpp

#include "Nenuphar.hpp"
#include <vector>

/**
 * @class Grenouilloland Grenouilloland.hpp
 *
 * D�claration de la classe Grenouilloland repr�sentant une impl�mentation
 * s�quentielle du jeu de la vie.
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
   * Destructeur red�finissable.
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
   * fournis en arguments, d'un �tat a un autre.
   *
   * @param[in] ligne - le num�ro de ligne.
   * @param[in] colonne - le num�ro de colonne.
   */
  void basculer(const int& ligne, const int& colonne);

  /**
   * R�initialise ce jeu a partir de nenuphars morts.
   */
  void reinitialiser();

public:

  /**
   * Calcule le nombre de g�n�rations fourni en argument.
   *
   * @param[in] iterations - le nombre d'it�rations � effectuer.
   * @note Cette m�thode est red�finissable afin de laisser aux classes d�riv�es
   *   la possibilit� d'impl�menter un autre algorithme de mise � jour
   *   (�ventuellement parall�le).
   */
  virtual void calculer(const int& iterations);

  /**
   * Calcule la g�n�ration suivante.
   *
   * @note Cette m�thode est red�finissable afin de laisser aux classes d�riv�es
   *   la possibilit� d'impl�menter un autre algorithme de mise � jour
   *   (�ventuellement parall�le).
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
