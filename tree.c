
#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fonction.h"

void afficher(GtkWidget* treeview1,char *l)
{


enum
{
id_t,
esp_t,
mature_t,
typ_t,
jour_t,
mois_t,
annee_t,
columns
};


GtkCellRenderer *renderer;
GtkTreeViewColumn * column;
GtkTreeIter iter;
GtkListStore *store;

char typ[20];    
char id[20];
char mature[20];
char esp[20];

char jour[20];
char mois[20];
char annee[20];
FILE *f;
plante t;
f=fopen("plantes.txt","a+");

store=NULL;
store=gtk_tree_view_get_model(treeview1);
if (store == NULL)
{

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("type d'une plante",renderer,"text",typ_t,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("durée de maturation",renderer,"text",mature_t,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

                renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("espacement",renderer,"text",esp_t,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("identifiant de la plante",renderer,"text",id_t,NULL);
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






	store=gtk_list_store_new(columns,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("plantes.txt","r");

if (f == NULL ) {return;}
else
{
 while((fscanf(f,"%s %s %s %s %s %s %s \n"
,t.typ,t.mature,t.esp,t.id,t.plantation.jour,t.plantation.mois,t.plantation.annee))!=EOF)
         {
         
         
        
	strcpy(typ,t.typ);
	strcpy(mature,t.mature);
	strcpy(esp,t.esp);
	strcpy(id,t.id);
	strcpy(jour,t.plantation.jour);
	strcpy(mois,t.plantation.mois);
	strcpy(annee,t.plantation.annee);

	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,typ_t,typ,mature_t,mature,esp_t,esp,id_t,id,jour_t,jour,mois_t,mois,annee_t,annee,-1);






}

}
fclose(f);	gtk_tree_view_set_model(GTK_TREE_VIEW(treeview1),GTK_TREE_MODEL(store));
	g_object_unref(store);

}
}



