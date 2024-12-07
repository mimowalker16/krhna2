#include "ServiceFichier.h"  
#include <fstream>  
#include <sstream>  
#include <stdexcept>  

std::vector<std::vector<Cellule>> ServiceFichier::chargerDepuisFichier(const std::string& chemin) {  
    std::ifstream fichier(chemin);  
    if (!fichier) throw std::runtime_error("Impossible d'ouvrir le fichier: " + chemin);  

    std::vector<std::vector<Cellule>> grille;  
    std::string ligne;  
    while (std::getline(fichier, ligne)) {  
        std::vector<Cellule> ligneGrille;  
        std::istringstream ss(ligne);  
        int val;  
        while (ss >> val) {  
            Cellule cellule;  
            cellule.setVivante(val == 1);  
            ligneGrille.push_back(cellule);  
        }  
        grille.push_back(ligneGrille);  
    }  
    return grille;  
}  

void ServiceFichier::sauvegarderDansFichier(const std::string& chemin, const std::vector<std::vector<Cellule>>& grille) {  
    std::ofstream fichier(chemin);  
    if (!fichier) throw std::runtime_error("Impossible de sauvegarder le fichier: " + chemin);  

    for (const auto& ligne : grille) {  
        for (const auto& cellule : ligne) {  
            fichier << (cellule.estVivante() ? 1 : 0) << " ";  
        }  
        fichier << "\n";  
    }  
}