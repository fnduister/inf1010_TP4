#include "Client.h"
#include <iostream>
#include "ProduitAuxEncheres.h"

Client::Client(unsigned int codeClient)
    : Usager(),
      codeClient_(codeClient)
{
}

Client::Client(const string &nom, const string &prenom, int identifiant,
               const string &codePostal, unsigned int codeClient)
    : Usager(nom, prenom, identifiant, codePostal),
      codeClient_(codeClient)
{
}

unsigned int Client::obtenirCodeClient() const
{
    return codeClient_;
}

vector<Produit *> Client::obtenirPanier() const
{
    return panier_;
}

double Client::obtenirTotalAPayer() const
{
	double total = 0.0;
	for (Produit* produit: panier_)
	{
		total += produit->obtenirPrix();
	}
	return total;
}

void Client::afficherPanier() const
{
    cout << "PANIER (de " << obtenirNom() << ")"
         << "\n";
    for (unsigned int i = 0; i < panier_.size(); i++)
		panier_[i]->afficher();
    cout << endl;
}

void Client::afficherProfil() const
{
	Usager::afficherProfil();
	cout << "\t\tcode client:\t" << codeClient_ << endl;
	cout << "\t\tpanier:\t\t" << panier_.size() << " elements" << endl;
}

void Client::modifierCodeClient(unsigned int codeClient)
{
    codeClient_ = codeClient_;
}

void Client::enleverProduit(Produit *produit)
{
    for (unsigned int i = 0; i < panier_.size(); i++)
    {
        if (panier_[i] == produit)
        {
            panier_[i] = panier_[panier_.size() - 1];
            panier_.pop_back();
            return;
        }
    }
}

void Client::ajouterProduit(class Produit* produit)
{
	for (unsigned int i = 0; i < panier_.size(); i++)
        if (panier_[i] == produit)
            return;
    panier_.push_back(produit);
}


void Client::reinitialiser()
{
	for (Produit* produit: panier_)
	{
		if (ProduitAuxEncheres* produitEnchere = dynamic_cast<ProduitAuxEncheres*>(produit))
		{
			produitEnchere->mettreAJourEnchere( nullptr, produitEnchere->obtenirPrixInitial());
		}
		produit->modifierFournisseur(nullptr);//on nullifie le fournisseur pour tous produits
	}
	panier_.clear();
}
