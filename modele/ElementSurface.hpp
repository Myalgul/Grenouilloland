#ifndef ElementSurface_hpp
#define ElementSurface_hpp

#include "StrategieAffectationGrenouille.hpp"
#include <iostream>
#include <memory>

typedef std::unique_ptr<ElementSurface> ptr_Element;

/**
 * @class ElementSurface ElementSurface.hpp
 *
 * D�claration de la classe ElementSurface repr�sentant un �l�ment de surface du grenouilloland.
 *
 * @note Bien que les num�ros de ligne et de colonne d'un �l�ment de surface ne changent
 *   pas, les attributs correspondants ne sont pas d�clar�s constants car la
 *   politique d'initialisation des conteneurs de la STL est bas�e sur la
 *   copie. En effet, l'op�rateur d'affectation ayant �t� implicitement
 *   supprim� (du fait du mot-cl� const), il serait alors impossible
 *   d'initialiser un vecteur d'�l�ment de surface � partir de la valeur d'un
 *   �l�ment de surface donn�.
 */
class ElementSurface : public StrategieAffectationGrenouille {
public:

    /**
    * Constructeur logique instanciant un �l�ment de surface.
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
    * Num�ro de ligne de cet �l�ment de surface.
    */
    int ligne_;

    /**
    * Num�ro de colonne de cet �l�ment de surface.
    */
    int colonne_;

    /**
    * Repr�sentation de cet �l�ment de surface.
    */
    std::string representation_;
};

#endif // ElementSurface_hpp
