#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"


int tab_an[100];
float tab_temp[100]={0};

void
on_showbutton_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *output;
int i;
int pos;
int n;
char ch1[100]="";
char ch2[100]="";
char aff[1000];
n=annee_seche(tab_an,tab_temp);
pos=valeur_max(tab_temp,n);
output=lookup_widget(button,"label21");
for(i=0;i<=n;i++)
{sprintf(ch2,"%d\n",tab_an[i]);
strcat(ch1,ch2);}
sprintf(aff,"Les annees de plantations sont:\n%s \n L'annee la plus seche est %d ",ch1,tab_an[pos]);
gtk_label_set_text(GTK_LABEL(output),aff);


}

