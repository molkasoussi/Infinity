#include <gtk/gtk.h>


  GtkWidget *windowGP;
  GtkWidget *windowLP;
  GtkWidget *windowA;
  GtkWidget *windowM;
  GtkWidget *windowS;
  GtkWidget *treeview1;

void
on_button_retourGP_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonGP_clicked                    (GtkWidget      *objet_graphique,
                                        gpointer         user_data);

void
on_button_ajoutp_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_supprimerp_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_modifierp_clicked            (GtkWidget       *objet_graphique,
                                        gpointer        user_data);

void
on_button_retourA_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_chercherLP_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_ajoutp2_clicked              (GtkWidget      *objet_graphique,
                                        gpointer         user_data);


void
on_button_supprimerp2_clicked          (GtkWidget      *objet_graphique,
                                        gpointer         user_data);

void
on_button_modiferp2_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_verif_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_retourM_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_retourLP_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_retourS_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_retourA_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);




                                   
void
on_button__capdef1_clicked             (GtkWidget      *objet_graphique,
                                        gpointer         user_data);

void
on_button_capdef2_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);
