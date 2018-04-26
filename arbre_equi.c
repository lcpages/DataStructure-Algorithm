/*
* fichier arbre_bin.c
* Projet SDA2 printemps 2018
* Chloé RICHE et Louis-César Pagès
*/

#include "arbre_equi.h"
#include "arbre_bin.h"

//determine la diffèrence entre chaque noeud
int isBalancedAux(Node abr)
{
    if(abr->gauche == NULL && abr->droit == NULL) return 0;

    if(abr->gauche != NULL && abr->droit == NULL) return -1 + isBalanced(abr->gauche);
    else if(abr->gauche == NULL && abr->droit != NULL) return 1 + isBalanced(abr->droit);
    else return isBalanced(abr->gauche) + isBalanced(abr->droit);

}
bool isBalanced(Node abr)
{
    if( isBalancedAux(abr) >1 || isBalancedAux(abr) < -1)
    return false;

    return true;
}
//hauteur d'un arbre
int getHeight(Node abr)
{
    if(abr->gauche == NULL && abr->droit == NULL) return 0;

    if(abr->gauche != NULL && abr->droit == NULL) return 1 + getHeight(abr->gauche);
    else if(abr->gauche == NULL && abr->droit != NULL) return 1 + getHeight(abr->droit);
    else if( getHeight(abr->gauche) > getHeight(abr->droit) ) return 1+getHeight(abr->gauche);
    else return 1+getHeight(abr->droit);
}
//calcule le total des hauteurs d'un arbre
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
    Node x = y->left;
    Node T2 = x->right;

    x->right = y;
    y->left = T2;

    return x;
}
Node rotateLeft(Node x)
{
    Node y = x->right;
    Node T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
}
Node rotateDoubleRight(Node y)
{
    Node y = x->gauche;
    Node z = y->droite;
    Node T2 = z->right;

    y->right = z->left;
    z->left = y;
    z->right = x;
    x->left = T2;

    return z;
}
Node rotateDoubleLeft(Node x)
{
    Node y = x->droite;
    Node z = y->gauche;
    Node T2 = z->gauche;

    y->left = z->right;
    z->left = x;
    z->right = y;
    x->right = T2;

    return z;
}
