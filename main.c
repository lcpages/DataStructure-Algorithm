/*
* fichier main.c
* Projet SDA2 printemps 2018
* Chloé RICHE et Louis-César Pagès
*/

#include "ensemble.h"
#include "arbre_bin.h"
#include "arbre_equi.h"

int main(int argc, char const *argv[])
{

    Node t1 = initBinarySearchTree();
    insert(t1,"foo", 1);
    //printBinarySearchTree(t1);
    insert(t1,"foo", 2);
    insert(t1,"foo", 3);

    insert(t1,"baz", 2);
    insert(t1,"bar", 1);
    insert(t1, "corge", 2);
    insert(t1, "corge", 3);

    insert(t1, "qux", 2);
    insert(t1, "grault", 1);
    insert(t1, "grault", 3);
    insert(t1, "waldo", 3);
    printBinarySearchTree(t1);


    //printf("\n %d \n", isBalanced(t1) );
    printf("\n%f \n", getAverageDepth(t1) );

    freeBinarySearchTree(t1);
    return 0;
}
