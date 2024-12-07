#ifndef SERVICE_FICHIER_H  
#define SERVICE_FICHIER_H  

#include <vector>  
#include <string>  
#include "Cellule.h"  

class ServiceFichier {  
public:  
    static std::vector<std::vector<Cellule>> chargerDepuisFichier(const std::string& chemin);  
    static void sauvegarderDansFichier(const std::string& chemin, const std::vector<std::vector<Cellule>>& grille);  
};  

#endif // SERVICE_FICHIER_H