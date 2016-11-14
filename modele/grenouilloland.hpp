
#ifndef Grenouilloland_hpp
#define Grenouilloland_hpp

#include "ElementSurface.hpp"
#include "Eau.hpp"
#include "Nenuphar.hpp"
#include "NenupharImmortel.hpp"
#include "NenupharDopant.hpp"
#include "NenupharVeneneux.hpp"
#include "NenupharNutritif.hpp"
#include "NenupharMortel.hpp"
#include <vector>

/**
 * @class Grenouilloland Grenouilloland.hpp
 *
 * Déclaration de la classe Grenouilloland représentant une implémentation
 * séquentielle du jeu de la vie.
 */
class Grenouilloland {
public:

    /**
     * Constructeur logique initialisant ce jeu avec des cellules mortes.
     *
     * @param[in] dimension - la valeur de @ref dimension_.
     */
    Grenouilloland(const int& dimension);

    /**
     * Destructeur redéfinissable.
     */
    virtual ~Grenouilloland() = default;

public:

    /**
     * Accesseur.
     *
     * @return la valeur de @ref dimension_.
     */
    const int& lireDimension() const;

    /**
     * Retourne la cellule (en lecture seule) dont les numeros de lignes et de
     * colonnes sont fournis en arguments.
     *
     * @param[in] ligne - le numero de ligne.
     * @param[in] colonne - le numero de colonne.
     * @return la cellule (en lecture seule) correspondante.
     */
    const ElementSurface* lireElement (const int& ligne, const int& colonne) const;

public:
    /**
     *
     */
    void changeElement (const int& ligne, const int& colonne, ElementSurface* element);

    /**
     *
     */
    void generationChemin (const int& ligne, const int& colonne);

    /**
     *
     */
    void generationNenuphar (const int& ligne, const int& colonne);

    /**
     *
     */
    void modification (Grenouille* grenouille) const;

    /**
     *
     */
    bool gagner (Grenouille grenouille) const;

    /**
     *
     */
    bool perdu (Grenouille grenouille) const;

protected:

    /**
    * Dimension de ce jeu.
    */
    const int dimension_;

    /**
     * Cellules de ce jeu.
     */
    std::vector< ElementSurface* > elementSurface_;
//    std::vector< ptr_Element > elementSurface_;

};

#endif
