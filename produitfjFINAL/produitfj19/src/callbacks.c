#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"

int x=0,y=0,z=0;

void FJsendmail(char body[])
{
        char cmd[300];
        FILE *fp = fopen("mail.txt","w+"); // open it for writing.
        fprintf(fp,"%s\n",body);        // write body to it.
        fclose(fp);             // close it.

        sprintf(cmd,"curl smtps://smtp.gmail.com:465 -v --mail-from \"stockproduit@gmail.com:Produit12345678\" --mail-rcpt \"mohamedfadhel.jaiet@esprit.tn\" --ssl -u stockproduit@gmail.com:Produit12345678 -T mail.txt -k --anyauth"); // prepare command.
        system(cmd);     // execute it.
}



void
on_FJcheckbutton1_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	{
		z=1;
	}
}


void
on_FJradiobutton1_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{/*if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=1;}*/

}


void
on_FJretour3_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)

{GtkWidget *FJafficher21,*FJmodifier;

FJmodifier=lookup_widget(objet,"FJmodifier");

gtk_widget_destroy(FJmodifier);
FJafficher21=create_FJafficher21();
gtk_widget_show(FJafficher21);


}


void
on_FJbutton1_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
produit p,p2[100];
int i=0,j,s=1;
char ch[200];
GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7, *input8, *input9, *input10, *input11, *output1; 
GtkWidget *FJajouter;
FILE *fi;

FJajouter=lookup_widget(objet,"FJajouter");
fi=fopen("stock.txt","r");
output1 =lookup_widget(objet,"FJlabel73"); 
input1=lookup_widget(objet,"FJentry11");
input2=lookup_widget(objet,"FJcomboboxentry1");
input3=lookup_widget(objet,"FJentry13");
input4=lookup_widget(objet,"FJspinbutton9");
input5=lookup_widget(objet,"FJspinbutton10");
input6=lookup_widget(objet,"FJspinbutton11");
input7=lookup_widget(objet,"FJspinbutton12");
input8=lookup_widget(objet,"FJspinbutton13");
input9=lookup_widget(objet,"FJspinbutton14");
input10=lookup_widget(objet,"FJentry14");
input11=lookup_widget(objet,"FJspinbutton8");

p.id=atoi(gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input2)));
strcpy(p.marque,gtk_entry_get_text(GTK_ENTRY(input3)));
p.ej=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
p.em=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
p.ea=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
p.fj=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
p.fm=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
p.fa=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input9));
p.cout=atoi(gtk_entry_get_text(GTK_ENTRY(input10)));
p.quantite=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input11));
while(fscanf(fi,"%d %s %s %d /%d /%d %d /%d /%d %d %d \n",&p2[i].id,p2[i].type,p2[i].marque,&p2[i].ej,&p2[i].em,&p2[i].ea,&p2[i].fj,&p2[i].fm,&p2[i].fa,&p2[i].cout,&p2[i].quantite)!=EOF)
	{
	i++;
	}
fclose(fi);
if (y==1)
	{for(j=0;j<i+1;j++)
	{if (p.id==p2[j].id){
		strcpy(ch,"Ce produit existe déjà");
		gtk_label_set_text(GTK_LABEL(output1),ch);
		s=0;
		}
	}
	if(s==1)
	{strcpy(ch,"le produit a été ajouté avec succés");
	gtk_label_set_text(GTK_LABEL(output1),ch);
	Ajouter(p);
	//sendmail("le produit a été ajouté avec succés");
}
	

	}
}


void
on_FJradiobutton2_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{y=1;}

}


