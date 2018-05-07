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
    printf("\n#######################################################\n");

	printf("TEST 1 : ordered set\n\n");
    Ens e = initOrderedSet();
    insertValue(e, 1);
    insertValue(e, 10);
    insertValue(e, 5);
    insertValue(e, 1678554);
    printf("The ordered set :\n");
    printOrderedSet(e);

    if(contains(e, 10)) printf("The ordered set contains the value 10.\n");
    printf("It contains %d elements.\n", getNumberElt(e));
    
    Ens e2 = initOrderedSet();
    insertValue(e2, 12);
    insertValue(e2, 105);
    insertValue(e2, 5);
    insertValue(e2, 164);
    
    printf("\nThe second ordered set :\n");
    printOrderedSet(e2);
    
    printf("\nThe intersection of the two sets is :\n");
    printOrderedSet(intersect(e, e2));
    
    freeOrderedSet(e);
    freeOrderedSet(e2);
    
	printf("\n#######################################################\n");

	printf("TEST 2 : automatic tree balancing\n\n");
    Node t = createAuto("phrases.txt");
    printf("\nUnbalanced tree : \n");
    printTabBinarySearchTree(t, 0);
    
    t = getBalancedTree(t);
    printf("\n\nAfter balancing : \n");
    printTabBinarySearchTree(t, 0);
    
    printf("\n\nAlphabetical order display : \n");
    printBinarySearchTree(t);
    
    printf("\n#######################################################\n");

	printf("TEST 3 : tree height, values and \n\n");
    
    
    freeBinarySearchTree(t);
    return 0;
}
