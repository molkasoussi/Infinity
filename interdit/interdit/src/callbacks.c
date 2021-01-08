#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include "tree.h"
#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "capteur.h"

void
on_ouvrier_ajouter_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_afficher_ajouter_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *esp_ajou,*esp_aff,*treeview1;

esp_ajou=lookup_widget(objet,"esp_ajou");
gtk_widget_destroy(esp_ajou);
esp_aff=lookup_widget(objet,"esp_aff");
esp_aff=create_esp_aff();
gtk_widget_show(esp_aff);
treeview1=lookup_widget(esp_ajou,"treeview1");
afficher_capteur(treeview1);


}


void
on_sedeconnecter_ajouter_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_calendrier_ajouter_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_troupeaux_ajouter_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_equipement_ajouter_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_clients_ajouter_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_modfier_ajouter_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *esp_ajou,*esp_mod;

esp_ajou=lookup_widget(objet,"esp_ajou");
gtk_widget_destroy(esp_ajou);
esp_mod=lookup_widget(objet,"esp_mod");
esp_mod=create_esp_mod();
gtk_widget_show(esp_mod);
}


void
on_supprimer_ajouter_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *esp_ajou,*esp_supp;

esp_ajou=lookup_widget(objet,"esp_ajou");
gtk_widget_destroy(esp_ajou);
esp_supp=lookup_widget(objet,"esp_supp");
esp_supp=create_esp_supp();
gtk_widget_show(esp_supp);
}


void
on_ajouter_ajouter_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)

{
/////////////////////////////
GtkWidget
 *idtf,*etat,*type,*jour,*mois,*annee,*emplacement,*marque;
/*
GtkWidget *out1;
GtkWidget *out2;
GtkWidget *out3;
GtkWidget *out4;
*/

capteur t;

jour=lookup_widget(objet_graphique,"spinbutton1");
t.date_ajou.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));

mois=lookup_widget(objet_graphique,"spinbutton2");
t.date_ajou.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));

annee=lookup_widget(objet_graphique,"spinbutton3");
t.date_ajou.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

idtf=lookup_widget(objet_graphique,"entry1");
emplacement=lookup_widget(objet_graphique,"entry7");
type=lookup_widget(objet_graphique,"combobox10");
etat=lookup_widget(objet_graphique,"combobox8");
marque=lookup_widget(objet_graphique,"combobox14");
/*
out1=lookup_widget(objet_graphique,"out1");
out2=lookup_widget(objet_graphique,"out2");
out3=lookup_widget(objet_graphique,"out3");
out4=lookup_widget(objet_graphique,"out4");*/

t.idtf=atoi(gtk_entry_get_text(GTK_ENTRY(idtf)));
strcpy(t.emplacement,gtk_entry_get_text(GTK_ENTRY(emplacement)));
if(strcmp("tempurature",gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)))==0)
t.type=1;
else
t.type=0;
if(strcmp("nv",gtk_combo_box_get_active_text(GTK_COMBO_BOX(etat)))==0)
t.etat=1;
else
t.etat=0;
/////////////////////////////////////////////////
{
if(strcmp("LINDY",gtk_combo_box_get_active_text(GTK_COMBO_BOX(marque)))==0)
t.marque=1;
else
t.marque=2;
}
ajout_capteur(t);

}


void
on_afficher_modifier_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *esp_aff,*esp_mod,*treeview1;

esp_mod=lookup_widget(objet,"esp_mod");
gtk_widget_destroy(esp_mod);
esp_aff=lookup_widget(objet,"esp_aff");
esp_aff=create_esp_aff();
gtk_widget_show(esp_aff);
treeview1=lookup_widget(esp_aff,"treeview1");
  afficher_capteur(treeview1);
}


void
on_clients_modifier_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_troupeaux_modifier_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_calendrier_modifier_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_sedeconnecter_modifier_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ajouter_modifier_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *esp_ajou,*esp_mod;

esp_mod=lookup_widget(objet,"esp_mod");
gtk_widget_destroy(esp_mod);
esp_ajou=lookup_widget(objet,"esp_ajou");
esp_ajou=create_esp_ajou();
gtk_widget_show(esp_ajou);
}


void
on_ouvrier_modifier_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_equipement_modifier_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_supprimer_modifier_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *esp_supp,*esp_mod;

esp_mod=lookup_widget(objet,"esp_mod");
gtk_widget_destroy(esp_mod);
esp_supp=lookup_widget(objet,"esp_supp");
esp_supp=create_esp_supp();
gtk_widget_show(esp_supp);
}


void
on_modifier1_modifier_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget
 *idtf,*etat,*type,*jour,*mois,*annee,*emplacement;
int id;
capteur t,t2;

jour=lookup_widget(objet_graphique,"spinbutton4");
t.date_ajou.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));

mois=lookup_widget(objet_graphique,"spinbutton5");
t.date_ajou.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));

annee=lookup_widget(objet_graphique,"spinbutton6");
t.date_ajou.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

