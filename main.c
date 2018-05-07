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
	/*printf("\n#######################################################\n");

	printf("TEXT 1 : mots.txt\n\n");
    Node t = createAuto("mots.txt");
    printf("\nUnbalanced tree : \n");
    printTabBinarySearchTree(t, 0);
    
    t = getBalancedTree(t);
    printf("\n\nAfter balancing : \n");
    printTabBinarySearchTree(t, 0);
    
    printf("\n\nAlphabetical order display : \n");
    printBinarySearchTree(t);
    freeBinarySearchTree(t);*/
    Node t = initBinarySearchTree();
    insert(t, "hello", 2);
    insert(t, "coucou", 5);
    insert(t, "coucou", 3);
    freeBinarySearchTree(t);
    return 0;
}
