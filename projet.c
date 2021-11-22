#include <stdio.h>
#include <string.h>
#include <stdlib.h>



struct Gestion_Bancaire{
char CIN[30];
char nom[100];
char prenom[100];
float montant;
};

struct Gestion_Bancaire compt1;
void ajouter(){
FILE* cp;
cp =fopen("Gestion_Bancaire.txt","a");
fprintf(cp,"\n ========================\n");
printf("entrez CIN :");
scanf("%s",&compt1.CIN);
fprintf(cp,"\n CIN de client est: %s",compt1.CIN);
fflush(stdin);

printf("entrez nom :");
scanf("%s",&compt1.nom);
fprintf(cp,"\n le Nom de client :%s",compt1.nom);
fflush(stdin);

printf("entrez prenom :");
scanf("%s",&compt1.prenom);
fprintf(cp,"\nPrénom de client :%s",compt1.prenom);
fflush(stdin);

printf("entrez montant :");
scanf("%f",&compt1.montant);
fprintf(cp,"\nmontant est :%f DH",compt1.montant);
fflush(stdin);


fclose(cp);

 

}

void afficher(){
  FILE *cp;
  cp = fopen("Gestion_Bancaire.txt","r");
 while(fread(&compt1, sizeof(struct Gestion_Bancaire), 1, cp))
        printf (" %s %s %s %f\n", compt1.CIN,
       compt1.nom, compt1.prenom,compt1.montant);
fclose(cp);

}
    

  
  
 

int main()
{
   
  
afficher();

    return 0;
}