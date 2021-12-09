/*
  ---------------------------------------------------------------------------
  Fichier     : matrice.h
  Nom du labo : Labo_07_C
  Auteur(s)   : Lucas Leissing & Bastien Pillonel
  Date        : 07.12.2021
  But         : Fichier des déclarations des ss programme permettant la
                manipulation de matrice (vector 2D).

  Remarque(s) : -

  Compilateur : MingW-w64 g++ 11.2.0
  ---------------------------------------------------------------------------
*/

#ifndef LABO_07_MATRICE_MATRICE_H
#define LABO_07_MATRICE_MATRICE_H

#include <iostream>
#include <vector>

using Data     = int;
using Vecteur  = std::vector<Data>;
using Matrice  = std::vector<std::vector<Data>>;

const Data  VALEUR_VECTEUR_VIDE  = 0;

//-------------------------------------------------------------------
// operateur de flux << (vecteur)
//-------------------------------------------------------------------
// Description: Surcharge de l'opérateur de flux permettant d'afficher
// un vecteur sous la forme (x1,x2,xn)
//
// Paramètres:
// Nom: ostream  Description: Le flux de l'opérateur qu'on souhaite
//                            surcharger.
// Nom: v        Description: Le vecteur que l'on souhaite afficher
//
// Retourne: Le dernier caractère à afficher
//-------------------------------------------------------------------
std::ostream& operator<<(std::ostream& os, const Vecteur& v);

//-------------------------------------------------------------------
// operateur de flux << (matrice)
//-------------------------------------------------------------------
// Description: Surcharge de l'opérateur de flux permettant d'afficher
// une matrice sous la forme [(),(),()]
//
// Paramètres:
// Nom: ostream  Description: Le flux de l'opérateur qu'on souhaite
//                            surcharger.
// Nom: m        Description: La matrice que l'on souhaite afficher
//
// Retourne: Le dernier caractère à afficher
//-------------------------------------------------------------------
std::ostream& operator<<(std::ostream& os, const Matrice& m);

//-------------------------------------------------------------------
// estCarre
//-------------------------------------------------------------------
// Description: Vérifie que la matrice est carrée => toutes les lignes
// ont la même taille qui est égal au nombre de ligne
//
// Paramètres:
// Nom: m    Description: Matrice à vérifier
//
// Retourne: Vrai => si la matrice est carré
//           Faux => sinon
//-------------------------------------------------------------------
bool estCarree(const Matrice& m);

//-------------------------------------------------------------------
// estReguliere
//-------------------------------------------------------------------
// Description: Vérifie si la matrice est régulière => toutes les lignes
// ont la même taille
//
// Paramètres:
// Nom: m    Description: Matrice ou se fera la recherche
//
// Retourne: Vrai => si la matrice est régulière
//           Faux => sinon
//-------------------------------------------------------------------
bool estReguliere(const Matrice& m);

//-------------------------------------------------------------------
// compareTaille
//-------------------------------------------------------------------
// Description: Compare la taille de deux vecteur passer en paramètre.
//              Fonction binaire utilisé dans la fonction minCol.
//
// Paramètres:
// Nom: a et b   Description: 2 vecteurs adjacent dont on cherche à
//                            comparer la taille
//
// Retourne: Vrai => taille de a < taille de b
//           Faux => sinon
//-------------------------------------------------------------------
bool compareTaille(const Vecteur& a, const Vecteur& b);

//-------------------------------------------------------------------
// minCol
//-------------------------------------------------------------------
// Description: Cherche la taille du/des vecteur le plus court d'une
//              matrice.
//
// Paramètres:
// Nom: m    Description: Matrice dans laquelle se passera la recherche
//
// Retourne: La taille du vecteur le plus court
//-------------------------------------------------------------------
size_t minCol(const Matrice& m);

//-------------------------------------------------------------------
// somme
//-------------------------------------------------------------------
// Description: Fait  la somme des éléments d'un même vecteur.
//              Utiliser dans sommeLignes pour remplir un vecteur de
//              toutes les sommes de chaque vecteur.
//
// Paramètres:
// Nom: i    Description: Vecteur dans lequel se fait la somme
//
// Retourne: La somme des éléments du vecteur
//-------------------------------------------------------------------
Data somme(const Vecteur& i);

