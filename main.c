/*
* fichier main.c
* Projet SDA2 printemps 2018
* Chloé RICHE et Louis-César Pagès
*/

#include "ensemble.h"
#include "arbre_bin.h"

int main()
{
  Node abr = initBinarySearchTree();
  abr = insert(abr, "fleur", 1);
  abr = insert(abr, "arbre", 1);
  abr = insert(abr, "fleur", 3);
  abr = insert(abr, "etoile", 4);
  abr = insert(abr, "journée", 7);


  Ens a = find(abr, "arbre");
  printOrderedSet(a);
  Ens b = find(abr, "fleur");
  printOrderedSet(b);
  Ens c = intersect(a, b);
  printOrderedSet(c);
  printf("%d\n", a->val);
  printf("%d\n", b->val);
  printf("%d\n", c->val);
  //printOrderedSet(findCooccurrences(abr, "arbre", "fleur"));
  return 0;
}
