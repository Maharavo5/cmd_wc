#include "wc.h"

FILE* open (char *fic){
	FILE *f=NULL;
	
	f=fopen(fic,"r+");
	
	return f;
}

void test (FILE *f){
	if (f==NULL){
		printf ("erreur d'ouverture!!\n");
		exit (1);
	}
}

int compteur_ligne (FILE *f){
	int ligne=0;
	char chaine[100];
	rewind(f);
	while (feof(f)!=1){
		fgets (chaine,100,f);
		ligne++;
	}
	return ligne-1;
	printf ("%d",ligne);
}

void write(int v){
	printf ("%d  ",v);
}

int compteur_mots(FILE* f){
	int mot=0;
	char chaine[100];
	rewind(f);
	while (feof(f)!=1){
		fscanf(f,"%s",chaine);
		mot++;
	}
	return mot;
}

int* allocation(int dim){
	int *tab=NULL;
	tab=(int*)malloc(dim*sizeof(int));
	return tab;
}

int  maxtab(int *tab,int dim){
	int i;
	int max=0;
	for (i=0;i<dim;i++){
		if (max<tab[i]){
			max=tab[i];
		}
	}
	return max;
}


int ligne_max(FILE *f){
	int n=0;
	int lettre;
	int i=0;
	int c=0;
	int max;
	int *tab=NULL;
	n=compteur_ligne(f);
	rewind (f);
	tab=allocation(n);
	do {
		lettre=fgetc(f);
		if (lettre=='\n'){
			tab[i]=c-1;
			i++;
			c=0;
		}
		else
			c++;
	}while(lettre!=EOF);
	
	//rewind(f);
	max=maxtab(tab,n);
	return max;
}

int compteur_caractere(FILE *f){
	int caractere=0;
	int chaine;
	rewind (f);
	while (!feof(f)){
		chaine =fgetc(f);
		caractere++;
	}
	return caractere;
}

void simple (int option,char *fic){
	FILE *f=NULL;
	int ligne=0;
	int mot=0;
	int caractere=0;
	if (option==2){
		f=open(fic);
		test(f);
		ligne=compteur_ligne(f);
		mot=compteur_mots(f);
		caractere=compteur_caractere(f);
		printf ("%d   %d   %d  %s",ligne ,mot,caractere,fic);
	}
}

void uni_option(char *lettre,int option,char *fic){
	FILE *f=NULL;
	int ligne=0;
	int mot=0;
	int caractere=0;
	int max;
	if(option>2){
		f=open(fic);
		test(f);
		if(strcmp(lettre,"-c")==0 || strcmp(lettre,"-m")==0){
			caractere=compteur_caractere(f);
			write (caractere);
		}
		if(strcmp(lettre,"-w")==0){
			mot=compteur_mots(f);
			write(mot);
		}
		if(strcmp(lettre,"-l")==0){
			ligne=compteur_ligne(f);
			write(ligne);
		}
		if (strcmp(lettre,"-L")==0){
			max=ligne_max(f);
			write(max);
		}
		printf("\t%s\n",fic);
	
	}
}

void multi_option(char **arg,int n){
	FILE *f=NULL;
	int ligne=0;
	int mot=0;
	int caractere=0;
	int max;
	int mot_total;
	int ligne_total;
	int caracter_total;
	int larg_total;
	int i;
	int b;
	if (n > 2 && arg[1][0]=='-')
	{ 
		for (i=2;i<n;i++)
		{
			f=open(arg[i]);
			for(b=1;b<strlen(arg[1]);b++)
			{
				switch (arg[1][b])
				{
					case 'l':
						ligne=compteur_ligne(f);
						//ligne_total+=ligne;
						write (ligne);
						break;
					case 'w':	
						mot=compteur_mots(f);
						//mot_total+=mot;
						write(mot);
						break;
					case 'c':
						caractere=compteur_caractere(f);
						write (caractere);
						//caracter_total+=caractere;
						break;
					case 'm':
						caractere=compteur_caractere(f);
						//caracter_total+=caractere;
						write (caractere);
						break;
					case 'L':
						max=ligne_max(f);
						write(max);
						break;
					default:	
							break;
				}
				//display(n,ligne_total,mot_total,caracter_total,larg_total,arg[1]);
			}
			
			printf("\t%s",arg[i]);
				fclose(f);
				printf("\n");
		}
		
	}

}


