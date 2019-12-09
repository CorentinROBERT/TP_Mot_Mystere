#include "fonctions.h"

//Saisie du mot mystere
//retourne un string
std::string saisieMotMystere(){
    std::string motMystere("");
    std::cout<<"Veuillez saisir le mot mystere : ";
    std::cin>>motMystere;
    std::cout<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl;
    return motMystere;
}

//Melange le mot mystere a deviner
void melangeLettreMot(std::string& motAMelanger){
    srand(unsigned(time(NULL)));
    std::random_shuffle(motAMelanger.begin(), motAMelanger.end());
}

//Essaie de deviner le mot mystere
void devinerMotMystere(std::string motMystere,std::vector<int>& tableauScore){

    std::string essaieMot("");
    int nbEssaie(0);
    std::string motMelanger(motMystere);

    melangeLettreMot(motMelanger);

    while(essaieMot.compare(motMystere)!=0){
        std::cout<<"\nEssaie "<<nbEssaie<< " " <<motMelanger<<"\n";
        std::cin>>essaieMot;
        nbEssaie++;

        if(essaieMot.compare(motMystere)!=0){
            std::cout<<"Ce n est pas le mot\n";
        }
        else{
            std::cout<<"Bravo !\n";
        }
        if(nbEssaie==5){
            std::cout<<"La solution etait : "<<motMystere<<"\n";
            break;
        }
    }
    tableauScore.push_back(nbEssaie);
}

//Calcul la moyenne des scores par partie
float moyenneScore(std::vector<int> tableauScore){
    if(tableauScore.size()!=0){
        float moyenne(0.0);
        for(int i(0);i<tableauScore.size();i++){
            moyenne+=tableauScore[i];
        }
        return moyenne/tableauScore.size();
    }
    return 0.0;
}

//Retourne un mot au hasard provenant du fichier dico
std::string motIssueDico(){

    std::vector<std::string> dico;
    std::ifstream ifs ("dico.txt", std::ifstream::in);

    if(ifs){
            std::string ligne("");
        std::cout<<"Fichier trouve\n";
        while(getline(ifs, ligne)) //Tant qu'on n'est pas à la fin, on lit
      {
         dico.push_back(ligne);
      }
        srand(unsigned(time(NULL)));
        int nbAlea = rand()%dico.size();
        std::random_shuffle ( dico.begin(), dico.end() );
        return dico[nbAlea];
    }
    else{
        std::cout<<"Fichier introuvable\n";
    }
    return "bonjour";
}
