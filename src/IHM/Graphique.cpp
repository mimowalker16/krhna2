#include "Graphique.h"  
#include "../Services/ServiceFichier.h"  
#include <SFML/Graphics.hpp>  

void Graphique::lancer(const std::string& cheminFichierEntree, int tailleCellule, int intervalle) {  
    auto grilleInitiale = ServiceFichier::chargerDepuisFichier(cheminFichierEntree);  
    Grille grille(grilleInitiale.size(), grilleInitiale[0].size());  

    for (int i = 0; i < grille.getHauteur(); ++i) {  
        for (int j = 0; j < grille.getLargeur(); ++j) {  
            grille.getCellules()[i][j] = grilleInitiale[i][j];  
        }  
    }  

    sf::RenderWindow window(sf::VideoMode(grille.getLargeur() * tailleCellule, grille.getHauteur() * tailleCellule), "Jeu de la Vie");  
    sf::RectangleShape cellule(sf::Vector2f(tailleCellule - 1, tailleCellule - 1));  

    while (window.isOpen()) {  
        sf::Event event;  
        while (window.pollEvent(event)) {  
            if (event.type == sf::Event::Closed) window.close();  
        }  

        window.clear();  
        const auto& cellules = grille.getCellules();  
        for (int i = 0; i < grille.getHauteur(); ++i) {  
            for (int j = 0; j < grille.getLargeur(); ++j) {  
                if (cellules[i][j].estVivante()) {  
                    cellule.setPosition(j * tailleCellule, i * tailleCellule);  
                    window.draw(cellule);  
                }  
            }  
        }  

        window.display();  
        sf::sleep(sf::milliseconds(intervalle));  
        grille.mettreAJour();  
    }  
}