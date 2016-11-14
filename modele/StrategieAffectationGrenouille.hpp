#ifndef StrategieAffectationGrenouille_hpp
#define StrategieAffectationGrenouille_hpp

#include "Grenouille.hpp"
class Grenouille;

class StrategieAffectationGrenouille {
public:
    virtual ~StrategieAffectationGrenouille() = default;
    virtual void affectationGrenouille(Grenouille grenouille) const = 0;
};

#endif // StrategieAffectationGrenouille_hpp
