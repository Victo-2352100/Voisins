#include "RessourceLoader.h"
using namespace std;

vector<string> RessourceLoader::getTrainData(string nomFichier, int k)
{
	if (k > 100 || k <= 0) {
		cout << "La valeur de k est invalide, c'est un pourcentage!";
		return;
	}
	int nbrLignes = prendreLignes(nomFichier);
	int debutLigne = 0;
	int versPourcentageLignes = (k * nbrLignes)/100;
	vector<string> donneesLignes = donnerLignes(nomFichier, debutLigne, versPourcentageLignes);
	return donneesLignes;
}

vector<string> RessourceLoader::getTestData(string nomFichier, int k)
{
	if (k > 100 || k <= 0) {
		cout << "La valeur de k est invalide, c'est un pourcentage!";
		return;
	}
	int debutLignes = ((k-100) * -1) * prendreLignes(nomFichier);
	//Inverse la valeur de k pour trouver la proportion de la deuxi�me partie et la positivise.
	k = (k-100) * -1;
	int nbrLignes = (k * prendreLignes(nomFichier))/100;
	vector<string> donneesLignes = donnerLignes(nomFichier, debutLignes, nbrLignes);
	return donneesLignes;
}

int RessourceLoader::prendreLignes(string nomFichier)
{
	int nbrLignes;
	ifstream file(nomFichier);

	if (!file.is_open()) {
		cout << "�chec de l'ouverture du fichier " << nomFichier << endl;
		return 0;
	}
	string ligneDonnee;
	while (getline(file, ligneDonnee)) {
		nbrLignes++;
	}
	return nbrLignes;
}

vector<string> RessourceLoader::donnerLignes(string nomFichier, int ligneDebut, int nbrLignesFouiller)
{
	if (ligneDebut < 0 || ligneDebut >= prendreLignes(nomFichier)) {
		cout << "La ligne de d�but doit �tre plus grande que z�ro." << endl;
		
	}
	vector<string> donnees;
	ifstream file(nomFichier);
	if (!file.is_open()) {
		cout << "�chec de l'ouverture du fichier " << nomFichier << endl;
		return;
	}
	string ligneDonnee;
	int compteur = 0;
	//Utilise le compteur pour compter les lignes et d�terminer quand enregistrer les donn�es
	while (getline(file, ligneDonnee)) {
		if (compteur >= ligneDebut && compteur < nbrLignesFouiller+ligneDebut) {
			donnees.push_back(ligneDonnee);
		}
		compteur++;
	}
	file.close();
	return donnees;
}

vector<float> RessourceLoader::classerDonnees(string nomFichier, int ligneDebut, int nbrLignesFouiller)
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

	ifstream file(nomFichier);

	if (!file.is_open()) {
		cout << "�chec lors de l'ouverture du fichier " << nomFichier << endl;
		return;
	}

	string ligneDonnee;
	//S�parer chaque donn�e d'une ligne et les mettre dans chaque vecteur de donn�es dans l'ordre
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
	file.close();
	return vector<float>();
}

void RessourceLoader::getTrainDataLinked(string nomFichier, int pourcentage)
{
	vector<string> lignesDonnees = getTrainData(nomFichier, pourcentage);

}

void RessourceLoader::getTestDataLinked(string nomFichier, int pourcentage)
{
	vector<string> lignesDonnees = getTestData(nomFichier, pourcentage);
}
// Inspir� d'un des programmes de cet article (le quatri�me): https://www.geeksforgeeks.org/cpp-program-for-inserting-a-node-in-a-linked-list/
// Bien entendu, la fonction est suppos� retourner la liste.
void RessourceLoader::mettreEnNoeud(vector<float> tabDonnees)
{
	if (tabDonnees.empty()) {
		cout << "Le vecteur est vide!";
		return;
	}
	Noeud* m_premier = nullptr;
	for (int i = 0;i < tabDonnees.size(); i++) { //On fait en sorte que chaque donn�e du tableau soit ajout�e
		Noeud* nouveau = new Noeud{ tabDonnees[i], nullptr };
		//V�rifie si c'est le premier
		if (m_premier == nullptr) {
			//Si oui, celui qu'on vient de cr�er sera le premier
			m_premier = nouveau;
		}
		else {
			//On commence l'itt�rateur au premier
			Noeud* iterateur = m_premier;
			while (iterateur->suivant != nullptr) {
				//Passe au noeud suivant jusqu'� ce que le noeud n'aie pas de pointeur pour le noeud suivant
				iterateur = iterateur->suivant;
			}
			//Ensuite, on mets le noeud suivant comme le noeud qu'on a cr�� plus t�t
			iterateur->suivant = nouveau;
		}
	}
}

void RessourceLoader::classerDonneesVecteurSimple(string donnees)
{

}
