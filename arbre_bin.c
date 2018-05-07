/*
* fichier arbre_bin.c
* Projet SDA2 printemps 2018
* Chloé RICHE et Louis-César Pagès
*/

#include "arbre_bin.h"
#include "arbre_equi.h"

Node initBinarySearchTree()
{
  Node abr = (Node)malloc(sizeof(struct noeud));
  // if(abr == NULL)
  // {
  //   return NULL;
  // }

  // on initialise tous les attributs à NULL
  abr->mot = NULL;
  abr->pos = NULL;
  abr->gauche = NULL;
  abr->droit = NULL;

  return abr;
}

void freeBinarySearchTree(Node abr)
{
  if(abr == NULL)
  {
    return;
  }
  else
  {
    // on libère les branches inférieures
    freeBinarySearchTree(abr->gauche);
    freeBinarySearchTree(abr->droit);
    // puis on libère les attributs du noeud
		free(abr->mot);
    freeOrderedSet(abr->pos);
    free(abr);
  }
}

int getNumberString(Node abr)
{
  if(abr == NULL)
  {
    return 0;
  }
  else
  {
    // on compte un élément par noeud
    return 1 + getNumberString(abr->gauche) + getNumberString(abr->droit);
  }
}

int getTotalNumberString(Node abr)
{
  if(abr == NULL)
  {
    return 0;
  }
  else
  {
    // on additionne le nombre d'occurrences de tous les noeuds
    return getNumberElt(abr->pos) + getTotalNumberString(abr->gauche) + getTotalNumberString(abr->droit);
  }
}

Node insert(Node abr, char* nouv_mot, int size, int nouv_pos)
{
  // si l'arbre est vide : insertion à la racine
  if(abr == NULL)
  {
    abr = initBinarySearchTree();
    abr->mot = malloc(size);
		strcpy(abr->mot, nouv_mot);
    abr->pos = initOrderedSet();
    insertValue(abr->pos, nouv_pos);
  }
  else if(abr->mot == NULL)
  {
		abr->mot = malloc(size);
		strcpy(abr->mot, nouv_mot);
		abr->pos = initOrderedSet();
		insertValue(abr->pos, nouv_pos);
  }
  // sinon si le mot à la racine est le même
  else if(strcmp(nouv_mot, abr->mot) == 0)
  {
     insertValue(abr->pos, nouv_pos);
  }
  // sinon recherche dans les branches inférieures
  else if(strcmp(nouv_mot, abr->mot) < 0)
  {
    abr->gauche = insert(abr->gauche, nouv_mot, size, nouv_pos);
  }
  else
  {
    abr->droit = insert(abr->droit, nouv_mot, size, nouv_pos);
  }

  return abr;
}

Ens find(Node abr, char* mot)
{
  // si l'arbre est vide
  if(abr == NULL)
  {
    return NULL;
  }

  // sinon si le mot à la racine est le même
  else if(strcmp(abr->mot, mot) == 0)
  {
    return abr->pos;
  }

  // sinon recherche dans les branches inférieures
  else if(strcmp(abr->mot, mot) > 0)
  {
    return(find(abr->gauche, mot));
  }
  else
  {
    return(find(abr->droit, mot));
  }
}

Ens findCooccurrences(Node abr, char* mot1, char* mot2)
{
  // si les deux mots sont contenus dans l'ABR
  if((find(abr, mot1) != NULL) && (find(abr, mot2) != NULL))
  {
    return intersect(find(abr, mot1), find(abr, mot2));
  }
  else
  {
    return NULL;
  }
}

void printBinarySearchTree(Node abr)
{
  // on commence tout en bas à gauche
  if(abr->gauche != NULL)
  {
    printBinarySearchTree(abr->gauche);
  }

  if(abr != NULL)
  {
    printf("%s\n", abr->mot);
    printOrderedSet(abr->pos);
  }

  // on finit tout en bas à droite
  if(abr->droit != NULL)
  {
    printBinarySearchTree(abr->droit);
  }
}

void printTabBinarySearchTree (Node abr, int nodeHeight)
{
	int i, nodeHgt = nodeHeight;
	if(abr != NULL)
	{
		for(i = 0; i < nodeHgt; i++)
			printf("  ");
		printf("%s\n", abr->mot);
		for(i = 0; i < nodeHgt; i++)
			printf("  ");
		printOrderedSet(abr->pos);
	}
	  if(abr->gauche != NULL)
  {
    printTabBinarySearchTree(abr->gauche, nodeHgt + 1);
  }
    if(abr->droit != NULL)
  {
    printTabBinarySearchTree(abr->droit, nodeHgt + 1);
  }
}

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
        if((buffer[0] == ' ') || buffer[0] == '\'' || (buffer[0] == '\n'))
        {
					if(nb_char > 0)
					{
						// on retourne juste avant le mot
						lseek(fd, -1 - nb_char, SEEK_CUR);
						char* str = malloc(nb_char +1);
						
						if(str == NULL)
						{
							perror("malloc");
							exit(EXIT_FAILURE);
						}
						if(read(fd, str, nb_char) == -1)
						{
								perror("read");
								exit(EXIT_FAILURE);
						}
						// end of the word
						if((str[nb_char-1] == '.') || (str[nb_char-1] == ','))
						{
							str[nb_char-1] = '\0';
						}
						str[nb_char] = '\0';
						
						// maj to min
						if(str[0] <= 90)
						{
							str[0] += 'a' - 'A';
						}
						// insertion du mot et du numéro de ligne
						insert(abr, str, nb_char + 1, nb_line);
						free(str);
						lseek(fd, 1, SEEK_CUR);
						
						// si on a sauté une ligne
						if(buffer[0] == '\n')
						{
							nb_line++;
						}
						nb_char = 0;
					}
        }
        else
        {
            nb_char++;
        }
     }
		 
		 if(nb_char > 0)
		 					{
						// on retourne juste avant le mot
						lseek(fd, - nb_char, SEEK_CUR);
						printf("NBCHARRRRRR %d\n", nb_char);
						char* str = malloc(nb_char + 1);
						
						if(str == NULL)
						{
							perror("malloc");
							exit(EXIT_FAILURE);
						}
						if(read(fd, str, nb_char) == -1)
						{
								perror("read");
								exit(EXIT_FAILURE);
						}
						// end of the word
						if((str[nb_char-1] == '.') || (str[nb_char-1] == ','))
						{
							str[nb_char-1] = '\0';
						}
						str[nb_char] = '\0';
						
						// maj to min
						if(str[0] <= 90)
						{
							str[0] += 'a' - 'A';
						}
						// insertion du mot et du numéro de ligne
						insert(abr, str, nb_char + 1, nb_line);
						free(str);
						lseek(fd, 1, SEEK_CUR);
						
						// si on a sauté une ligne
						if(buffer[0] == '\n')
						{
							nb_line++;
						}
						nb_char = 0;
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
