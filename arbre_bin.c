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

int getNumberString(Node abr)
{
  if(abr == NULL)
  {
    return 0;
  }
  else
  {
    return 1 + getNumberString(abr->gauche) + getNumberString(abr->droit);
  }
}

int getTotalNumberString(Node abr)
{
  if(abr == NULL)
  {
    return 0;
  }
  else
  {
    return getNumberElt(abr->pos) + getTotalNumberString(abr->gauche) + getTotalNumberString(abr->droit);
  }
}

Node insert(Node abr, char* nouv_mot, int nouv_pos)
{
  // si l'arbre est vide : insertion à la racine
  if(abr == NULL)
  {
    abr->mot = nouv_mot;
    abr->pos = initOrderedSet();
    insertValue(abr->pos, nouv_pos);
  }

  // sinon si le mot à la racine est le même
  else if(strcmp(abr->mot, nouv_mot) == 0)
  {
    if(!contains(abr->pos, nouv_pos))
    {
      insertValue(abr->pos, nouv_pos);
    }
  }

  // sinon recherche dans les branches inférieures
  else if(strcmp(abr->mot, nouv_mot) < 0)
  {
    abr->gauche = insert(abr->gauche, nouv_mot, nouv_pos);
  }
  else
  {
    abr->droit = insert(abr->droit, nouv_mot, nouv_pos);
  }

  return abr;
}

Ens find(Node abr, char* mot)
{
  // si l'arbre est vide
  if(abr == NULL)
  {
    return NULL;
  }

  // sinon si le mot à la racine est le même
  else if(strcmp(abr->mot, mot) == 0)
  {
    return arb->pos;
  }

  // sinon recherche dans les branches inférieures
  else if(strcmp(abr->mot, mot) < 0)
  {
    return(find(abr->gauche, mot));
  }
  else
  {
    return(find(abr->droit, mot));
  }
}

Ens findCooccurrences(Node abr, char* mot1, char* mot2)
{
  // si les deux mots sont contenus dans l'ABR
  if((find(abr, mot1) != NULL) && (find(abr, mot2) != NULL))
  {
    return intersect(find(abr, mot1), find(abr, mot2));
  }
  else
  {
    return NULL;
  }
}

void printBinarySearchTree(Node abr)
{
  if(abr->gauche != NULL)
  {
    printBinarySearchTree(abr->gauche);
  }
  if(abr != NULL)
  {
    printf("%s\n", abr->mot);
    printOrderedSet(abr->pos);
  }
  if(abr->droit != NULL)
  {
    printBinarySearchTree(abr->droit);
  }
}
