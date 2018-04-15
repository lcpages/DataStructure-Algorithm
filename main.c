/*
* fichier main.c
* Projet SDA2 printemps 2018
* Chloé RICHE et Louis-César Pagès
*/

#include "ensemble.h"
#include "arbre_bin.h"

// int main()
// {
//   Ens a = initOrderedSet();
//   int nb_el = getNumberElt(a);
//   printf("Au départ, %d éléments dans a.\n", nb_el);
//
//
//   insertValue(a, 10);
//   insertValue(a, 11);
//   printOrderedSet(a);
//   //insertValue(a, -1);
//   //insertValue(a, 178);
//   nb_el = getNumberElt(a);
//   printf("Après, %d éléments dans a.\n", nb_el);
//   return 0;
// }

int main(int argc, char const *argv[]) {

    Ens exemple = initOrderedSet();
    Ens exemple2 =initOrderedSet();
    insertValue(exemple, 3);
    insertValue(exemple, 2);
    insertValue(exemple, 1);
    insertValue(exemple2, 1);

    printf("Nombre éléments dans exemple : %d\n", getNumberElt(exemple));
    printf("Nombre éléments dans exemple2 : %d\n",getNumberElt(exemple2));
    //insertValue(exemple2, 1);

    printOrderedSet(exemple);
    printOrderedSet(exemple2);
    printf("\n" );
    Ens inter = intersect(exemple2, exemple);
    printOrderedSet(inter);
    printOrderedSet(exemple2);

    return 0;
}
