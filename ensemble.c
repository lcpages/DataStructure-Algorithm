/*
* fichier ensemble.c
* Projet SDA2 printemps 2018
* Chloé RICHE et Louis-César Pagès
*/

#include "ensemble.h"

Ens initOrderedSet();
void freeOrderedSet();
int getNumberElt(Ens e);
int insertValue(Ens Str, int e);
bool contains(Ens Str, int e);
void printOrderedSet(Ens Str);
Ens intersect(Ens Str, Ens Str2);
