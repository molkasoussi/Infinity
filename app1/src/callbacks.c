#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"file.h"
int z;
char idsp[20];

void
on_button1_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre1;
GtkWidget *fenetre2;
GtkWidget *treeview1;


fenetre1=lookup_widget(objet,"Step1");
gtk_widget_destroy(fenetre1);
fenetre2=create_Step2();
gtk_widget_show(fenetre2);
treeview1=lookup_widget(fenetre2,"treeview1");
afficher_clients(treeview1);
}


void
on_button2_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre1;
GtkWidget *fenetre3;

fenetre1=lookup_widget(objet,"Step1");
gtk_widget_destroy(fenetre1);
fenetre3=create_Step3();
gtk_widget_show(fenetre3);
}


void
on_button4_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre1;
GtkWidget *fenetre5;

fenetre1=lookup_widget(objet,"Step1");
gtk_widget_destroy(fenetre1);
fenetre5=create_Step5();
gtk_widget_show(fenetre5);
}


void
on_button3_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre1;
GtkWidget *fenetre4;

fenetre1=lookup_widget(objet,"Step1");
gtk_widget_destroy(fenetre1);
fenetre4=create_Step4();
gtk_widget_show(fenetre4);
}


void
on_button5_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* id;
	gchar* nom;
	gchar* prenom;
	gchar* email;
	gchar* mdp;
	gchar* jour_naissance;
	gchar* mois_naissance;
	gchar* annee_naissance;
	client c;
	
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model, &iter, path))
	{
		gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &id, 1, &nom, 2,&prenom,3,&email, 4,&mdp, 5,&jour_naissance, 6,&mois_naissance, 7,&annee_naissance,-1);
		strcpy(c.id,id);
		strcpy(c.nom,nom);
		strcpy(c.prenom,prenom);
		strcpy(c.mail,email);
		strcpy(c.mdp,mdp);
		c.date_naissance.jour=jour_naissance;
		c.date_naissance.mois=mois_naissance;
		c.date_naissance.annee=annee_naissance;

		supprimer_tree(c);
		afficher_clients(treeview);
		
}
}


void
on_button9_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre2;
GtkWidget *treeviewrech;
GtkWidget *id,*msg;
char idrech[20];

fenetre2=lookup_widget(objet,"Step2");
treeviewrech=lookup_widget(objet,"treeview1");
id=lookup_widget(objet,"entry7");
msg=lookup_widget(objet,"label50");

strcpy(idrech,gtk_entry_get_text(GTK_ENTRY(id)));
rechercher_client(idrech,treeviewrech);

gtk_label_set_text(GTK_LABEL(msg),"Resultat(s) obtenu(s)!");

}


void
on_buttonSupp_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Step2 ;
GtkWidget *id;
char idsupp[20];

id=lookup_widget(objet,"entry7");
strcpy(idsupp,gtk_entry_get_text(GTK_ENTRY(id)));
supprimer_id(idsupp);
}


void
on_button6_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Step2 ;
GtkWidget *Step1 ;
Step2=lookup_widget(objet,"Step2");
gtk_widget_destroy(Step2);
Step1=lookup_widget(objet,"Step1");
Step1=create_Step1();
gtk_widget_show(Step1);
}


void
on_button7_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
client c ; 

GtkWidget *nom,*prenom,*mail,*id,*mdp,*jour,*mois,*annee,*treeview1,*msg;
GtkWidget *Step3,*Step1;
int v;
char identifiant[20];

Step3=lookup_widget(objet,"Step3");
Step1=lookup_widget(objet,"Step1");
msg=lookup_widget(objet,"label52");
nom=lookup_widget(objet,"entry1");
strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
prenom=lookup_widget(objet,"entry2");
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
mail=lookup_widget(objet,"entry3");
strcpy(c.mail,gtk_entry_get_text(GTK_ENTRY(mail)));
id=lookup_widget(objet,"entry4");
strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(id)));
mdp=lookup_widget(objet,"entry5");
strcpy(c.mdp,gtk_entry_get_text(GTK_ENTRY(mdp)));
jour=lookup_widget(objet,"spinbutton1");
c.date_naissance.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
mois=lookup_widget(objet,"spinbutton2");
c.date_naissance.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
annee=lookup_widget(objet,"spinbutton3");
c.date_naissance.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

