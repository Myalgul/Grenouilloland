#ifndef Nenuphar_hpp
#define Nenuphar_hpp

#include "ElementSurface.hpp"

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
class Nenuphar : public ElementSurface {
public:

    /**
    * Constructeur logique instanciant un nenuphar en utilisant le constructeur
    * par de la classe ElementSurface.
    */
    using ElementSurface::ElementSurface;
    ~Nenuphar(){};
    void affectationGrenouille(Grenouille* grenouille) const override;

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

    /**
    * Accesseur.
    *
    * @return la valeur de @ref colonne_.
    */
    const char& lireRepresentation() const;

protected:

    /**
    * Numéro de ligne de ce nenuphar.
    */
    int ligne_;

    /**
    * Numéro de colonne de ce nenuphar.
    */
    int colonne_;

    /**
    * Représentation de ce nenuphar.
    */
    int representation_;
};

#endif

