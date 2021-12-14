#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonctionc.h"
int xa;
int r=0;
int rm=0;

Capts ca,cm,cra,Cr;

void
on_cabuttonlogin_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_cabuttongdcretour_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* windowgdcretour;
GtkWidget* closegdcet;
closegdcet= lookup_widget(button,"cawindowgdc");
gtk_widget_destroy(closegdcet);
windowgdcretour=create_cawindowet();
gtk_widget_show (windowgdcretour);
}


void
on_acbgdcrech_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* windowretourmodifierunapteur;
GtkWidget* closegdcre;
closegdcre= lookup_widget(button,"cawindowgdc");
gtk_widget_destroy(closegdcre);

windowretourmodifierunapteur=create_acwrechercher();
gtk_widget_show (windowretourmodifierunapteur);
}


void
on_cabuttonajouter_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* windowajouterunapteur;
GtkWidget* closegdcaj;
closegdcaj= lookup_widget(button,"cawindowgdc");
gtk_widget_destroy(closegdcaj);

windowajouterunapteur=create_cawindowajouter();
gtk_widget_show (windowajouterunapteur);
}


void
on_cabuttonmodifier_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
//GtkWidget* input1;
//input1 = lookup_widget(button,"caentrymnom");
//gtk_entry_set_text(GTK_ENTRY(input1),cra.nom);

GtkWidget* windowmoderunapteur;
GtkWidget* closegdcmo;
closegdcmo= lookup_widget(button,"cawindowgdc");
gtk_widget_destroy(closegdcmo);
windowmoderunapteur=create_cawindowmodifier();
gtk_widget_show (windowmoderunapteur);
}


void
on_cabuttonsupprimer_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* windowsupperunapteur;
GtkWidget* closegdcsu;
closegdcsu= lookup_widget(button,"cawindowgdc");
gtk_widget_destroy(closegdcsu);

windowsupperunapteur=create_acwindowsupprimer();
gtk_widget_show (windowsupperunapteur);
}


void
on_cabuttonsretour_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* windowsretour;
GtkWidget* closeldaet;
closeldaet= lookup_widget(button,"cawindowsecurit__");
gtk_widget_destroy(closeldaet);
windowsretour=create_cawindowet();
gtk_widget_show (windowsretour);
}


void
on_cabuttongdc_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* cawindowgdc;
GtkWidget* treeviewtr;
GtkWidget* cawindowet1;

cawindowet1=lookup_widget(objet_graphique,"cawindowet");
gtk_widget_destroy(cawindowet1);
cawindowgdc=lookup_widget(objet_graphique,"cawindowgdc");
cawindowgdc=create_cawindowgdc();
gtk_widget_show (cawindowgdc);
treeviewtr = lookup_widget(cawindowgdc,"caatreeviewgdc");
afficher_capts(treeviewtr);
}


void
on_cabuttons__curit___clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* cawindowsecurit__;
GtkWidget* treeviewtrax;
GtkWidget* cawindowet;

cawindowet=lookup_widget(objet_graphique,"cawindowet");
gtk_widget_destroy(cawindowet);
cawindowsecurit__=lookup_widget(objet_graphique,"cawindowsecurit__");
cawindowsecurit__=create_cawindowsecurit__();
gtk_widget_show (cawindowsecurit__);
treeviewtrax = lookup_widget(cawindowsecurit__,"treeviewtrax");
afficher_securite(treeviewtrax);
}


void
on_cabuttonquitter_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button9_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* cawindowgdc;
GtkWidget* treeviewtr;
GtkWidget* cawindowet1;

cawindowet1=lookup_widget(button,"cawindowajouter");
gtk_widget_destroy(cawindowet1);
cawindowgdc=lookup_widget(button,"cawindowgdc");
cawindowgdc=create_cawindowgdc();
gtk_widget_show (cawindowgdc);
treeviewtr = lookup_widget(cawindowgdc,"caatreeviewgdc");
afficher_capts(treeviewtr);
}


void
on_acrbdebit_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
/*if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
	//strcpy(ca.type,"débit");
}*/
}


void
on_acrbdechet_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{/*
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
	strcpy(ca.type,"déchet");
}*/
}


void
on_acrbf_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
/*if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
	strcpy(ca.type,"fumée");
}*/
}


void
on_acrbm_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{/*
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
	strcpy(ca.type,"mouvement");
}*/
}


