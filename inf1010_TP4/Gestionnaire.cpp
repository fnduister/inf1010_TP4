#include "Gestionnaire.h"
#include <algorithm>

vector<Usager *> Gestionnaire::obtenirUsagers() const
{
    return usagers_;
}

void Gestionnaire::afficherLesProfils() const
{
	cout << "PROFILS" << std::endl;
	for (Usager* usager: usagers_)
	{
		usager->afficherProfil();
	}
}

double Gestionnaire::obtenirChiffreAffaires() const
{
	double total = 0.0;
	for (Usager* usager: usagers_)
	{
		total += usager->obtenirTotalAPayer();
	}
	return total;
}

void Gestionnaire::ajouterUsager(Usager *usager)
{
	for (unsigned int i = 0; i < usagers_.size(); i++)
		if (usagers_[i] == usager)
			return;
	usagers_.push_back(usager);
}

void Gestionnaire::reinitialiser()
{
    for(Usager* usager:usagers_)
    {
		usager->reinitialiser();
    }
}

void Gestionnaire::encherir(Client *client, ProduitAuxEncheres *produit, double montant) const
{
	if (client != produit->obtenirEncherisseur())
	{
		if (montant > produit->obtenirPrix()) {
			if (produit->obtenirEncherisseur() != nullptr)
				produit->obtenirEncherisseur()->enleverProduit(produit);
			produit->mettreAJourEnchere(client, montant);
			client->ajouterProduit(produit);
		}
	}
}
