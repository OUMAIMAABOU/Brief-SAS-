#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct Gestion_Bancaire{
char CIN[30];
char nom[100];
char prenom[100];
float montant;
};
 struct Gestion_Bancaire compt1;
  struct Gestion_Bancaire compt[100];
   int i ;
void Ajouter()
{
 
for ( i = 0;i<100;i++){
 printf("\nENTREZ CIN:");
 scanf("%s",compt[i].CIN); 
 printf("\nENTREZ LE NOM:");
 scanf("%s",compt[i].nom);
 printf("\nENTREZ PRENOM:");

 scanf("%s",compt[i].prenom); 
 printf("\nSOLDE :");

 scanf("%f",&compt[i].montant);
 printf("\nBien ajouter:");
break ;
 }
}
void Afficher() 
{ 

 for(i=0;i<100;i++)
 {
 printf("CIN :%s",compt[i].CIN);
 printf("\nNom client : %s",compt[i].nom);
 printf("\n Prenom client :\t %s ",compt[i].prenom); 
 printf("\nSolde :%f  ",compt[i].montant);  

 }
 
}


void Supprimer()
{
 int i,j;
 char cin[20] ;

 
 int k ;
 k=-1;
 for(i=0;i<100;i++)
 { if(strcmp(compt[i].CIN,cin)==0)
   {
     k=1;
    for(j=i;j<100-1;j++)
    { 
      compt[j]=compt[j+1];
    }
    
   }
  
 }
 
 
 
}
void Trier() 
{
  int  c[100];
 int i,j;
 float a = 0;
 for(i=0;i<100;i++)
{
  if(compt[i].montant>compt[i+1].montant)
   {
     a=c[i];
     c[i]=c[j];
     c[j]=a;
   }
  }
 }
 

void save()
{
 FILE *cp;
  cp=fopen("Gestion_Bancaire.txt","a");
 for (i = 0; i<100;i++){



 fprintf(cp, "%s;%s;%s;%f\n",compt1.CIN, compt1.nom, compt1.prenom,compt1.montant);
  }

  
void afficher(){
  FILE *cp;
  cp = fopen("Gestion_Bancaire.txt","r");
  char bef[100][100];
  i = 0;
 while(fgets(bef[i], 100, cp)){
   printf("%s", bef[i]);
   i++;
 }
fclose(cp);

}
int main()
{
int ops ;
char qus;

do{
system("cls");
printf("\n #####MENU##### \n");
printf("\n 1.pour ajouter");
printf("\n 2.pour afficher");
printf("\n 3.pour Operation");
printf("\n 4.pour supprime");
printf("\n 5.SUPRIMER TOUT FICHES");
printf("\n 6.QUITTER");
do{
printf("\n entre votre choix :");
scanf("%d",&ops);

switch(ops){
case 1:
Ajouter();
break;
case 2:


break;
case 3:

break;
case 4:

break;

case 5:
save();

break;
case 6:
break;
}
}while(ops<1 || ops>6);

printf("\n continuez O/N?");
scanf("%s",&qus);
fflush(stdin);

}while (qus=='o' || qus=='O' );
 return 0;
}




