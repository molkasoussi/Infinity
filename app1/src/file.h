#include <gtk/gtk.h>
typedef struct 
{
 int jour;
 int mois;
 int annee;
}date;

typedef struct
{
     char nom[50];
     char prenom[50];
     char mail[50];
     char id[20];
     char mdp[50];
     date date_naissance; 
} client; 

void ajouter_client(client c);
void modifier_client(client c);
void supprimer_id(char idsp[]);
void rechercher_client( char Id[20],GtkWidget *liste);
void supprimer_tree(client c);
void afficher_clients(GtkWidget *liste);
int verif_client(char id[]);
