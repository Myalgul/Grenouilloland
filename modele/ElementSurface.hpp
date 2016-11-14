#ifndef ElementSurface_hpp
#define ElementSurface_hpp

#include "StrategieAffectationGrenouille.hpp"
#include <iostream>
#include <memory>

typedef std::unique_ptr<ElementSurface> ptr_Element;

/**
 * @class ElementSurface ElementSurface.hpp
 *
 * Déclaration de la classe ElementSurface représentant un élément de surface du grenouilloland.
 *
 * @note Bien que les numéros de ligne et de colonne d'un élément de surface ne changent
 *   pas, les attributs correspondants ne sont pas déclarés constants car la
 *   politique d'initialisation des conteneurs de la STL est basée sur la
 *   copie. En effet, l'opérateur d'affectation ayant été implicitement
 *   supprimé (du fait du mot-clé const), il serait alors impossible
 *   d'initialiser un vecteur d'élément de surface à partir de la valeur d'un
 *   élément de surface donné.
 */
class ElementSurface : public StrategieAffectationGrenouille {
public:

    /**
    * Constructeur logique instanciant un élément de surface.
    *
    * @param[in] ligne - la valeur de @ref ligne_.
    * @param[in] colonne - la valeur de @ref colonne_.
    */
    ElementSurface(const int& ligne, const int& colonne, const std::string& representation);
    virtual ~ElementSurface();
    virtual void affectationGrenouille(Grenouille* grenouille) const = 0;

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

#endif // ElementSurface_hpp
