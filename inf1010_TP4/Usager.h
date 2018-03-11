#ifndef USAGER_H
#define USAGER_H

#include "Produit.h"
#include <string>

using namespace std;

class Usager
{
  public:
	virtual ~Usager() = default;
	Usager(const string &nom = "Doe", const string &prenom = "John",
           int identifiant = 0, const string &codePostal = "A1A A1A");

    string obtenirNom() const;
    string obtenirPrenom() const;
    int obtenirIdentifiant() const;
    string obtenirCodePostal() const;
    virtual double obtenirTotalAPayer() const;
    virtual void afficherProfil() const;

    void modifierNom(const string &nom);
    void modifierPrenom(const string &prenom);
    void modifierIdentifiant(int identifiant);
    void modifierCodePostal(const string &codePostal);
    virtual void reinitialiser() = 0;
    void ajouterProduit(Produit *produit);
    void enleverProduit(Produit *produit);

  private:
    string nom_;
    string prenom_;
    int identifiant_;
    string codePostal_;
};

#endif
