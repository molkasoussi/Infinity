#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <gtk/gtk.h>


#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "tree.h"
#include "fonction.h"
GtkTreeSelection *selection1;

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
on_buttonM_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *p;
GtkWidget *windowGT,*windowM, *treeview1;
windowGT=lookup_widget(objet_graphique,"windowGT");
gtk_widget_destroy(windowGT);
windowM=lookup_widget(objet_graphique,"windowM");
windowM=create_windowM();
gtk_widget_show(windowM);
windowL = create_windowL ();
p=lookup_widget(windowL,"treeview1");
afficher(p,"troupeaux.txt");
gtk_widget_show (windowL);
}

void
on_buttonLDT_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *p;
GtkWidget *windowGT, *windowL, *treeview1;
windowGT=lookup_widget(objet_graphique,"windowGT");
gtk_widget_destroy(windowGT);

//gtk_widget_hide (windowGT);
//gtk_widget_destroy(windowGT);
windowL = create_windowL ();
p=lookup_widget(windowL,"treeview1");
afficher(p,"troupeaux.txt");
gtk_widget_show (windowL);
}


void
on_buttonS_clicked                     (GtkWidget       *objet_graphique,
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
on_buttonNDT_clicked                   (GtkWidget       *objet_graphique,
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
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
  GtkTreeIter iter;
  GtkWidget *donnee;
   	gchar *identifiant;
        gchar *poids;
        gchar *type;
        gchar *genre;
        gchar *etat;
        gchar *jour;
        gchar *mois;
        gchar *annee;
	troupeaux t;
	char mot[20];
	int id;
      GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if(gtk_tree_model_get_iter(model,&iter,path))
{

gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,identifiant,1,poids,2,type,3,genre,4,etat,5,jour,6,mois,7,annee,-1);
donnee=identifiant;
strcpy(t.type,type);
strcpy(t.identifiant,identifiant);
strcpy(t.poids,poids);
strcpy(t.genre,genre);
strcpy(t.etat,etat);
strcpy(t.naissance.jour,jour);
strcpy(t.naissance.mois,mois);
strcpy(t.naissance.annee,annee);
}
//donnee=lookup_widget(objet,"recherche");
FILE *f=NULL;
f=fopen("donnee.txt","w");
if(f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s %s %s\n",t.identifiant,t.poids,t.type,t.genre,t.etat,t.naissance.jour
                  ,t.naissance.mois,t.naissance.annee );
}

fclose(f);
}



void
on_buttonCh_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *donnee, *windowL, *treeview1;

char ty[20];
troupeaux *t=NULL;
t=(troupeaux *)malloc(sizeof(troupeaux));
donnee=lookup_widget(objet_graphique,"entry10");
strcpy(ty,gtk_entry_get_text(GTK_ENTRY(donnee)));

chercher(ty,t);

{
windowL=lookup_widget(objet_graphique,"windowL");
gtk_widget_destroy(windowL);
windowL=create_windowL();
gtk_widget_show(windowL);
treeview1=lookup_widget(windowL,"treeview1");
chercher1(treeview1,ty);
}
}


/*char identifiant[10];
int test;
char recherche[10];
troupeaux t;
id=lookup_widget(objet_graphique,"entry10");
resultat=lookup_widget(objet_graphique,"labelr");
strcpy(identifiant,gtk_entry_get_text(GTK_ENTRY(id)));
test=chercher(identifiant);
if(test==0)
strcpy(recherche,"n existe pas");
else
strcpy(recherche,"existant");
gtk_label_set_text(GTK_LABEL(resultat),recherche);
}*/


void
on_buttonAjoute_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *p;
GtkWidget *windowGT,*windowA,*windowL;
troupeaux t;
GtkWidget
 *identifiant,*poids,*type,*jour,*mois,*annee,*etat,*genre,*treeview1,*identifianto, *poidso,*typeo,*etato,*genreo;
