#ifndef Eau_hpp
#define Eau_hpp

#include "ElementSurface.hpp"

class Eau : public ElementSurface {
public:

    /**
    * Constructeur logique instanciant de l'eau en utilisant le constructeur
    * par de la classe ElementSurface.
    */
    using ElementSurface::ElementSurface;
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
    * @return la valeur de @ref representation_.
    */
    const std::string& lireRepresentation() const;

protected:
    /**
    * Numéro de ligne de cet élément de surface.
    */
    int ligne_;

    /**
    * Numéro de colonne de cet élément de surface.
    */
    int colonne_;

    /**
    * Représentation de cet élément de surface.
    */
    std::string representation_;
};

#endif // Eau_hpp
