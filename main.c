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

	printf("TEXT 1 : phrases.txt\n\n");
    Node t = createAuto("phrases.txt");
    printf("\nUnbalanced tree : \n");
    printTabBinarySearchTree(t, 0);
    
    t = getBalancedTree(t);
    printf("\n\nAfter balancing : \n");
    printTabBinarySearchTree(t, 0);
    
    printf("\n\nAlphabetical order display : \n");
    printBinarySearchTree(t);
    freeBinarySearchTree(t);*/
    
    Node t = createAuto("phrases.txt");
    freeBinarySearchTree(t);

    return 0;
}
