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

        free(st);
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

  // si la valeur s'insère avant
  if(sup->val > e)
  {
    Ens ex = malloc(sizeof(struct el));
    ex->val = e;
    ex->suiv = sup;
    st = ex;
    free(sup);
    return 1;
  }
  else
  {
    // tant qu'on a pas atteint la fin de l'ensemble
    while(sup->suiv != NULL)
    {
      // on doit insérer avant le suivant
      if(sup->suiv->val > e)
      {
        Ens ex = malloc(sizeof(struct el));
        ex->val = e;
        ex->suiv = sup->suiv;
        sup->suiv = ex;
        return 1;
      }
      sup = sup->suiv;
    }
    // si on doit insérer au bout de l'ensemble
    sup->val = e;
    st->suiv = sup;
    return 1;
  }

  return 0;
    /*if(sup->val > e){
           Ens ex = malloc(sizeof(struct el));
           ex->suiv = sup->suiv;
           ex->val = sup->val;
           sup->val = e;
           sup->suiv =ex;

           return 1;
       }


        while(sup->suiv != NULL) {
            if(sup->suiv->val >e){
                Ens ex = malloc(sizeof(struct el));
                ex->suiv = sup->suiv;
                ex->val = e;
                sup->suiv =ex;

                return 1;
            }
            sup = sup->suiv;
        }
    //    sup2->suiv->val = e;
        // while(sup->suiv->val < e && sup->suiv != NULL)  sup = sup->suiv;
        // if(sup->suiv == NULL){
        //     sup->suiv = initOrderedSet();
        //     sup->suiv->val = e;
        // }else{
        // Ens ex = malloc(sizeof(struct el));
        // ex->suiv = sup->suiv;
        // ex->val = e;
        // sup->suiv =ex;
        // }
        // sup->suiv = initOrderedSet();
        //sup->suiv->val = e;

        return 1;*/
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

        if(st == NULL) return ;
        Ens sup = st;
        while(sup->suiv != NULL){
            printf("%d\n", sup->val );
            sup = sup->suiv;
        }
        printf("%d\n", sup->val );
}
Ens intersect(Ens st, Ens st2){

        if(st == NULL || st2 == NULL) return NULL;
        Ens sup = st; Ens sup2 = st2;
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
        }
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
