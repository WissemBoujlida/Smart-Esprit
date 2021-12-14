#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "menu.h"

int sup = 1 ;
char ident1[10] ;
int choix;


void
on_fobuttonconnect_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{

}


void
on_fobuttonaficher_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fowindowaffiche;
GtkWidget *fotreeview1;

fowindowaffiche=lookup_widget(objet,"fowindowaffiche");
fowindowaffiche=create_fowindowaffiche();


gtk_widget_show(fowindowaffiche);

fotreeview1=lookup_widget(fowindowaffiche,"fotreeview1");
foafficher("menu.txt",fotreeview1);
}


void
on_fobuttonchercher_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *fowindowchercher;
 fowindowchercher = create_fowindowchercher ();
  gtk_widget_show (fowindowchercher);
}


void
on_fobuttonmeilleur_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{

FILE* f;

FILE* fm;

int a,b,na,nb;

float c,nc=1000.00;

  int l;

    char nom[25];

    char type[20];

    char entree[30];

    char suite[30];

    char dessert[30];

    char str[25];

    char date[10];

    char id[10];

char text[15];

char msg[100];
strcpy(msg,"le meilleur menu est ");

GtkWidget *sortie;

sortie=lookup_widget(button,"folabelme1");

// GtkWidget *fomeilleur;

f=fopen("dechet.txt","r");

while(fscanf(f,"%d %d %f\n",&a,&b,&c)!=EOF){



  if (nc>c){nc=c;

  nb=b;

  na=a;                 }

}

sprintf(text,"%d",na);

fm=fopen("menu.txt","r");



while(fscanf(fm,"%s %s %s %s %s %s %s\n",id,nom,type,entree,suite,dessert,date)!=EOF){

   







if (strcmp(type,"petit_dej")==0){l=1;}

else if (strcmp(type,"repas")==0){l=2;}

else if (strcmp(type,"dinner")==0){l=3;}









if ((strcmp(date,text)==0) && (nb==l)){ 



strcat(msg,nom);

 gtk_label_set_text(GTK_LABEL(sortie),msg);}

}







fclose(fm);

fclose(f);













}



void
on_fotreeview1_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

GtkTreeIter iter;
gchar* id;
gchar* nom;
gchar* type;
gchar* entree;
gchar* suite;
gchar* dessert;
gchar* date;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&id,1,&nom,2,&type,3,&entree,4,&suite,5,&dessert,6,&date,-1);



strcpy(ident1,id);}
}


void
on_fobuttondelete_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fowindowsupp;
  fowindowsupp = create_fowindowsupp ();
  gtk_widget_show (fowindowsupp);
}


void
on_fobuttonmodifier1_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fowindowmodifier;



 fowindowmodifier = create_fowindowmodifier ();
  
 gtk_widget_show (fowindowmodifier);
}


void
on_fobuttonretour_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fowindowaffiche,*fowindowen; 
fowindowaffiche=lookup_widget(button,"fowindowaffiche"); 
gtk_widget_destroy(fowindowaffiche); 
fowindowen=create_fowindowen(); 
gtk_widget_show(fowindowen);

}


void
on_fobuttonajout1_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *fowindowajouter;
 fowindowajouter = create_fowindowajouter ();
  gtk_widget_show (fowindowajouter);

}


void
on_fobuttonajoutermenu_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
menu m;
GtkWidget *input1,*input2,*spin,*input4,*input5,*input6,*input7;
GtkWidget *fowindowajouter;
char typea[20],date1[10];
int a;

fowindowajouter=lookup_widget(objet,"fowindowajouter");

input1=lookup_widget(objet,"foentryaid");
input2=lookup_widget(objet,"foentryanom");
if (choix==1){strcpy(typea,"petit_dej");}
if (choix==2){strcpy(typea,"repas");}
if (choix==3){strcpy(typea,"dinner");}


input4=lookup_widget(objet,"foentryaentree");
input5=lookup_widget(objet,"foentryasuite");
input6=lookup_widget(objet,"foentryadessert");

//input7=lookup_widget(objet,"entry2");

spin = lookup_widget(objet,"fospinbutton1");
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin));
sprintf(date1,"%d",a);



