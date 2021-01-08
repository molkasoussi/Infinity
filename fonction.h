
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>


typedef struct
{
    char jour[30];
    char mois[30];
    char annee[30];
}date;

typedef struct 
{
char identifiant[30];
char poids[30];
char type[30];
char genre[30];
char etat[30];
date naissance;
} troupeaux;

void ajouter (troupeaux t );
void supprimer (char identifiant[]);
void modifer(char ch[] ,troupeaux t2);
int count(char type[]);
int chercher(char ty[],troupeaux *p);
int chercher_id(char ty[],troupeaux *p);


//int exister (char*identifiant);
