#include <stdio.h>
#include <string.h>
#include <stdlib.h>



struct Gestion_Bancaire{
char CIN[30];
char nom[100];
char prenom[100];
char montant[100];
};

struct Gestion_Bancaire compt1;
void ajouter(){
FILE* cp;
cp =fopen("Gestion_Bancaire.txt","a");
fprintf(cp," ========================\n");
printf("entrez CIN :");
scanf("%s",&compt1.CIN);
fprintf(cp,"\n CIN de client est: %s",&compt1.CIN);
fflush(stdin);

printf("entrez nom :");
scanf("%s",&compt1.nom);
fprintf(cp,"\n le Nom de client :%s",&compt1.nom);
fflush(stdin);

printf("entrez prenom :");
scanf("%s",&compt1.prenom);
fprintf(cp,"\nPrénom de client :%s",&compt1.prenom);
fflush(stdin);

printf("entrez montant :");
scanf("%s",&compt1.montant);
fprintf(cp,"\nmontant est :%s DH",&compt1.montant);
fflush(stdin);


fclose(cp);

 

}

int main()
{
   
   ajouter();


    return 0;
}