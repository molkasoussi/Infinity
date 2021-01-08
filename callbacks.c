#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "tree.h"
#include "fonction.h"

char id[20];

void
on_buttonLDT_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *p;
GtkWidget *windowGT, *windowL, *treeview1;
gtk_widget_hide (windowGT);
gtk_widget_destroy(windowGT);
windowL = create_windowL ();
p=lookup_widget(windowL,"treeview1");
afficher(p,"src/ouvrier.txt");
gtk_widget_show (windowL);
}


void
on_buttonNDT_clicked                   (GtkWidget        *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowGT,*windowN;
windowGT=lookup_widget(objet_graphique,"windowGT");
//gtk_widget_destroy(windowGT);
windowN=lookup_widget(objet_graphique,"windowN");
windowN=create_windowN();
gtk_widget_show(windowN);
}


void
on_buttonM_clicked                     (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowGT,*windowA;
windowGT=lookup_widget(objet_graphique,"windowGT");
gtk_widget_destroy(windowGT);
windowM=lookup_widget(objet_graphique,"windowA");
windowM=create_windowM();
gtk_widget_show(windowM);
}


void
on_buttonS_clicked                     (GtkWidget     *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowGT,*windowS;
windowGT=lookup_widget(objet_graphique,"windowGT");
gtk_widget_destroy(windowGT);
windowS=lookup_widget(objet_graphique,"windowS");
windowS=create_windowS();
gtk_widget_show(windowS);
}




void
on_buttonA_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowGT,*windowA;
windowGT=lookup_widget(objet_graphique,"windowGT");
gtk_widget_destroy(windowGT);
windowA=lookup_widget(objet_graphique,"windowA");
windowA=create_windowA();
gtk_widget_show(windowA);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
 GtkTreeIter iter;
   gchar *identifiant;
        gchar *Nom;
        gchar *Prenom;
        gchar *Cin;
	gchar *Sexe;
      
        gchar *jour;
        gchar *mois;
        gchar *annee;
	char mot[20];
	
      GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if(gtk_tree_model_get_iter(model,&iter,path))
{

gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&identifiant,-1);
strcpy(id,identifiant);


}

       
}


void
on_buttonModifie_clicked               (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *p;
GtkWidget *windowGT,*windowM,*windowL;
ouvrier t2;
char ch[20];
GtkWidget
 *identifiant,*Nom,*Prenom,*jour,*mois,*annee,*Cin,*Sexe,*treeview1,*sortiem;


identifiant=lookup_widget(objet_graphique,"entry4");
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(identifiant)));


jour=lookup_widget(objet_graphique,"spinbutton6");
sprintf(t2.naissance.jour,"%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour)));
mois=lookup_widget(objet_graphique,"spinbutton7");
sprintf(t2.naissance.mois,"%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois)));
annee=lookup_widget(objet_graphique,"spinbutton8");
sprintf(t2.naissance.annee,"%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee)));


sortiem=lookup_widget(objet_graphique, "label58");

identifiant=lookup_widget(objet_graphique,"entry4");
strcpy(t2.identifiant,gtk_entry_get_text(GTK_ENTRY(identifiant)));


Nom=lookup_widget(objet_graphique,"entry14");
strcpy(t2.Nom,gtk_entry_get_text(GTK_ENTRY(Nom)));
Prenom=lookup_widget(objet_graphique,"entry15");
strcpy(t2.Prenom,gtk_entry_get_text(GTK_ENTRY(Prenom)));
Cin=lookup_widget(objet_graphique,"entry16");
strcpy(t2.Cin,gtk_entry_get_text(GTK_ENTRY(Cin)));
Sexe=lookup_widget(objet_graphique,"combobox7");
strcpy(t2.Sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Sexe)));

modifer(ch,t2);

gtk_label_set_text(GTK_LABEL(sortiem),"Modification effectuée avec succès!");


}







void
on_button6_clicked                     (GtkWidget        *objet_graphique,
                                        gpointer         user_data)
{
char 	Id[30];
GtkWidget *windowliste,*sortiem;
GtkWidget *treeview_Affichage;
GtkWidget *idr;
idr = lookup_widget (objet_graphique,"entry10");
strcpy(Id,gtk_entry_get_text(GTK_ENTRY(idr)));
sortiem=lookup_widget(objet_graphique, "label62");

windowliste=lookup_widget (objet_graphique,"windowL");
treeview_Affichage=lookup_widget (windowliste,"treeview1");
rechercher_ouv(Id,treeview_Affichage);


gtk_label_set_text(GTK_LABEL(sortiem),"Resultat(s) obtenu(s)!");

}


