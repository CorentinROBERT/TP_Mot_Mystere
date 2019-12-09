#include <iostream>
#include "fonctions.h"

using namespace std;

int main()
{

    //choix du nombre de joueur
    int nbJoueur(0);
    //choix recommencer partie
    char choix('o');
    //tableau de score
    std::vector<int> tableauScore;
    //mot mystere a deviner
    std::string motMystere("");

    //Proposition de recommencer partie
    while(choix != 'n'){

        std::cout<<"1. Jouer solo\n2. Jouer a 2\n";
        cin>>nbJoueur;

        switch(nbJoueur){
            case 1:
                //------------------------------------------------------------------
                // Partie solo
                //------------------------------------------------------------------
                //Recuperation d un mot issue du fichier dictionnaire
                motMystere = motIssueDico();
                break;
            case 2:
                //------------------------------------------------------------------
                // Partie a 2
                //------------------------------------------------------------------
                //demande du mot mystere par le joueur 1
                motMystere = saisieMotMystere();
                break;
            default:
                break;
        }

        //melange le mot mystere
        //demande a l'utilisateur quel est le mot mystere
        devinerMotMystere(motMystere,tableauScore);

        std::cout<<"\nVoulez vous faire une autre partie ? (o/n) : ";
        std::cin>>choix;
    }
    std::cout<<"Votre score est de : "<<moyenneScore(tableauScore)<<"\n\n";

    //------------------------------------------------------------------


    return 0;
}
