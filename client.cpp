#include <iostream>
#include <cstdlib>

#include "modele/Grenouilloland.hpp"
#include "modele/Compteur.hpp"

void Affichage (const Grenouilloland& jeu);

using namespace std;

int main()
{
    char choix;
    Grenouilloland jeu(5);
    Grenouille* grenouille = jeu.lireGrenouille();
    Compteur compteur;

    do {
        Affichage(jeu);
        //compteur.demarrer(&jeu);
        cout << grenouille->lireLigne() << "/" << grenouille->lireColonne() << ":" << grenouille->lireVie() << endl;
        cin >> choix;
        switch (choix) {
            case 'h' :  grenouille->ecrireLigne(grenouille->lireLigne()-1);
                        break;
            case 'b' :  grenouille->ecrireLigne(grenouille->lireLigne()+1);
                        break;
            case 'g' :  grenouille->ecrireColonne(grenouille->lireColonne()-1);
                        break;
            case 'd' :  grenouille->ecrireColonne(grenouille->lireColonne()+1);
                        break;
        }
        jeu.modification();
        jeu.maj();
    } while (!jeu.gagner() && !jeu.perdu());
//    int i = 0;
//    do {
//        cout << "Generation " << i << endl;
//        Affichage(jeu);
//        cout << endl;
//        compteur.demarrer(&jeu);
//        compteur.reset();
//        i++;
//    } while (i != 10);

    if (jeu.gagner()) {
        cout << endl << "Bravo vous avez fini le jeu grenouilloland !!!" << endl;
    } else {
        cout << endl << "Mince votre grenouille est morte avant la fin, vous pouvez retenter votre chance" << endl;
    }

    return EXIT_SUCCESS;
}

void Affichage (const Grenouilloland& jeu) {
    int dim = jeu.lireDimension();
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            cout << jeu.lireElement(i, j)->lireRepresentation() << " ";
        }
        cout << endl;
    }
}
