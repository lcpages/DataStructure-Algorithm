/*
* fichier arbre_equi.h
* Projet SDA2 printemps 2018
* Chloé RICHE et Louis-César Pagès
*/

#ifndef _EQUI_H_
#define _EQUI_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "ensemble.h"
#include "arbre_bin.h"

// determine la difference d'un noeud entre ses fils gauche et droit
int difference (Node abr);

//determine si un arbre binaire est équilibré
bool isBalanced(Node abr);

//determine la hauteur de l'arbre
int getHeight(Node abr);

//determine la hauteur moyenne à chaque noeud
double getAverageDepth(Node abr);

// rotation simple à gauche
// x diff de 2, x->droit diff de 1
Node rotateLeft(Node x);

// rotation simple à droite
// y diff de -2, y->gauche diff de -1
Node rotateRight(Node y);

// rotation double à gauche
// A diff de -2 et A->gauche diff de 1
Node rotateDoubleLeft(Node A);

// rotation double à droite
// A diff de 2 et A->droit diff de -1
Node rotateDoubleRight(Node A);

// équilibre l'arbre si nécessaire
Node getBalancedTree (Node abr);

#endif
