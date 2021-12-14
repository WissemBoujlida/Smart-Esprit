#include <gtk/gtk.h>

void sendmail(char body[]);

void
on_FJcheckbutton1_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FJradiobutton1_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FJretour3_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_FJbutton1_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_FJradiobutton2_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FJretour2_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_FJbutton2_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_FJretour4_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_FJbutton3_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_FJretour5_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_FJretour1_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_FJtreeview2_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_FJbuttonafficher_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);



void
on_FJActualiser12_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_FJmod_clicked                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_FJradiobuttonnon_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FJboutonmodifier_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_FJboutonchercher_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_FJruptstock1_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_FJentry9_changed                    (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_FJretour69_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);