jour=lookup_widget(objet_graphique,"jour");
sprintf(t.naissance.jour,"%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour)));
mois=lookup_widget(objet_graphique,"mois");
sprintf(t.naissance.mois,"%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois)));
annee=lookup_widget(objet_graphique,"spinbutton3");
sprintf(t.naissance.annee,"%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee)));
identifiant=lookup_widget(objet_graphique,"entryIdentifiant");
//strcpy(t.identifiant,gtk_entry_get_text(GTK_ENTRY(identifiant)));
poids=lookup_widget(objet_graphique,"entryPoids");
//strcpy(t.poids,gtk_entry_get_text(GTK_ENTRY(poids)));
type=lookup_widget(objet_graphique,"entryType");
//strcpy(t.type,gtk_entry_get_text(GTK_ENTRY(type)));
etat=lookup_widget(objet_graphique,"combobox3");
genre=lookup_widget(objet_graphique,"genre");
//strcpy(t.genre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(genre)));
//strcpy(t.etat,gtk_combo_box_get_active_text(GTK_COMBO_BOX(etat)));


//CHAMP_OBLIGATOIRE
identifianto=lookup_widget(objet_graphique,"identifianto");
poidso=lookup_widget(objet_graphique,"poidso");
typeo=lookup_widget(objet_graphique,"typeo");
etato=lookup_widget(objet_graphique,"etato");
genreo=lookup_widget(objet_graphique,"genreo");
if(
(strcmp(gtk_entry_get_text(GTK_ENTRY(poids)),"") != 0) && (strcmp(gtk_entry_get_text(GTK_ENTRY(identifiant)),"") != 0) && (gtk_combo_box_get_active (GTK_COMBO_BOX(genre))!= -1) && (gtk_combo_box_get_active (GTK_COMBO_BOX(etat)) != -1) && (strcmp(gtk_entry_get_text(GTK_ENTRY(type)),"")!= 0))
{
strcpy(t.poids,gtk_entry_get_text(GTK_ENTRY(poids)));
strcpy(t.identifiant,gtk_entry_get_text(GTK_ENTRY(identifiant)));
strcpy(t.genre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(genre)));
strcpy(t.etat,gtk_combo_box_get_active_text(GTK_COMBO_BOX(etat)));
strcpy(t.type,gtk_entry_get_text(GTK_ENTRY(type)));
ajouter(t);
windowA=lookup_widget(objet_graphique,"windowA");
gtk_widget_hide(windowA);
windowGT=lookup_widget(objet_graphique,"windowGT");
windowGT=create_windowGT();
gtk_widget_show(windowGT);
 afficher(p,"troupeaux.txt");
}
else

{
 if(strcmp(gtk_entry_get_text(GTK_ENTRY(identifiant)),"") == 0)
{
gtk_label_set_text(GTK_LABEL(identifianto),"* ce champ est obligatoire");
}
if(strcmp(gtk_entry_get_text(GTK_ENTRY(poids)),"") == 0)
{
gtk_label_set_text(GTK_LABEL(poidso),"* ce champ est obligatoire ");
}
if(strcmp(gtk_entry_get_text(GTK_ENTRY(type)),"") == 0)
{
gtk_label_set_text(GTK_LABEL(typeo),"* ce champ est obligatoire");
}
if(gtk_combo_box_get_active (GTK_COMBO_BOX(genre)) == -1)
{
gtk_label_set_text(GTK_LABEL(genreo),"* ce champ est obligatoire");
}
if(gtk_combo_box_get_active (GTK_COMBO_BOX(etat)) == -1)
{
gtk_label_set_text(GTK_LABEL(etato),"* ce champ est obligatoire");
}
}


/*ajouter(t);
windowA=lookup_widget(objet_graphique,"windowA");
gtk_widget_hide(windowA);
windowGT=lookup_widget(objet_graphique,"windowGT");
windowGT=create_windowGT();
gtk_widget_show(windowGT);*/
//afficher(p,"troupeaux.txt");
}




void
on_buttonModifier_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{


GtkWidget *p;
GtkWidget *windowGT,*windowM,*windowL;
troupeaux t2;
char ch[10];
troupeaux *t;
t=(troupeaux *)malloc(sizeof(troupeaux));
GtkWidget 
*identifiant,*poids,*type,*jour,*mois,*annee,*etat,*genre,*treeview1,*id;

identifiant=lookup_widget(objet_graphique,"identifiant");
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(identifiant)));
//chercher(ch,t);

jour=lookup_widget(objet_graphique,"spinbutton4");
sprintf(t2.naissance.jour,"%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour)));
mois=lookup_widget(objet_graphique,"spinbutton5");
sprintf(t2.naissance.mois,"%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois)));
annee=lookup_widget(objet_graphique,"spinbutton6");
sprintf(t2.naissance.annee,"%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee)));
id=lookup_widget(objet_graphique,"entryId");
strcpy(t2.identifiant,gtk_entry_get_text(GTK_ENTRY(id)));
poids=lookup_widget(objet_graphique,"poids");
strcpy(t2.poids,gtk_entry_get_text(GTK_ENTRY(poids)));
type=lookup_widget(objet_graphique,"type");
strcpy(t2.type,gtk_entry_get_text(GTK_ENTRY(type)));
etat=lookup_widget(objet_graphique,"combobox4");
genre=lookup_widget(objet_graphique,"combobox2");
strcpy(t2.genre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(genre)));
strcpy(t2.etat,gtk_combo_box_get_active_text(GTK_COMBO_BOX(etat)));
modifer(ch,t2);
windowM=lookup_widget(objet_graphique,"windowM");
gtk_widget_hide(windowM);
windowGT=lookup_widget(objet_graphique,"windowGT");
windowGT=create_windowGT();
gtk_widget_show(windowGT);
//treeview1=lookup_widget(windowL,"treeview1");

//afficher(treeview1);

        


        afficher(p,"troupeaux.txt");
   

}





void
on_buttonNombre_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *type, *nombre;
int nb;
char ch[10];
troupeaux t;
type=lookup_widget(objet_graphique,"entry11");
nombre=lookup_widget(objet_graphique,"label30");
strcpy(t.type,gtk_entry_get_text(GTK_ENTRY(type)));

nb=count(t.type);
sprintf(ch,"%d",nb);

gtk_label_set_text(GTK_LABEL(nombre),ch);








}