strcpy(m.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(m.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(m.type,typea);
strcpy(m.entree,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(m.suite,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(m.dessert,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(m.date,date1);
foajouter(m);
choix=0;

}


void
on_foradiop_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choix=1;
}


void
on_foradior_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choix=2;
}


void
on_foradiod_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choix=3;
}


gboolean
on_fowindowmodifier_focus_in_event     (GtkWidget       *button,
                                        GdkEventFocus   *event,
                                        gpointer         user_data)
{
FILE* f;
    
    char id[10];
    char date[10];
    char nom[25];
    char type[20];
    char entree[30];
    char suite[30];
    char dessert[30];
    GtkWidget *input, *input1; 
    int a;


GtkWidget *combobox, *spin;
input1 = lookup_widget(button,"focomboboxentrymtype");
input = lookup_widget(button,"foentrymid");
spin = lookup_widget(button,"fospinbuttonmdate");
f=fopen("menu.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %s\n",id,nom,type,entree,suite,dessert,date)!=EOF){
if (strcmp(id,ident1)==0){
gtk_entry_set_text(GTK_ENTRY(lookup_widget(button,"foentrymid")),ident1);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(button,"foentrymnom")),nom);            
gtk_entry_set_text(GTK_ENTRY(lookup_widget(button,"foentrymentree")),entree);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(button,"foentrymsuite")),suite);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(button,"foentrymdessert")),dessert);
if(strcmp(type,"repas")==0) {a=1;}
else if (strcmp(type,"dinner")==0){a=2;}
else {a=0;}
gtk_combo_box_set_active(GTK_COMBO_BOX(input1),a);
gtk_spin_button_set_value(spin,atoi(date));


}
}

fclose(f);
  return FALSE;
}


void
on_fobuttonenregistrer_clicked        (GtkWidget       *button,
                                        gpointer         user_data)
{
FILE* ft;
FILE* f;
    char id[10];
    char date[10];
    char nom[25];
    char type[20];
    char entree[30];
    char suite[30];
    char dessert[30];
    char id1[10];
    char date1[10];
    char nom1[25];
    char type1[20];
    char entree1[30];
    char suite1[30];
    char dessert1[30];
   int a;
GtkWidget *combobox, *spin;
GtkWidget *input2, *input1, *input3, *input4, *input5;
spin = lookup_widget(button,"fospinbuttonmdate");
combobox = lookup_widget(button,"focomboboxentrymtype");
input1 = lookup_widget(button,"foentrymid");
input2 = lookup_widget(button,"foentrymnom");
input3 = lookup_widget(button,"foentrymentree");
input4 = lookup_widget(button,"foentrymsuite");
input5 = lookup_widget(button,"foentrymdessert");
//
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin));
sprintf(date1,"%d",a);

strcpy(type1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox))) ;

strcpy(id1,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(nom1,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(entree1,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(suite1,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(dessert1,gtk_entry_get_text(GTK_ENTRY(input5)));




f=fopen("menu.txt","r");
ft=fopen("tmp.txt","ab+");
while(fscanf(f,"%s %s %s %s %s %s %s\n",id,nom,type,entree,suite,dessert,date)!=EOF){



if (strcmp(id,id1)==0) {fprintf(ft,"%s %s %s %s %s %s %s\n",id1,nom1,type1,entree1,suite1,dessert1,date1);}

else {fprintf(ft,"%s %s %s %s %s %s %s\n",id,nom,type,entree,suite,dessert,date);}
}

fclose(f);
fclose(ft);
remove("menu.txt");
rename("tmp.txt","menu.txt");
}


void
on_focheckbutton1_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_fobuttoncherche2_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
   GtkWidget *input; 
//*sortie;
   char text[10];
//char msg[100];
input = lookup_widget(button,"foentrycherche");
//sortie=lookup_widget(button,"folabelmescher");
strcpy(text,gtk_entry_get_text(GTK_ENTRY(input)));
fochercher(text);
/*if (chercher(text)==1) {strcpy(msg,"le menu existe");}
else {strcpy(msg,"le menu n'existe pas");}
gtk_label_set_text(GTK_LABEL(sortie),msg);*/
GtkWidget *fowindowchercher,*w1;
GtkWidget *fotreeview2;
w1=lookup_widget(button,"fowindowchercher");
fowindowchercher=create_fowindowchercher();
gtk_widget_show(fowindowchercher);
gtk_widget_hide(w1);
fotreeview2=lookup_widget(fowindowchercher,"fotreeview2");
foafficher("menurecherche.txt",fotreeview2);

}



gboolean
on_fowindowsupp_focus_in_event         (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data)
{

  return FALSE;
}


void
on_fobuttonsupp_clicked                (GtkWidget       *button,
                                        gpointer         user_data)

{  
char a[10];
strcpy(a,ident1);
fosupprimer(a);}









