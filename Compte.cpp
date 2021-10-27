#include "Compte.h"
#include "GC.cpp"
#include<iostream>
using namespace std;
using namespace Banque;
MAD* Compte::plafond = new MAD(2000);
int Compte::count = 0;

Compte::Compte(Client* titu, MAD* sol):numcompte(++count)
{
	this->ref = new GC(1);
	this->titulaire = titu;
	this->solde = sol;
}

Compte::Compte(const Compte& c):numcompte(c.numcompte)
{
	this->ref = c.ref;
	this->ref->incre();
	this->titulaire = c.titulaire;
	this->solde=c.solde;
}

void Banque::Compte::crediter(MAD*M)
{
	*(this->solde) = *(this->solde)+*M;
}

bool Banque::Compte::debiter(MAD*M)
{
	if (*(this->solde) >= *M && *M <= *(Compte::plafond))
	{
		*(this->solde) = *(this->solde) - *M;
	return true;
	}
	return false;
}

bool Compte::verser(MAD* M, Compte& C)
{
	//this->solde->afficher();
	if (this->debiter(M)==true) {
	//	this->solde->afficher();
		C.crediter(M);
	//	C.solde->afficher();
		return true;
	}
	return false;
}


void Compte::consulter() const
{
	cout << "num compte=" << this->numcompte << endl;
	this->solde->afficher();
	cout << "titulaire " << endl;
	this->titulaire->Afficher();
}

//Compte::~Compte() {
//
//	if (this->titulaire!=nullptr && this->ref->decr() ==0 ) 
//	{
//		delete this->titulaire; 
//		this->titulaire =nullptr;
//	}
//
//}
