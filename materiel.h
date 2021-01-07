#include <gtk/gtk.h>


typedef struct heure {
int j;
int mo;
int a;
} heure;
typedef struct materiel{
char nom[10];
char ref[10] ; //reference
heure date;
char fourniseur [10];
char annee [10];
char etat[10];
char type [10]; 
} materiel ;

void ajouter (materiel m,heure date ); // nom, reference, type, date, annee de garentie.
void modifier (materiel m); // reference, nom, type, etat.
void consulter (GtkWidget *liste);
void suprimer (materiel m ); // reference.
void recherche (char id[20],GtkWidget *liste);



