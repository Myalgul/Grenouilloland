#ifndef Nenuphar_hpp
#define Nenuphar_hpp

// D�claration incompl�te de la classe grenouilloland.
class Grenouilloland;

/**
 * @class Nenuphar Nenuphar.hpp
 *
 * D�claration de la classe Nenuphar repr�sentant une nenuphar du jeu de la vie.
 *
 * @note Bien que les num�ros de ligne et de colonne d'une nenuphar ne changent
 *   pas, les attributs correspondants ne sont pas d�clar�s constants car la
 *   politique d'initialisation des conteneurs de la STL est bas�e sur la
 *   copie. En effet, l'op�rateur d'affectation ayant �t� implicitement
 *   supprim� (du fait du mot-cl� const), il serait alors impossible
 *   d'initialiser un vecteur de nenuphars � partir de la valeur d'une nenuphar
 *   donn�e.
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
   * Indique si cette nenuphar �tait vivante � l'it�ration pr�c�dente.
   *
   * @return @c true si cette nenuphar �tait vivante a l'it�ration pr�c�dente
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
   * Fait basculer cette nenuphar d'un �tat � un autre.
   */
  void basculer();

  /**
   * Archive l'�tat de cette nenuphar.
   */
  void archiver();

  /**
   * Met a jour cette nenuphar en fonction de son �tat ant�rieur et celui de ses
   * huit voisines.
   *
   * @param[in,out] proprietaire - le jeu de la vie propri�taire de cette
   *   nenuphar.
   */
  void mettreAJour(Grenouilloland& proprietaire);

protected:

  /**
   * Num�ro de ligne de cette nenuphar.
   */
  int ligne_;

  /**
   * Num�ro de colonne de cette nenuphar.
   */
  int colonne_;

  /**
   * Etat de cette nenuphar � l'it�ration pr�c�dente.
   */
  bool archive_;

  /**
   * Etat courant de cette nenuphar.
   */
  bool etat_;

};

#endif

