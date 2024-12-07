#include "Grille.h"  
#include <iostream>  

Grille::Grille(int lignes, int colonnes)  
    : cellules(lignes, std::vector<Cellule>(colonnes)), modeTorique(false) {}  

void Grille::afficher() const {  
    for (const auto &ligne : cellules) {  
        for (const auto &cellule : ligne) {  
            std::cout << (cellule.estVivante() ? "1 " : "0 ");  
        }  
        std::cout << '\n';  
    }  
}  

void Grille::mettreAJour() {  
    int lignes = cellules.size();  
    int colonnes = cellules[0].size();  
    std::vector<std::vector<Cellule>> nouvelleGrille(lignes, std::vector<Cellule>(colonnes));  

    for (int x = 0; x < lignes; ++x) {  
        for (int y = 0; y < colonnes; ++y) {  
            int voisinsVivants = compterVoisinsVivants(x, y);  
            if (cellules[x][y].estVivante()) {  
                nouvelleGrille[x][y].setVivante(voisinsVivants == 2 || voisinsVivants == 3);  
            } else {  
                nouvelleGrille[x][y].setVivante(voisinsVivants == 3);  
            }  
        }  
    }  

    cellules = nouvelleGrille; // Remplacer l'ancienne grille par la nouvelle  
}  

int Grille::compterVoisinsVivants(int x, int y) const {  
    int voisinsVivants = 0;  
    int lignes = cellules.size();  
    int colonnes = cellules[0].size();  

    for (int dx = -1; dx <= 1; ++dx) {  
        for (int dy = -1; dy <= 1; ++dy) {  
            if (dx == 0 && dy == 0) continue; // Ignorer la cellule elle-même  

            int nx = x + dx;  
            int ny = y + dy;  

            if (modeTorique) {  
                nx = (nx + lignes) % lignes;  
                ny = (ny + colonnes) % colonnes;  
            }  

            if (nx >= 0 && nx < lignes && ny >= 0 && ny < colonnes && cellules[nx][ny].estVivante()) {  
                ++voisinsVivants;  
            }  
        }  
    }  
    return voisinsVivants;  
}  

const std::vector<std::vector<Cellule>>& Grille::getCellules() const {  
    return cellules;  
}  

int Grille::getLargeur() const {  
    return cellules[0].size();  
}  

int Grille::getHauteur() const {  
    return cellules.size();  
}  

void Grille::activerModeTorique(bool torique) {  
    modeTorique = torique;  
}