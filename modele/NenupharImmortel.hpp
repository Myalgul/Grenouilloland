#ifndef NenupharImmortel_hpp
#define NenupharImmortel_hpp

#include "Nenuphar.hpp"

class NenupharImmortel : public Nenuphar {
public:

    /**
    * Constructeur logique instanciant un nenuphar en utilisant le constructeur
    * par de la classe Nenuphar.
    */
    using Nenuphar::Nenuphar;
    ~NenupharImmortel(){};
    void affectationGrenouille(Grenouille* grenouille) const override;
    bool vieillir() override;
};

#endif // NenupharImmortel_hpp
