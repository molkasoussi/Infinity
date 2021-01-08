#ifndef FONCTIONS_H_
#define FONCTIONS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <gtk/gtk.h>



typedef struct
{
    int jour;
    int mois;
    int annee;
}date;
typedef struct
{
    int idtf;
    int etat;
    int type;
    char emplacement[20];
    int marque;
    date date_ajou;
}capteur;
void ajout_capteur(capteur t);
void supprimer_capteur(int idtf);
void modifier_capteur(int idtf, capteur t2);
void cherche_id(int idtf,capteur *p);
#endif