void
on_acrbt_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{/*
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
	strcpy(ca.type,"temperature");
}*/
}


void
on_button7_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* input1;
GtkWidget* combobox1;
GtkWidget* input2;
GtkWidget* output3;
GtkWidget* output4;
GtkWidget* Casbavmin;
GtkWidget* Caspinbuttonvmax;
FILE* fg;
int g;
char nom[100];
char localisation[100];
char nomver[100];
char existe1[100]="Cet identifiant existe";
char existe0[100]="  ";
char success[100]="ajout avec succès";

input1 = lookup_widget(objet_graphique,"caentryandc");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(ca.nom,nom);

combobox1 = lookup_widget(objet_graphique,"accbmvald3");
if(strcmp("temperature",gtk_combo_box_get_active_text (GTK_COMBO_BOX(combobox1)))==0){strcpy(ca.type,"temperature");}
else if(strcmp("mouvement",gtk_combo_box_get_active_text (GTK_COMBO_BOX(combobox1)))==0){strcpy(ca.type,"mouvement");}
else if(strcmp("déchet",gtk_combo_box_get_active_text (GTK_COMBO_BOX(combobox1)))==0){strcpy(ca.type,"déchet");}
else if(strcmp("débit",gtk_combo_box_get_active_text (GTK_COMBO_BOX(combobox1)))==0){strcpy(ca.type,"débit");}
else if(strcmp("fumée",gtk_combo_box_get_active_text (GTK_COMBO_BOX(combobox1)))==0){strcpy(ca.type,"fumée");}

input2 = lookup_widget(objet_graphique,"caentryalocalisation");
strcpy(localisation,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(ca.localisation,localisation);

Casbavmin = lookup_widget(objet_graphique,"casbavmin");
ca.valmin=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Casbavmin));
Caspinbuttonvmax = lookup_widget(objet_graphique,"caspinbuttonvmax");
ca.valmax=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Caspinbuttonvmax));
ca.etat=0;
output3 = lookup_widget(objet_graphique,"aclabacne");
output4 = lookup_widget(objet_graphique,"aclaas");


fg=fopen("capteurs.txt","r");
while(fscanf(fg,"%s %s %s %i %i %i ",Cr.nom,Cr.type,Cr.localisation,&Cr.valmin,&Cr.valmax,&Cr.etat)!=(EOF))
	{if(strcmp(Cr.nom,ca.nom)==0)
		{
			gtk_label_set_text(GTK_LABEL(output3),existe1);
			gtk_label_set_text(GTK_LABEL(output4),existe0);
			g=0;
		}
	else if(strcmp(Cr.nom,nomver)!=0)
		{
			gtk_label_set_text(GTK_LABEL(output3),existe0);
			gtk_label_set_text(GTK_LABEL(output4),success);
			g=1;
		}
	}
fclose(fg);


if(g==1){ajouter(ca);}
//check();
}


void
on_caradiobuttondebit_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
	strcpy(cm.type,"débit");
}
}


void
on_caradiobuttonmfumee_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
	strcpy(cm.type,"fumée");
}
}


void
on_caradiobuttonmtemp_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
	strcpy(cm.type,"temperature");
}
}


void
on_caradiobuttonmmouv_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
	strcpy(cm.type,"mouvement");
}
}


