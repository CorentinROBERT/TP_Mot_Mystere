#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include <vector>
#include <fstream>

#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

std::string saisieMotMystere();
void melangeLettreMot(std::string& motAMelanger);
void devinerMotMystere(std::string motMystere,std::vector<int>& tableauScore);
float moyenneScore(std::vector<int> tableauScore);
std::string motIssueDico();

#endif // FONCTIONS_H_INCLUDED
