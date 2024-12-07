#include "Cellule.h"  

// Constructeur par défaut : cellule morte  
Cellule::Cellule() : vivante(false) {}  

// Retourne si la cellule est vivante  
bool Cellule::estVivante() const {  
    return vivante;  
}  

// Définit si la cellule est vivante ou non  
void Cellule::setVivante(bool etat) {  
    vivante = etat;  
}