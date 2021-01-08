#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "capteur.h"
#include <gtk/gtk.h>


void ajout_capteur(capteur t)
{
    FILE *f=NULL;
    f=fopen("capteur.txt","a");
    if(f!=NULL)
    {
        fprintf(f,"%d %d %d %s %d %d %d %d\n",t.idtf,t.type,t.etat,t.emplacement,t.date_ajou.jour,t.date_ajou.mois,t.date_ajou.annee,t.marque);
        fclose(f);
    }
    else
        printf("not founded");
}
void supprimer_capteur(int idtf )
{
    FILE *f=NULL;
    FILE *tmp=NULL;
    capteur t1;
    f=fopen("capteur.txt","r");
    tmp=fopen("tmp.txt","w");
    if(f!=NULL)
    {
       while(fscanf(f,"%d %d %d %s %d %d %d %d\n",&t1.idtf,&t1.type,&t1.etat,t1.emplacement,&t1.date_ajou.jour,&t1.date_ajou.mois,&t1.date_ajou.annee,&t1.marque)!=EOF)
       {
        if(t1.idtf!=idtf)
        {
         fprintf(tmp,"%d %d %d %s %d %d %d %d\n",t1.idtf,t1.type,t1.etat,t1.emplacement,t1.date_ajou.jour,t1.date_ajou.mois,t1.date_ajou.annee,t1.marque);
        }

       }
        fclose(f);
        fclose(tmp);
        remove("capteur.txt");
        rename("tmp.txt","capteur.txt");

    }
    else
        printf("not founded");
}
///////////////////////////////////////////
void modifier_capteur(int idtf ,capteur t2)
{
    supprimer_capteur(idtf);
    ajout_capteur( t2);
}
//////////////////////////////////////////////
void cherche_id(int idtf,capteur *p)
{
    FILE *f=NULL;
    capteur t1;
    int teste;
    f=fopen("capteur.txt","r");
    teste=0;
        
    if(f!=NULL)
    {
      while(fscanf(f,"%d %d %d %s %d %d %d %d\n",&t1.idtf,&t1.type,&t1.etat,t1.emplacement,&t1.date_ajou.jour,&t1.date_ajou.mois,&t1.date_ajou.annee,&t1.marque)!=EOF)
       {
         if(t1.idtf == idtf )
        {
         *p=t1;
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









