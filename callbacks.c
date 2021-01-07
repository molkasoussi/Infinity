#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "materiel.h"

int x=0;// bt radio
int t[2]={0,0};// check
void
on_bwretour1_clicked                   (GtkWidget      *widget,
                                        gpointer         user_data)
{
GtkWidget *windowgestion0, *windowajouter,  *treeview1;
windowajouter=lookup_widget(widget,"windowbwajouter");
gtk_widget_hide(windowajouter);
windowgestion0=create_bwgestion0();
gtk_widget_show (windowgestion0);
}


void
on_bwajouter0_clicked                 (GtkWidget      *widget,
                                        gpointer         user_data)
{
GtkWidget *windowgestion0, *windowajouter,  *treeview1;
windowgestion0=lookup_widget(widget,"windowbwgestion0");
gtk_widget_hide(windowgestion0);
windowajouter=create_bwajouter();
gtk_widget_show (windowajouter);
}


void
on_bwsuprimer0_clicked                 (GtkWidget      *widget,
                                        gpointer         user_data)
{
GtkWidget *windowgestion0, *windowsuprimer0,  *treeview1;
windowgestion0=lookup_widget(widget,"windowbwgestion0");
gtk_widget_hide(windowgestion0);
windowsuprimer0=create_bwsuprimer3();
gtk_widget_show (windowsuprimer0);
}


void
on_bwconsulter0_clicked                (GtkWidget      *widget,
                                        gpointer         user_data)
{
GtkWidget *windowbwgestion0, *windowbwconsulter2,  *treeview1;
windowbwgestion0=lookup_widget(widget,"windowbwgestion0");
gtk_widget_hide(windowbwgestion0);
windowbwconsulter2=create_bwconsulter2();
gtk_widget_show (windowbwconsulter2);

treeview1=lookup_widget(windowbwconsulter2, "treeview1" );
consulter (treeview1);

}


void
on_bwmodifier0_clicked                 (GtkWidget      *widget,
                                        gpointer         user_data)
{
GtkWidget *windowbwgestion0, *windowbwmodifier0,  *treeview1;
windowbwgestion0=lookup_widget(widget,"windowbwgestion0");
gtk_widget_hide(windowbwgestion0);
windowbwmodifier0=create_bwmodifier0();
gtk_widget_show (windowbwmodifier0);
}




void
on_bwretour2_clicked                   (GtkWidget      *widget,
                                        gpointer         user_data)
{
GtkWidget *windowbwgestion0, *windowbwconsulter2;
windowbwconsulter2=lookup_widget(widget,"windowbwconsulter2");
gtk_widget_hide(windowbwconsulter2);
windowbwgestion0=create_bwgestion0();
gtk_widget_show (windowbwgestion0);
}


void
on_bwrecherche2_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowbwconsulter2,  *treeview1;
GtkWidget *output1, *output,*in1;
char id[10];
materiel m;
char nom[20];
char texte1 [200] ="votre recherche ";
char texte2 [200] ="";
char texte3 [200]="";
char texte4 [200]="";
char texte5[200]="";
char texte6[200]="";
int b=0;
in1=lookup_widget(button, "entry6");
strcpy (id, gtk_entry_get_text (GTK_ENTRY(in1)));
FILE*f;
f=fopen("materiel.txt","r");
if (x==1){
strcat (texte2,"le id ");
sprintf (texte4, "%s est par %s ",texte1,texte2);
output =lookup_widget(button, ("label45"));
gtk_label_set_text(GTK_LABEL(output),texte4);
if (f!= NULL)
{ 
while (fscanf (f,"%s %s %s %s %d %d %d %s",m.nom,m.ref,m.annee,m.fourniseur,&m.date.j,&m.date.mo,&m.date.a,m.type)!=EOF)
{ if (strcmp (id,m.ref)==0){
sprintf (texte5,"le matériel est existe");
sprintf(texte6," le nom  de matériel est : %s, l'annee de garentie est : %s,\n le fournisseur est : %s, le date est : %d/%d/%d, \n et son type est : %s \n",m.nom,m.annee,m.fourniseur,m.date.j,m.date.mo,m.date.a,m.type);}
else
sprintf (texte4,"non");
}
output=lookup_widget(button,("label14"));
gtk_label_set_text(GTK_LABEL(output),texte5);
output1=lookup_widget(button,("label27"));
gtk_label_set_text(GTK_LABEL(output1),texte6);
fclose (f);  }}
if (x==2){
strcat (texte3,"le nom ");
sprintf (texte4, "%s est par %s ",texte1,texte3);
output =lookup_widget(button, ("label45"));
gtk_label_set_text(GTK_LABEL(output),texte4);

if (f!= NULL)
{ 
while (fscanf (f,"%s %s %s %s %d %d %d %s",m.nom,m.ref,m.annee,m.fourniseur,&m.date.j,&m.date.mo,&m.date.a,m.type)!=EOF)
{ if (strcmp (id,m.nom)==0){
sprintf (texte5,"le matériel est existe");
sprintf(texte6," le reférence de matériel est : %s, l'annee de garentie est : %s,\n le fournisseur est : %s, le date est : %d/%d/%d, \n et son type est : %s \n",m.ref,m.annee,m.fourniseur,m.date.j,m.date.mo,m.date.a,m.type);}
else
sprintf (texte4,"non");
}
output=lookup_widget(button,("label14"));
gtk_label_set_text(GTK_LABEL(output),texte5);
output1=lookup_widget(button,("label27"));
gtk_label_set_text(GTK_LABEL(output1),texte6);
fclose (f);  }

}}
void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{t[0]=1;}
}



