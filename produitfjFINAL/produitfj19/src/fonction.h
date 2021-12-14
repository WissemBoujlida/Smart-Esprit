#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

/*typedef struct date
{
int j;
int m;
int a;
}date;*/

typedef struct produit
{
int id;
char type[20];
char marque[20];
int ej;
int em;
int ea;
int fj;
int fm;
int fa;
int cout;
int quantite;
}produit;

int verif(char log[],char Pw[]);
void Ajouter(produit p);
void Supprimer(produit p);
//void Modifier(int id,char fich[]);
//void chercher(int id);
void afficher(GtkWidget *liste,char fname[]);
void afficher1(GtkWidget *liste,char fname[]);
void modifier(produit p);
void vider(GtkWidget *liste);
void trouver(char fich[],char rupt[]);
#endif
