#include "IHM/Console.h"  
#include "IHM/Graphique.h"  
#include <iostream>  
#include <string>  

int main(int argc, char* argv[]) {  
    if (argc < 4) {  
        std::cerr << "Usage: " << argv[0] << " <fichier_entree> <mode> <iterations|taille_cellule> [intervalle_ms]\n";  
        std::cerr << "Modes disponibles:\n";  
        std::cerr << "  - console : exécution dans la console\n";  
        std::cerr << "  - graphique : exécution avec interface graphique\n";  
        return 1;  
    }  

    std::string cheminFichierEntree = argv[1];  
    std::string mode = argv[2];  

    if (mode == "console") {  
        int iterations = std::stoi(argv[3]);  
        std::string cheminFichierSortie = "resultat";  
        Console::lancer(cheminFichierEntree, cheminFichierSortie, iterations);  
    } else if (mode == "graphique") {  
        int tailleCellule = std::stoi(argv[3]);  
        int intervalle = argc > 4 ? std::stoi(argv[4]) : 100;  
        Graphique::lancer(cheminFichierEntree, tailleCellule, intervalle);  
    } else {  
        std::cerr << "Mode invalide: " << mode << ". Utilisez 'console' ou 'graphique'.\n";  
        return 1;  
    }  

    return 0;  
}