void
on_buttonAjoute_clicked                (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *p;
GtkWidget *windowGT,*windowA,*windowL,*err;


ouvrier t;
GtkWidget
 *identifiant,*sortiea,*Nom,*Prenom,*jour,*mois,*annee,*Cin,*Sexe,*treeview1;
jour=lookup_widget(objet_graphique,"jour");
sprintf(t.naissance.jour,"%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour)));
mois=lookup_widget(objet_graphique,"mois");
sprintf(t.naissance.mois,"%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois)));
annee=lookup_widget(objet_graphique,"spinbutton3");
sprintf(t.naissance.annee,"%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee)));

sortiea=lookup_widget(objet_graphique, "label57");



identifiant=lookup_widget(objet_graphique,"entryIdentifiant");
strcpy(t.identifiant,gtk_entry_get_text(GTK_ENTRY(identifiant)));


Nom=lookup_widget(objet_graphique,"entry11");
strcpy(t.Nom,gtk_entry_get_text(GTK_ENTRY(Nom)));
Prenom=lookup_widget(objet_graphique,"entry12");
strcpy(t.Prenom,gtk_entry_get_text(GTK_ENTRY(Prenom)));
Cin=lookup_widget(objet_graphique,"entry13");
strcpy(t.Cin,gtk_entry_get_text(GTK_ENTRY(Cin)));
Sexe=lookup_widget(objet_graphique,"combobox8");
strcpy(t.Sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Sexe)));
err=lookup_widget(objet_graphique,"label75");

if (strcmp(t.identifiant,"")==0) 
{
gtk_label_set_text(GTK_LABEL(err),"Il faut Mettre Un Identifiant");
}else {
ajouter(t);
gtk_label_set_text(GTK_LABEL(sortiea),"Ajout effectué avec succès!");
}




        //afficher(p,"ouvrier.txt");
}

void
on_buttonSupprime_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *identifiant,*sortiea;
ouvrier t;
identifiant=lookup_widget(objet_graphique,"entry1");
strcpy(t.identifiant,gtk_entry_get_text(GTK_ENTRY(identifiant)));

sortiea=lookup_widget(objet_graphique, "label60");

supprimer (t.identifiant);

gtk_label_set_text(GTK_LABEL(sortiea)," effectué avec succès!");
}

void
on_buttonTaux_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{ GtkWidget *aa ,*sortiea,*windowN;
char resultat [30];
char annee[30];
float taux ; 
sortiea=lookup_widget(objet_graphique, "label33");
windowN=lookup_widget(objet_graphique, "windowN");
aa=lookup_widget(objet_graphique,"entry17");
strcpy(annee,gtk_entry_get_text(GTK_ENTRY(aa)));
taux=taux_absc(annee);
sprintf(resultat,"%f",taux);
gtk_label_set_text(GTK_LABEL(sortiea),resultat);

}



void
on_ajoutabs_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_GT;
GtkWidget *fenetre_A;
fenetre_GT=lookup_widget (objet_graphique,"windowGT");
gtk_widget_destroy(fenetre_GT);
fenetre_A=create_gestionabsence();
gtk_widget_show(fenetre_A);
}


void
on_remplirabs_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
abscence a;

GtkWidget *identifiant,*jour,*mois,*annee,*val,*sortiea;

sortiea=lookup_widget(objet_graphique, "label63"); 
identifiant=lookup_widget(objet_graphique,"entry18");
strcpy(a.id,gtk_entry_get_text(GTK_ENTRY(identifiant)));
jour=lookup_widget(objet_graphique,"jour");
sprintf(a.jour,"%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour)));
mois=lookup_widget(objet_graphique,"mois");
sprintf(a.mois,"%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois)));
annee=lookup_widget(objet_graphique,"annee");
sprintf(a.annee,"%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee)));
val=lookup_widget(objet_graphique,"entry19");
strcpy(a.val,gtk_entry_get_text(GTK_ENTRY(val)));

remplir(a);

gtk_label_set_text(GTK_LABEL(sortiea),"Ajout effectué avec succès!");
}


void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
 GtkTreeIter iter;
   	gchar *identifiant;
        gchar *jour;
        gchar *mois;
        gchar *annee;
	gchar *val;
	
	int id;
      GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if(gtk_tree_model_get_iter(model,&iter,path))
{

gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,identifiant,1,jour,2,mois,3,annee,4,val,-1);
strcpy(id,identifiant);
}

}


void
on_afficherabs_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *p;

windowL = create_gestionabsence ();
p=lookup_widget(windowL,"treeview2");
gtk_widget_show (windowL);
afficher_abs(p,"absenteisme.txt");

}


void
on_reGT_clicked                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_GT;
GtkWidget *fenetre_L;
fenetre_L=lookup_widget (objet_graphique,"ListeDesouvriers");
gtk_widget_destroy(fenetre_L);
fenetre_GT=create_windowGT();
gtk_widget_show(fenetre_GT);
}


void
on_REaj_clicked                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *fenetre_A;
GtkWidget *fenetre_GT;
fenetre_A=lookup_widget (objet_graphique,"windowA");
gtk_widget_destroy(fenetre_A);
fenetre_GT=create_windowGT();
gtk_widget_show(fenetre_GT);
}


void
on_REL_clicked                         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_M;
GtkWidget *fenetre_GT;
fenetre_M=lookup_widget (objet_graphique,"windowM");
gtk_widget_destroy(fenetre_M);
fenetre_GT=create_windowGT();
gtk_widget_show(fenetre_GT);
}


