#include <iostream>
#include <iomanip>
#include "Produit.h"
#include "ProduitAuxEncheres.h"
#include "ProduitSolde.h"
#include "Client.h"
#include "ClientPremium.h"
#include "Fournisseur.h"
#include "Gestionnaire.h"

using namespace std;

/*Reponse au questions
 *
 *1) La reponse est 1
 *2) La sortie est 1 parce que la classe de base n'est pas polymorphique, cette methode n'est pas virtuel
 *3) On retire le virtual de la fonction dans la classe B - On retire la fonction f() de la classe C
 *4) Parce que c'est une classe abstraite (elle a une methode virtuelle pure)
 *5) Pour faire le tri on peut faire un dynamic_cast sur les produits soldés
 *   Imaginons que vecteur<Produit*> panier_; contient tous les produits on pourrait alors faire le tri de cette facon
 *   et  vecteur<Produit*> ordinaire_; est un vecteur vide.
 *   
 *   cout << "Produit solde" << endl;
 *   for(Produit* produit:panier_){
 *		if(ProduitSolde* produitSolde = dynamic_cast<ProduitSolde*>(produit))
 *			produitSolde.afficher();
 *		else
 *			ordinaire_.push_back(produit);
 *   }
 *   cout << "Autres produit" << endl;
 *   for(Produit* produit:ordinaire_){
 *		produit.afficher();
 *   }
 *    
 */