idtf=lookup_widget(objet_graphique,"entry2");
t.idtf=atoi(gtk_entry_get_text(GTK_ENTRY(idtf)));
emplacement=lookup_widget(objet_graphique,"entry8");
strcpy(t.emplacement,gtk_entry_get_text(GTK_ENTRY(emplacement)));



type=lookup_widget(objet_graphique,"combobox11");
etat=lookup_widget(objet_graphique,"combobox13");

if(strcmp("tempurature",gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)))==0)
t.type=1;
else
t.type=0;
if(strcmp("nv",gtk_combo_box_get_active_text(GTK_COMBO_BOX(etat)))==0)
t.etat=1;
else
t.etat=0;
t2=t;
modifier_capteur(t.idtf,t);
/////////////////annuléé//////////

GtkWidget *esp_mod;
esp_mod=lookup_widget(objet_graphique,"esp_mod");
gtk_widget_destroy(esp_mod);
esp_mod=create_esp_mod();
gtk_widget_show(esp_mod);
}


void
on_ouvirer_afficher_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_equipement_afficher_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_clients_afficher_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_troupeaux_afficher_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_calendrier_afficher_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ajouter_afficher_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *esp_aff,*esp_ajou;

esp_aff=lookup_widget(objet,"esp_aff");
gtk_widget_destroy(esp_aff);
esp_ajou=lookup_widget(objet,"esp_ajou");
esp_ajou=create_esp_ajou();
gtk_widget_show(esp_ajou);
}


void
on_modfier_afficher_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *esp_aff,*esp_mod;

esp_aff=lookup_widget(objet,"esp_aff");
gtk_widget_destroy(esp_aff);
esp_mod=lookup_widget(objet,"esp_mod");
esp_mod=create_esp_mod();
gtk_widget_show(esp_mod);
}


void
on_sedeconnecter_afficher_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button5_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *donnee,*esp_aff,*treeview1;
int idtf;
capteur *t=NULL;
t=(capteur *)malloc(sizeof(capteur));
donnee=lookup_widget(objet,"entry6");
idtf=atoi(gtk_entry_get_text(GTK_ENTRY(donnee)));
cherche_id(idtf,t);
//if(t!=NULL)
{
esp_aff=lookup_widget(objet,"esp_aff");
gtk_widget_destroy(esp_aff);
esp_aff=create_esp_aff();
gtk_widget_show(esp_aff);
treeview1=lookup_widget(esp_aff,"treeview1");
rechercher_capteur(treeview1 ,t->idtf);
}
}

void
on_actualiser_afficher_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview1,*esp_aff;
esp_aff=lookup_widget(objet,"esp_aff");
gtk_widget_destroy(esp_aff);
esp_aff=create_esp_aff();
gtk_widget_show(esp_aff);
treeview1=lookup_widget(esp_aff,"treeview1");
afficher_capteur(treeview1);
}


void
on_supprimer_afficher_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *esp_aff,*esp_supp;
esp_aff=lookup_widget(objet,"esp_aff");
gtk_widget_destroy(esp_aff);
esp_supp=lookup_widget(objet,"esp_supp");
esp_supp=create_esp_supp();
gtk_widget_show(esp_supp);

}


void
on_ouvrier_supprimer_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_equipement_supprimer_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_clients_supprimer_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_troupeaux_supprimer_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_calendrier_supprimer_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ajouter_supprimer_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *esp_ajou,*esp_supp;

esp_supp=lookup_widget(objet,"esp_supp");
gtk_widget_destroy(esp_supp);
esp_ajou=lookup_widget(objet,"esp_ajou");
esp_ajou=create_esp_ajou();
gtk_widget_show(esp_ajou);
}


void on_modfier_supprimer_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *esp_mod,*esp_supp;

esp_supp=lookup_widget(objet,"esp_supp");
gtk_widget_destroy(esp_supp);
esp_mod=lookup_widget(objet,"esp_mod");
esp_mod=create_esp_mod();
gtk_widget_show(esp_mod);
}


void on_afficher_supprimer_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *esp_aff,*esp_supp,*treeview1;

esp_supp=lookup_widget(objet,"esp_supp");
gtk_widget_destroy(esp_supp);
esp_aff=lookup_widget(objet,"esp_aff");
esp_aff=create_esp_aff();
gtk_widget_show(esp_aff);
treeview1=lookup_widget(esp_aff,"treeview1");
  afficher_capteur(treeview1);
}


void on_supprimer1_supprimer_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)

{
GtkWidget *donnee;
int id;
donnee=lookup_widget(objet,"entry4");
id=atoi(gtk_entry_get_text(GTK_ENTRY(donnee)));
supprimer_capteur(id);
/////////annulée/////////////
GtkWidget *esp_supp;
esp_supp=lookup_widget(objet,"esp_supp");
gtk_widget_destroy(esp_supp);
esp_supp=create_esp_supp();
gtk_widget_show(esp_supp);

}


void on_sedeconnecter_supprimer_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button8_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button12_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button13_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}

