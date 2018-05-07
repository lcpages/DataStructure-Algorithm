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
    Ens e3 = intersect(e, e2);
    printOrderedSet(e3);
    
    freeOrderedSet(e);
    freeOrderedSet(e2);
    freeOrderedSet(e3);
    
	printf("\n#######################################################\n");

	printf("TEST 2 : automatic tree balancing\n\n");
    Node t = createAuto("lorem_simple.txt");
    printf("\nUnbalanced tree : \n");
    printTabBinarySearchTree(t, 0);
    printf("The root has a difference of %d.\n", difference(t));

    t = getBalancedTree(t);
    printf("\n\nAfter balancing : \n");
    printTabBinarySearchTree(t, 0);
    printf("The root has a difference of %d.\n", difference(t));

    printf("\n\nAlphabetical order display : \n");
    printBinarySearchTree(t);
    freeBinarySearchTree(t);
    
    printf("\n#######################################################\n");

	printf("TEST 3 : tree height, values with a big tree\n\n");
    
    Node b = createAuto("lorem_long.txt");
    printf("The tree has a height of : %d.\n", getHeight(b));
    printf("The average depth for a node is : %lf.\n\n", getAverageDepth(b));
    printf("The tree has %d words/nodes.\n", getNumberString(b));
    printf("The tree has %d pairs word-sentence.\n\n", getTotalNumberString(b));
    
    printf("The words lorem and ipsum appear both on the line(s) :\n");
    Ens i = findCooccurrences(b, "lorem", "ipsum");
    printOrderedSet(i);
    
    freeOrderedSet(i);
    freeBinarySearchTree(b);
    return 0;
}
