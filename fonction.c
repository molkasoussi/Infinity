#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "callbacks.h"
#include "fonction.h"
#include<string.h>
#include <gtk/gtk.h>





int exister (char*identifiant){
FILE*f=NULL;
ouvrier t;
f=fopen("src/ouvrier.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %s %s \n",t.identifiant,t.naissance.jour,t.naissance.mois,t.naissance.annee,t.Nom,t.Prenom,t.Sexe,t.Cin)!=EOF){
if(strcmp(t.identifiant,identifiant)==0)
return 1;   //id existe deja 
}
fclose(f);
return 0;
}


void ajouter(ouvrier t)
{
FILE*f=NULL; 
f=fopen("src/ouvrier.txt","a");
fprintf(f,"%s %s %s %s %s %s %s %s \n",t.identifiant,t.naissance.jour,t.naissance.mois,t.naissance.annee,t.Nom,t.Prenom,t.Sexe,t.Cin); 
fclose(f); 
}



void supprimer (char identifiant[])
{
FILE*f=NULL;
FILE*f1=NULL;
ouvrier t ;
f=fopen("src/ouvrier.txt","r");
f1=fopen("src/ancien.txt","w+");//mode lecture et ecriture 
while(fscanf(f,"%s %s %s %s %s %s %s %s \n",t.identifiant,t.naissance.jour,t.naissance.mois,t.naissance.annee,t.Nom,t.Prenom,t.Sexe,t.Cin)!=EOF){
if(strcmp(identifiant,t.identifiant)!=0)fprintf(f1,"%s %s %s %s %s %s %s %s \n",t.identifiant,t.naissance.jour,t.naissance.mois,t.naissance.annee,t.Nom,t.Prenom,t.Sexe,t.Cin);
}
fclose(f);
fclose(f1);
remove("src/ouvrier.txt");
rename("src/ancien.txt","src/ouvrier.txt");
}

void modifer(char id[30] ,ouvrier t2)
{
    supprimer(id);
    ajouter(t2);
}

void afficher(GtkWidget* treeview1,char *l)
{
enum
{
idtf_t, 
nom_t,
prenom_t,
Sexe_t,
cin_t,
jour_t,
mois_t,
annee_t,
columns
};

GtkCellRenderer *renderer;
GtkTreeViewColumn * column;
GtkTreeIter iter;
GtkListStore *store;

char identifiant[30];
char Nom[30];
char Prenom[30];
char Cin[30];
char Sexe[30];

char jour[20];
char mois[20];
char annee[20];
FILE *f;
ouvrier t;


store=NULL;
store=gtk_tree_view_get_model(treeview1);
if (store == NULL)
{

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",idtf_t,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",nom_t,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

                renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",prenom_t,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Cin",renderer,"text",cin_t,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Sexe",renderer,"text",Sexe_t,NULL);
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

f=fopen("src/ouvrier.txt","r");

if (f == NULL ) {return;}
else
{
 while((fscanf(f,"%s %s %s %s %s %s %s %s \n" ,t.identifiant,t.naissance.jour,t.naissance.mois,t.naissance.annee,t.Nom,t.Prenom,t.Sexe,t.Cin))!=EOF)
         {
         strcpy(identifiant,t.identifiant);
         strcpy(jour,t.naissance.jour);
         strcpy(mois,t.naissance.mois);
         strcpy(annee,t.naissance.annee);
strcpy(Nom,t.Nom);
strcpy(Prenom,t.Prenom);

strcpy(Sexe,t.Sexe);
strcpy(Cin,t.Cin);

	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,idtf_t,identifiant,jour_t,jour,mois_t,mois,annee_t,annee,nom_t,Nom,prenom_t,Prenom,Sexe_t,Sexe,cin_t,Cin,-1);






}
fclose(f);
}
	gtk_tree_view_set_model(GTK_TREE_VIEW(treeview1),GTK_TREE_MODEL(store));
	g_object_unref(store);

}
}
///////////////////////rechercheeerr//////////////////////////////////////////////////////////////////////////

enum
{

EID,
ENOM,
EPRENOM,
ES,
ECIN,
EJ,
EMOIS,
EANNEE,
COLUMNS
};


