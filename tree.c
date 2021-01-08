
#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fonction.h"
#include "tree.h"


void afficher(GtkWidget* treeview1,char *l)
{
enum
{
idtf_t, 
poid_t,
type_t,
sexe_t,
sante_t,
jour_t,
mois_t,
annee_t,
columns
};

GtkCellRenderer *renderer;
GtkTreeViewColumn * column;
GtkTreeIter iter;
GtkListStore *store;

char identifiant[20];
char poids[20];
char type[20];
char genre[20];
char etat[20];
char jour[20];
char mois[20];
char annee[20];
FILE *f;
troupeaux t;
f=fopen("troupeaux.txt","a+");

store=NULL;
store=gtk_tree_view_get_model(treeview1);
if (store == NULL)
{

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",idtf_t,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("poids",renderer,"text",poid_t,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

                renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",type_t,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("genre",renderer,"text",sexe_t,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

                renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("etat",renderer,"text",sante_t,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",jour_t,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);
                 
                renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",mois_t,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",annee_t,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);






	store=gtk_list_store_new(columns,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("troupeaux.txt","r");

if (f == NULL ) {return;}
else
{
 while((fscanf(f,"%s %s %s %s %s %s %s %s\n",t.identifiant,t.poids,t.type,t.genre,t.etat,t.naissance.jour,t.naissance.mois,t.naissance.annee)!=EOF))
         {
         strcpy(identifiant,t.identifiant);
         strcpy(poids,t.poids);
         strcpy(type,t.type);
         strcpy(genre,t.genre);
         strcpy(etat,t.etat);
         strcpy(jour,t.naissance.jour);
         strcpy(mois,t.naissance.mois);
         strcpy(annee,t.naissance.annee);
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,idtf_t,identifiant,poid_t,poids,type_t,type,sexe_t,genre,sante_t,etat,jour_t,jour,mois_t,mois,annee_t,annee,-1);


}
fclose(f);
}
	gtk_tree_view_set_model(GTK_TREE_VIEW(treeview1),GTK_TREE_MODEL(store));
	g_object_unref(store);

}
}

//////////////////////////
void chercher1(GtkWidget *treeview1,char ty[20])
{

enum
{
idtf_t, 
poid_t,
type_t,
sexe_t,
sante_t,
jour_t,
mois_t,
annee_t,
columns
};

GtkCellRenderer *renderer;
GtkTreeViewColumn * column;
GtkTreeIter iter;
GtkListStore *store;

char identifiant[20];
char poids[20];
char type[20];
char genre[20];
char etat[20];
char jour[20];
char mois[20];
char annee[20];
FILE *f;
troupeaux t;

f=fopen("troupeaux.txt","r");

store=NULL;
store=gtk_tree_view_get_model(treeview1);
    
if (store == NULL)
{      
       
  

        

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",idtf_t,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("poids",renderer,"text",poid_t,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

                renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",type_t,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("genre",renderer,"text",sexe_t,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

                renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("etat",renderer,"text",sante_t,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",jour_t,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);
                 
                renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",mois_t,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",annee_t,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

store=gtk_list_store_new(columns,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("troupeaux.txt","r");

if (f == NULL ) {return;}
else
{
 while(fscanf(f,"%s %s %s %s %s %s %s %s\n",t.identifiant,t.poids,t.type,t.genre,t.etat,t.naissance.jour,t.naissance.mois,t.naissance.annee)!=EOF)   
         {
if(strcmp(t.type,ty)==0)
{    
	
	strcpy(identifiant,t.identifiant);
         strcpy(poids,t.poids);
         strcpy(type,t.type);
         strcpy(genre,t.genre);
         strcpy(etat,t.etat);
         strcpy(jour,t.naissance.jour);
         strcpy(mois,t.naissance.mois);
         strcpy(annee,t.naissance.annee);
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,idtf_t,identifiant,poid_t,poids,type_t,type,sexe_t,genre,sante_t,etat,jour_t,jour,mois_t,mois,annee_t,annee,-1);
	
}
}
fclose(f);
}
gtk_tree_view_set_model(GTK_TREE_VIEW(treeview1),GTK_TREE_MODEL(store));
	g_object_unref(store);
}

}
