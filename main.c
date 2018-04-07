/*
* fichier main.c
* Projet SDA2 printemps 2018
* Chloé RICHE et Louis-César Pagès
*/

#include "ensemble.h"
#include "arbre_bin.h"

int main()
{
  Ens a = initOrderedSet();
  int nb_el = getNumberElt(a);
  printf("Au départ, %d éléments dans a.\n", nb_el);

  insertValue(a, 10);
  insertValue(a, 200);
  //insertValue(a, -1);
  //insertValue(a, 178);
  nb_el = getNumberElt(a);
  printf("Après, %d éléments dans a.\n", nb_el);
  return 0;
}
