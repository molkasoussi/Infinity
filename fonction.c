#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "callbacks.h"
#include "fonction.h"
#include<string.h>
#include <gtk/gtk.h>

void ajouter(troupeaux t)
{
FILE*f=NULL; 
f=fopen("troupeaux.txt","a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %s %s %s %s %s\n",t.identifiant,t.poids,t.type,t.genre,t.etat,t.naissance.jour,t.naissance.mois,t.naissance.annee );
        fclose(f);
}
    else
        printf("not founded");
}

/*int exister (char*identifiant)
{
FILE*f=NULL;
troupeaux t;
f=fopen("troupeaux","r");// ouverture du fichier equipement en  mode lecture 
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",t.identifiant,t.poids,t.type,t.genre,t.etat,t.naissance.jour,t.naissance.mois,t.naissance.annee)!=EOF){
if(strcmp(t.identifiant,identifiant)==0)
return 1;   //id existe deja 
}
fclose(f);
return 0;
}*/


void supprimer (char identifiant[])
{
FILE*f=NULL;
FILE*f1=NULL;
troupeaux t ;
f=fopen("troupeaux.txt","r");
f1=fopen("ancien.txt","w+");//mode lecture et ecriture 
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",t.identifiant,t.poids,t.type,t.genre,t.etat,t.naissance.jour,t.naissance.mois,t.naissance.annee)!=EOF){
if(strcmp(identifiant,t.identifiant)!=0)fprintf(f1,"%s %s %s %s %s %s %s %s\n",t.identifiant,t.poids,t.type,t.genre,t.etat,t.naissance.jour,t.naissance.mois,t.naissance.annee);
}
fclose(f);
fclose(f1);
remove("troupeaux.txt");
rename("ancien.txt","troupeaux.txt");
}

void modifer(char id[] ,troupeaux t2)
{
    supprimer(id);
    ajouter(t2);
}

int count(char type[])
{
    int nombre=0;

    FILE *f=NULL;
    troupeaux t1;
    f=fopen("troupeaux.txt","r");
    if(f!=NULL)
    {
       while(fscanf(f,"%s %s %s %s %s %s %s %s\n",t1.identifiant,t1.poids,t1.type,t1.genre,t1.etat,t1.naissance.jour
                    ,t1.naissance.mois,t1.naissance.annee )!=EOF)
       {
         if(strcmp(type,t1.type)==0 )
        {
          nombre+=1;

        }

       }
        fclose(f);
        }
        else
        printf("not founded");
    return(nombre);
}


int chercher(char ty[],troupeaux *p)
{
    FILE *f=NULL;
    troupeaux t1;
    int teste;
    f=fopen("troupeaux.txt","r");
    teste=0;
    if(f!=NULL)
    {
       while(fscanf(f,"%s %s %s %s %s %s %s %s\n",t1.identifiant,t1.poids,t1.type,t1.genre,t1.etat,t1.naissance.jour
                    ,t1.naissance.mois,t1.naissance.annee )!=EOF)
       {
         if(strcmp(t1.type,ty)==0)
        { *p=t1;
          teste=1;
          break;
        }

       }
        fclose(f);
        }
        else
        printf("not founded");
        return(teste);
}
int chercher_id(char ty[],troupeaux *p)
{
    FILE *f=NULL;
    troupeaux t1;
    int teste=0;
    f=fopen("troupeaux.txt","r");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %s %s\n",t1.identifiant,t1.poids,t1.type,t1.genre,t1.etat,t1.naissance.jour
                ,t1.naissance.mois,t1.naissance.annee )!=EOF)
        {
            if(strcmp(t1.identifiant,ty)==0)
            { *p=t1;
            teste=1;
                break;
            }

        }
        fclose(f);
    }
    else
        printf("not founded");
    return(teste);
}