strcpy(identifiant,gtk_entry_get_text(GTK_ENTRY(id)));
v=verif_client(identifiant);
if(v==1)
{
gtk_widget_show (msg);
}
else
{
ajouter_client(c);
gtk_widget_hide(Step3);
Step1=create_Step1();
gtk_widget_show(Step1);
}


}


void
on_buttonRetour_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Step3 ;
GtkWidget *Step1 ;
Step3=lookup_widget(objet,"Step3");
gtk_widget_destroy(Step3);
Step1=lookup_widget(objet,"Step1");
Step1=create_Step1();
gtk_widget_show(Step1);
}


void
on_button11_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Step4 ;
GtkWidget *Step1 ;
Step4=lookup_widget(objet,"Step4");
gtk_widget_destroy(Step4);
Step1=lookup_widget(objet,"Step1");
Step1=create_Step1();
gtk_widget_show(Step1);
}


void
on_buttonV_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Step4;
GtkWidget *input1,*nom,*prenom,*mail,*id,*mdp;
     char nom1[50];
     char prenom1[50];
     char mail1[50];
     char id1[20];
     char mdp1[50];
     char idv[20];
int v;
FILE *f;
client c2;
Step4=lookup_widget(objet,"Step4");
input1=lookup_widget(objet,"entry8");
id=lookup_widget(objet,"entry_nom") ;
nom=lookup_widget(objet,"entryprenom");
prenom=lookup_widget(objet,"entry12");
mail=lookup_widget(objet,"entry14");
mdp=lookup_widget(objet,"entry13");

strcpy(idv,gtk_entry_get_text(GTK_ENTRY(input1)));
v=verif_client(input1);
if(v==1)
{
f=fopen("clients.txt","r");
while(fscanf(f,"%s %s %s %s %s %d %d %d  \n",c2.id,c2.nom,c2.prenom,c2.mail,c2.mdp,&c2.date_naissance.jour,&c2.date_naissance.mois,&c2.date_naissance.annee)!=EOF)
{
if(strcmp(c2.id,idv)==0)
{
strcpy(id1,c2.id);
strcpy(nom1,c2.nom);
strcpy(prenom1,c2.prenom);
strcpy(mail1,c2.mail);
strcpy(mdp1,c2.mdp);
}
}
fclose(f);
gtk_entry_set_text(id,id1);
gtk_entry_set_text(nom,nom1);
gtk_entry_set_text(prenom,prenom1);
gtk_entry_set_text(mail,mail1);
gtk_entry_set_text(mdp,mdp1);
}
}


void
on_button14_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
client c ; 

GtkWidget *nom,*prenom,*mail,*id,*mdp,*jour,*mois,*annee,*treeview1;
GtkWidget *Step4,*Step1;
GtkWidget *msg;


Step4=lookup_widget(objet,"Step4");
Step1=lookup_widget(objet,"Step1");
nom=lookup_widget(objet,"entry_nom");
strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
prenom=lookup_widget(objet,"entryprenom");
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
mail=lookup_widget(objet,"entry12");
strcpy(c.mail,gtk_entry_get_text(GTK_ENTRY(mail)));
id=lookup_widget(objet,"entry14");
strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(id)));
mdp=lookup_widget(objet,"entry13");
strcpy(c.mdp,gtk_entry_get_text(GTK_ENTRY(mdp)));
jour=lookup_widget(objet,"spinbutton4");
c.date_naissance.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
mois=lookup_widget(objet,"spinbutton5");
c.date_naissance.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
annee=lookup_widget(objet,"spinbutton6");
c.date_naissance.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

msg=lookup_widget(objet,"label49");

modifier_client(c);

