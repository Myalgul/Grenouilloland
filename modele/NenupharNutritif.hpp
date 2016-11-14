#ifndef NenupharNutritif_hpp
#define NenupharNutritif_hpp

#include "Nenuphar.hpp"

class NenupharNutritif : public Nenuphar {
public:

    /**
    * Constructeur logique instanciant un nenuphar en utilisant le constructeur
    * par de la classe Nenuphar.
    */
    using Nenuphar::Nenuphar;
    void affectationGrenouille(Grenouille grenouille) const override;
};

#endif // NenupharNutritif_hpp
