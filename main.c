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
    Node t = createAuto("phrases.txt");
    //printOrderedSet(t->pos);
    printBinarySearchTree(t);
    //getBalancedTree(t);
    printf("\n" );
//    printf("%s  %s\n",t->gauche->gauche->droit->mot, t->gauche->gauche->mot  );
    printf("%s  %s\n",t->gauche->gauche->gauche->gauche->gauche->droit->mot, t->gauche->gauche->gauche->mot  );
    printf("\n %d ",difference(t) );
    printf("%d\n",difference(t->gauche->gauche->gauche) );
    t = getBalancedTree(t);
    //t = rotateRight(t);
    // printf("%d\n",difference(t->gauche->gauche->gauche) );
    // printf("%s  %s\n",t->gauche->gauche->gauche->mot, t->gauche->droit->mot  );
    printBinarySearchTree(t);
    printf("\n %d \n",difference(t) );

    // printBinarySearchTree(t);
    freeBinarySearchTree(t);

    // char * mot1 = "i";
    // char * mot2 = "i";
    // char * mot3 = "i";
    // Node t1 = initBinarySearchTree();
    // insert(t1, mot1, 1);
    // insert(t1, mot2, 1);
    // insert(t1, mot3, 1);
    // t1 = getBalancedTree(t1);
    // //insert(t1, "b", 1);
    // t1 = getBalancedTree(t1);
    // printBinarySearchTree(t1);
    // //printf("%d\n",insertValue(t1->pos, 1 ) );
    //
    // // printf("\n%d\n", isBalanced(t1));
    //
    // freeBinarySearchTree(t1);
    return 0;
}
