/*
* fichier ensemble.c
* Projet SDA2 printemps 2018
* Chloé RICHE et Louis-César Pagès
*/

#include "ensemble.h"

Ens initOrderedSet()
{
  Ens st = malloc(sizeof(struct ensemble));
  Ens->V = malloc(sizeof(int));
  Ens->size = 0;

  return st;
}

void freeOtderedSet(Ens * st)
{
  free(st->V);
  free(st);
}

int getNumberElt(Ens st)
{
  return st->size;
}

int insertValue(Ens St, int e)
{
  if(contains(St,e))
  {
    return 0;
  }
  St->size++;
  St->V = realloc(St, St->size * sizeof(int));

  St->V[St->size] = e;

  return 1;
}

bool contains(Ens St, int e)
{
  for(int i=0; i<st->size; i++)
  {
    if(St->V[i] == e)
    {
      return true;
    }
  }
  return false;
}

void printOrderedSet(Ens St)
{
  for(int i=0; i<St->size; i++)
  {
    printf("%d ",St->V[i]);
  }
}

int intersect(Ens Str, Ens Str2);
