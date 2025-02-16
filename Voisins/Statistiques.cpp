#include <iostream>
#include <vector>
#include "Statistiques.h"
using namespace std;

float Statistiques::calculMoyenne(vector<float> nombres)
{
	float resultat{ 0 };
	for (int i = 0; i < nombres.size(); i++) {
		resultat += nombres[i];
	}
	resultat = resultat / (nombres.size() - 1);
	return resultat;
}

float Statistiques::calculMediane(vector<float> nombres)
{
	int emplacementMediane{ 0 };
	float mediane{ 0 };
	if (nombres.size() % 2 != 1) {
		emplacementMediane = nombres.size() / 2;
		mediane = nombres[emplacementMediane - 1];
	}
	else {
		emplacementMediane = (nombres.size() + 1) / 2;
		mediane = nombres[emplacementMediane - 1];
	}
	return mediane;
}

float Statistiques::calculEcartType(vector<float> nombres)
{
	float moyenne = calculMoyenne(nombres);
	vector<float> resultatsMoyennes(nombres.size());
	for (int i = 0; i < nombres.size();i++) {
		resultatsMoyennes[i] = (nombres[i] - moyenne);
		resultatsMoyennes[i] = resultatsMoyennes[i] * resultatsMoyennes[i];
	}
	float temporaire{ 0 };
	float ecartType{0};
	for (int i = 0; i < resultatsMoyennes.size();i++) {
		temporaire += resultatsMoyennes[i];
	}
	ecartType = temporaire / nombres.size();

	return ecartType;
}

float Statistiques::calculDistanceEuclyde(vector<float> nombres)
{
	float somme = 0;
	if (nombres.size() <= 2) {
		cout << "Il doit y avoir deux nombres ou plus dans la variable!";
		return 0;
	}
	for (int i = 0; i < nombres.size();i++) {
		somme += (nombres[i]*nombres[i]);
	}
	somme = sqrt(somme);
	return somme;
}

float Statistiques::calculDistanceManhattan(vector<float> nombres)
{
	float somme = 0;
	if (nombres.size() <= 2) {
		cout << "Il doit y avoir deux nombres ou plus dans la variable!";
		return 0;
	}
	for (int i = 0; i < nombres.size();i++) {
		somme += nombres[i];
	}

	return somme;
}
