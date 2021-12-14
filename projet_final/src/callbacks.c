#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "function.h"

int s=1;
void
on_rbfemme_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) s=0;
}


void
on_rbhomme_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) s=1;
}


void
on_entrycinaj_grab_focus               (GtkWidget       *widget,
                                        gpointer         user_data)
{
GtkWidget* input0;
GtkWidget* input1;
input0= lookup_widget(widget, "comboboxniveauaj");
input1= lookup_widget(widget, "comboboxblockaj");
gtk_combo_box_set_active(GTK_COMBO_BOX(input0),0);
gtk_combo_box_set_active(GTK_COMBO_BOX(input1),0);
}

void
on_Ajouter_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* input1;
GtkWidget* input2;
GtkWidget* input3;
GtkWidget* input4;
GtkWidget* input5;
GtkWidget* input6;
GtkWidget* input7;
GtkWidget* input8;
GtkWidget* input9;
input1= lookup_widget(objet_graphique, "entrycinaj");
input2= lookup_widget(objet_graphique, "entrynomaj");
input3= lookup_widget(objet_graphique, "entryprenomaj");
input4= lookup_widget(objet_graphique, "comboboxniveauaj");
input5= lookup_widget(objet_graphique, "comboboxblockaj");
input6= lookup_widget(objet_graphique, "entrytelephoneaj");
input7= lookup_widget(objet_graphique, "spinbuttonjouraj");
input8= lookup_widget(objet_graphique, "spinbuttonmoisaj");
input9= lookup_widget(objet_graphique, "spinbuttonanneeaj");
char c [100];
char n [100];
char p  [100];
char sex [100];
char niv [100];
char b [100];
char tel [100];
int j;
int m;
int a;
char sj [100];
char sm [100];
char sa [100];
char dn [100];
int unique;
strcpy(c,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(n,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p,gtk_entry_get_text(GTK_ENTRY(input3)));
if (s==0) strcpy(sex,"femme");
else strcpy(sex,"homme");
j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input9));
sprintf(sj,"%d",j);
sprintf(sm,"%d",m);
sprintf(sa,"%d",a);
strcat(sj,"/");
strcat(sm,"/");
strcat(sm,sa);
strcat(sj,sm);
strcpy(dn,sj);
strcpy(niv,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));
strcpy(b,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));
strcpy(tel,gtk_entry_get_text(GTK_ENTRY(input6)));

etudiant_heberge e;
strcpy(e.cin,c);
strcpy(e.nom,n);
strcpy(e.prenom,p);
strcpy(e.sex,sex);
strcpy(e.date_naissance,dn);
strcpy(e.niveau,niv);
strcpy(e.block,b);
strcpy(e.telephone,tel);
if((strlen(e.cin)==0)||(strlen(e.nom)==0)||(strlen(e.prenom)==0)||(strlen(e.telephone)==0))
{
GtkWidget *windowerror1;
windowerror1=create_windowerror1();
gtk_widget_show(windowerror1);
}
else
{
unique=is_unique("etudiants.txt",e.cin);
if((unique==-1))
{
GtkWidget *windowerror2;
windowerror2=create_windowerror2();
gtk_widget_show(windowerror2);
}
else
{
if((unique==1)&&(strlen(e.cin)!=0)&&(strlen(e.nom)!=0)&&(strlen(e.prenom)!=0)&&(strlen(e.telephone)!=0))
{
ajouter("etudiants.txt",e);
GtkWidget *windowok;
windowok=create_windowok();
gtk_widget_show(windowok);
}
}
}
}
void
on_afficheraj_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowgestionetudiant;
GtkWidget *windowafficher;
GtkWidget *treeview1;
windowgestionetudiant=lookup_widget(objet_graphique,"windowgestionetudiant");
gtk_widget_destroy(windowgestionetudiant);
windowafficher=lookup_widget(objet_graphique,"windowafficher");
windowafficher=create_windowafficher();
gtk_widget_show(windowafficher);
treeview1=lookup_widget(windowafficher,"treeview1");
afficher("etudiants.txt",treeview1);
}
int choix[5]={0,0};
void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
 choix[0]=1;

}
}


void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
choix[1]=1;

}
}


void
on_rechercher_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

