#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* open (char *fic);
void test (FILE *f);
int compteur_ligne (FILE *f);
void write(int v);
int compteur_mots(FILE* f);
int compteur_caractere(FILE *f);
void simple (int option,char *fic);
void uni_option(char *lettre,int option,char *fic);
int* allocation(int dim);
int ligne_max(FILE *f);
int  maxtab(int *tab,int dim);
void multi_option(char **arg,int n);
