/*
  ---------------------------------------------------------------------------
  Fichier     : main.cpp
  Nom du labo : Labo_07_C
  Auteur(s)   : Lucas Leissing & Bastien Pillonel
  Date        : 07.12.2021
  But         : Le main fait simplement le test des fonctions mise à dispo par
                la librairie matrice avec diverses matrices "etreme".

  Remarque(s) : -

  Compilateur : MingW-w64 g++ 11.2.0
  ---------------------------------------------------------------------------
*/

#include <cstdlib>
#include <iostream>
#include <limits>
#include "matrice.h"

using namespace std;

//-------------------------------------------------------------------------
// Prototype de fonction
//-------------------------------------------------------------------------

void finProgramme(const string& MSG_FIN);

int main() {

   //-------------------------------------------------------------------------
   // Déclaration des constantes et variables du programme
   //-------------------------------------------------------------------------
   const string   MSG_FIN  =  "Presser ENTER pour quitter";

   Vecteur  vVide(0),
            v1({1,2,3,4});

   Matrice  mVide(0),
            mVecteurVide({{},{},{}}),
            m1({{},{1,5,2}}),
            m2({{3,-4,5},{}}),
            m3({{4,30,6},{2},{-5,7},{20,0,0,0}}),
            m4({{1,2},{3,4}}),
            m5({{1,2,3},{4,5,6}});

   //-------------------------------------------------------------------------
   // Test des fonctions
   //-------------------------------------------------------------------------
   // Opérateur de flux vecteur
   cout  << "Operateur de flux vecteur vide : "       << vVide << endl
         << "Operateur de flux vecteur 1 : "          << v1    << endl  << endl;

   // Opérateur de flux matrice
   cout  << "Operateur de flux matrice vide : "          << mVide          << endl
         << "Operateur de flux matrice vecteur vide : "  << mVecteurVide   << endl
         << "Operateur de flux matrice 1 : "             << m1             << endl
         << "Operateur de flux matrice 2 : "             << m2             << endl
         << "Operateur de flux matrice 3 : "             << m3             << endl
         << "Operateur de flux matrice 4 : "             << m4             << endl
         << "Operateur de flux matrice 5 : "             << m5             << endl
         << endl;

   // estCarree
   cout  << "estCarree matrice vide : "
         << boolalpha   << estCarree(mVide)          << endl
         << "estCarree matrice vecteur vide : "
         << estCarree(mVecteurVide)   << endl
         << "estCarree matrice 1 : "
         << estCarree(m1)             << endl
         << "estCarree matrice 2 : "
         << estCarree(m2)             << endl
         << "estCarree matrice 3 : "
         << estCarree(m3)             << endl
         << "estCarree matrice 4 : "
         << estCarree(m4)             << endl
         << endl;

   // estReguliere
   cout  << "estReguliere matrice vide : "
         << boolalpha   << estReguliere(mVide)          << endl
         << "estReguliere matrice vecteur vide : "
         << estReguliere(mVecteurVide)   << endl
         << "estReguliere matrice 1 : "
         << estReguliere(m1)             << endl
         << "estReguliere matrice 2 : "
         << estReguliere(m2)             << endl
         << "estReguliere matrice 3 : "
         << estReguliere(m3)             << endl
         << "estReguliere matrice 5 : "
         << estReguliere(m5)             << endl
         << endl;

   // minCol
   cout  << "minCol matrice vide : "          << minCol(mVide)          << endl
         << "minCol matrice vecteur vide : "  << minCol(mVecteurVide)   << endl
         << "minCol matrice 1 : "             << minCol(m1)             << endl
         << "minCol matrice 2 : "             << minCol(m2)             << endl
         << "minCol matrice 3 : "             << minCol(m3)             << endl
         << endl;

   // sommeLigne
   cout  << "sommeLigne matrice vide : "          << sommeLigne(mVide)        << endl
         << "sommeLigne matrice vecteur vide : "  << sommeLigne(mVecteurVide) << endl
         << "sommeLigne matrice 1 : "             << sommeLigne(m1)           << endl
         << "sommeLigne matrice 2 : "             << sommeLigne(m2)           << endl
         << "sommeLigne matrice 3 : "             << sommeLigne(m3)           << endl
         << endl;

   // sommeColonne
   cout  << "sommeColonne matrice vide : "          << sommeCol(mVide)        << endl
         << "sommeColonne matrice vecteur vide : "  << sommeCol(mVecteurVide) << endl
         << "sommeColonne matrice 1 : "             << sommeCol(m1)           << endl
         << "sommeColonne matrice 2 : "             << sommeCol(m2)           << endl
         << "sommeColonne matrice 3 : "             << sommeCol(m3)           << endl
         << endl;

   // vectSommeMin
   cout  << "vectSommeMin matrice vide : "          << vectSommeMin(mVide)
         << endl
         << "vectSommeMin matrice vecteur vide : "  << vectSommeMin(mVecteurVide)
         << endl
         << "vectSommeMin matrice 1 : "             << vectSommeMin(m1)
         << endl
         << "vectSommeMin matrice 2 : "             << vectSommeMin(m2)
         << endl
         << "vectSommeMin matrice 3 : "             << vectSommeMin(m3)
         << endl  << endl;

   // shuffleMatrice
   cout  << "shuffleMatrice matrice vide : "
         << (shuffleMatrice(mVide), mVide)               << endl
         << "shuffleMatrice matrice vecteur vide : "
         << (shuffleMatrice(mVecteurVide), mVecteurVide) << endl
         << "shuffleMatrice matrice 1 : "
         << (shuffleMatrice(m1), m1)                     << endl
         << "shuffleMatrice matrice 2 : "
         << (shuffleMatrice(m2), m2)                     << endl
         << "shuffleMatrice matrice 3 : "
         << (shuffleMatrice(m3), m3)                     << endl  << endl;

   // sortMatrice
   cout  << "sortMatrice matrice vide : "
         << (sortMatrice(mVide), mVide)               << endl
         << "sortMatrice matrice vecteur vide : "
         << (sortMatrice(mVecteurVide), mVecteurVide) << endl
         << "sortMatrice matrice 1 : "
         << (sortMatrice(m1), m1)                     << endl
         << "sortMatrice matrice 2 : "
         << (sortMatrice(m2), m2)                     << endl
         << "sortMatrice matrice 3 : "
         << (sortMatrice(m3), m3)                     << endl  << endl;

   //-------------------------------------------------------------------------
   // Test des fonctions
   //-------------------------------------------------------------------------
   finProgramme(MSG_FIN);

   return EXIT_SUCCESS;
}

void finProgramme(const string& MSG_FIN){
   cout  << MSG_FIN;
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
   exit(EXIT_SUCCESS);
}
