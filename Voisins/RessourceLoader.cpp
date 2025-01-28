#include "RessourceLoader.h"
using namespace std;

/*
*Fonction retourne un tableau contenant k % des enregistrements avec la méthode getline pour séparer chaque donnée lorsqu'il y a une virgule
*J'ai pas trop compris les instructions alors je prendrai rendez-vous au besoin
*/
void RessourceLoader::getTrainData()
{
	//Faire un vecteur pour chaque valeur
	vector<string> tabAciditeFixe;
	vector<string> tabAcideVolatile;
	vector<string> tabAcideCitrique;
	vector<string> tabSucreResiduel;
	vector<string> tabChlorureSodium;
	vector<string> tabDioxydeSoufreLibre;
	vector<string> tabDioxydeSoufreTotal;
	vector<string> tabDensite;
	vector<string> tabPH;
	vector<string> tabSulfatePotassium;
	vector<string> tabAlcool;

	ifstream file("binary-winequality-white.csv");

	if (!file.is_open()) {
		cout << "Échec lors de l'ouverture du fichier " << "binary-winequality-white.csv" << endl;
	}
	string ligneDonnee;
	//Séparer chaque donnée d'une ligne et les mettre dans chaque vecteur de données dans l'ordre
	while (getline(file, ligneDonnee)) {
		std::stringstream ss(ligneDonnee);
		string article;
		getline(ss, article, ',');
		tabAciditeFixe.push_back(article);
		getline(ss, article, ',');
		tabAcideVolatile.push_back(article);
		getline(ss, article, ',');
		tabAcideCitrique.push_back(article);
		getline(ss, article, ',');
		tabSucreResiduel.push_back(article);
		getline(ss, article, ',');
		tabChlorureSodium.push_back(article);
		getline(ss, article, ',');
		tabDioxydeSoufreLibre.push_back(article);
		getline(ss, article, ',');
		tabDioxydeSoufreTotal.push_back(article);
		getline(ss, article, ',');
		tabDensite.push_back(article);
		getline(ss, article, ',');
		tabPH.push_back(article);
		getline(ss, article, ',');
		tabSulfatePotassium.push_back(article);
		getline(ss, article);
		tabAlcool.push_back(article);
	}

}

void RessourceLoader::getTestData()
{

}
