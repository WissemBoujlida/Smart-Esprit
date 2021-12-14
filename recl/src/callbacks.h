#include <gtk/gtk.h>


void
on_aobutton_dep_clicked                  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_aobutton_consult_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_aoradiobutton_oui_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_aoradiobutton_non_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_aocheckbutton_ouieq_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_aocheckbutton_noneq_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_aocheckbuttonr_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_aocheckbuttonh_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_aobutton_dep_pl_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void
on_aobutton_annuler_pl_clicked           (GtkWidget       *button,
                                        gpointer         user_data);

void
on_aotreeview_rec_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_aobutton_acc_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_aobutton_modifier_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_aobutton_supprimer_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_aobutton_oui_supp_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_aobutton_non_supp_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_aobutton_rech_pl_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_aobutton_service_rec_clicked          (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_aobutton_retour_pl_clicked            (GtkButton       *button,
                                        gpointer         user_data);


void
on_aoaobutton_retour00_clicked           (GtkButton       *button,
                                        gpointer         user_data);


void
on_aobutton_retour_menu_p_clicked            (GtkButton       *button,
                                        gpointer         user_data);


