#include <gtk/gtk.h>


void
on_rbfemme_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rbhomme_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Ajouter_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_afficheraj_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_rechercher_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_enregistrer_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_modifieraf_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_supprimeraf_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_actualiser_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_retour_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_entrynommo_grab_focus               (GtkWidget       *widget,
                                        gpointer         user_data);


void
on_niveau_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_retourniveau_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);


void
on_entrycinaj_grab_focus               (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_rbhommemo_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rbfemmemo_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
