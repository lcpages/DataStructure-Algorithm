/*
* fichier arbre_bin.h
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

//determine si un arbre binaire est équilibré
bool isBalanced(Node abr);
//determine la hauteur de l'arbre
int getHeight(Node abr);
//determine la hauteur moyenne à chaque noeud
double getAverageDepth(Node abr);
//rotation simple à gauche
Node rotateLeft(Node x);
//rotation simple à droite
Node rotateRight(Node y);
//rotation double à gauche
Node rotateDoubleLeft(Node x);
//rotation double à droite
Node rotateDoubleRight(Node y);

#endif
