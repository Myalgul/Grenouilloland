#ifndef Nenuphar_hpp
#define Nenuphar_hpp

#include "ElementSurface.hpp"

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
class Nenuphar : public ElementSurface {
public:

    /**
    * Constructeur logique instanciant un nenuphar en utilisant le constructeur
    * par de la classe ElementSurface.
    */
    using ElementSurface::ElementSurface;
    ~Nenuphar(){};
    void affectationGrenouille(Grenouille* grenouille) const override;
    bool vieillir() override;

public:

    /**
    * Accesseur.
    *
    * @return la valeur de @ref taille_.
    */
    const int& lireTaille() const;

protected:

    /**
     * Taille de ce nenuphar.
     */
    int taille_ = 3;
};

#endif

