/*
* fichier ensemble.c
* Projet SDA2 printemps 2018
* Chloé RICHE et Louis-César Pagès
*/


#include "ensemble.h"

Ens initOrderedSet(){

        Ens st = malloc(sizeof(struct ensemble));
        st->suiv = NULL;

        return st;
}

void freeOtderedSet(Ens * st){

        free(st->suiv);
        free(st);
}

int getNumberElt(Ens st){

        return length(st->suiv);
}

int insertValue(Ens St, int e){

        if(contains(st,e)){
                return 0;
        }
        st->suiv = realloc(st, (length(st->suiv)+1) * sizeof(int));
        st->suiv[length(st->suiv)] = e;

        return 1;
}
bool contains(Ens st, int e){

        for(int i=0; i<length(st->suiv); i++){
                if(st->suiv[i] == e){
                        return true;
                }
        }
        return false;
}
void printOrderedSet(Ens st){

        for(int i=0; i<length(st->suiv); i++){
                printf("%d ",st->suiv[i]);
        }
}
int * intersect(Ens st, Ens st2){

        int * tab = malloc(sizeof(int));
        unsigned int count = 0;

        for(int i=0; i<length(st2); i++){
                for(int j=0; j<length(st); j++){
                        if(st->suiv[j] == st->suiv[i])
                        {
                                tab = realloc(++count *sizeof(int));
                                tab[count] = st->suiv[j];
                                break;
                        }
                }
        }
        return tab;
}