void
on_FJretour2_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_FJbutton2_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_FJretour4_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_FJbutton3_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{FILE* ft;
produit p;
int id1,i=0;
char ch[100];
char ej1[40];
char em1[40];
char ea1[40];
char fj1[40];
char fm1[40];
char fa1[40];
char cout1[40];
char quantite1[40];

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
GtkWidget* output10 ;
GtkWidget* output11 ;

ft=fopen("stock.txt","r");
output1 = lookup_widget(objet_graphique,"FJlabel75");
output2 = lookup_widget(objet_graphique,"FJlabel76");
output3 = lookup_widget(objet_graphique,"FJlabel68");
output4 = lookup_widget(objet_graphique,"FJlabel69");
output5 = lookup_widget(objet_graphique,"FJlabel77");
output6 = lookup_widget(objet_graphique,"FJlabel71");
output7 = lookup_widget(objet_graphique,"FJlabel72");
output8 = lookup_widget(objet_graphique,"FJlabel78");
output9 = lookup_widget(objet_graphique,"FJlabel79");
output10 = lookup_widget(objet_graphique,"FJlabel80");
output11 = lookup_widget(objet_graphique,"FJlabel1919");
input1 = lookup_widget(objet_graphique, "FJentry16") ;
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(input1)));
id1=atoi(ch);
while(fscanf(ft,"%d %s %s %d /%d /%d %d /%d /%d %d %d \n",&p.id,p.type,p.marque,&p.ej,&p.em,&p.ea,&p.fj,&p.fm,&p.fa,&p.cout,&p.quantite)!=EOF){
     	if(p.id==id1)
			{
			i=1;
			gtk_label_set_text(GTK_LABEL(output1),p.type);
			gtk_label_set_text(GTK_LABEL(output2),p.marque);
			sprintf(ej1,"%d",p.ej);
			gtk_label_set_text(GTK_LABEL(output3),ej1);
			sprintf(em1,"%d",p.em);
			gtk_label_set_text(GTK_LABEL(output4),em1);
			sprintf(ea1,"%d",p.ea);
			gtk_label_set_text(GTK_LABEL(output5),ea1);
			sprintf(fj1,"%d",p.fj);
			gtk_label_set_text(GTK_LABEL(output6),fj1);
			sprintf(fm1,"%d",p.fm);
			gtk_label_set_text(GTK_LABEL(output7),fm1);
			sprintf(fa1,"%d",p.fa);
			gtk_label_set_text(GTK_LABEL(output8),fa1);
			sprintf(cout1,"%d",p.cout);
			gtk_label_set_text(GTK_LABEL(output9),cout1);
			sprintf(quantite1,"%d",p.quantite);
			gtk_label_set_text(GTK_LABEL(output10),quantite1);
		
		 	}
	}
if (i==0)
	{gtk_label_set_text(GTK_LABEL(output11),"Ce produit n existe pas");}
fclose(ft);
	
}

void
on_FJretour5_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *FJafficher21,*FJchercher;

FJchercher=lookup_widget(objet,"FJchercher");

gtk_widget_destroy(FJchercher);
FJafficher21=create_FJafficher21();
gtk_widget_show(FJafficher21);

}


void
on_FJretour1_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)

{GtkWidget *FJafficher21,*FJrupturedestock;

FJrupturedestock=lookup_widget(objet,"FJrupturedestock");

gtk_widget_destroy(FJrupturedestock);
FJafficher21=create_FJafficher21();
gtk_widget_show(FJafficher21);

}


void
on_FJtreeview2_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gint id;
	gchar* type;
	gchar* marque;
	gint ej;
	gint em;
	gint ea;
	gint fj;
	gint fm;
	gint fa;
	gint cout;
	gint quantite;
	produit p;


GtkTreeModel *model=gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model, &iter, path))
{
	gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &id, 1, &type, 2, &marque, 3, &ej, 4, &em, 5, &ea, 6, &fj, 7, &fm, 8, &fa, 9, &cout, 10, &quantite, -1);
	p.id=id;
	strcpy(p.type,type);
	strcpy(p.marque,marque);
	p.ej=ej;
	p.em=em;
	p.ea=ea;
	p.fj=fj;
	p.fm=fm;
	p.fa=fa;
	p.cout=cout;
	p.quantite=quantite;
	Supprimer(p);
	sendmail("le produit a été supprimé avec succés");
	afficher(treeview,"stock.txt");
}

}


