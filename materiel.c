#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "materiel.h"
#include <gtk/gtk.h>

enum {
NOM,
REF,
TYPE,
ANNEE, 
FOURNISEUR,
DATE,
COLUMNS
};


//affichage 
consulter (GtkWidget *liste){
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char nom[10];
char reference[10] ; //reference
char type [50];
char  date [50];
char fourniseur [10]; //fournisseur 
char annee_garentie[10]; //annee 
int jour;
int mois;
int an; //date
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL){



renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("reference",renderer,"text",REF,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("annee_garentie",renderer,"text",ANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("fourniseur",renderer,"text",FOURNISEUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  date", renderer, "text",DATE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
//

f=fopen ("materiel.txt","r");
if (f==NULL){return;}
else {
f=fopen("materiel.txt","a+");
while (fscanf (f," %s %s %s %s %d %d %d %s",nom,reference,annee_garentie,fourniseur,&jour,&mois,&an,type)!=EOF)
{ 
sprintf(date,"%d/%d/%d",jour,mois,an);	
gtk_list_store_append(store, &iter);
gtk_list_store_set (store, &iter, NOM, nom, REF, reference, ANNEE, annee_garentie, FOURNISEUR, fourniseur,DATE,date,TYPE, type, -1);  }

fclose (f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);  
 }}}


//// recherche

recherche(char id[20],GtkWidget *liste)
{
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
 	GtkWidget *window6_liste;
	GtkListStore *store;

materiel m;
char nom[10];
char reference[10] ; //reference
char type [50];
char  date [50];
char fourniseur [10]; 
char annee_garentie[10]; //annee 
int jour;
int mois;
int an; //date

store=NULL;
FILE *f;
//GtkTreeView *liste;
 store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("reference",renderer,"text",REF,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("annee_garentie",renderer,"text",ANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("fourniseur",renderer,"text",FOURNISEUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  date", renderer, "text",DATE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
//

f=fopen ("materiel.txt","r");
if (f==NULL){return;}
else {
while (fscanf (f," %s %s %s %s %d %d %d %s",nom,reference,annee_garentie,fourniseur,&jour,&mois,&an,type)!=EOF)
{ 
sprintf(date,"%d/%d/%d",jour,mois,an);	

        if((strcmp(id,m.ref)==0))
gtk_list_store_append(store, &iter);
gtk_list_store_set (store, &iter, NOM, nom, REF, reference, ANNEE, annee_garentie, FOURNISEUR, fourniseur,DATE,date,TYPE, type, -1);  }	
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);

}}