int main()
{
    Gestionnaire poly;
    Client ratus;
    Client gaspard("Donada--Vidal", "Gaspard", 5215487, "P4R 1I5", 1997);
    Client rick("S", "Rick", 8435174, "HF1 8H3", 20012003);
    ClientPremium marou;
    ClientPremium julie("Cash", "Julie", 1126250, "HZ9 1J4", 19141918, 50);
    Fournisseur mina;
    Fournisseur martine("Bellaiche", "Martine", 6845123, "H4C 8D4");
    Fournisseur samuel("Kadoury", "Samuel", 1687421, "H1G 2G4");
    Produit sel;
    Produit chaussures(&martine, "chaussures", 1, 40.0);
    Produit stylo(&samuel, "stylo", 2, 3.0);
    ProduitAuxEncheres sculpture;
    ProduitAuxEncheres violoncelle(&martine, "violoncelle", 3, 5000.0);
    ProduitSolde saladier;
    ProduitSolde montre(&mina, "montre", 4, 100.0, 30);
    ProduitSolde nem(&samuel, "nem crevettes", 5, 2.0);
    poly.ajouterUsager(&gaspard);
    poly.ajouterUsager(&rick);
    poly.ajouterUsager(&martine);
    poly.ajouterUsager(&samuel);
    poly.ajouterUsager(&ratus);
    poly.ajouterUsager(&marou);
    poly.ajouterUsager(&mina);
    poly.ajouterUsager(&julie);

    vector<bool> tests;

    // le constructeur par défaut de client doit fonctionner
    tests.push_back(ratus.obtenirNom() == "Doe" &&
                    ratus.obtenirPrenom() == "John" &&
                    ratus.obtenirIdentifiant() == 0 &&
                    ratus.obtenirCodePostal() == "A1A A1A" &&
                    ratus.obtenirCodeClient() == 0);

    //le constructeur par paramètres de client doit fonctionner
    tests.push_back(gaspard.obtenirNom() == "Donada--Vidal" &&
                    gaspard.obtenirPrenom() == "Gaspard" &&
                    gaspard.obtenirIdentifiant() == 5215487 &&
                    gaspard.obtenirCodePostal() == "P4R 1I5" &&
                    gaspard.obtenirCodeClient() == 1997);
    // le constructeur par défaut de client premium doit fonctionner
    tests.push_back(marou.obtenirNom() == "Doe" &&
                    marou.obtenirPrenom() == "John" &&
                    marou.obtenirIdentifiant() == 0 &&
                    marou.obtenirCodePostal() == "A1A A1A" &&
                    marou.obtenirCodeClient() == 0 &&
                    marou.obtenirJoursRestants() == 0);
    // le constructeur par paramètres de client premium doit fonctionner
    tests.push_back(julie.obtenirNom() == "Cash" &&
                    julie.obtenirPrenom() == "Julie" &&
                    julie.obtenirIdentifiant() == 1126250 &&
                    julie.obtenirCodePostal() == "HZ9 1J4" &&
                    julie.obtenirCodeClient() == 19141918 &&
                    julie.obtenirJoursRestants() == 50);
     //le constructeur par défaut de fournisseur doit fonctionner
    tests.push_back(mina.obtenirNom() == "Doe" &&
                    mina.obtenirPrenom() == "John" &&
                    mina.obtenirIdentifiant() == 0 &&
                    mina.obtenirCodePostal() == "A1A A1A");
    // le constructeur par paramètres de fournisseur doit fonctionner
    tests.push_back(martine.obtenirNom() == "Bellaiche" &&
                    martine.obtenirPrenom() == "Martine" &&
                    martine.obtenirIdentifiant() == 6845123 &&
                    martine.obtenirCodePostal() == "H4C 8D4");
    // le constructeur par défaut de produit doit fonctionner
    tests.push_back(sel.obtenirNom() == "outil" &&
                    sel.obtenirReference() == 0 &&
                    sel.obtenirFournisseur() == nullptr &&
                    sel.obtenirPrix() == 0.0);
    // le constructeur par paramètres de produit doit fonctionner
    tests.push_back(stylo.obtenirNom() == "stylo" &&
                    stylo.obtenirReference() == 2 &&
                    stylo.obtenirFournisseur() == &samuel &&
                    stylo.obtenirPrix() == 3.0);

    // le constructeur par défaut de produit aux enchères doit fonctionner
    tests.push_back(sculpture.obtenirNom() == "outil" &&
                    sculpture.obtenirReference() == 0 &&
                    sculpture.obtenirFournisseur() == nullptr &&
                    sculpture.obtenirPrix() == 0.0 &&
                    sculpture.obtenirPrixInitial() == 0.0);
    // le constructeur par paramètres de produit aux enchères doit fonctionner
    tests.push_back(violoncelle.obtenirNom() == "violoncelle" &&
                    violoncelle.obtenirReference() == 3 &&
                    violoncelle.obtenirFournisseur() == &martine &&
                    violoncelle.obtenirPrix() == 5000.0 &&
                    violoncelle.obtenirPrixInitial() == 5000.0);
    // le constructeur par défaut de produit soldé doit fonctionner
    tests.push_back(saladier.obtenirNom() == "outil" &&
                    saladier.obtenirReference() == 0 &&
                    saladier.obtenirFournisseur() == nullptr &&
                    saladier.obtenirPrix() == 0.0 &&
                    saladier.obtenirPourcentageRabais() == 0);
    // le constructeur par paramètres de produit soldé doit fonctionner
    tests.push_back(nem.obtenirNom() == "nem crevettes" &&
                    nem.obtenirReference() == 5 &&
                    nem.obtenirFournisseur() == &samuel &&
                    nem.obtenirPrix() == 2 &&
                    nem.obtenirPourcentageRabais() == 0);

    //// une surenchère doit être strictement supérieure à l'offre précédente
    poly.encherir(&julie, &violoncelle, 5000.0);
    tests.push_back(julie.obtenirPanier().size() == 0);
    poly.encherir(&gaspard, &violoncelle, 6000.0);
    poly.encherir(&julie, &violoncelle, 6000.0);
    tests.push_back(julie.obtenirPanier().size() == 0);
    poly.encherir(&julie, &violoncelle, 7000.0);
    tests.push_back(julie.obtenirPanier().size() == 1);
    // on ne peut pas surencherir sur sa propre enchère
    poly.encherir(&julie, &violoncelle, 8000.0);
    tests.push_back(violoncelle.obtenirPrix() == 7000.0);
    // surenchérir doit enlever le produit du panier de l'ancien encherisseur
    poly.encherir(&gaspard, &violoncelle, 8000.0);
    tests.push_back(julie.obtenirPanier().size() == 0);
    // surenchérir doit ajouter le produit au panier du nouvel enchérisseur
    poly.encherir(&julie, &violoncelle, 9000.0);
    tests.push_back(julie.obtenirPanier().size() == 1 &&
                    julie.obtenirPanier()[0]->obtenirNom() == "violoncelle");
    // surenchérir doit mettre à jour l'attribut encherisseur_
    tests.push_back(violoncelle.obtenirEncherisseur() != nullptr &&
                    violoncelle.obtenirEncherisseur()->obtenirPrenom() == "Julie");
    // surenchérir doit mettre à jour le prix du produit
    tests.push_back(violoncelle.obtenirPrix() == 9000.0);
    // le prix initial ne doit pas varier
    tests.push_back(violoncelle.obtenirPrixInitial() == 5000.0);

    // ajouter le produit au client doit l'ajouter au panier
    gaspard.ajouterProduit(&stylo); // produit normal
    gaspard.ajouterProduit(&nem);   // produit soldé
    tests.push_back(gaspard.obtenirPanier().size() == 2 &&
                    gaspard.obtenirPanier()[0]->obtenirNom() == "stylo" &&
                    gaspard.obtenirPanier()[1]->obtenirNom() == "nem crevettes");
    // idem pour client premium
    julie.ajouterProduit(&stylo); // produit normal
    julie.ajouterProduit(&nem);   // produit soldé
    tests.push_back(julie.obtenirPanier().size() == 3 &&
                    julie.obtenirPanier()[1]->obtenirNom() == "stylo" &&
                    julie.obtenirPanier()[2]->obtenirNom() == "nem crevettes");
    // on ne peut pas ajouter le même produit deux fois dans le panier
    gaspard.ajouterProduit(&stylo); // produit normal
    gaspard.ajouterProduit(&nem);   // produit soldé
    tests.push_back(gaspard.obtenirPanier().size() == 2);
    // idem pour client premium
    julie.ajouterProduit(&stylo); // produit normal
    julie.ajouterProduit(&nem);   // produit soldé
    tests.push_back(julie.obtenirPanier().size() == 3);

    // ajouter le produit au fournisseur doit l'ajouter au catalogue
    tests.push_back(martine.obtenirCatalogue().size() == 2 &&
                    martine.obtenirCatalogue()[0]->obtenirNom() == "chaussures" && // normal
                    martine.obtenirCatalogue()[1]->obtenirNom() == "violoncelle"); // enchères
    tests.push_back(mina.obtenirCatalogue().size() == 1 &&
                    mina.obtenirCatalogue()[0]->obtenirNom() == "montre"); // soldé
    // modifier le fournisseur d'un produit doit ajouter le produit au nouveau fournisseur
    martine.ajouterProduit(&montre);
    tests.push_back(martine.obtenirCatalogue().size() == 3 &&
                    martine.obtenirCatalogue()[0]->obtenirNom() == "chaussures" &&
                    martine.obtenirCatalogue()[1]->obtenirNom() == "violoncelle" &&
                    martine.obtenirCatalogue()[2]->obtenirNom() == "montre");
    // modifier le fournisseur d'un produit doit retirer le produit du catalogue précédent
    tests.push_back(mina.obtenirCatalogue().size() == 0);
    // enlever un produit doit mettre l'attribut fournisseur à jour
    martine.enleverProduit(&montre);
    tests.push_back(montre.obtenirFournisseur() == nullptr);
    // enlever un produit doit le retirer du catalogue du fournisseur
    tests.push_back(martine.obtenirCatalogue().size() == 2 &&
                    martine.obtenirCatalogue()[0]->obtenirNom() == "chaussures" &&
                    martine.obtenirCatalogue()[1]->obtenirNom() == "violoncelle");
    // enlever un produit une deuxième fois ne doit rien faire
    martine.enleverProduit(&montre);
    tests.push_back(martine.obtenirCatalogue().size() == 2 &&
                    martine.obtenirCatalogue()[0]->obtenirNom() == "chaussures" &&
                    martine.obtenirCatalogue()[1]->obtenirNom() == "violoncelle");

    // réinitialiser doit vider le panier de tous les clients
    poly.reinitialiser();
    tests.push_back(gaspard.obtenirPanier().size() == 0 &&
                    ratus.obtenirPanier().size() == 0 &&
                    julie.obtenirPanier().size() == 0 &&
                    marou.obtenirPanier().size() == 0 &&
                    rick.obtenirPanier().size() == 0);
    // réinitialiser doit mettre à jour l'attribut encherisseur_ quand nécessaire
    tests.push_back(violoncelle.obtenirEncherisseur() == nullptr);
    // réinitialiser doit remettre les produits aux enchères à leur prix intial
    tests.push_back(violoncelle.obtenirPrix() == violoncelle.obtenirPrixInitial());
    // réinitialiser doit vider le catalogue de tous les fournisseurs
    tests.push_back(martine.obtenirCatalogue().size() == 0 &&
                    samuel.obtenirCatalogue().size() == 0 &&
                    mina.obtenirCatalogue().size() == 0);
    // réinitialiser doit mettre à jour l'attribut fournisseur_ quand nécessaire
    tests.push_back(stylo.obtenirFournisseur() == nullptr &&
                    sculpture.obtenirFournisseur() == nullptr &&
                    nem.obtenirFournisseur() == nullptr);

    // le chiffre d'affaires devrait être nul après une réinitialisation
    tests.push_back(poly.obtenirChiffreAffaires() == 0.0);
    // le total à payer des clients normaux doit sommer les prix dans le panier
    gaspard.ajouterProduit(&chaussures);       // 40
    gaspard.ajouterProduit(&montre);           // 100 - 30
    poly.encherir(&gaspard, &violoncelle, 20000); // 20000
	//test 39
    tests.push_back(gaspard.obtenirTotalAPayer() == 20110.0);
    // le total à payer des clients premiums doit prendre en compte la réduction
    julie.ajouterProduit(&chaussures);       // 35
    julie.ajouterProduit(&montre);           // 100 - 30 - 5
    poly.encherir(&julie, &violoncelle, 21000); // 21000 - 5
    tests.push_back(julie.obtenirTotalAPayer() == 21095.0);
    // la réduction ne doit pas induire des prix négatifs
    julie.ajouterProduit(&nem); // 0
    tests.push_back(julie.obtenirTotalAPayer() == 21095.0);
    // la surenchère doit actualiser le prix à payer pour l'ancien encherisseur
	//test 42
    tests.push_back(gaspard.obtenirTotalAPayer() == 110.0);
    // le total à payer des fournisseurs doit être nul
    samuel.ajouterProduit(&chaussures);
    samuel.ajouterProduit(&montre);
    tests.push_back(samuel.obtenirTotalAPayer() == 0.0);
    // le chiffre d'affaires doit additionner les totaux à payer
	//test 44
    tests.push_back(poly.obtenirChiffreAffaires() == 110.0 + 21095.0);
    
    // un usager ne peut pas être ajouté deux fois au gestionnaire
	tests.push_back(poly.obtenirUsagers().size() == 8);
    poly.ajouterUsager(&martine);
    tests.push_back(poly.obtenirUsagers().size() == 8);

    // fonctions d'affichage
    gaspard.afficherPanier();
    julie.afficherPanier();
    ratus.afficherPanier();
    martine.afficherCatalogue();
    samuel.afficherCatalogue();
    mina.afficherCatalogue();
    poly.afficherLesProfils();

    cout << "TESTS" << endl;
    for (unsigned int i = 0; i < tests.size(); i++)
    {
        cout << "\tTest " << setfill('0') << setw(2) << i + 1 << "... ";
        if (tests[i])
            cout << "OK!" << endl;
        else
            cout << "ECHEC" << endl;
    }

    return 0;
}
