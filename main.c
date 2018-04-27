/*
* fichier main.c
* Projet SDA2 printemps 2018
* Chloé RICHE et Louis-César Pagès
*/

#include "ensemble.h"
#include "arbre_bin.h"

int main(int argc, char const *argv[])
{
    Node t = createAuto("phrases.txt");
    printf("%s\n", t->mot);
    printOrderedSet(t->pos);
    //printBinarySearchTree(t);
    freeBinarySearchTree(t);

    return 0;
}
