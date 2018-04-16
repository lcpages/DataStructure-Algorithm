/*
* fichier main.c
* Projet SDA2 printemps 2018
* Chloé RICHE et Louis-César Pagès
*/

#include "ensemble.h"
#include "arbre_bin.h"

int main(int argc, char const *argv[])
{

    // Ens exemple = initOrderedSet();
    // //Ens exemple2 =initOrderedSet();
    // insertValue(exemple, 1);
    // insertValue(exemple, 2);
    // insertValue(exemple, 3);
    // // insertValue(exemple2, 1);
    // //
    // // printf("Nombre éléments dans exemple : %d\n", getNumberElt(exemple));
    // // printf("Nombre éléments dans exemple2 : %d\n",getNumberElt(exemple2));
    // // //insertValue(exemple2, 1);
    // //
    //     printOrderedSet(exemple);
    // printOrderedSet(exemple2);
    // printf("\n" );
    // Ens inter = intersect(exemple2, exemple);
    // printOrderedSet(inter);
    // printOrderedSet(exemple2);

    Node t1 = initBinarySearchTree();
    insert(t1,"toto", 2);
    //printBinarySearchTree(t1);
    insert(t1,"toto", 4);
    insert(t1,"velo", 2);
    insert(t1,"velo", 3);

    insert(t1, "tata", 3);
    insert(t1, "tata", 2);
    printBinarySearchTree(t1);
    freeBinarySearchTree(t1);

    return 0;
}
