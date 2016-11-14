#ifndef NenupharDopant_hpp
#define NenupharDopant_hpp

#include "Nenuphar.hpp"

class NenupharDopant : public Nenuphar {
public:

    /**
    * Constructeur logique instanciant un nenuphar en utilisant le constructeur
    * par de la classe Nenuphar.
    */
    using Nenuphar::Nenuphar;
    ~NenupharDopant(){};
    void affectationGrenouille(Grenouille* grenouille) const override;
};

#endif // NenupharDopant_hpp
