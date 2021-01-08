#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "capteur.h"
#include "tree.h"
void afficher_capteur(GtkWidget *treeview1)
{
enum
{
idtf_c, 
etat_c,
type_c,
emplacement_c,
jour_c,
mois_c,
annee_c,
marque_c,
columns
};

GtkCellRenderer *renderer;
GtkTreeViewColumn * column;
GtkTreeIter iter;
GtkListStore *store;

char idtf[20];
char etat[20];
char type[20];
char emplacement[20];
char jour[20];
char mois[20];
char annee[20];
char marque[20];
FILE *f=NULL;
capteur t;
f=fopen("capteur.txt","r");

store=NULL;
store=gtk_tree_view_get_model(treeview1);
if (store == NULL)
{

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("idtf",renderer,"text",idtf_c,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("etat",renderer,"text",etat_c,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

                renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",type_c,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("emplacement",renderer,"text",emplacement_c,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

                
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",jour_c,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);
                 
                renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",mois_c,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",annee_c,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("marque",renderer,"text",marque_c,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);





	store=gtk_list_store_new(columns,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("capteur.txt","r");

if (f == NULL ) {return;}
else
{
 while(fscanf(f,"%d %d %d %s %d %d %d %d\n",&t.idtf,&t.type,&t.etat,t.emplacement,&t.date_ajou.jour,&t.date_ajou.mois,&t.date_ajou.annee,&t.marque)!=EOF)
         {
           if(t.etat==1)
            strcpy(etat,"nouveau");
    else
     strcpy(etat,"ancien");
    if(t.type==1)
    strcpy(type,"temperature");
    else
    strcpy(type,"humdite");

    if(t.marque==1)
    strcpy(marque,"LINDY");
    else
    strcpy(marque,"OMEGA");
    
    strcpy(emplacement,t.emplacement);
     sprintf(idtf,"%d",t.idtf);
    sprintf(jour,"%d",t.date_ajou.jour);
     sprintf(mois,"%d",t.date_ajou.mois);
 sprintf(annee,"%d",t.date_ajou.annee);
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,idtf_c,idtf,etat_c,etat,type_c,type,emplacement_c,emplacement,jour_c,jour,mois_c,mois,annee_c,annee,marque_c,marque,-1);


}
fclose(f);
}
	gtk_tree_view_set_model(GTK_TREE_VIEW(treeview1),GTK_TREE_MODEL(store));
	g_object_unref(store);


}

}
///////////////////////////////////////////////////

void rechercher_capteur(GtkWidget *treeview1 ,int d)
{
enum
{
idtf_c, 
etat_c,
type_c,
emplacement_c,
jour_c,
mois_c,
annee_c,
marque_c,
columns
};

GtkCellRenderer *renderer;
GtkTreeViewColumn * column;
GtkTreeIter iter;
GtkListStore *store;

char idtf[20];
char etat[20];
char type[20];
char emplacement[20];
char jour[20];
char mois[20];
char annee[20];
char marque[20];
FILE *f=NULL;
capteur t;
f=fopen("capteur.txt","a+");

store=NULL;
store=gtk_tree_view_get_model(treeview1);
if (store == NULL)
{

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("idtf",renderer,"text",idtf_c,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("etat",renderer,"text",etat_c,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

                renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",type_c,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("emplacement",renderer,"text",emplacement_c,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

                
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",jour_c,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);
                 
                renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",mois_c,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",annee_c,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);
		
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("marque",renderer,"text",marque_c,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);






	store=gtk_list_store_new(columns,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("capteur.txt","r");

if (f == NULL ) {return;}
else
{
 while(fscanf(f,"%d %d %d %s %d %d %d %d\n",&t.idtf,&t.type,&t.etat,t.emplacement,&t.date_ajou.jour,&t.date_ajou.mois,&t.date_ajou.annee,&t.marque)!=EOF)
         {
	if (t.idtf==d) {
           if(t.etat==1)
            strcpy(etat,"nouveau");
    else
     strcpy(etat,"ancien");
    if(t.type==1)
    strcpy(type,"temperature");
    else
    strcpy(type,"humdite");
    
    if(t.marque==1)
    strcpy(marque,"OMEGA");
    else
    strcpy(marque,"LINDY");
    strcpy(emplacement,t.emplacement);
     sprintf(idtf,"%d",t.idtf);
    sprintf(jour,"%d",t.date_ajou.jour);
     sprintf(mois,"%d",t.date_ajou.mois);
 sprintf(annee,"%d",t.date_ajou.annee);
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,idtf_c,idtf,etat_c,etat,type_c,type,emplacement_c,emplacement,jour_c,jour,mois_c,mois,annee_c,annee,marque_c,marque,-1);

}
}
fclose(f);
}
	gtk_tree_view_set_model(GTK_TREE_VIEW(treeview1),GTK_TREE_MODEL(store));
	g_object_unref(store);


}





}