void
on_FJbuttonafficher_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *FJafficher21;
GtkWidget *FJajouter;
GtkWidget *FJtreeview2;

FJajouter=lookup_widget(objet,"FJajouter");

gtk_widget_destroy(FJajouter);
FJafficher21=lookup_widget(objet,"FJafficher21");
FJafficher21=create_FJafficher21();

gtk_widget_show(FJafficher21);

FJtreeview2=lookup_widget(FJafficher21,"FJtreeview2");
afficher(FJtreeview2,"stock.txt");
}


void
on_FJActualiser12_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *FJafficher21,*w1;
GtkWidget *FJtreeview2;

w1=lookup_widget(objet,"FJafficher21");
FJafficher21=create_FJafficher21();
gtk_widget_show(FJafficher21);
gtk_widget_hide(w1);
FJtreeview2=lookup_widget(FJafficher21,"FJtreeview2");
//gtk_widget_show_all(FJafficher21);


//vider(FJtreeview2);
afficher(FJtreeview2,"stock.txt");

}


void
on_FJmod_clicked                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{produit p,p2[100];
int i=0,j,m=1;
char ch[100];
GtkWidget* output1;
GtkWidget* input1;
GtkWidget* input2;
GtkWidget* input3;
GtkWidget* input4;
GtkWidget* input5;
GtkWidget* input6;
GtkWidget* input7;
GtkWidget* input8;
GtkWidget* input9;
GtkWidget* input10;
GtkWidget* input11;
FILE *fi;
   	
fi=fopen("stock.txt","r");
output1 =lookup_widget(objet_graphique,"FJlabel72"); 
input1=lookup_widget(objet_graphique,"FJentry9");
input2=lookup_widget(objet_graphique,"FJcomboboxentry2");
input3=lookup_widget(objet_graphique,"FJentry10");
input4=lookup_widget(objet_graphique,"FJspinbutton2");
input5=lookup_widget(objet_graphique,"FJspinbutton3");
input6=lookup_widget(objet_graphique,"FJspinbutton4");
input7=lookup_widget(objet_graphique,"FJspinbutton5");
input8=lookup_widget(objet_graphique,"FJspinbutton6");
input9=lookup_widget(objet_graphique,"FJspinbutton7");
input10=lookup_widget(objet_graphique,"FJentry8");
input11=lookup_widget(objet_graphique,"FJspinbutton1");

p.id=atoi(gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input2)));
strcpy(p.marque,gtk_entry_get_text(GTK_ENTRY(input3)));
p.ej=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
p.em=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
p.ea=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
p.fj=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
p.fm=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
p.fa=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input9));
p.cout=atoi(gtk_entry_get_text(GTK_ENTRY(input10)));
p.quantite=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input11));
while(fscanf(fi,"%d %s %s %d /%d /%d %d /%d /%d %d %d \n",&p2[i].id,p2[i].type,p2[i].marque,&p2[i].ej,&p2[i].em,&p2[i].ea,&p2[i].fj,&p2[i].fm,&p2[i].fa,&p2[i].cout,&p2[i].quantite)!=EOF)
	{
	i++;
	}
fclose(fi);
if(z==1)
	{for(j=0;j<i+1;j++)
	{if (p.id==p2[j].id){
		strcpy(ch,"Modifié avec succés");
		gtk_label_set_text(GTK_LABEL(output1),ch);
		modifier(p);
		//sendmail("le produit a été modifié avec succés");
		z=0;
		m=0;
		}
	}
	if(m==1)
	{strcpy(ch,"Ce produit n'existe pas verifiez l'id");
	gtk_label_set_text(GTK_LABEL(output1),ch);}
	}
else
	gtk_label_set_text(GTK_LABEL(output1),"Confirmez svp");
	}

void
on_FJradiobuttonnon_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{y=0;
}


void
on_FJboutonmodifier_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *FJafficher21,*FJmodifier;

