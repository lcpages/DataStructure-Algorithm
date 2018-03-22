/*
* fichier arbre_bin.c
* Projet SDA2 printemps 2018
* Chloé RICHE et Louis-César Pagès
*/

#include "arbre_bin.h"

Node initBinarySearchTree()
{
  Node abr = (Node)malloc(sizeof(struct noeud));
  if(abr == NULL)
  {
    return NULL;
  }

  abr->mot = NULL;
  abr->pos = NULL;
  abr->gauche = NULL;
  abr->droit = NULL;

  return abr;
}

void freeBinarySearchTree(Node abr)
{
  if(abr == NULL)
  {
    return;
  }
  else
  {
    freeBinarySearchTree(abr->gauche);
    freeBinarySearchTree(abr->droit);
    freeOrderedSet(abr->pos);
    free(mot);
  }
}

int getNumberString(Node abr);
int getTotalNumberString(Node abr);
insert(Node abr, char* nouv_mot, int nouv_pos);
Ens find(Node abr, char* mot);
Ens findCooccurrences(Node abr, char* mot1, char* mot2);
void printBinarySearchTree(Node abr);