if ((choix[0]==1)&&(choix[1]==0))
{
GtkWidget* input10;
char c [100];
input10= lookup_widget(objet_graphique, "entrycinre");
strcpy(c,gtk_entry_get_text(GTK_ENTRY(input10)));
rechercher("etudiants.txt",c);
GtkWidget *windowafficher,*w1;
GtkWidget *treeview1;
w1=lookup_widget(objet_graphique,"windowafficher");
windowafficher=create_windowafficher();
gtk_widget_show(windowafficher);
gtk_widget_hide(w1);
treeview1=lookup_widget(windowafficher,"treeview1");
afficher("etudiants_recherchee.txt",treeview1);
choix[0]=0;
choix[1]=0;
}
else 
{
if ((choix[0]==0)&&(choix[1]==1))
{
GtkWidget* input11;
char b [100];
input11= lookup_widget(objet_graphique, "entryblockre");
strcpy(b,gtk_entry_get_text(GTK_ENTRY(input11)));
FILE *f, *fw;
char cin[100],nom[100],prenom[100],sex[100],date_naissance[100],niveau[100],block[100],telephone[100];
f=fopen("etudiants.txt","r");
fw=fopen("etudiants_recherchee.txt","w");
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",cin,nom,prenom,sex,date_naissance,niveau,block,telephone)!=EOF)
{
if((strcmp(block,b))==0) fprintf(fw,"%s %s %s %s %s %s %s %s\n",cin,nom,prenom,sex,date_naissance,niveau,block,telephone);
}
fclose(f);
fclose(fw);
GtkWidget *windowafficher,*w1;
GtkWidget *treeview1;
w1=lookup_widget(objet_graphique,"windowafficher");
windowafficher=create_windowafficher();
gtk_widget_show(windowafficher);
gtk_widget_hide(w1);
treeview1=lookup_widget(windowafficher,"treeview1");
afficher("etudiants_recherchee.txt",treeview1);
choix[0]=0;
choix[1]=0;
}
else 
{
if ((choix[0]==1)&&(choix[1]==1))
{
GtkWidget* input0;
GtkWidget* input1;
char CIN [100];
char BLOCK [100];
input0= lookup_widget(objet_graphique, "entrycinre");
input1= lookup_widget(objet_graphique, "entryblockre");
strcpy(CIN,gtk_entry_get_text(GTK_ENTRY(input0)));
strcpy(BLOCK,gtk_entry_get_text(GTK_ENTRY(input1)));
FILE *f, *fw;
char cin[100],nom[100],prenom[100],sex[100],date_naissance[100],niveau[100],block[100],telephone[100];
f=fopen("etudiants.txt","r");
fw=fopen("etudiants_recherchee.txt","w");
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",cin,nom,prenom,sex,date_naissance,niveau,block,telephone)!=EOF)
{
if((strcmp(block,BLOCK)==0)&&(strcmp(cin,CIN)==0)) fprintf(fw,"%s %s %s %s %s %s %s %s\n",cin,nom,prenom,sex,date_naissance,niveau,block,telephone);
}
fclose(f);
fclose(fw);
GtkWidget *windowafficher,*w1;
GtkWidget *treeview1;
w1=lookup_widget(objet_graphique,"windowafficher");
windowafficher=create_windowafficher();
gtk_widget_show(windowafficher);
gtk_widget_hide(w1);
treeview1=lookup_widget(windowafficher,"treeview1");
afficher("etudiants_recherchee.txt",treeview1);
choix[0]=0;
choix[1]=0;
}
}
}
}


etudiant_heberge e;
void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar *cin;
gchar *nom;
gchar *prenom;
gchar *sex;
gchar *date_naissance;
gchar *niveau;
gchar *block;
gchar *telephone;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&cin,1,&nom,2,&prenom,3,&sex,4,&date_naissance,5,&niveau,6,&block,7,&telephone,-1);
strcpy(e.cin,cin);
strcpy(e.nom,nom);
strcpy(e.prenom,prenom);
strcpy(e.sex,sex);
strcpy(e.date_naissance,date_naissance);
strcpy(e.niveau,niveau);
strcpy(e.block,block);
strcpy(e.telephone,telephone);
}
}

void
on_supprimeraf_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
supprimer("etudiants.txt",e.cin);
}

void
on_entrynommo_grab_focus               (GtkWidget       *widget,
                                        gpointer         user_data)
{
GtkWidget* widget1;
GtkWidget* widget2;
GtkWidget* widget3;
GtkWidget* widget4;
GtkWidget* widget5;
GtkWidget* widget6;
GtkWidget* widget7;
GtkWidget* widget8;
GtkWidget* widget9;
GtkWidget* widgeth;
GtkWidget* widgetf;
widget1=lookup_widget(widget, "entrynommo");
gtk_entry_set_text(GTK_ENTRY(widget1),e.nom);
widget2= lookup_widget(widget, "comboboxniveaumo");
widget3= lookup_widget(widget, "comboboxblockmo");
int n=0,b=0;
n=atoi(e.niveau);
b=atoi(e.block);
gtk_combo_box_set_active(GTK_COMBO_BOX(widget2),n-1);
gtk_combo_box_set_active(GTK_COMBO_BOX(widget3),b-1);
widget4=lookup_widget(widget, "entrytelephonemo");
gtk_entry_set_text(GTK_ENTRY(widget4),e.telephone);
widget5=lookup_widget(widget, "entryprenommo");
gtk_entry_set_text(GTK_ENTRY(widget5),e.prenom);
widgeth=lookup_widget(widget, "rbhommemo");
widgetf=lookup_widget(widget, "rbfemmemo");
if(strcmp(e.sex,"homme")==0) gtk_toggle_button_set_active(GTK_RADIO_BUTTON(widgeth),TRUE);
if(strcmp(e.sex,"femme")==0) gtk_toggle_button_set_active(GTK_RADIO_BUTTON(widgetf),TRUE);
int p_occ=-1,d_occ=0;
pos_car(e.date_naissance,'/',&p_occ,&d_occ);
int i;
char j [3];
for(i=0;i<p_occ;i++) j[i]=e.date_naissance[i];
j[p_occ]='\0';
int ij=0;
ij=atoi(j);
widget7=lookup_widget(widget, "spinbuttonjourmo");
gtk_spin_button_set_value(widget7,ij);
char m [3];
for(i=p_occ+1;i<d_occ;i++) m[i-p_occ-1]=e.date_naissance[i];
m[d_occ-p_occ-1]='\0';
int im=0;
im=atoi(m);
widget8=lookup_widget(widget, "spinbuttonmoismo");
gtk_spin_button_set_value(widget8,im);
char a [5];
for(i=d_occ+1;i<strlen(e.date_naissance);i++) a[i-d_occ-1]=e.date_naissance[i];
a[strlen(e.date_naissance)-d_occ-1]='\0';
int ia=0;
ia=atoi(a);
widget9=lookup_widget(widget, "spinbuttonanneemo");
gtk_spin_button_set_value(widget9,ia);
}