gtk_label_set_text(GTK_LABEL(msg),"Modification effectuée avec succès!");
}


void
on_button12_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *id;
GtkWidget *Step5 ;
Step5=lookup_widget(objet,"Step5");
id=lookup_widget(objet,"entry9");
strcpy(idsp,gtk_entry_get_text(GTK_ENTRY(id)));
z=1;
}


void
on_button13_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Step5 ;
GtkWidget *Step1 ;
Step5=lookup_widget(objet,"Step5");
gtk_widget_destroy(Step5);
Step1=lookup_widget(objet,"Step1");
Step1=create_Step1();
gtk_widget_show(Step1);
}


void
on_button19_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Step5 ;
GtkWidget *Step6 ;
Step5=lookup_widget(objet,"Step5");
if(z==1)
{
supprimer_id(idsp);
gtk_widget_destroy(Step5);
Step6=lookup_widget(objet,"Step6");
Step6=create_Step6();
gtk_widget_show(Step6);
}
}


void
on_button18_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Step5 ;
GtkWidget *Step1 ;
Step5=lookup_widget(objet,"Step5");
gtk_widget_destroy(Step5);
Step1=lookup_widget(objet,"Step1");
Step1=create_Step1();
gtk_widget_show(Step1);
}


void
on_button20_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Step6 ;
GtkWidget *Step1 ;
Step6=lookup_widget(objet,"Step6");
gtk_widget_destroy(Step6);
Step1=lookup_widget(objet,"Step1");
Step1=create_Step1();
gtk_widget_show(Step1);
}


void
on_verifier_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Nomm, *input1,*ouput1,*ouput2,*ouput3,*ouput4,*ouput5,*ouput6,*ouput7,*ouput8;
GtkWidget *fenetremodif;
char chnb1[30],chnb2[30],chnb3[30], Nom[30];
fenetremodif=lookup_widget(objet,"step4");
client p2,p;
input1=lookup_widget(objet,"entry8");
strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(input1)));



FILE *f;
f=fopen("clients.txt","r");
while(fscanf(f,"%s %s %s %s %s %d %d %d  \n",p2.id,p2.nom,p2.prenom,p2.mail,p2.mdp,&p2.date_naissance.jour,&p2.date_naissance.mois,&p2.date_naissance.annee)!=EOF)
{
if(strcmp(p.id,p2.id)==0)
{
ouput7=lookup_widget(objet,"label53") ;
gtk_label_set_text(GTK_LABEL(ouput7),p2.id); 

//ouput2=lookup_widget(objet_graphique,"label67") ;
sprintf(chnb1,"%d",p2.date_naissance.jour);
sprintf(chnb2,"%d",p2.date_naissance.mois);
sprintf(chnb3,"%d",p2.date_naissance.annee);
ouput2=lookup_widget(objet,"label59") ;
gtk_label_set_text(GTK_LABEL(ouput2),chnb1);
gtk_widget_show (ouput2);

ouput3=lookup_widget(objet,"label60") ;
gtk_label_set_text(GTK_LABEL(ouput3),chnb2);
gtk_widget_show (ouput3);
ouput8=lookup_widget(objet,"label61") ;
gtk_label_set_text(GTK_LABEL(ouput8),chnb3);
gtk_widget_show (ouput8);
ouput1=lookup_widget(objet,"label55") ;
gtk_label_set_text(GTK_LABEL(ouput1),p2.nom);
gtk_widget_show (ouput1);
ouput6=lookup_widget(objet,"label56") ;
gtk_label_set_text(GTK_LABEL(ouput6),p2.prenom);
gtk_widget_show (ouput6);
ouput4=lookup_widget(objet,"label57") ;
gtk_label_set_text(GTK_LABEL(ouput4),p2.mail);
gtk_widget_show (ouput4);
ouput5=lookup_widget(objet,"label58") ;
gtk_label_set_text(GTK_LABEL(ouput5),p2.mdp);
gtk_widget_show (ouput5);
}
}
fclose(f);


}

