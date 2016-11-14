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
    void affectationGrenouille(Grenouille grenouille) const override;
};

#endif // Eau_hpp
