/*
* fichier arbre_bin.h
* Projet SDA2 printemps 2018
* Chloé RICHE et Louis-César Pagès
*/

#ifndef _ABR_H_
#define _ABR_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "ensemble.h"

/*
* structure de l'arbre binaire de recherche
* mot : mot du noeud
* pos : ses positions dans le texte
* gauche : branche gauche, mots avant dans le dico
* droit : branche droite, mots après dans le dico
*/
typedef struct noeud
{
  char* mot;
  Ens pos;
  struct noeud* gauche;
  struct noeud* droit;
}  *Node;

// création/destruction de l'ABR
Node initBinarySearchTree();
void freeBinarySearchTree(Node abr);

// renvoie le nb de mots différents contenus dans l'ABR
int getNumberString(Node abr);
// renvoie le nb de paires mots-phrases différentes dans l'ABR
int getTotalNumberString(Node abr);

// insertion d'une nouvelle paire mot-position dans l'abr
// retourne l'arbre modifié si besoin
Node insert(Node abr, char* nouv_mot, int nouv_pos);

// retrouve tous les indices d'occurrence du mot
Ens find(Node abr, char* mot);
// permet de retrouver tous les indices de co-occurrence des mots
// 2 pour le moment
// fonction variadique ?
Ens findCooccurrences(Node abr, char* mot1, char* mot2);

// affiche l'ABR
// parcours infixe (ordre alphabétique)
void printBinarySearchTree(Node abr);

// création automatique de l'ABR à partir d'un texte
// argument : chemin vers le fichier du texte
Node createAuto(char* chemin);

#endif
