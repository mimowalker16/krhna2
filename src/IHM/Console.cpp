#include "Console.h"
#include <iostream>

void Console::executer(const std::string& cheminFichierEntree, const std::string& cheminFichierSortie, int iterations) {
    Grille grille(0, 0);
    grille.initialiserDepuisFichier(cheminFichierEntree);

    for (int iter = 0; iter < iterations; ++iter) {
        std::cout << "Iteration " << iter + 1 << ":\n";
        grille.afficherConsole();
        grille.sauvegarderDansFichier(cheminFichierSortie + "_iter_" + std::to_string(iter + 1) + ".txt");
        grille.mettreAJour();
        std::cout << "---------------------\n";
    }
}