void
on_caentrymdone_changed                (GtkEditable     *editable,
                                        gpointer         user_data)
{
FILE* ft;
Capts C;
char nom[100];
char debit[20]="débit";
char dechet[20]="déchet";
char fumee[20]="fumée";
char temp[20]="temperature";
char mouv[20]="mouvement";
GtkWidget* input1;
GtkWidget* output1 ;
GtkWidget* output2 ;
GtkWidget* output3 ;
GtkWidget* output4 ;
GtkWidget* output5 ;
GtkWidget* output6 ;
GtkWidget* output7 ;
GtkWidget* output8 ;
GtkWidget* output9 ;

ft=fopen("capteurs.txt","r");
input1 = lookup_widget(editable,"caentrymdone");
output1 = lookup_widget(editable, "caentrymnom") ;
output2 = lookup_widget(editable, "caentrymlocalisation") ;
output3 = lookup_widget(editable, "caspinbuttonmvalmin") ;
output4 = lookup_widget(editable, "casbvm") ;
output5 = lookup_widget(editable, "caradiobuttonmdechet") ;
output6 = lookup_widget(editable, "caradiobuttondebit") ;
output7 = lookup_widget(editable, "caradiobuttonmfumee") ;
output8 = lookup_widget(editable, "caradiobuttonmtemp") ;
output9 = lookup_widget(editable, "caradiobuttonmmouv") ;
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
while(fscanf(ft,"%s %s %s %i %i %i ",C.nom,C.type,C.localisation,&C.valmin,&C.valmax,&C.etat)!=(EOF))
     {if(strcmp(C.nom,nom)==0)
			{
			gtk_entry_set_text(GTK_ENTRY(output1),C.nom);
			gtk_entry_set_text(GTK_ENTRY(output2),C.localisation);
			gtk_spin_button_set_value (GTK_SPIN_BUTTON(output3),C.valmin);
			gtk_spin_button_set_value (GTK_SPIN_BUTTON(output4),C.valmax);
			if(strcmp(C.type,debit)==0){gtk_toggle_button_set_active(GTK_RADIO_BUTTON(output6),TRUE);}
			else if (strcmp(C.type,dechet)==0){gtk_toggle_button_set_active(GTK_RADIO_BUTTON(output5),TRUE);}
			else if (strcmp(C.type,fumee)==0){gtk_toggle_button_set_active(GTK_RADIO_BUTTON(output7),TRUE);}
			else if (strcmp(C.type,temp)==0){gtk_toggle_button_set_active(GTK_RADIO_BUTTON(output8),TRUE);}
			else if (strcmp(C.type,mouv)==0){gtk_toggle_button_set_active(GTK_RADIO_BUTTON(output9),TRUE);}
		 	}
}
fclose(ft);	
}


void
on_caradiobuttonmdechet_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
	strcpy(cm.type,"déchet");
}
}


void
on_cabuttonmretour_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* cawindowgdc;
GtkWidget* treeviewtr;
GtkWidget* cawindowet1;

cawindowet1=lookup_widget(button,"cawindowmodifier");
gtk_widget_destroy(cawindowet1);
cawindowgdc=lookup_widget(button,"cawindowgdc");
cawindowgdc=create_cawindowgdc();
gtk_widget_show (cawindowgdc);
treeviewtr = lookup_widget(cawindowgdc,"caatreeviewgdc");
afficher_capts(treeviewtr);
}


void
on_cabuttonmvalider_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* input1;
GtkWidget* input2;
GtkWidget* Casbavmin;
GtkWidget* Caspinbuttonvmax;

//GtkWidget* combobox;
char success[100]="modification avec succès";
char verif[100]="confirmez la modification svp";
char nom[100];
char localisation[100];
input1 = lookup_widget(objet_graphique,"caentrymnom");
//combobox = lookup_widget(objet_graphique,"accombobox");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(cm.nom,nom);

input2 = lookup_widget(objet_graphique,"caentrymlocalisation");
strcpy(localisation,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(cm.localisation,localisation);

Casbavmin = lookup_widget(objet_graphique,"caspinbuttonmvalmin");
cm.valmin=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Casbavmin));
Caspinbuttonvmax = lookup_widget(objet_graphique,"casbvm");
cm.valmax=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Caspinbuttonvmax));
cm.etat=0;
GtkWidget* output7;
output7 = lookup_widget(objet_graphique,"aclmas");

if(rm==1)
{
gtk_label_set_text(GTK_LABEL(output7),success);
modifier(cm);
//check();
rm=0;
}
else{gtk_label_set_text(GTK_LABEL(output7),verif);}

}


void
on_cabuttonldtadministrateur_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_cabuttonldtnutritioninste_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_cabuttonldtadr_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_cabuttonldtadf_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_cabuttonldtsrh_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_cabuttonldttechnicien_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_acrbretour_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* cawindowgdc;
GtkWidget* treeviewtr;
GtkWidget* cawindowet1;

cawindowet1=lookup_widget(button,"acwrechercher");
gtk_widget_destroy(cawindowet1);
cawindowgdc=lookup_widget(button,"cawindowgdc");
cawindowgdc=create_cawindowgdc();
gtk_widget_show (cawindowgdc);
treeviewtr = lookup_widget(cawindowgdc,"caatreeviewgdc");
afficher_capts(treeviewtr);
}




void
on_ouijesuissure_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_acsbs_clicked                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* input1;
char ID[100];
char success[100]="suppression avec succès";
char verif[100]="confirmez la suppression svp";
input1 = lookup_widget(objet_graphique,"acsenom");
strcpy(ID,gtk_entry_get_text(GTK_ENTRY(input1)));
GtkWidget* output7;
output7 = lookup_widget(objet_graphique,"aclsas");


