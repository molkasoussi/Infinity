#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include"file.h"
#include <gtk/gtk.h>

enum {
       EID,
       ENOM,
       EPRENOM,
       EEMAIL,
       EMDP,
       EJOUR,
       EMOIS,
       EANNEE,
       COLOMNS
      };

void ajouter_client(client c)
{
FILE *f;
	f = fopen("clients.txt","a+");
	if(f!=NULL){
		fprintf(f,"%s %s %s %s %s %d %d %d \n",c.id,c.nom,c.prenom,c.mail,c.mdp,c.date_naissance.jour,c.date_naissance.mois,c.date_naissance.annee);
	}
	fclose(f);
}

void afficher_clients(GtkWidget *liste)
{
GtkListStore *store;
GtkCellRenderer *renderer;
GtkTreeViewColumn *col;
GtkTreeIter iter;
char id[20];
char nom[50];
char prenom[50];
char email[50];
char mdp[50];
char jour_naissance[20];
char mois_naissance[20];
char annee_naissance[20];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer= gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("id",renderer,"text",EID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),col);
renderer= gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",ENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),col);
renderer= gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",EPRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),col);
renderer= gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("email",renderer,"text",EEMAIL,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),col);
renderer= gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("mdp",renderer,"text",EMDP,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),col);
renderer= gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("jour_naissance",renderer,"text",EJOUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),col);
renderer= gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("mois_naissance",renderer,"text",EMOIS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),col);
renderer= gtk_cell_renderer_text_new(); 	

	col = gtk_tree_view_column_new_with_attributes("annee_naissance",renderer,"text",EANNEE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),col);
}
store=gtk_list_store_new(COLOMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("clients.txt","r");
if (f==NULL)
{
return;
}
else
{
f=fopen("clients.txt","a+"); 
while(fscanf(f,"%s %s %s %s %s %s %s %s \n",id,nom,prenom,email,mdp,jour_naissance,mois_naissance,annee_naissance)!=EOF)
{
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store,&iter,EID,id,ENOM,nom,EPRENOM,prenom,EEMAIL,email,EMDP,mdp,EJOUR,jour_naissance,EMOIS,mois_naissance,EANNEE,annee_naissance,-1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}

}

void supprimer_tree(client c)
{
client c2;
FILE *f , *g;
    f=fopen("clients.txt","r");
    g=fopen("supp.txt","w");
   if(f==NULL || g==NULL)
{
return;
}
else
{
while(fscanf(f,"%s %s %s %s %s %d %d %d  \n",c2.id,c2.nom,c2.prenom,c2.mail,c2.mdp,&c2.date_naissance.jour,&c2.date_naissance.mois,&c2.date_naissance.annee)!=EOF)
{

if(strcmp(c.id,c2.id)!=0 ||strcmp(c.nom,c2.nom)!=0 || strcmp(c.prenom,c2.prenom)!=0 || strcmp(c.mail,c2.mail)!=0)
fprintf(g,"%s %s %s %s %s %d %d %d \n",c2.id,c2.nom,c2.prenom,c2.mail,c2.mdp,c2.date_naissance.jour,c2.date_naissance.mois,c2.date_naissance.annee);
}
fclose(f);
fclose(g);
remove("clients.txt");
rename("supp.txt","clients.txt");
}
}

void rechercher_client( char idrech[20],GtkWidget *liste)
{
GtkListStore *store;
GtkCellRenderer *renderer;
GtkTreeViewColumn *col;
GtkTreeIter iter;
char id[20];
char nom[50];
char prenom[50];
char email[50];
char mdp[50];
char jour_naissance[20];
char mois_naissance[20];
char annee_naissance[20];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer= gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("id",renderer,"text",EID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),col);
renderer= gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",ENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),col);
renderer= gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",EPRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),col);
renderer= gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("email",renderer,"text",EEMAIL,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),col);
renderer= gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("mdp",renderer,"text",EMDP,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),col);
renderer= gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("jour_naissance",renderer,"text",EJOUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),col);
renderer= gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("mois_naissance",renderer,"text",EMOIS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),col);
renderer= gtk_cell_renderer_text_new(); 	

	col = gtk_tree_view_column_new_with_attributes("annee_naissance",renderer,"text",EANNEE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),col);
}
store=gtk_list_store_new(COLOMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("clients.txt","r");
if (f==NULL)
{
return;
}
else
{
f=fopen("clients.txt","a+"); 
while(fscanf(f,"%s %s %s %s %s %s %s %s \n",id,nom,prenom,email,mdp,jour_naissance,mois_naissance,annee_naissance)!=EOF){
     if(strcmp(id,idrech)==0)
   {
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store,&iter,EID,id,ENOM,nom,EPRENOM,prenom,EEMAIL,email,EMDP,mdp,EJOUR,jour_naissance,EMOIS,mois_naissance,EANNEE,annee_naissance,-1);
   }
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}

void modifier_client(client c)
{
     char nom1[50];
     char prenom1[50];
     char mail1[50];
     char id1[20];
     char mdp1[50];
     int jdn;
     int mdn;
     int adn;

FILE *f , *g;

client c2;
    f=fopen("clients.txt","r");
    g=fopen("mdf.txt","a+");
while(fscanf(f,"%s %s %s %s %s %d %d %d  \n",id1,nom1,prenom1,mail1,mdp1,&jdn,&mdn,&adn)!=EOF)
{
if(strcmp(c.id,id1)==0)
fprintf(g,"%s %s %s %s %s %d %d %d \n",c.id,c.nom,c.prenom,c.mail,c.mdp,c.date_naissance.jour,c.date_naissance.mois,c.date_naissance.annee);
else
fprintf(g,"%s %s %s %s %s %d %d %d \n",id1,nom1,prenom1,mail1,mdp1,jdn,mdn,adn);

}
fclose(f);
fclose(g);
remove("clients.txt");
rename("mdf.txt","clients.txt");
}

int verif_client(char id[])
{
    FILE *f=NULL;
    client c;
    int v;
    f=fopen("clients.txt","r");
    v=0;
    if(f!=NULL)
    {
while(fscanf(f,"%s %s %s %s %s %d %d %d  \n",c.id,c.nom,c.prenom,c.mail,c.mdp,&c.date_naissance.jour,&c.date_naissance.mois,&c.date_naissance.annee)!=EOF)
{
         if(strcmp(c.id,id)==0)
        {
          v=1;
          break;
        }
}
     fclose(f);
     }
return(v);

}

void supprimer_id(char idsp[])
{
client c;
FILE *f , *g;
    f=fopen("clients.txt","r");
    g=fopen("supp.txt","w");
   if(f==NULL || g==NULL)
{
return;
}
else
{
while(fscanf(f,"%s %s %s %s %s %d %d %d  \n",c.id,c.nom,c.prenom,c.mail,c.mdp,&c.date_naissance.jour,&c.date_naissance.mois,&c.date_naissance.annee)!=EOF)
{
  if(strcmp(c.id,idsp)!=0)
{
fprintf(g,"%s %s %s %s %s %d %d %d \n",c.id,c.nom,c.prenom,c.mail,c.mdp,c.date_naissance.jour,c.date_naissance.mois,c.date_naissance.annee);
}
}
fclose(f);
fclose(g);
remove("clients.txt");
rename("supp.txt","clients.txt");
}
}


