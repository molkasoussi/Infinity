#include "capteur.h"
void temperature_capteur ( date temp);
{


    FILE *f=NULL ,*tmp=NULL;
    tempurature t1;
    f=fopen("temperature.txt","r");
    tmp=fopen("temperature def.txt","w")
    if(f!=NULL)
    {
       while(fscanf(f,"%d %d %d %d %f\n",t1.id,t1.jours,t1.mois,t1.annee,t1.valeur)!=EOF)
       {
         if(jours == t1.jours && mois == t1.mois && annee == t1.annee && t.valeur>100 )
        {
           fprintf(tmp,"%d %f\n",t1.id,t1.valeur);	
	}

       }
        fclose(f);
        fclose(tmp);
        }
        else
        printf("not founded");
}
