/*
* fichier ensemble.c
* Projet SDA2 printemps 2018
* Chloé RICHE et Louis-César Pagès
*/

#include "ensemble.h"

Ens initOrderedSet(){

        Ens st = malloc(sizeof(struct el));
        st->suiv = NULL;
        st->val = -1;
        return st;
}

void freeOrderedSet(Ens st){

    if(st == NULL) // si l'ensemble est nul
    {
        return;
    }
    else
    {   //on libère l'espace des éléments chainés.
        freeOrderedSet(st->suiv);
        free(st);
    }

}

int getNumberElt(Ens st){
  // si l'ensemble n'existe pas ou est vide
  if(st == NULL || st->val == -1)
  {
    return 0;
  }
  else if(st->suiv == NULL) return 1;
  return 1 + getNumberElt(st->suiv);
}

int insertValue(Ens st, int e){
  // si on ne doit pas insérer l'élément
  if(e < 0 || contains(st,e))
  {
    return 0;
  }
  // si l'ensemble est vide
  else if(st->val == -1)
  {
    st->val = e;
    return 1;
  }

  Ens sup = st;

    //si la valeur s'insère avant
    if(sup->val > e){
           Ens ex = malloc(sizeof(struct el));
           ex->suiv = sup->suiv;
           ex->val = sup->val;
           sup->val = e;
           sup->suiv =ex;
           return 1;
       }
       // tant qu'on a pas atteint la fin de l'ensemble
        while(sup->suiv != NULL)
        {
            // on doit insérer avant le suivant
            if(sup->suiv->val >e){
                Ens ex = malloc(sizeof(struct el));
                ex->suiv = sup->suiv;
                ex->val = e;
                sup->suiv =ex;

                return 1;
            }
            sup = sup->suiv;
        }
        sup->suiv = initOrderedSet();
        sup->suiv->val = e;
        return 1;
}

bool contains(Ens st, int e){

        if(st == NULL) return false;
        if(st->val == e ) return true; //vérifie la 1er valeur
        Ens sup = st;
        while(sup->suiv != NULL){ //vérifie les valeurs intermédiaires
            if(sup->val == e){
                return true;
            }
            sup = sup->suiv;
        }
        if(sup->val == e){ //vérifie la dernière valeur
            return true;
        }
        return false;
}
void printOrderedSet(Ens st){

        if(st == NULL) return ;
        Ens sup = st;
        while(sup->suiv != NULL){
            printf("%d ", sup->val );
            sup = sup->suiv;
        }
        printf("%d\n", sup->val );
}
Ens intersect(Ens st, Ens st2){

        if(st == NULL || st2 == NULL) return NULL;
        Ens sup = st; Ens sup2 = st2; //pointeurs de support
        Ens res = initOrderedSet();

        do{ //on se déplace dans le premier ensemble
            do{ //on se déplace dans le deuxième ensemble
                if(sup->val == sup2->val){
                    insertValue(res, sup->val);
                    break;
                }
                if(sup2->suiv == NULL ) break; //si taille de ensemble2 == 1
                sup2 = sup2->suiv;

            }while( sup2->suiv != NULL);

            if(sup->suiv == NULL ) break; //si taille de ensemble == 1
            sup2 = st2;
            sup = sup->suiv;

        }while(sup->suiv != NULL);
        return res;
}
