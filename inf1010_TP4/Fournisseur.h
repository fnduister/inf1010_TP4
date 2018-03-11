#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <string>
#include <vector>
#include "Usager.h"
#include "Produit.h"

using namespace std;

class Fournisseur : public Usager
{
  public:
    Fournisseur();
    Fournisseur(const string &nom, const string &prenom, int identifiant, const string &codePostal);

    vector<Produit *> obtenirCatalogue() const;
    void afficherCatalogue() const;
	virtual void afficherProfil() const;

    virtual void reinitialiser();
    void ajouterProduit(Produit *produit);
    void enleverProduit(Produit *produit);

  private:
    vector<Produit *> catalogue_;
};

#endif