void rechercher_ouv(char identifiant[],GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
 	GtkWidget *window6_liste;
	GtkListStore *store;
	ouvrier t;
	

store=NULL;

FILE *f;

 store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("identifiant",renderer, "text",EID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Nom",renderer, "text",ENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column =gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",EPRENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("sexe",renderer, "text",ES,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("cin",renderer, "text",ECIN,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour",renderer, "text",EJ,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois",renderer, "text",EMOIS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee",renderer, "text",EANNEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
  f=fopen("src/ouvrier.txt","r");
    if (f ==NULL)
    {
	return;
    }
else
	f=fopen("src/ouvrier.txt","r");

   while((fscanf(f,"%s %s %s %s %s %s %s %s \n" ,t.identifiant,t.naissance.jour,t.naissance.mois,t.naissance.annee,t.Nom,t.Prenom,t.Sexe,t.Cin))!=EOF)
  
{ 
	if((strcmp(t.identifiant,identifiant)==0))
	{
	gtk_list_store_append (store,&iter);
				gtk_list_store_set(store,&iter,EID,t.identifiant,ENOM,t.Nom,EPRENOM,t.Prenom,ES,t.Sexe,ECIN,t.Cin,EJ,t.naissance.jour,EMOIS,t.naissance.mois,EANNEE,t.naissance.annee,-1);
	}
}
	
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));

	g_object_unref(store);






}
//////////////////////////////////absence////////////////////////////

void remplir (abscence a)
{
FILE *f=NULL;
f=fopen("src/absenteisme.txt","a");
fprintf(f,"%s %s %s %s %s \n ", a.id,a.jour,a.mois,a.annee,a.val);
fclose(f);
}



////////////////////////////////////////////////////////////////////////



float taux_absc(char annee[20])
 { 
FILE*f=NULL; 
FILE*f1=NULL;

f=fopen("src/ouvrier.txt","r"); 
f1=fopen("src/absenteisme.txt","r");
ouvrier t;
abscence a;
int tot=0,nb_abs=0; 
float taux;
while((fscanf(f,"%s %s %s %s %s %s %s %s \n"
,t.identifiant,t.naissance.jour,t.naissance.mois,t.naissance.annee,t.Nom,t.Prenom,t.Sexe,t.Cin))!=EOF)
{ tot ++ ; }  //totale_des_ouvriers
while(fscanf(f1,"%s %s %s %s %s\n",a.id,a.jour,a.mois,a.annee,a.val)!=EOF)
 { if(strcmp(a.annee,annee)==0&& strcmp(a.val,"0")==0)
	{ nb_abs++;} } //nbre_des_ouvriers_absents
 /*if ( tot==0 || nb_abs==0)
 { taux=0;}*/
taux=(nb_abs/(30*tot))*100;
fclose(f);
fclose(f1);
 return taux;
 }
////////////////////////////////////////////////////////////////////////////
void afficher_abs(GtkWidget* treeview2,char *l)
{
enum
{
idtf_t, 
jour_t,
mois_t,
annee_t,
val_t,
columns
};

GtkCellRenderer *renderer;
GtkTreeViewColumn * column;
GtkTreeIter iter;
GtkListStore *store;

char identifiant[30];
char val[30];
char jour[20];
char mois[20];
char annee[20];
FILE *f;
abscence a;


store=NULL;
store=gtk_tree_view_get_model(treeview2);
if (store == NULL)
{

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",idtf_t,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",jour_t,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2),column);
                 
                renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",mois_t,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",annee_t,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2),column);


		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("val",renderer,"text",val_t,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2),column);







	store=gtk_list_store_new(columns,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("src/absenteisme.txt","a+");

if (f == NULL ) {return;}
else
{
 while((fscanf(f,"%s %s %s %s %s \n",a.id,a.jour,a.mois,a.annee,a.val))!=EOF)
         {
         strcpy(identifiant,a.id);
         strcpy(jour,a.jour);
         strcpy(mois,a.mois);
         strcpy(annee,a.annee);

	strcpy(val,a.val);


	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,idtf_t,identifiant,jour_t,jour,mois_t,mois,annee_t,annee,val_t,val,-1);






}
fclose(f);
}
	gtk_tree_view_set_model(GTK_TREE_VIEW(treeview2),GTK_TREE_MODEL(store));
	g_object_unref(store);

}
}
