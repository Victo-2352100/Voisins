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
	Calcule le nombre de lignes à récupérer du fichier puis fait appel à des méthodes spécialisées pour retourner le nombre de lignes
	@param nomFichier: Nom du fichier déjà trouvable dans le dossier du projet
	@param k: Nombre entre 1 et 100 qui spécifie le pourcentage des lignes du fichier à enregistrer en données
	@returns un tableau contenant k % des enregistrements. Dois être plus grand que 0 et plus petit ou égal à 100
	*/
	vector<string> getTrainData(string nomFichier, int k);
	/*
	Calcule le nombre de lignes à récupérer du fichier spécifié ainsi que la première ligne où commencer à fouiller, le pourcentage inscrit étant la deuxième partie du fichier
	@param nomFichier: Nom du fichier déjà trouvable dans le dossier du projet
	@param k: Nombre entre 1 et 100 qui spécifie le pourcentage des lignes du fichier à enregistrer en données
	@returns un tableau contenant 1-k % des enregistrements. Dois être plus grand que 0 et plus petit ou égal à 100
	*/
	vector<string> getTestData(string nomFichier, int k);
	/*
	Crée un vecteur string qui contient chaque ligne du fichier csv dont le nom est mentionné en paramètres
	@param nomFichier: Nom du fichier déjà trouvable dans le dossier du projet
	@returns Le nombre de lignes présentes dans le fichier, la taille du vecteur, donc.
	*/
	int prendreLignes(string);
	/*
	Crée un vecteur string qui contient chaque ligne du fichier csv avec la méthode ifstream
	@param nomFichier: Nom du fichier déjà trouvable dans le dossier du projet
	@param ligneDebut: Numéro de la ligne où la méthode commence à enregistrer les données dans le vecteur
	@param nbrLignesFouiller: Nombre de ligne que la méthode fouille pour enregistrer leurs données
	@returns un vector<string> qui contient les lignes spécifiées du document sans les avoir classées selon leurs qualités
	*/
	vector<string> donnerLignes(string, int, int);
	/*
	Méthode qui ouvre un document csv, identifié par la variable, par la méthode StringStream pour séparer chaque valeur en trouvant les virgules dans la ligne
	A besoin du nom du fichier dans lequel se trouvent les données
	@param nomFichier : Nom du fichier déjà trouvable dans le dossier du projet
	@returns un vector<float> qui contient toutes les données une fois classées
	*/
	vector<float> classerDonnees(string, int, int);
	/*
	Méthode
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