//-------------------------------------------------------------------
// sommeLigne
//-------------------------------------------------------------------
// Description: Calcule et stock toutes les sommes de chaque vecteur
//              dans un autre vecteur.
//
// Paramètres:
// Nom: m    Description: Matrice ou se fera la somme de chaque vecteur
//
// Retourne: Un vecteur contenant toutes les somme de chaque vecteur
//-------------------------------------------------------------------
Vecteur sommeLigne(const Matrice& m);

//-------------------------------------------------------------------
// addition
//-------------------------------------------------------------------
// Description: Additionne deux éléments de deux vecteur en colonne
//
// Paramètres:
// Nom: a et b    Description: Les deux valeurs additionnées
//
// Retourne: Le resultat de l'addition
//-------------------------------------------------------------------
Data addition(Data a, Data b);

//-------------------------------------------------------------------
// additionEnCol
//-------------------------------------------------------------------
// Description: Fais la somme en colone de deux vecteurs.
//
// Paramètres:
// Nom: a et b    Description: Les deux vecteur superposé à additioner
//
// Retourne: Le resultat de la somme
//-------------------------------------------------------------------
Vecteur additionEnCol(Vecteur a, Vecteur b);

//-------------------------------------------------------------------
// sommeCol
//-------------------------------------------------------------------
// Description: Fait l'addition en colone de toutes les lignes
//
// Paramètres:
// Nom: m    Description: Matrice ou se fera l'addition
//
// Retourne: Le vecteur avec toutes les sommes de chaque colonne
//-------------------------------------------------------------------
Vecteur sommeCol(const Matrice& m);

//-------------------------------------------------------------------
// compareSomme
//-------------------------------------------------------------------
// Description: Compare la somme de deux vecteur adjacent. Utiliser
//              dans la fonction vectSommeMin afin de trouver le
//              vecteur avec la plus petite somme.
//
// Paramètres:
// Nom: a et b  Description: Les deux vecteur adjacent a et b dont
//                           la somme est comparé
//
// Retourne: Vrai => somme a < somme b
//           Faux => sinon
//-------------------------------------------------------------------
bool compareSomme(const Vecteur& a, const Vecteur& b);

//-------------------------------------------------------------------
// vectSommeMin
//-------------------------------------------------------------------
// Description: Cherche le vecteur dont la somme est la plus petite
//
// Paramètres:
// Nom: m    Description: Matrice ou se fait la recherche
//
// Retourne: Le PREMIER vecteur dont la somme est la minimum
//-------------------------------------------------------------------
Vecteur vectSommeMin(const Matrice& m);

//-------------------------------------------------------------------
// shuffle
//-------------------------------------------------------------------
// Description: Mélange l'ordre des vecteurs dans la matrice sans
// modifier le contenu des vecteurs
//
// Paramètres:
// Nom: m    Description: Matrice à mélanger
//
// Retourne: -
//-------------------------------------------------------------------
void shuffleMatrice(Matrice& m);

//-------------------------------------------------------------------
// min_element_verif
//-------------------------------------------------------------------
// Description: Sert à retourner l'élément minimum d'un vecteur.
//              ATTENTION l'utilité de cette fonction est de définir
//              qu'un vecteur s'il est vide vaut 0. Il reste possible
//              de définire une autre valeur pour un vecteur vide grace
//              à la const VALEUR_VECTEUR_VIDE située plus haut.
//
// Paramètres:
// Nom: i    Description: Vecteur ou se fait la recherche de l'élément
//                        min.
//
// Retourne: L'élément minimum du vecteur
//-------------------------------------------------------------------
Data min_element_verif(const Vecteur& i);

//-------------------------------------------------------------------
// compareMin
//-------------------------------------------------------------------
// Description: A l'aide de la fonction min_element_verif, cherche
//              quelle vecteur possède l'élément le plus petit entre
//              2 vecteur.
//
// Paramètres:
// Nom: a et b    Description: Les 2 vecteurs adjacent dont on compare
//                             les éléments min
//
// Retourne:   Vrai => élément min a < élément min b
//             Faux => sinon
//-------------------------------------------------------------------
bool compareMin(const Vecteur& a, const Vecteur& b);

//-------------------------------------------------------------------
// sortMatrice
//-------------------------------------------------------------------
// Description: A l'aide de compareMin, trie les vecteur en fonction
//              de leur élément min respectif dans l'ordre croissant
//
// Paramètres:
// Nom: m    Description: Matrice à trié
//
// Retourne: -
//-------------------------------------------------------------------
void sortMatrice(Matrice& m);

#endif //LABO_07_MATRICE_MATRICE_H
