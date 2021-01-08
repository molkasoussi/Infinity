#include <gtk/gtk.h>


  GtkWidget *windowGT;
  GtkWidget *windowL;
  GtkWidget *windowA;
  GtkWidget *windowM;
  GtkWidget *windowN;
  GtkWidget *windowS;
  GtkWidget *treeview1;

void
on_buttonA_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonM_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonLDT_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonS_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonNDT_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonCh_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonAjoute_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonModifier_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonNombre_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);


void
on_buttonSupprime_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_modifier1_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_Nombree_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_R1_clicked                          (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_R2_clicked                          (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_R3_clicked                          (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_R4_clicked                          (GtkButton       *objet_graphique,
                                        gpointer         user_data);
