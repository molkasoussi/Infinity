#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <gtk/gtk.h>


#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "tree.h"
#include "fonction.h"


void
on_button_retourGP_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{


}


void
on_buttonGP_clicked                    (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *p;
GtkWidget *windowGP, *windowLP, *treeview1;
gtk_widget_hide (windowGP);
gtk_widget_destroy(windowGP);
windowLP = create_windowLP ();
p=lookup_widget(windowLP,"treeview1");
afficher(p,"plantes.txt");
gtk_widget_show (windowLP);
}


void
on_button_ajoutp_clicked               (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowGP,*windowA;
windowGP=lookup_widget(objet_graphique,"windowGP");
gtk_widget_destroy(windowGP);
windowA=lookup_widget(objet_graphique,"windowA");
windowA=create_windowA();
gtk_widget_show(windowA);

}


void
on_button_supprimerp_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowGP,*windowS;
windowGP=lookup_widget(objet_graphique,"windowGP");
gtk_widget_destroy(windowGP);
windowS=lookup_widget(objet_graphique,"windowS");
windowS=create_windowS();
gtk_widget_show(windowS);

}


void
on_button_modifierp_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowGP,*windowA;
windowGP=lookup_widget(objet_graphique,"windowGP");
gtk_widget_destroy(windowGP);
windowM=lookup_widget(objet_graphique,"windowA");
windowM=create_windowM();
gtk_widget_show(windowM);

}




void
on_button_chercherLP_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char 	id[30];
GtkWidget *windowliste,*sortiem;
GtkWidget *Id;
Id= lookup_widget (objet_graphique,"entry5");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(Id)));
sortiem=lookup_widget(objet_graphique, "label62");
GtkWidget *treeview_Affichage;
windowliste=lookup_widget (objet_graphique,"windowLP");

treeview_Affichage=lookup_widget (windowliste,"treeview1");

rechercher_ouv(id , treeview_Affichage);


gtk_label_set_text(GTK_LABEL(sortiem),"Resultat(s) obtenu(s)!");


}


void
on_button_ajoutp2_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *p;
GtkWidget *windowGP,*windowA,*windowLP;
plante t;
GtkWidget *idtf,
 *identifiant,*typ,*mature,*jour,*mois,*annee,*esp,*treeview1;
jour=lookup_widget(objet_graphique,"jour");
sprintf(t.plantation.jour,"%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour)));
mois=lookup_widget(objet_graphique,"mois");
sprintf(t.plantation.mois,"%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois)));
annee=lookup_widget(objet_graphique,"annee");
sprintf(t.plantation.annee,"%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee)));

typ=lookup_widget(objet_graphique,"entry1");
strcpy(t.typ,gtk_entry_get_text(GTK_ENTRY(typ)));

mature=lookup_widget(objet_graphique,"entry2");
strcpy(t.mature,gtk_entry_get_text(GTK_ENTRY(mature)));

esp=lookup_widget(objet_graphique,"entry3");
strcpy(t.esp,gtk_entry_get_text(GTK_ENTRY(esp)));

idtf=lookup_widget(objet_graphique,"entry4");
strcpy(t.id,gtk_entry_get_text(GTK_ENTRY(idtf)));

ajouter_plante(t);
windowA=lookup_widget(objet_graphique,"windowA");
gtk_widget_hide(windowA);
windowGP=lookup_widget(objet_graphique,"windowGP");
windowGP=create_windowGP();
gtk_widget_show(windowGP);
//treeview1=lookup_widget(windowL,"treeview1");

//afficher(treeview1);

        


        afficher(p,"plantes.txt");

}




void
on_button_supprimerp2_clicked          (GtkWidget     *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *id;
plante t;
id=lookup_widget(objet_graphique,"entry6");
strcpy(t.id,gtk_entry_get_text(GTK_ENTRY(id)));
supprimer_plante(t.id);
windowS=lookup_widget(objet_graphique,"windowS");
gtk_widget_hide(windowS);
windowGP=lookup_widget(objet_graphique,"windowGP");
windowGP=create_windowGP();
gtk_widget_show(windowGP);
}


void
on_button_modiferp2_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *p;
GtkWidget *windowGP,*windowM,*windowLP;
plante t2;
char ch[20];
GtkWidget
 *identifiant,*typ,*mature,*esp,*jour,*mois,*annee,*id,*treeview1;

identifiant=lookup_widget(objet_graphique,"entry10");
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(identifiant)));


jour=lookup_widget(objet_graphique,"spinbutton4");
sprintf(t2.plantation.jour,"%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour)));
mois=lookup_widget(objet_graphique,"spinbutton5");
sprintf(t2.plantation.mois,"%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois)));
annee=lookup_widget(objet_graphique,"spinbutton6");
sprintf(t2.plantation.annee,"%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee)));


id=lookup_widget(objet_graphique,"entry10");
strcpy(t2.id,gtk_entry_get_text(GTK_ENTRY(id)));

typ=lookup_widget(objet_graphique,"entry7");
strcpy(t2.typ,gtk_entry_get_text(GTK_ENTRY(typ)));

mature=lookup_widget(objet_graphique,"entry8");
strcpy(t2.mature,gtk_entry_get_text(GTK_ENTRY(mature)));

esp=lookup_widget(objet_graphique,"entry9");
strcpy(t2.esp,gtk_entry_get_text(GTK_ENTRY(esp)));

modifer(ch,t2);
windowM=lookup_widget(objet_graphique,"windowM");
gtk_widget_destroy(windowM);
windowGP=lookup_widget(objet_graphique,"windowGP");
windowGP=create_windowGP();
gtk_widget_show(windowGP);


}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)

{
 GtkTreeIter iter;
   gchar *identifiant;
        gchar *type;
        gchar *maturation;
        gchar *espacement;

      
        gchar *jour;
        gchar *mois;
        gchar *annee;
	char mot[20];
	int id;
      GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if(gtk_tree_model_get_iter(model,&iter,path))
{

gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,identifiant,1,jour,2,mois,3,annee,4,type,5,maturation,6,espacement,-1);
id=identifiant;

}

       
}



       






