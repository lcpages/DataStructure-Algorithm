/*
* fichier arbre_equi.c
* Projet SDA2 printemps 2018
* Chloé RICHE et Louis-César Pagès
*/

#include "arbre_equi.h"

int difference (Node abr)
{
  if(getHeight(abr) == 0)
  {
    return 0;
  }
  else
  {
    return (getHeight(abr->droit) - getHeight(abr->gauche));
  }
}

bool isBalanced (Node abr)
{
  if(difference(abr) >= -1 && difference(abr) <= 1)
  {
    return true;
  }

  return false;
}

//hauteur d'un arbre
int getHeight(Node abr)
{
  // arbre vide
  if(abr == NULL)
  {
    return 0;
  }
  // racine uniquement
  if(abr->gauche == NULL && abr->droit == NULL)
  {
    return 1;
  }
  // si l'arbre a des branches après la racine
  else
  {
    if(getHeight(abr->gauche) > getHeight(abr->droit))
    {
      return 1 + getHeight(abr->gauche);
    }
    else
    {
      return 1 + getHeight(abr->droit);
    }
  }
}

//calcule la moyenne des hauteurs à chaque noeud d'un arbre
double getAverageDepthAux(Node abr)
{
    if(abr->gauche == NULL && abr->droit == NULL) return 0;

    if(abr->gauche != NULL && abr->droit == NULL)
    {
        return (getHeight(abr) + getHeight(abr->gauche));
    }
    else if(abr->gauche == NULL && abr->droit != NULL)
    {
        return (getHeight(abr) + getHeight(abr->droit));
    }
    else
    {
        return (getHeight(abr) + getHeight(abr->droit) + getHeight(abr->gauche));
    }

}

//determine la moyenne des hauteurs d'un arbre
double getAverageDepth(Node abr)
{
     return getAverageDepthAux(abr)/getNumberString(abr);
}

Node rotateRight(Node y)
{
    Node x = y->gauche;
    Node T2 = y->gauche->droit;

    y->gauche = T2;
    x->droit = y;

    return x;
}

Node rotateLeft(Node x)
{
    Node y = x->droit;
    Node T2 = y->gauche;

    x->droit = T2;
    y->gauche = x;

    return y;
}

Node rotateDoubleRight(Node A)
{
    Node C = A->droit;
    Node D = C->gauche;
    Node F = D->gauche;
    Node G = D->droit;

    A->droit = F;
    D->gauche = A;
    C->gauche = G;
    D->droit = C;

    return D;
}

Node rotateDoubleLeft(Node A)
{
    Node B = A->gauche;
    Node E = B->droit;
    Node F = E->gauche;
    Node G = E->droit;

    B->droit = F;
    E->gauche = B;
    A->gauche = G;
    E->droit = A;

    return E;
}

Node getBalancedTree (Node abr)
{
  // si on a besoin d'équilibrer
  if(!isBalanced(abr))
  {
    // branche droite trop grande
    if(difference(abr) >= 2 )
    {
      if(difference(abr->droit) <= 1)
      {
        abr = rotateLeft(abr);
      }
      else if(difference(abr->droit) >= -1)
      {
        abr= rotateDoubleRight(abr);
      }
    }
    // branche gauche trop grande
    else if(difference(abr) <= -2)
    {
      if(difference(abr->gauche) <= -1)
      {
        abr = rotateRight(abr);
      }
      else if(difference(abr->gauche) >= 1)
      {
        abr = rotateDoubleLeft(abr);
      }
    }
    if(difference(abr)>=2) abr = getBalancedTree(abr);
    if(difference(abr)<=-2) abr = getBalancedTree(abr);
  }
  return abr;
}