void
on_modifieraf_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input;
GtkWidget *windowmodifier;
windowmodifier=lookup_widget(objet_graphique,"windowmodifier");
windowmodifier=create_windowmodifier();
gtk_widget_show(windowmodifier);
}

int m=1;
void
on_rbhommemo_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) m=1;
}


void
on_rbfemmemo_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) m=0;
}

void
on_enregistrer_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget* input2;
GtkWidget* input3;
GtkWidget* input4;
GtkWidget* input5;
GtkWidget* input6;
GtkWidget* input7;
GtkWidget* input8;
GtkWidget* input9;

input2= lookup_widget(objet_graphique, "entrynommo");
input3= lookup_widget(objet_graphique, "entryprenommo");
input4= lookup_widget(objet_graphique, "comboboxniveaumo");
input5= lookup_widget(objet_graphique, "comboboxblockmo");
input6= lookup_widget(objet_graphique, "entrytelephonemo");
input7= lookup_widget(objet_graphique, "spinbuttonjourmo");
input8= lookup_widget(objet_graphique, "spinbuttonmoismo");
input9= lookup_widget(objet_graphique, "spinbuttonanneemo");
char c [100];
char n [100];
char p  [100];
char sex [100];
char niv [100];
char b [100];
char tel [100];
int j;
int m;
int a;
char sj [100];
char sm [100];
char sa [100];
char dn [100];

strcpy(n,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p,gtk_entry_get_text(GTK_ENTRY(input3)));
if (m==0) strcpy(sex,"femme");
else strcpy(sex,"homme");
j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input9));
sprintf(sj,"%d",j);
sprintf(sm,"%d",m);
sprintf(sa,"%d",a);
strcat(sj,"/");
strcat(sm,"/");
strcat(sm,sa);
strcat(sj,sm);
strcpy(dn,sj);
strcpy(niv,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));
strcpy(b,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));
strcpy(tel,gtk_entry_get_text(GTK_ENTRY(input6)));

etudiant_heberge ne;
strcpy(ne.cin,e.cin);
strcpy(ne.nom,n);
strcpy(ne.prenom,p);
strcpy(ne.sex,sex);
strcpy(ne.date_naissance,dn);
strcpy(ne.niveau,niv);
strcpy(ne.block,b);
strcpy(ne.telephone,tel);
modifier("etudiants.txt",ne,e.cin);
}

void
on_actualiser_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowafficher,*w1;
GtkWidget *treeview1;
w1=lookup_widget(objet_graphique,"windowafficher");
windowafficher=create_windowafficher();
gtk_widget_show(windowafficher);
gtk_widget_hide(w1);
treeview1=lookup_widget(windowafficher,"treeview1");
afficher("etudiants.txt",treeview1);
}

void
on_retour_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowgestionetudiant,*windowafficher;
windowafficher=lookup_widget(objet_graphique,"windowafficher");
gtk_widget_destroy(windowafficher);
windowgestionetudiant=create_windowgestionetudiant();
gtk_widget_show(windowgestionetudiant);
}




void
on_niveau_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
nbr_etudiant_niveau("etudiants.txt");
GtkWidget *windowafficher;
GtkWidget *windowafficherniveau;
GtkWidget *treeview2;
windowafficher=lookup_widget(objet_graphique,"windowafficher");
gtk_widget_destroy(windowafficher);
windowafficherniveau=lookup_widget(objet_graphique,"windowafficherniveau");
windowafficherniveau=create_windowafficherniveau();
gtk_widget_show(windowafficherniveau);
treeview2=lookup_widget(windowafficherniveau,"treeview2");
afficherniveau("niveau.txt",treeview2);
}


void
on_retourniveau_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowafficher,*windowafficherniveau;
windowafficherniveau=lookup_widget(objet_graphique,"windowafficherniveau");
gtk_widget_destroy(windowafficherniveau);
windowafficher=create_windowafficher();
gtk_widget_show(windowafficher);

}