void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{t[1]=1;}
}


void
on_bwsuprimer3_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_bwsuprimer30_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *in1,*label18;
GtkWidget *Supprimer;
materiel m;
char id[10];
GtkWidget *output;
in1=lookup_widget(button, "bwentry1");
output=lookup_widget(button,"label18");
strcpy (id, gtk_entry_get_text (GTK_ENTRY(in1)));
gtk_label_set_text(GTK_LABEL(output),"Suppression Réussie !");
int b=0;
FILE*f=NULL;
FILE*f1=NULL;
f=fopen("materiel.txt","r");
f1=fopen("tmp.txt","w");
while (fscanf (f," %s %s %s %s %d %d %d %s",m.nom,m.ref,m.annee,m.fourniseur,&m.date.j,&m.date.mo,&m.date.a,m.type)!=EOF)

{
        if((strcmp(m.ref,id)!=0))
        {
        fprintf(f1,"%s %s %s %s %d %d %d %s \n",m.nom,m.ref,m.annee,m.fourniseur,m.date.j,m.date.mo,m.date.a,m.type);
b=1;
}
}
fclose(f);
fclose(f1);
remove("materiel.txt");
rename("tmp.txt","materiel.txt");
 }



void
on_bwajouter10_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *in1, *in2, *in3, *in4,*in5,*in6,*in7,*in8,*bwajouter;
materiel m;
bwajouter=lookup_widget(button,"bwajouter");                                                 
in1= lookup_widget (button,"bwnom1");
in2= lookup_widget (button,"bwref1");
in3= lookup_widget (button,"bwgarentie1");
in4= lookup_widget (button,"bwfourniseur1");
in5= lookup_widget (button,"combobox1");
in6= lookup_widget (button,"spinbutton1");
in7= lookup_widget (button,"spinbutton2");
in8= lookup_widget (button,"spinbutton3");
strcpy (m.nom, gtk_entry_get_text (GTK_ENTRY(in1)));
strcpy (m.ref, gtk_entry_get_text (GTK_ENTRY(in2)));
strcpy (m.type,gtk_combo_box_get_active_text (GTK_COMBO_BOX(in5)));
strcpy (m.annee, gtk_entry_get_text (GTK_ENTRY(in3)));
strcpy (m.fourniseur, gtk_entry_get_text (GTK_ENTRY(in4)));
m.date.j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (in6));
m.date.mo=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (in7));
m.date.a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (in8));
FILE *f;
f=fopen("materiel.txt","a+");
if (f!=NULL){
fprintf  (f," %s %s %s %s %d %d %d %s \n",m.nom,m.ref,m.annee,m.fourniseur,m.date.j,m.date.mo,m.date.a,m.type) ;
fclose (f); }
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{


GtkTreeIter iter;
gchar *nom;
gchar *reference ; //reference
gchar *annee_garentie; //annee 
gchar *fourniseur;
gint *type; 
gint *jour;
/*gchar *mois;
gchar *an; //date*/
materiel m;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model, &iter, path)) {
	gtk_tree_model_get(GTK_LIST_STORE(model), &iter,0,&nom,1,&reference,2,&annee_garentie,3,&fourniseur,4,jour,5,&type,-1);
	strcpy(m.nom,nom);
	strcpy(m.ref,reference);
	strcpy(m.annee,annee_garentie);
	strcpy(m.fourniseur,fourniseur);
        strcpy(m.type,type);
	strcpy(m.date.j,jour);

consulter (treeview);
}
}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_bwmodifier20_clicked                (GtkButton       *button,
                                        gpointer         user_data)

