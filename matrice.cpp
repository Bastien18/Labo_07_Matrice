/*
  ---------------------------------------------------------------------------
  Fichier     : matrice.cpp
  Nom du labo : Labo_07_C
  Auteur(s)   : Lucas Leissing & Bastien Pillonel
  Date        : 07.12.2021
  But         : Fichier des définition des ss programme permettant la
                manipulation de matrice (vector 2D).

  Remarque(s) : -

  Compilateur : MingW-w64 g++ 11.2.0
  ---------------------------------------------------------------------------
*/

#include <algorithm>
#include <numeric>
#include <chrono>
#include <random>
#include "matrice.h"

using namespace std;

// Opérateur de flux vecteur
ostream& operator<<(ostream& os, const Vecteur & v){
   os << '(';
   for(Vecteur::const_iterator it = v.begin(); it != v.end(); ++it){
      if(it != v.begin())
         os << ',';
      os << *it;
   }
   return os << ')';
}

// Opérateur de flux matrice
ostream& operator<<(ostream& os, const Matrice& m){
   os << '[';
   for(Matrice::const_iterator it = m.begin(); it != m.end(); ++it){
      if(it != m.begin())
         os << ',';
      os << *it;
   }
   return os << ']';
}

// Vérifie si la matrice est carré ou non
bool estCarree(const Matrice& m){
   for(size_t i = 0; i < m.size(); ++i){
      if(m.size() != m[i].size())
         return false;
   }
   return true;
}

// Vérifie si la matrice est régulière
bool estReguliere(const Matrice& m){
   for(size_t i = 1; i < m.size(); ++i){
      if(m[i - 1].size() != m[i].size())
         return false;
   }
   return true;
}

// Compare la taille de deux vecteurs adjacents dans une matrice
bool compareTaille(const Vecteur& a, const Vecteur& b){return a.size() < b.size();}

// Retourne la longueur minimum des vecteurs d'une matrice (retourne 0 si matrice
// vide)
size_t minCol(const Matrice& m){
   if(m.empty())
      return 0ull;
   return min_element(m.begin(), m.end(), compareTaille)->size();
}

// Renvoie la somme de chaque élément du vecteur de la matrice
Data somme(const Vecteur& i){return accumulate(i.begin(),i.end(),0);}

// Retourne un vecteur avec la somme de chaque ligne d'une matrice
Vecteur sommeLigne(const Matrice& m){
   Vecteur sommeLigne(m.size());
   transform(m.begin(),m.end(), sommeLigne.begin(), somme);
   return sommeLigne;
}

// Additionne deux éléments de deux vecteur en colonne
Data addition(const Data a, const Data b){
   return a + b;
}

// Fais la somme en colone de deux vecteurs
Vecteur additionEnCol(Vecteur a, Vecteur b){
   // Choisi le vecteur le plus petit afin de faire le moins d'addition possible
   if(a.size() < b.size()){
      transform(a.begin(), a.end(), b.begin(), b.begin(), addition);
      return b;
   }
   else{
      transform(b.begin(), b.end(), a.begin(), a.begin(), addition);
      return a;
   }
}

// Fait la somme de toutes les colonnes
Vecteur sommeCol(const Matrice& m){
   Vecteur sommeCol (0);
   return accumulate(m.begin(), m.end(), sommeCol, additionEnCol);
}

// Compare la somme de 2 vecteurs adjacents d'une matrice
bool compareSomme(const Vecteur& a, const Vecteur& b){
   return  accumulate(a.begin(),a.end(),0) < accumulate(b.begin(),b.end(),0);
}

// Retourne le 1er vecteur dont la somme est la plus faible (retourne vecteur vide si
// matrice vide)
Vecteur vectSommeMin(const Matrice& m){
   if(m.empty())
      return {};
   return *min_element(m.begin(), m.end(), compareSomme);
}

// mélange les vecteurs d'une matrice
void shuffleMatrice(Matrice& m){
   unsigned graine = std::chrono::system_clock::now().time_since_epoch().count();
   shuffle(m.begin(), m.end(), default_random_engine(graine));
}

// retourne l'élément min d'un vecteur ATTENTION si vecteur vide vaut 0 !!!!!!!
Data min_element_verif(const Vecteur& i){
   if(i.empty())
      return VALEUR_VECTEUR_VIDE;
   return *min_element(i.begin(), i.end());
}

// Compare les éléments min de deux vecteur
bool compareMin(const Vecteur& a, const Vecteur& b){
   return   min_element_verif(a) < min_element_verif(b);
}

// Trie les vecteurs de la matrice dans l'ordre croissant en fonction de leur
// élément min
void sortMatrice(Matrice& m){
   sort(m.begin(), m.end(), compareMin);
}
