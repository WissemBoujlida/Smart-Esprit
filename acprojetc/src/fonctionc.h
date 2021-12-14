#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
typedef struct capteurs
{
    char nom[40];
    char type[20];
    char localisation[40];
    int valmin;
    int valmax;
    int etat;
}Capts;

void ajouter(Capts C);
void afficher ();
void rechercher(int name);
void defectueux();
void supprimer(char b[]);
void modifier(Capts C1);
void ajouter_nom();
void check();
void afficher_detail(GtkWidget *liste, Capts C);
void afficher_securite(GtkWidget *liste);
void afficher_capts(GtkWidget *liste);
