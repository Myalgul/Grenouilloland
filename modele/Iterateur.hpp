#ifndef Iterateur_hpp
#define Iterateur_hpp

// Déclarations incomplètes des classes Nenuphar et Grenouilloland.
class Nenuphar;
class Grenouilloland;

/**
 * @class Iterateur Iterateur.hpp
 *
 * Déclaration de la classe Iterateur représentant un itérateur permettant de
 * parcourir les huits voisines d'une nenuphar du jeu de la vie.
 *
 * @note Cette classe implémente le behavioral design pattern Iterator.
 */
class Iterateur {
public:

  /**
   * Constructeur logique.
   *
   * @param[in] nenuphar - la valeur de @ref _nenuphar.
   * @param[in] proprietaire - la valeur de @ref _proprietaire.
   */
  Iterateur(const Nenuphar& nenuphar, const Grenouilloland& proprietaire);

public:

  /**
   * Accesseur.
   *
   * @return la valeur de @ref _nenuphar.
   */
  const Nenuphar& lireNenuphar() const;

  /**
   * Accesseur.
   *
   * @return la valeur de @ref _proprietaire.
   */
  const Grenouilloland& lireProprietaire() const;

  /**
   * Accesseur.
   *
   * @return la valeur de @ref _rang.
   */
  const int& lireRang() const;

public:

  /**
   * Indique si la nenuphar reperee par cet iterateur possede encore des
   * voisines non visitees.
   *
   * @return @c true si la nenuphar reperee par cet iterateur possede encore
   * des voisines non visitees, sinon @c false.
   */
  bool encore() const;

  /**
   * Retourne la nenuphar voisine courante et se positionne sur la suivante.
   *
   * @return la nenuphar voisine courante.
   */
  const Nenuphar& suivante();

protected:

  /**
   * Couples de deltas permettant de se positionner sur une case voisines à
   * partir des numéros de ligne et de colonne de la nenuphar repérée par cet
   * itérateur.
   *    7  0  1
   *    6  c  2
   *    5  4  3
   */
  static const int deltas_[8][2];

protected:

  /**
   * Nenuphar (en lecture seule) repérée par cet itérateur.
   */
  const Nenuphar& nenuphar_;

  /**
   * Instance (en lecture seule) du jeu de la vie propriétaire de la nenuphar
   * repèrée par cet itérateur.
   */
  const Grenouilloland& proprietaire_;

  /**
   * Rang de la nenuphar voisine courante dans la liste des huit voisines.
   */
  int rang_;

};

#endif