void
on_RE_SUP_LIS_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_S;
GtkWidget *fenetre_GT;
fenetre_S=lookup_widget (objet_graphique,"windowS");
gtk_widget_destroy(fenetre_S);
fenetre_GT=create_windowGT();
gtk_widget_show(fenetre_GT);
}


void
on_RE_ABS_GT_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_abs;
GtkWidget *fenetre_GT;
fenetre_abs=lookup_widget (objet_graphique,"gestionabsence");
gtk_widget_destroy(fenetre_abs);
fenetre_GT=create_windowGT();
gtk_widget_show(fenetre_GT);
}


void
on_REABSCE_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_TAUX;
GtkWidget *fenetre_GT;
fenetre_TAUX=lookup_widget (objet_graphique,"windowS");
gtk_widget_destroy(fenetre_TAUX);
fenetre_GT=create_windowGT();
gtk_widget_show(fenetre_GT);
}


void
on_button_oui_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *identifiant;
ouvrier t;
supprimer (t.identifiant);
}


void
on_button_non_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_busupprimer_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview1,*windowliste,*windowl,*windowGT;

windowliste=lookup_widget (objet_graphique,"windowL");
treeview1=lookup_widget (windowliste,"treeview1");
supprimer (id);
afficher(treeview1,"ouvrier.txt");
windowl=lookup_widget(objet_graphique,"windowM");
gtk_widget_hide(windowl);
windowGT=lookup_widget(objet_graphique,"windowok");
windowGT=create_windowok ();
gtk_widget_show(windowGT);
}

void
on_Nonn_clicked                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_S;
GtkWidget *fenetre_GT;
fenetre_S=lookup_widget (objet_graphique,"windowS");
gtk_widget_destroy(fenetre_S);
fenetre_GT=create_windowGT();
gtk_widget_show(fenetre_GT);
}


void
on_button7_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{ GtkWidget *sortiem;
sortiem=lookup_widget(objet_graphique, "label54");
gtk_label_set_text(GTK_LABEL(sortiem),"voulez vous vraiment supprimer?");

}



void
on_button8_verif_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)

{GtkWidget *Nomm, *input1,*ouput1,*ouput2,*ouput3,*ouput4,*ouput5,*ouput6,*ouput7,*ouput8;
GtkWidget *fenetremodif;
char chnb1[30],chnb2[30],chnb3[30], Nom[30];
fenetremodif=lookup_widget(objet_graphique,"windowM");
ouvrier p2,p;
input1=lookup_widget(objet_graphique,"entry20");
strcpy(p.identifiant,gtk_entry_get_text(GTK_ENTRY(input1)));



FILE *f;
f=fopen("src/ouvrier.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %s %s \n",p2.identifiant,p2.naissance.jour,p2.naissance.mois,p2.naissance.annee,p2.Nom,p2.Prenom,p2.Sexe,p2.Cin)!=EOF)
{
if(strcmp(p.identifiant,p2.identifiant)==0)
{
ouput7=lookup_widget(objet_graphique,"label74") ;
gtk_label_set_text(GTK_LABEL(ouput7),p2.identifiant);//p2 l9dimm 

//ouput2=lookup_widget(objet_graphique,"label67") ;
sprintf(chnb1,"%s",p2.naissance.jour);
sprintf(chnb2,"%s",p2.naissance.mois);
sprintf(chnb3,"%s",p2.naissance.annee);
ouput2=lookup_widget(objet_graphique,"label67") ;
gtk_label_set_text(GTK_LABEL(ouput2),chnb1);
gtk_widget_show (ouput2);

ouput3=lookup_widget(objet_graphique,"label68") ;
gtk_label_set_text(GTK_LABEL(ouput3),chnb2);
gtk_widget_show (ouput3);
ouput8=lookup_widget(objet_graphique,"label69") ;
gtk_label_set_text(GTK_LABEL(ouput8),chnb3);
gtk_widget_show (ouput8);
ouput1=lookup_widget(objet_graphique,"label70") ;
gtk_label_set_text(GTK_LABEL(ouput1),p2.Nom);
gtk_widget_show (ouput1);
ouput6=lookup_widget(objet_graphique,"label71") ;
gtk_label_set_text(GTK_LABEL(ouput6),p2.Prenom);
gtk_widget_show (ouput6);
ouput4=lookup_widget(objet_graphique,"label72") ;
gtk_label_set_text(GTK_LABEL(ouput4),p2.Cin);
gtk_widget_show (ouput4);
ouput5=lookup_widget(objet_graphique,"label73") ;
gtk_label_set_text(GTK_LABEL(ouput5),p2.Sexe);
gtk_widget_show (ouput5);
}
}
fclose(f);



}


void
on_butto_ok_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *p;
GtkWidget *fenetre_S;
GtkWidget *fenetre_GT;
fenetre_S=lookup_widget (objet_graphique,"windowok");
gtk_widget_destroy(fenetre_S);
fenetre_GT=create_windowL ();
gtk_widget_show(fenetre_GT);
p=lookup_widget(fenetre_GT,"treeview1");
afficher(p,"ouvrier.txt");
}