FJafficher21=lookup_widget(objet,"FJafficher21");

gtk_widget_destroy(FJafficher21);
FJmodifier=create_FJmodifier();
gtk_widget_show(FJmodifier);

}


void
on_FJboutonchercher_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *FJafficher21,*FJchercher;

FJafficher21=lookup_widget(objet,"FJafficher21");

gtk_widget_destroy(FJafficher21);
FJchercher=create_FJchercher();
gtk_widget_show(FJchercher);
}


void
on_FJruptstock1_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *FJrupturedestock;
GtkWidget *FJafficher21;
GtkWidget *FJtreeview1;

FJafficher21=lookup_widget(objet,"FJafficher21");

gtk_widget_destroy(FJafficher21);
//FJrupturedestock=lookup_widget(objet,"FJrupturedestock");
FJrupturedestock=create_FJrupturedestock();

gtk_widget_show(FJrupturedestock);

FJtreeview1=lookup_widget(FJrupturedestock,"FJtreeview1");
afficher1(FJtreeview1,"stock.txt");

}


void
on_FJentry9_changed                    (GtkEditable     *editable,
                                        gpointer         user_data)

{FILE* ft;
produit p;
int id1;
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
GtkWidget* output10 ;
char coutt[20];
char Matrice[4][20]={"Viande","Fruit","Legume","Autre"};
int i=0;

ft=fopen("stock.txt","r");
input1 = lookup_widget(editable,"FJentry9");
output1 = lookup_widget(editable, "FJcomboboxentry2") ;
output2 = lookup_widget(editable, "FJentry10") ;
output3 = lookup_widget(editable, "FJspinbutton2") ;
output4 = lookup_widget(editable, "FJspinbutton3") ;
output5 = lookup_widget(editable, "FJspinbutton4") ;
output6 = lookup_widget(editable, "FJspinbutton5") ;
output7 = lookup_widget(editable, "FJspinbutton6") ;
output8 = lookup_widget(editable, "FJspinbutton7") ;
output9 = lookup_widget(editable, "FJentry8") ;
output10 = lookup_widget(editable, "FJspinbutton1") ;
id1=atoi(gtk_entry_get_text(GTK_ENTRY(input1)));
while(fscanf(ft,"%d %s %s %d /%d /%d %d /%d /%d %d %d \n",&p.id,p.type,p.marque,&p.ej,&p.em,&p.ea,&p.fj,&p.fm,&p.fa,&p.cout,&p.quantite)!=EOF)
     {if(p.id==id1)
		{	while(i<4 && strcmp(Matrice[i],p.type)!=0)
				{
					i++;
				}

			gtk_combo_box_set_active(GTK_COMBO_BOX(output1),i);
			gtk_entry_set_text(GTK_ENTRY(output2),p.marque);
			gtk_spin_button_set_value (GTK_SPIN_BUTTON(output3),p.ej);
			gtk_spin_button_set_value (GTK_SPIN_BUTTON(output4),p.em);
			gtk_spin_button_set_value (GTK_SPIN_BUTTON(output5),p.ea);
			gtk_spin_button_set_value (GTK_SPIN_BUTTON(output6),p.fj);
			gtk_spin_button_set_value (GTK_SPIN_BUTTON(output7),p.fm);
			gtk_spin_button_set_value (GTK_SPIN_BUTTON(output8),p.fa);
			sprintf(coutt,"%d",p.cout);
			gtk_entry_set_text(GTK_ENTRY(output9),coutt);
			gtk_spin_button_set_value (GTK_SPIN_BUTTON(output10),p.quantite);
			
		 }
	}
fclose(ft);	
}




void
on_FJretour69_clicked                  (GtkWidget       *objet,
                                       gpointer         user_data)
{
GtkWidget *FJajouter,*FJafficher21;

FJafficher21=lookup_widget(objet,"FJafficher21");

gtk_widget_destroy(FJafficher21);
FJajouter=create_FJajouter();
gtk_widget_show(FJajouter);
}

