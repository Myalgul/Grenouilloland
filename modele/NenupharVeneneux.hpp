#ifndef NenupharVeneneux_hpp
#define NenupharVeneneux_hpp

#include "Nenuphar.hpp"

class NenupharVeneneux : public Nenuphar {
public:

    /**
    * Constructeur logique instanciant un nenuphar en utilisant le constructeur
    * par de la classe Nenuphar.
    */
    using Nenuphar::Nenuphar;
    void affectationGrenouille(Grenouille grenouille) const override;
};

#endif // NenupharVeneneux_hpp
