#ifndef NenupharMortel_hpp
#define NenupharMortel_hpp

#include "Nenuphar.hpp"

class NenupharMortel: public Nenuphar {
public:

    /**
    * Constructeur logique instanciant un nenuphar en utilisant le constructeur
    * par de la classe Nenuphar.
    */
    using Nenuphar::Nenuphar;
    ~NenupharMortel(){};
    void affectationGrenouille(Grenouille* grenouille) const override;
};

#endif // NenupharMortel_hpp
