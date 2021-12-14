#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <string.h>
#include "reclamation.h"


int c=0;
int e=0;
int obj1=0;
int obj2=0;
int m=1;
rec del;

void
on_aobutton_dep_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *B;
B=create_aowindow_formulaire();
gtk_widget_show(B);

}


void
on_aobutton_consult_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *aowindow_menu ;
GtkWidget *aowindow_consult;
GtkWidget *aotreeview_rec;

aowindow_menu =lookup_widget(objet,"aowindow_menu ");

gtk_widget_destroy(aowindow_menu );
aowindow_consult=lookup_widget(objet,"aowindow_consult");
aowindow_consult=create_aowindow_consult();

gtk_widget_show(aowindow_consult);

aotreeview_rec=lookup_widget(aowindow_consult,"aotreeview_rec");
afficher_rec(aotreeview_rec,"reclm.txt");

}


void
on_aoradiobutton_oui_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
  c=1;
}


void
on_aoradiobutton_non_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
  c=0;
}


void
on_aocheckbutton_ouieq_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
char mail[250]="(  Vous recevrez un e-mail sur l'adresse avec laquelle voue êtes connecté(e)   )";
 GtkWidget*msg ;
 
 if (gtk_toggle_button_get_active(togglebutton))
  {
   msg= lookup_widget(togglebutton, "label_oui") ;
   gtk_label_set_text(GTK_LABEL(msg),mail);
  e=1;
 
  }
}


void
on_aocheckbutton_noneq_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(togglebutton))
  e=0;
}


void
on_aocheckbuttonr_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(togglebutton))
 obj1=1;
}


void
on_aocheckbuttonh_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(togglebutton))
 obj2=1;
}


void
on_aobutton_dep_pl_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{

rec r;
int j,m,a;
char dj[3];
char dm[4];
char da[5];
char ct[10];
char eq[10];
char objj[]="";
GtkWidget *A;
GtkWidget *B;
GtkWidget *aoentrynom;
GtkWidget *aoentrypnom;
GtkWidget *aoentrycin;
GtkWidget *aoentryid;
GtkWidget *aospinbutton_jr;
GtkWidget *aospinbutton_ms;
GtkWidget *aospinbutton_an;
GtkWidget *aoentryprob;

aoentrynom=lookup_widget(button,"aoentrynom");
aoentrypnom=lookup_widget(button,"aoentrypnom");
aoentrycin=lookup_widget(button,"aoentrycin");
aoentryid=lookup_widget(button,"aoentryid");

aospinbutton_jr=lookup_widget(button, "aospinbutton_jr");
aospinbutton_ms=lookup_widget(button, "aospinbutton_ms");
aospinbutton_an=lookup_widget(button, "aospinbutton_an");
aoentryprob=lookup_widget(button,"aoentryprob");
strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(aoentrynom)));
strcpy(r.pnom,gtk_entry_get_text(GTK_ENTRY(aoentrypnom)));
strcpy(r.cin,gtk_entry_get_text(GTK_ENTRY(aoentrycin)));
strcpy(r.id,gtk_entry_get_text(GTK_ENTRY(aoentryid)));
actv(c,ct);
strcpy(r.contact,ct);
actv(e,eq);
strcpy(r.enquette,eq);
j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(aospinbutton_jr));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(aospinbutton_ms));
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(aospinbutton_an));
sprintf(dj, "%d",j );
sprintf(dm, "%d",m );
sprintf(da, "%d",a );
strcpy(r.date,dj);
strcat(r.date,dm);
strcat(r.date,da);
objpl(obj1,obj2,objj);
strcpy(r.objet,objj);
strcpy(r.prob,gtk_entry_get_text(GTK_ENTRY(aoentryprob)));
ajouter_pl(r);
B=create_aowindow_dep_succ();
gtk_widget_show(B);
A=lookup_widget(button,"aowindow_formulaire");
gtk_widget_hide(A);

}


void
on_aobutton_annuler_pl_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *A;
GtkWidget *B;
A=lookup_widget(button,"aowindow_formulaire");
gtk_widget_hide(A);
B=create_aowindow_menu ();
gtk_widget_show(B);
}


