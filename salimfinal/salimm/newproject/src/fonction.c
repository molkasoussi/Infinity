#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "callbacks.h"
#include "fonction.h"
#include<string.h>
#include <gtk/gtk.h>

void ajouter_plante(plante p)
{
FILE*f=NULL; //flot de donnée
f=fopen("plantes.txt","a");// creation du fichier equipement .txt et ouverture en  mode lecture et ecriture a la fin
fprintf(f,"%s %s %s %s %s %s %s\n",p.typ,p.mature,p.esp,p.id,p.plantation.jour,p.plantation.mois,p.plantation.annee); //f variable de type file 
fclose(f); //retour NULL si operation fini 
}



void supprimer_plante(char id[])
{
FILE*f=NULL;
FILE*f1=NULL;
plante p;
f=fopen("plantes.txt","r");
f1=fopen("ancien.txt","w+");//mode lecture et ecriture 
while(fscanf(f,"%s %s %s %s %s %s %s\n",p.typ,p.mature,p.esp,p.id,p.plantation.jour,p.plantation.mois,p.plantation.annee)!=EOF){
if(strcmp(id,p.id)!=0)fprintf(f1,"%s %s %s %s %s %s %s\n",p.typ,p.mature,p.esp,p.id,p.plantation.jour,p.plantation.mois,p.plantation.annee);
}
fclose(f);
fclose(f1);
remove("plantes.txt");
rename("ancien.txt","plantes.txt");
}




void modifer(char id[30] ,plante t2)
{
    supprimer_plante(id);
    ajouter_plante(t2);
}


enum
{
ETYP,
EMATURE,
EESP,
EID,
EJOUR,
EMOIS,
EANNEE,
COLUMNS
};

void rechercher_ouv(char id[],GtkWidget *treeview1)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
 	GtkWidget *window6_treeview1;
	GtkListStore *store;
	plante t;
	

store=NULL;

FILE *f;

 store=gtk_tree_view_get_model(treeview1);
if(store==NULL)
{
	renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type d'une plante",renderer, "text",EID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1),column);

	renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("durée de maturation",renderer, "text",EMATURE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1),column);

	renderer = gtk_cell_renderer_text_new();
	column =gtk_tree_view_column_new_with_attributes("espacement",renderer,"text",EESP,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("identifiant de la plante",renderer,"text",ETYP,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour",renderer, "text",EJOUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois",renderer, "text",EMOIS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee",renderer, "text",EANNEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1),column);

}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
  f=fopen("plantes.txt","r");
    if (f ==NULL)
    {
	return;
    }
else
	f=fopen("plantes.txt","r");

   while((fscanf(f,"%s %s %s %s %s %s %s \n" ,t.typ,t.mature,t.esp,t.id,t.plantation.jour,t.plantation.mois,t.plantation.annee))!=EOF)
  
{ 
	if((strcmp(t.id,id)==0))
	{
	gtk_list_store_append (store,&iter);
				gtk_list_store_set(store,&iter,EID,t.id,EMATURE,t.mature,EESP,t.esp,ETYP,t.typ,EJOUR,t.plantation.jour,EMOIS,t.plantation.mois,EANNEE,t.plantation.annee,-1);
	}
}
	
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(treeview1), GTK_TREE_MODEL(store));

	g_object_unref(store);






}


int deffectueux (int iden [], char *fichier, float minv , float maxv )
{   FILE *f;
 int jour , mois, annee; 
float val;
    int n=0,i,t,k=0;
    int max;
    int id;
    f=fopen("temperature.txt","r");
    if(f!=NULL)
 {
    while(fscanf(f,"%d %d %d %d %f",&id,&jour,&mois,&annee,&val)!=EOF)
    {   //printf("id=%d val=%f\n",c.id,c.val);
        if(val>maxv||val<minv)
        {
                   iden[n]=id;
                   n++;
               }
           }
        }
         fclose(f);
    i=0;
    max=0;
    for(i=0;i<n;i++){
        for(t=0;t<n;t++){
            if(iden[i]==iden[t]){
                k++;
        }   }
        if(max<k)
        {   max=k;
            id=iden[i];
    }
    k=0;
    }
    i=0;
    while(i<n)
    {
        for(t=i+1;t<n;t++)
        {
            if(iden[i]==iden[t])
            {iden[t]=0;}
        }
        i++;
    }
    for(i=0;i<n;i++)
    {  if(iden[i]!=0)
        printf("%d/",iden[i]);
    }
    return id;
}








