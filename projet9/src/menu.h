


#include <gtk/gtk.h>



typedef struct menu{
    char id[10];
    char date[10];
    char nom[25];
    char type[20];
    char entree[30];
    char suite[30];
    char dessert[30];
}menu;
void ajouter(menu m);
void modifier(char identif[],char nouveau[],int choix);
void supprimer(char iden[] );
void chercher(char ident[]);
void afficher (char fichier[],GtkWidget *liste);
void meilleur();
