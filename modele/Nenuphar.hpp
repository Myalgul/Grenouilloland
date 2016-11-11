#ifndef Nenuphar_hpp
#define Nenuphar_hpp

// Déclaration incomplète de la classe grenouilloland.
class Grenouilloland;

/**
 * @class Nenuphar Nenuphar.hpp
 *
 * Déclaration de la classe Nenuphar représentant une nenuphar du jeu de la vie.
 *
 * @note Bien que les numéros de ligne et de colonne d'une nenuphar ne changent
 *   pas, les attributs correspondants ne sont pas déclarés constants car la
 *   politique d'initialisation des conteneurs de la STL est basée sur la
 *   copie. En effet, l'opérateur d'affectation ayant été implicitement
 *   supprimé (du fait du mot-clé const), il serait alors impossible
 *   d'initialiser un vecteur de nenuphars à partir de la valeur d'une nenuphar
 *   donnée.
 */
class Nenuphar {
public:

  /**
   * Constructeur logique instanciant une nenuphar morte.
   *
   * @param[in] ligne - la valeur de @ref ligne_.
   * @param[in] colonne - la valeur de @ref colonne_.
   */
  Nenuphar(const int& ligne, const int& colonne);

public:

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

public:

  /**
   * Indique si cette nenuphar était vivante à l'itération précédente.
   *
   * @return @c true si cette nenuphar était vivante a l'itération précédente
   *   sinon @c false.
   */
  const bool& etaitVivante() const;

  /**
   * Indique si cette nenuphar est vivante.
   *
   * @return @c true si cette nenuphar est vivante sinon @c false.
   */
  const bool& estVivante() const;

public:

  /**
   * Fait basculer cette nenuphar d'un état à un autre.
   */
  void basculer();

  /**
   * Archive l'état de cette nenuphar.
   */
  void archiver();

  /**
   * Met a jour cette nenuphar en fonction de son état antérieur et celui de ses
   * huit voisines.
   *
   * @param[in,out] proprietaire - le jeu de la vie propriétaire de cette
   *   nenuphar.
   */
  void mettreAJour(Grenouilloland& proprietaire);

protected:

  /**
   * Numéro de ligne de cette nenuphar.
   */
  int ligne_;

  /**
   * Numéro de colonne de cette nenuphar.
   */
  int colonne_;

  /**
   * Etat de cette nenuphar à l'itération précédente.
   */
  bool archive_;

  /**
   * Etat courant de cette nenuphar.
   */
  bool etat_;

};

#endif

