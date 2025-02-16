#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
class RessourceLoader
{
private:
public:
	/*
	Calcule le nombre de lignes � r�cup�rer du fichier puis fait appel � des m�thodes sp�cialis�es pour retourner le nombre de lignes
	@param nomFichier: Nom du fichier d�j� trouvable dans le dossier du projet
	@param k: Nombre entre 1 et 100 qui sp�cifie le pourcentage des lignes du fichier � enregistrer en donn�es
	@returns un tableau contenant k % des enregistrements. Dois �tre plus grand que 0 et plus petit ou �gal � 100
	*/
	vector<string> getTrainData(string nomFichier, int k);
	/*
	Calcule le nombre de lignes � r�cup�rer du fichier sp�cifi� ainsi que la premi�re ligne o� commencer � fouiller, le pourcentage inscrit �tant la deuxi�me partie du fichier
	@param nomFichier: Nom du fichier d�j� trouvable dans le dossier du projet
	@param k: Nombre entre 1 et 100 qui sp�cifie le pourcentage des lignes du fichier � enregistrer en donn�es
	@returns un tableau contenant 1-k % des enregistrements. Dois �tre plus grand que 0 et plus petit ou �gal � 100
	*/
	vector<string> getTestData(string nomFichier, int k);
	/*
	Cr�e un vecteur string qui contient chaque ligne du fichier csv dont le nom est mentionn� en param�tres
	@param nomFichier: Nom du fichier d�j� trouvable dans le dossier du projet
	@returns Le nombre de lignes pr�sentes dans le fichier, la taille du vecteur, donc.
	*/
	int prendreLignes(string);
	/*
	Cr�e un vecteur string qui contient chaque ligne du fichier csv avec la m�thode ifstream
	@param nomFichier: Nom du fichier d�j� trouvable dans le dossier du projet
	@param ligneDebut: Num�ro de la ligne o� la m�thode commence � enregistrer les donn�es dans le vecteur
	@param nbrLignesFouiller: Nombre de ligne que la m�thode fouille pour enregistrer leurs donn�es
	@returns un vector<string> qui contient les lignes sp�cifi�es du document sans les avoir class�es selon leurs qualit�s
	*/
	vector<string> donnerLignes(string, int, int);
	/*
	M�thode qui ouvre un document csv, identifi� par la variable, par la m�thode StringStream pour s�parer chaque valeur en trouvant les virgules dans la ligne
	A besoin du nom du fichier dans lequel se trouvent les donn�es
	@param nomFichier : Nom du fichier d�j� trouvable dans le dossier du projet
	@returns un vector<float> qui contient toutes les donn�es une fois class�es
	*/
	vector<float> classerDonnees(string, int, int);
	/*
	M�thode
	*/
	void getTrainDataLinked(string, int);
	void getTestDataLinked(string, int);
	void mettreEnNoeud(vector<float>);
	void classerDonneesVecteurSimple(string);
};
struct Noeud {
	float m_donnee;
	Noeud* suivant;
};

