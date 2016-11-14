#ifndef Grenouille_hpp
#define Grenouille_hpp

class ElementSurface;

class Grenouille {

public:
    Grenouille(const int& ligne, const int& colonne);

public:
    const int& lireLigne() const;
    const int& lireColonne() const;
    const int& lireVie() const;
//    const ElementSurface* lireElementSurface() const;
    bool estMalade() const;
    bool estMorte() const;
    void ecrireVie(const int& vie);
    void ecrireLigne(const int& ligne);
    void ecrireColonne(const int& colonne);
//    void ecrireElementSurface(const ElementSurface* element);
    void guerison();
    void tombeMalade();
    void modification();

protected:
    int ligne_;
    int colonne_;
    int vie_;
    bool malade_;
//    const ElementSurface* ptrElementSurface_;
};

#endif // Grenouille_hpp