void
on_buttonSupprime_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *identifiant;
troupeaux t;
identifiant=lookup_widget(objet_graphique,"entry1");
strcpy(t.identifiant,gtk_entry_get_text(GTK_ENTRY(identifiant)));
supprimer (t.identifiant);
windowS=lookup_widget(objet_graphique,"windowS");
gtk_widget_hide(windowS);
windowGT=lookup_widget(objet_graphique,"windowGT");
windowGT=create_windowGT();
gtk_widget_show(windowGT);



    
}


void
on_modifier1_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char idtf[10];
char ch[10];
troupeaux *t;
t=(troupeaux *)malloc(sizeof(troupeaux));
GtkWidget *identifiant,*poids,*type,*jour,*mois,*annee,*etat,*genre,*treeview1,*id;
identifiant=lookup_widget(objet_graphique,"identifiant");
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(identifiant)));
int x=0;
x=0;
x=chercher_id(ch,t);
if(x==1)
{jour=lookup_widget(objet_graphique,"spinbutton4");
    mois=lookup_widget(objet_graphique,"spinbutton5");
    annee=lookup_widget(objet_graphique,"spinbutton6");
    id=lookup_widget(objet_graphique,"entryId");
    type=lookup_widget(objet_graphique,"type");
    poids=lookup_widget(objet_graphique,"poids");
    etat=lookup_widget(objet_graphique,"combobox4");
    genre=lookup_widget(objet_graphique,"combobox2");

    gtk_entry_set_text(GTK_ENTRY(id),t->identifiant);
    gtk_entry_set_text(GTK_ENTRY(type),t->type);
    gtk_entry_set_text(GTK_ENTRY(identifiant),t->identifiant);
    gtk_entry_set_text(GTK_ENTRY(poids),t->poids);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour),atoi(t->naissance.jour));
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois),atoi(t->naissance.mois));
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee),atoi(t->naissance.annee));
   // if(strcmp("Male",t->genre) ==0)
        //gtk_combo_box_set_active(GTK_COMBO_BOX(genre),1);
   // if(strcmp("Female",t->genre) ==0)
       // gtk_combo_box_set_active(GTK_COMBO_BOX(genre),2);
    //if(strcmp("Malade",t->etat)==0)
        gtk_combo_box_set_active(GTK_COMBO_BOX(etat),1);

    //if(strcmp("Vaccine",t->etat) ==0)
        gtk_combo_box_set_active(GTK_COMBO_BOX(etat),2);
    //if(strcmp("Decces",t->etat) ==0)
        gtk_combo_box_set_active(GTK_COMBO_BOX(etat),3);




}


//gtk_combo_box_set_active(GTK_COMBO_BOX(etat),t->etat);
//gtk_combo_box_set_active(GTK_COMBO_BOX(genre),t->genre);
/*
jour=lookup_widget(objet_graphique,"spinbutton4");
sprintf(t->naissance.jour,"%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour)));
mois=lookup_widget(objet_graphique,"spinbutton5");
sprintf(t->naissance.mois,"%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois)));
annee=lookup_widget(objet_graphique,"spinbutton6");
sprintf(t->naissance.annee,"%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee)));

*/



}


void
on_Nombree_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *type, *nombre;
int nb;
char ch[10];
troupeaux t;
type=lookup_widget(objet_graphique,"entry11");
nombre=lookup_widget(objet_graphique,"label30");
strcpy(t.type,gtk_entry_get_text(GTK_ENTRY(type)));

nb=count(t.type);
sprintf(ch,"%d",nb);

gtk_label_set_text(GTK_LABEL(nombre),ch);






}


void
on_R1_clicked                          (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowGT,*windowL;
windowL=lookup_widget(objet_graphique,"windowL");
gtk_widget_destroy(windowL);
windowGT=lookup_widget(objet_graphique,"windowGT");
windowGT=create_windowGT();
gtk_widget_show(windowGT);
}


void
on_R2_clicked                          (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowGT,*windowA;
windowA=lookup_widget(objet_graphique,"windowA");
gtk_widget_destroy(windowA);
windowGT=lookup_widget(objet_graphique,"windowGT");
windowGT=create_windowGT();
gtk_widget_show(windowGT);
}


void
on_R3_clicked                          (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowGT,*windowM;
windowM=lookup_widget(objet_graphique,"windowM");
gtk_widget_destroy(windowM);
windowGT=lookup_widget(objet_graphique,"windowGT");
windowGT=create_windowGT();
gtk_widget_show(windowGT);
}


void
on_R4_clicked                          (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowGT,*windowS;
windowS=lookup_widget(objet_graphique,"windowS");
gtk_widget_destroy(windowS);
windowGT=lookup_widget(objet_graphique,"windowGT");
windowGT=create_windowGT();
gtk_widget_show(windowGT);
}

