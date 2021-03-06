/*
* fichier ensemble.h
* Projet SDA2 printemps 2018
* Chloé RICHE et Louis-César Pagès
*/

#ifndef _EMS_H_
#define _EMS_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct el
{
  int val;
  struct el * suiv;
}  *Ens;

Ens initOrderedSet();
void freeOrderedSet();
int getNumberElt(Ens e);
int insertValue(Ens Str, int e);
bool contains(Ens Str, int e);
void printOrderedSet(Ens Str);
Ens intersect(Ens Str, Ens Str2);


#endif
