#ifndef Compteur_hpp
#define Compteur_hpp

#include "Grenouilloland.hpp"

class Compteur {

public:
    Compteur();
    ~Compteur();

public:
    void demarrer(Grenouilloland* jeu);
    void attendre(const float& temps);
    bool estFini() const;
    void reset();

protected:
    const float& tempsAttente = 1;
    int depart = 0;
};

#endif // Compteur_hpp
