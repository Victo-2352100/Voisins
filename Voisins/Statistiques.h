#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Statistiques {
	float calculMoyenne(vector<float>);
	float calculMediane(vector<float>);
	float calculEcartType(vector<float>);
	/*
	*Calcule la distance entre plusieurs points selon la méthode d'Euclyde (autrement connue sous le nom de la méthode de Pythagore)
	*Autrement dit, on additionne les carrés de chaque mesure pour ensuite faire la racine carrée du résultat afin de trouver la mesure manquante.
	*La variable doit avoir au moins deux nombres
	*/
	float calculDistanceEuclyde(vector<float>);
	/*
	*Calcule la distance entre plusieurs points selon la méthode de Manhattan 
	*Autrement dit, on additionne les mesures et cela résulte en la mesure manquante
	*La variable doit avoir au moins deux nombres
	*/
	float calculDistanceManhattan(vector<float>);
};

