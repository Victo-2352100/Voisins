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
	*Calcule la distance entre plusieurs points selon la m�thode d'Euclyde (autrement connue sous le nom de la m�thode de Pythagore)
	*Autrement dit, on additionne les carr�s de chaque mesure pour ensuite faire la racine carr�e du r�sultat afin de trouver la mesure manquante.
	*La variable doit avoir au moins deux nombres
	*/
	float calculDistanceEuclyde(vector<float>);
	/*
	*Calcule la distance entre plusieurs points selon la m�thode de Manhattan 
	*Autrement dit, on additionne les mesures et cela r�sulte en la mesure manquante
	*La variable doit avoir au moins deux nombres
	*/
	float calculDistanceManhattan(vector<float>);
};

