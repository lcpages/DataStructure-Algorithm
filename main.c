/*
* fichier main.c
* Projet SDA2 printemps 2018
* Chloé RICHE et Louis-César Pagès
*/

#include "ensemble.h"
#include "arbre_bin.h"
#include "arbre_equi.h"

Node createAuto(char* chemin)
{
  int fd, nb_char = 0, nb_line = 1;
  char c, buffer[1];

  // ouverture du fichier
  if((fd = open(chemin, O_RDONLY)) == -1)
  {
    perror("open");
    exit(EXIT_FAILURE);
  }

  // initialisation de l'ABR
  Node abr = initBinarySearchTree();

  // tant qu'il reste des caractères à lire dans le fichier
  while((c = read(fd, buffer, 1)) > 0)
  {
    // si on a finit le mot ou la ligne précédent(e)
    if((buffer[0] == ' ') || (buffer[0] == '\n'))
    {
      // au cas où on a plusieurs espaces/retours chariot
      if(nb_char > 0)
      {
        // on retourne juste avant le mot
        lseek(fd, -1 - nb_char, SEEK_CUR);
        char* str = malloc(nb_char);

        if(read(fd, str, nb_char) == -1)
        {
          perror("read");
          exit(EXIT_FAILURE);
        }

        // insertion du mot et du numéro de ligne
        abr = insert(abr, str, nb_line);
        free(str);

        // on se replace 1 caractère après le mot (comme avant)
        lseek(fd, 1, SEEK_CUR);
        nb_char = 0;
      }

      // si on a sauté une ligne
      if(buffer[0] == '\n')
      {
        nb_line++;
      }
    }

    else
    {
      nb_char++;
    }
  }

  // fermeture du fichier
  if(close(fd) == -1)
  {
    perror("close");
    exit(EXIT_FAILURE);
  }

  // on renvoie l'ABR complété
  return abr;
}

int main(int argc, char const *argv[])
{
    /*Node t = createAuto("phrases.txt");
    printf("%s\n", t->mot);
    printOrderedSet(t->pos);
    //printBinarySearchTree(t);
    freeBinarySearchTree(t);*/


    Node t1 = initBinarySearchTree();
    insert(t1, "m", 1);
    insert(t1, "c", 1);
    insert(t1, "a", 1);
    t1 = getBalancedTree(t1);
    insert(t1, "b", 1);
    t1 = getBalancedTree(t1);
    printBinarySearchTree(t1);

    printf("\n%d\n", isBalanced(t1));

    freeBinarySearchTree(t1);
    return 0;
}