void
on_aotreeview_rec_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter   iter;
gchar *nom;
gchar *pnom;
gchar *cin;
gchar *id;
gchar *contact;
gchar *enquette;
gchar *date;
gchar *objet;
gchar *prob;
rec r;


GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model, &iter, path))
{
gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&nom,1,&pnom,2,&cin,3,&id,4,&contact,5,&enquette,6,&date,7,&objet,8,&prob,-1);
strcpy(r.nom,nom);
strcpy(r.pnom,pnom);
strcpy(r.cin,cin);
strcpy(r.id,id);
strcpy(r.contact,contact);
strcpy(r.enquette,enquette);
strcpy(r.date,date);
strcpy(r.objet,objet);
strcpy(r.prob,prob);
strcpy(del.nom,nom);
strcpy(del.pnom,pnom);
strcpy(del.cin,cin);
strcpy(del.id,id);
strcpy(del.contact,contact);
strcpy(del.enquette,enquette);
strcpy(del.date,date);
strcpy(del.objet,objet);
strcpy(del.prob,prob);
afficher_rec(treeview,"reclm.txt");
}

}


void
on_aobutton_acc_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *aowindow_consult,*wz;
GtkWidget *aotreeview_rec;

wz=lookup_widget(objet,"aowindow_consult");
aowindow_consult=create_aowindow_consult();
gtk_widget_show(aowindow_consult);
gtk_widget_hide(wz);
aotreeview_rec=lookup_widget(aowindow_consult,"aotreeview_rec");

afficher_rec(aotreeview_rec,"reclm.txt");



}


void
on_aobutton_modifier_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *B;
GtkWidget *aowindow_consult;
aowindow_consult=lookup_widget(objet,"aowindow_consult");
gtk_widget_destroy(aowindow_consult);
B=create_aowindow_formulaire();
supprimer_pl(del);
gtk_widget_show(B);
}


void
on_aobutton_supprimer_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
   GtkWidget *B;
B=create_aowindow_c_supp();
gtk_widget_show(B);
 
}


void
on_aobutton_oui_supp_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *A;
A=lookup_widget(objet,"aowindow_cs");
supprimer_pl(del);
gtk_widget_show(A);
}


void
on_aobutton_non_supp_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *A;
A=lookup_widget(button,"aowindow_c_supp");
gtk_widget_hide(A);
}


void
on_aobutton_rech_pl_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *aotreeview_rec;
GtkWidget *aowindow_consult ,*wz; 
GtkWidget *aoentry_rech_date;
char rech_date[30]; 


wz=lookup_widget(button,"aowindow_consult");
aowindow_consult=create_aowindow_consult();
gtk_widget_show(aowindow_consult);
gtk_widget_hide(wz);
aotreeview_rec=lookup_widget(aowindow_consult,"aotreeview_rec");

aoentry_rech_date=lookup_widget(button,"aoentry_rech_date");
strcpy(rech_date,gtk_entry_get_text(GTK_ENTRY(aoentry_rech_date)));
recherche_pl(rech_date);
afficher_rec(aotreeview_rec,"drec.txt");

}





void
on_aobutton_retour_pl_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_aobutton_service_rec_clicked          (GtkButton       *objet,
                                        gpointer         user_data)
{   
int result=0;    
char srv[50]="hello";
GtkWidget*service_rr ;    
GtkWidget *B;
B=create_aowindow_service();
gtk_widget_show(B);
result=service_rec();
if (result==1)
{
strcpy(srv,"Hebergement");
service_rr= lookup_widget(objet, "aolabel_service_rrcc") ;
 gtk_label_set_text(GTK_LABEL(service_rr),srv);
}
if (result==2)
{
strcpy(srv,"Restauration");
service_rr= lookup_widget(objet, "aolabel_service_rrcc") ;
 gtk_label_set_text(GTK_LABEL(service_rr),srv);

}
}



void
on_aobutton_retour_menu_p_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}

void
on_aobutton_retour00_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}

