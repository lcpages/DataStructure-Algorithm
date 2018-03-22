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

typedef struct ensemble
{
  int* V;
  size_t size;
}  *Ens;

Ens initOrderedSet();
void freeOtderedSet();
int getNumberElt(Ens e);
int insertValue(Ens Str, int e);
bool contains(Ens Str, int e);
void printOrderedSet(Ens Str);
int intersect(Ens Str, Ens Str2);


#endif