if (r==1)
	{
	supprimer(ID);
	gtk_label_set_text(GTK_LABEL(output7),success);
	r=0;
	}
else{gtk_label_set_text(GTK_LABEL(output7),verif);}




						
}


void
on_acsbsretour_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* cawindowgdc;
GtkWidget* treeviewtr;
GtkWidget* cawindowet1;

cawindowet1=lookup_widget(button,"acwindowsupprimer");
gtk_widget_destroy(cawindowet1);
cawindowgdc=lookup_widget(button,"cawindowgdc");

//gtk_widget_destroy(cawindowgdc);

cawindowgdc=create_cawindowgdc();
gtk_widget_show (cawindowgdc);
treeviewtr = lookup_widget(cawindowgdc,"caatreeviewgdc");
afficher_capts(treeviewtr);
}





void
on_ouijesuissure12_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(togglebutton))
{
	r=1;

}
}


void
on_acrbrvald12_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

FILE* ft;
Capts Cr;
char nom[100];
char safa1[40];
char safa2[40];
char safa3[40]="defectueux";
char safa4[40]="non defectueux";
GtkWidget* input1;
GtkWidget* output1 ;
GtkWidget* output2 ;
GtkWidget* output3 ;
GtkWidget* output4 ;
GtkWidget* output5 ;
GtkWidget* treedetail;
ft=fopen("capteurs.txt","r");
output1 = lookup_widget(objet_graphique,"acrlrimdonetypeaf");
output2 = lookup_widget(objet_graphique, "acrlrimdoneeopaf") ;
output3 = lookup_widget(objet_graphique, "acrlrimdonevlminaf") ;
output4 = lookup_widget(objet_graphique, "acrlrimdonevlmaxaf") ;
output5 = lookup_widget(objet_graphique, "acrlrimdoneetataf") ;
input1 = lookup_widget(objet_graphique, "acrenom") ;
treedetail = lookup_widget(objet_graphique,"acdtree56");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
while(fscanf(ft,"%s %s %s %i %i %i ",Cr.nom,Cr.type,Cr.localisation,&Cr.valmin,&Cr.valmax,&Cr.etat)!=(EOF))
     {if(strcmp(Cr.nom,nom)==0)
			{
			gtk_label_set_text(GTK_LABEL(output1),Cr.type);
			gtk_label_set_text(GTK_LABEL(output2),Cr.localisation);
			sprintf(safa1,"%i",Cr.valmin);
			gtk_label_set_text(GTK_LABEL(output3),safa1);
			sprintf(safa2,"%i",Cr.valmax);
			gtk_label_set_text(GTK_LABEL(output4),safa2);
			if(Cr.etat==1){gtk_label_set_text(GTK_LABEL(output5),safa3);}
			else if(Cr.etat==0){gtk_label_set_text(GTK_LABEL(output5),safa4);}
			
			afficher_detail(treedetail,Cr);
		 	}
	}
fclose(ft);
	
}


void
on_acdtree56_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_acctreeviews55_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_treeviewtrax_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_accbmvalider_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(togglebutton))
{
	rm=1;
}
}


void
on_caatreeviewgdc_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
//GtkWidget* input1;
//input1 = lookup_widget(objet_graphique,"caentrymnom");
GtkTreeIter iter;
gchar *nom;
gchar *type;
gchar *localisation;
gint *valmin;
gint *valmax;
gint *etat;


GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path))
{
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&nom,1,&type,2,&localisation,3,&valmin,4,&valmax,5,&etat,-1);
	strcpy(cra.nom,nom);
	strcpy(cra.type,type);
	strcpy(cra.localisation,localisation);
	cra.valmin=valmin;
	cra.valmax=valmax;
	cra.etat=etat;

}
}


gboolean
on_cawindowmodifier_focus_in_event     (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data)
{
GtkWidget* input1;
input1 = lookup_widget(widget,"caentrymdone");
gtk_entry_set_text(GTK_ENTRY(input1),cra.nom);
  return FALSE;
}


gboolean
on_acwindowsupprimer_focus_in_event    (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data)
{
GtkWidget* input1;
input1 = lookup_widget(widget,"acsenom");
gtk_entry_set_text(GTK_ENTRY(input1),cra.nom);
  return FALSE;
}

