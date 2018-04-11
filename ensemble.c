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
  if(st->suiv == NULL) {
    free(st);
  }
  else {
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
  else return 1 + getNumberElt(st->suiv);
}

int insertValue(Ens st, int e){
  // si on ne doit pas insérer l'élément
  // éléments strictement positifs
  // inclus une seule fois dans l'arbre
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

  // si e s'insère avant
  if(st->val > e){
     Ens ex = malloc(sizeof(struct el));
     ex->suiv = st->suiv;
     ex->val = st->val;
     st->val = e;
     st->suiv = ex;

     return 1;
   }
   // si on est au bout de l'ensemble
   else if(st->suiv == NULL) {
     Ens ex = malloc(sizeof(struct el));
     ex->suiv = st->suiv;
     ex->val = e;
     st->suiv = ex;

     return 1;
   }

   insertValue(st->suiv, e);
   return 1;
}

bool contains(Ens st, int e){

        if(st == NULL) return false;
        Ens sup = st;
        while(sup->suiv != NULL){
            if(sup->val == e){
                return true;
            }
            sup = sup->suiv;
        }
        return false;
}

void printOrderedSet(Ens st){

        if(st == NULL || st->val == -1) return ;
        Ens sup = st;
        while(sup->suiv != NULL){
            printf("%d, ", sup->val );
            sup = sup->suiv;
        }
        printf("%d\n", sup->val );
}

Ens intersect(Ens st, Ens st2){
  if(st == NULL || st2 == NULL) return NULL;
  else {
    while(st != NULL && st2 != NULL) {
      if(st->val == st2->val) {
        insertValue(res, sup->val);
      }
      else {
        intersect(st, st2->suiv);
      }
    }
  }

      /*  Ens sup = st; Ens sup2 = st2;
        Ens res = initOrderedSet();

        while(sup->suiv != NULL){
            do{

                if(sup->val == sup2->val){
                    insertValue(res, sup->val);
                    break;
                }
                sup2 = sup2->suiv;
            }while( sup2->suiv != NULL);

            sup2 = st2;
            sup = sup->suiv;
        }*/
        return res;
}


// int main(int argc, char const *argv[]) {
//
//     Ens exemple = initOrderedSet();
//     Ens exemple2 =initOrderedSet();
//     insertValue(exemple, 3);
//     insertValue(exemple, 2);
//     insertValue(exemple, 1);
//     insertValue(exemple2, 6);
//     insertValue(exemple2, 2);
//     insertValue(exemple2, 4);
//     //insertValue(exemple2, 1);
//
//     printOrderedSet(exemple);
//     printOrderedSet(exemple2);
//     printf("\n" );
//     Ens inter = intersect(exemple, exemple2);
//     printOrderedSet(inter);
//     printOrderedSet(exemple2);
//
//     return 0;
// }