{
char id [10];
int b=0;
GtkWidget *in1,*in2 ,*in3,*in4, *in5, *in6,*in7 ,*in8, *bwmodifier ,*output;
materiel m;

FILE*f;
FILE*f1;
f=fopen("materiel.txt","r");
f1=fopen("tmp.txt","w");
in1= lookup_widget (button,"entry7");
strcpy (id, gtk_entry_get_text (GTK_ENTRY(in1)));
while (fscanf (f," %s %s %s %s %d %d %d %s",m.nom,m.ref,m.annee,m.fourniseur,&m.date.j,&m.date.mo,&m.date.a,m.type)!=EOF)

{
        if((strcmp(m.ref,id)!=0)) { 
  fprintf(f1,"%s %s %s %s %d %d %d %s \n",m.nom,m.ref,m.annee,m.fourniseur,m.date.j,m.date.mo,m.date.a,m.type);}
 if((strcmp(m.ref,id)==0)) {
in2= lookup_widget (button,"entry8");
in3= lookup_widget (button,"entry9");
in4= lookup_widget (button,"entry10");
in5= lookup_widget (button,"combobox2");
in6= lookup_widget (button,"spinbutton4");
in7= lookup_widget (button,"spinbutton5");
in8= lookup_widget (button,"spinbutton6");
strcpy (m.nom, gtk_entry_get_text (GTK_ENTRY(in2)));
strcpy (id, gtk_entry_get_text (GTK_ENTRY(in1)));
strcpy (m.annee, gtk_entry_get_text (GTK_ENTRY(in3)));
strcpy (m.fourniseur, gtk_entry_get_text (GTK_ENTRY(in4)));
m.date.j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (in6));
m.date.mo=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (in7));
m.date.a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (in8));
strcpy (m.type,gtk_combo_box_get_active_text (GTK_COMBO_BOX(in5)));
	output=lookup_widget(button,"label42");
        gtk_label_set_text(GTK_LABEL(output),"le materiel est bien modifier");

        fprintf(f1,"%s %s %s %s %d %d %d %s \n",m.nom,id,m.annee,m.fourniseur,m.date.j,m.date.mo,m.date.a,m.type);
}
}
/*else 
output=lookup_widget(button,"label42");
strcpy (id, gtk_entry_get_text (GTK_ENTRY(in1)));
gtk_label_set_text(GTK_LABEL(output),"le materiel est n'est pas existé");*/

fclose(f);
fclose(f1);
remove("materiel.txt");
rename("tmp.txt","materiel.txt");
}


void
on_bwretour20_enter                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowbwgestion0, *windowbwmodifier0;
windowbwmodifier0=lookup_widget(button,"windowbwmodifier0");
gtk_widget_hide(windowbwmodifier0);
windowbwgestion0=create_bwgestion0();
gtk_widget_show (windowbwgestion0);
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


void
on_bwcapteur50_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void 
on_button15_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
//retour
{
}


void
on_button16_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button17_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{ // retour
GtkWidget *windowbwgestion0, *windowbwrecherche100;
windowbwrecherche100=lookup_widget(button,"windowbwrecherche100");
gtk_widget_hide(windowbwrecherche100);
windowbwgestion0=create_bwgestion0();
gtk_widget_show (windowbwgestion0);


}


void
on_button18_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowbwgestion0, *windowbwrecherche100;
windowbwgestion0=lookup_widget(button,"windowbwgestion0");
gtk_widget_hide(windowbwgestion0);
windowbwrecherche100=create_bwrecherche100();
gtk_widget_show (windowbwrecherche100);
}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=2;}
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=1;}
}


void
on_bquitter_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button19_verifier_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
{GtkWidget *Nomm, *input1,*ouput1,*ouput2,*ouput3,*ouput4,*ouput5,*ouput6,*ouput7,*ouput8;
GtkWidget *fenetremodif;
char chnb1[30],chnb2[30],chnb3[30];
char Nom[30];
fenetremodif=lookup_widget(button,"bwmodifier10");
materiel p2,p;
input1=lookup_widget(button,"entry11");
strcpy(p.ref,gtk_entry_get_text(GTK_ENTRY(input1)));



FILE *f;
f=fopen("materiel.txt","r");
while(fscanf(f,"%s %s %s %s %d %d %d %s \n",p2.nom,p2.ref,p2.annee,p2.fourniseur,&p2.date.j,&p2.date.mo,&p2.date.a,p2.type)!=EOF)
{
if(strcmp(p.ref,p2.ref)==0)
{
ouput7=lookup_widget(button,"label65") ;
gtk_label_set_text(GTK_LABEL(ouput7),p2.ref);//p2 l9dimm 

//ouput2=lookup_widget(objet_graphique,"label67") ;
sprintf(chnb1,"%d",p2.date.j);
sprintf(chnb2,"%d",p2.date.mo);
sprintf(chnb3,"%d",p2.date.a);
ouput2=lookup_widget(button,"label70") ;
gtk_label_set_text(GTK_LABEL(ouput2),chnb1);
gtk_widget_show (ouput2);

ouput3=lookup_widget(button,"label71") ;
gtk_label_set_text(GTK_LABEL(ouput3),chnb2);
gtk_widget_show (ouput3);
ouput8=lookup_widget(button,"label72") ;
gtk_label_set_text(GTK_LABEL(ouput8),chnb3);
gtk_widget_show (ouput8);
ouput1=lookup_widget(button,"label66") ;
gtk_label_set_text(GTK_LABEL(ouput1),p2.nom);
gtk_widget_show (ouput1);
ouput6=lookup_widget(button,"label67") ;
gtk_label_set_text(GTK_LABEL(ouput6),p2.type);
gtk_widget_show (ouput6);
ouput4=lookup_widget(button,"label68") ;
gtk_label_set_text(GTK_LABEL(ouput4),p2.annee);
gtk_widget_show (ouput4);
ouput5=lookup_widget(button,"label69") ;
gtk_label_set_text(GTK_LABEL(ouput5),p2.fourniseur);
gtk_widget_show (ouput5);
}
}
fclose(f);



}

}

