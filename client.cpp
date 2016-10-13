
/**
 * @mainpage
 *
 * Le jeu de la vie.
 *
 * @author Emmanuel CAGNIOT - Emmanuel.Cagniot@ensicaen.fr
 * @date 18.6.2014
 */

#include "Presentateur.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>

/**
 * Programme principal.
 *
 * @param[in] argc - le nombre d'arguments de la ligne de commandes.
 * @param[in] argv - les arguments de la ligne de commandes.
 * @return @c EXIT_SUCCESS en cas d'ex�cution r�ussie ou @c EXIT_FAILURE sinon.
 */
int
main(int argc, char* argv[]) {

  // La ligne de commandes est vide : l'utilisateur demande de l'aide.
  if (argc == 1) {
    std::cout << "Usage: "
	      << argv[0]
	      << "dimension_min dimension_max dimension_initiale"
	      << std::endl;
    return EXIT_SUCCESS;
  }

  // Le nombre d'arguments de la ligne de commandes est diff�rent de quatre :
  // l'utilisateur fait n'importe quoi.
  if (argc != 4) {
    std::cerr << "Nombre d'arguments incorrect." << std::endl;
    return EXIT_FAILURE;
  }

  // Tentative d'extraction de la r�solution minimum.
  int minimum;
  {
    std::istringstream entree(argv[1]);
    entree >> minimum;
    if (! entree || ! entree.eof() || minimum < 1) {
      std::cerr << "La r�solution minimum n'est pas un entier positif."
		<< std::endl;
      return EXIT_FAILURE;
    }
  }

  // Tentative d'extraction de la r�solution maximum.
  int maximum;
  {
    std::istringstream entree(argv[2]);
    entree >> maximum;
    if (! entree || ! entree.eof() || maximum < minimum) {
      std::cerr << "La r�solution maximum n'est pas un entier sup�rieur � "
		<< minimum
		<< "."
		<< std::endl;
      return EXIT_FAILURE;
    }
  }

  // Tentative d'extraction de la r�solution initiale.
  int initiale;
  {
    std::istringstream entree(argv[3]);
    entree >> initiale;
    if (! entree || ! entree.eof() || initiale < minimum ||
        initiale > maximum) {
      std::cerr << "La r�solution maximum n'est pas un entier dans ["
		<< minimum
		<< ", "
		<< maximum
		<< "]."
		<< std::endl;
      return EXIT_FAILURE;
    }
  }

  // Tout est ok : initialisation de Gtk.
  Gtk::Main foo(argc, argv);

  // Initialisation de la classe Vue.
  Vue::initialiser();

  // Instanciation et d�marrage du pr�sentateur.
  Presentateur presentateur(minimum, maximum, initiale);
  presentateur.demarrer();

  // Tout s'est bien pass�.
  return EXIT_SUCCESS;

}
