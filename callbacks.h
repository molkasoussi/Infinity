#include <gtk/gtk.h>
GtkWidget *windowGT;
  GtkWidget *windowL;
  GtkWidget *windowA;
  GtkWidget *windowM;
  GtkWidget *windowN;
  GtkWidget *windowS;
  GtkWidget *treeview1;


void
on_buttonLDT_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonNDT_clicked                   (GtkWidget        *objet_graphique,
                                        gpointer         user_data);

void
on_buttonM_clicked                     (GtkWidget        *objet_graphique,
                                        gpointer         user_data);

void
on_buttonS_clicked                     (GtkWidget        *objet_graphique,
                                        gpointer         user_data);

void
on_buttonA_activate                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonA_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonModifie_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);



void
on_buttonA_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button6_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonAjoute_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonSupprime_clicked              (GtkWidget        *button,
                                        gpointer         user_data);

void
on_buttonTaux_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);
void
on_ajoutabs_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_remplirabs_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_afficherabs_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_reGT_clicked                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_REaj_clicked                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_REL_clicked                         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_RE_SUP_LIS_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_RE_ABS_GT_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_REABSCE_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_oui_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_non_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_busupprimer_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_Nonn_clicked                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button7_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

/*void
on_radiobutton2_present_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1_Absent_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);*/

void
on_button8_verif_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_butto_ok_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);
