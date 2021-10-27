#include "Client.h"
#include <iostream>
using namespace Banque;
using namespace std;
Client::Client(string n, string p, string a)
{
	this->nom = n;
	this->prenom = p; 
	this->adresse = a;
}

void Client::Afficher() const
{
	cout << "nom :" << this->nom << "\n" << "prenom:" << this->prenom << "\n" << "Adresse:" << this->adresse << endl;
}