void
on_button_verif_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Nomm, *input1,*ouput1,*ouput2,*ouput3,*ouput4,*ouput5,*ouput6,*ouput8,*ouput7;
GtkWidget *fenetremodif;
char chnb1[30],chnb2[30],chnb3[30], Nom[30];
fenetremodif=lookup_widget(objet_graphique,"windowM");
 plante p2,p;
input1=lookup_widget(objet_graphique,"entry11");
strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(input1)));



FILE *f;
f=fopen("plantes.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %s \n"
,p2.typ,p2.mature,p2.esp,p2.id,p2.plantation.jour,p2.plantation.mois,p2.plantation.annee)!=EOF)
{
if(strcmp(p.id,p2.id)==0)
{
ouput7=lookup_widget(objet_graphique,"label29") ;
gtk_label_set_text(GTK_LABEL(ouput7),p2.id); 

//ouput2=lookup_widget(objet_graphique,"label67") ;
sprintf(chnb1,"%s",p2.plantation.jour);
sprintf(chnb2,"%s",p2.plantation.mois);
sprintf(chnb3,"%s",p2.plantation.annee);
ouput2=lookup_widget(objet_graphique,"label33") ;
gtk_label_set_text(GTK_LABEL(ouput2),chnb1);
gtk_widget_show (ouput2);

ouput3=lookup_widget(objet_graphique,"label34") ;
gtk_label_set_text(GTK_LABEL(ouput3),chnb2);
gtk_widget_show (ouput3);
ouput8=lookup_widget(objet_graphique,"label35") ;
gtk_label_set_text(GTK_LABEL(ouput8),chnb3);
gtk_widget_show (ouput8);
ouput1=lookup_widget(objet_graphique,"label30") ;
gtk_label_set_text(GTK_LABEL(ouput1),p2.typ);
gtk_widget_show (ouput1);
ouput6=lookup_widget(objet_graphique,"label31") ;
gtk_label_set_text(GTK_LABEL(ouput6),p2.mature);
gtk_widget_show (ouput6);
ouput4=lookup_widget(objet_graphique,"label32") ;
gtk_label_set_text(GTK_LABEL(ouput4),p2.esp);
gtk_widget_show (ouput4);

}
}
fclose(f);



}








void
on_button_retourM_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_GP;
GtkWidget *fenetre_LP;
fenetre_LP=lookup_widget (objet_graphique,"Listes des plantations");
gtk_widget_destroy(fenetre_LP);
fenetre_GP=create_windowGP();
gtk_widget_show(fenetre_GP);
}


void
on_button_retourLP_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_GP;
GtkWidget *fenetre_LP;
fenetre_LP=lookup_widget (objet_graphique,"Listes des plantations");
gtk_widget_destroy(fenetre_LP);
fenetre_GP=create_windowGP();
gtk_widget_show(fenetre_GP);

}


void
on_button_retourS_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_S;
GtkWidget *fenetre_GP;
fenetre_S=lookup_widget (objet_graphique,"windowS");
gtk_widget_destroy(fenetre_S);
fenetre_GP=create_windowGP();
gtk_widget_show(fenetre_GP);


}



void
on_button_retourA_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_A;
GtkWidget *fenetre_GP;
fenetre_A=lookup_widget (objet_graphique,"windowA");
gtk_widget_destroy(fenetre_A);
fenetre_GP=create_windowGP();
gtk_widget_show(fenetre_GP);

}







void
on_button__capdef1_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_GP;
GtkWidget *fenetre_capdef;
fenetre_GP=lookup_widget (objet_graphique,"windowA");
gtk_widget_destroy(fenetre_GP);
fenetre_capdef=create_windowcapdef();
gtk_widget_show(fenetre_capdef);

}


void
on_button_capdef2_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{


     GtkWidget *output;
char texte [200]="";
{
FILE *f;
int i,j;
int deft=0;
int def[30];
int T[20];
char M[500][20];

int d;
char marque [20];
int n=deffectueux(T,"temperature.txt",-5,60.5);

int nbr=0;
f=fopen("marque.txt","r");
    if(f!=NULL)
 {
while(fscanf(f,"%s %d",&marque,&d)!=EOF)
{

          strcpy(M[nbr],marque);
          def[nbr]=0;
          nbr++;

  }
}
 fclose(f);
 i=0;
 while(i<nbr)
 {
     for(j=i+1;j<nbr;j++)
        {
            if(strcmp(M[i],M[j])==0)
            {strcpy(M[j],"00000");
            }
        }
        i++;
 }
 for(j=0;j<nbr;j++)
    {if(strcmp(M[j],"00000")!=0)
    {printf("/%s/",M[j]);
    deft++;}}

sprintf (texte,"la marque la plus defectueuse est %s ",M[n-1]);
output=lookup_widget(objet_graphique,("label41"));
gtk_label_set_text(GTK_LABEL(output),texte);

}
}






