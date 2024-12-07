#ifndef GRILLE_H  
#define GRILLE_H  

#include <vector>  
#include "Cellule.h"  

class Grille {  
private:  
    int largeur;  
    int hauteur;  
    bool modeTorique;  
    std::vector<std::vector<Cellule>> cellules;  

public:  
    Grille(int lignes, int colonnes);  
    void afficher() const;               // Affiche la grille dans la console  
    void mettreAJour();                  // Met à jour la grille selon les règles du jeu  
    const std::vector<std::vector<Cellule>>& getCellules() const;  
    int getLargeur() const;  
    int getHauteur() const;  
    void activerModeTorique(bool torique); // Mode torique activé ou désactivé  
    int compterVoisinsVivants(int x, int y) const; // Compte les voisins vivants  
};  

#endif // GRILLE_H