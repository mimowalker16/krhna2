#ifndef CELLULE_H  
#define CELLULE_H  

class Cellule {  
private:  
    bool vivante; // Etat de la cellule (vivante ou morte)  

public:  
    Cellule(); // Constructeur  
    bool estVivante() const;       // Retourne l'état de la cellule  
    void setVivante(bool etat);    // Définit l'état de la cellule  
};  

#endif // CELLULE_H