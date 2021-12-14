#include <gtk/gtk.h>


void
on_fobuttonconnect_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_fobuttonaficher_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_fobuttonchercher_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_fobuttonmeilleur_clicked            (GtkWidget       *button,
                                        gpointer         user_data);

void
on_fotreeview1_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_fobuttondelete_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_fobuttonmodifier1_clicked           (GtkWidget       *button,
                                        gpointer         user_data);

void
on_fobuttonretour_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_fobuttonajout1_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_fobuttonajoutermenu_clicked         (GtkWidget       *button,
                                        gpointer         user_data);

void
on_foradiop_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_foradior_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_foradiod_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

gboolean
on_fowindowmodifier_focus_in_event     (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

void
on_fobuttonenregistrer_clicked         (GtkWidget       *button,
                                        gpointer         user_data);

void
on_focheckbutton1_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_fobuttoncherche2_clicked            (GtkWidget        *button,
                                        gpointer         user_data);

gboolean
on_fowindowsupp_focus_in_event         (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

void
on_fobuttonsupp_clicked                (GtkWidget       *button,
                                        gpointer         user_data);
