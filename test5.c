#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Gestion_Bancaire{
char CIN[30];
char nom[100];
char prenom[100];
float montant;
};

  struct Gestion_Bancaire compt[100];
   int i ;
   int p=0;

void save()
{
 FILE *cp;
  cp=fopen("Gestion_Bancaire.txt","a");
fprintf(cp,"\n==================\n");

 fprintf(cp,"CIN               :%s",compt[i].CIN);
 fflush(cp);
fprintf(cp,"\nLE NOM EST       :%s",compt[i].nom);
 fflush(cp);
fprintf(cp,"\nPRENOM DE CLIENT :%s",compt[i].prenom);
 fflush(cp);
fprintf(cp,"\nSOLDE DE CLIENT  :%f",compt[i].montant);
 fflush(cp);
 fclose(cp);
}

void Ajouter()
{
 
 printf("\nENTREZ CIN:");
 scanf("%s",compt[p].CIN); 
 printf("\nENTREZ LE NOM:");
 scanf("%s",compt[p].nom);
 printf("\nENTREZ PRENOM:");

 scanf("%s",compt[p].prenom); 
 printf("\nSOLDE :");

 scanf("%f",&compt[p].montant);
 printf("\nBien ajouter:");
save();
p++;
}
void Affichertan() 

{ 

 for(i=0;i<p;i++)
 {
 printf("CIN              :%s",compt[i].CIN);
 printf("\nNom client     :\t %s",compt[i].nom);
 printf("\n Prenom client :%s ",compt[i].prenom); 
 printf("\nSolde          :%f  ",compt[i].montant);  

 }
 
}
void RechercherCompte(){
     char cin[20];
   
    printf("Enter CIN: ");
    scanf("%s",cin);

    for(i=0; i<p; i++){
    if(strcmp(compt[i].CIN,cin)==0){
        printf("CIN                 :%s",compt[i].CIN);
        printf("\n NOM DE CLIENT    :%s",compt[i].nom);
        printf("\n PRENOM DE CLIENT :%s",compt[i].prenom);
        printf("\n SOLDE            :%f",compt[i].montant);

    }
    printf("n'existe pas ");
    }
  }

 
 
void Ascendant(){ 
  int N=p;
  float max;
   int pmax=0;
  while(N>0)
   { 
      max=compt[0].montant;
							         
		for(i=0;i<N;i++)
	{
if(compt[i].montant>max)
{
max=compt[i].montant;
pmax=i;
}
										        	
}

												
for(i=pmax;i<N;i++)	
{
compt[i].montant=compt[i+1].montant;
}
												
compt[N-1].montant=max;
N--;
}
for(i=0;i<p;i++)
{
printf("%f \n",compt[i].montant);
}
}

void Descendant() { 
  int N=p;
  float max;
   int pmax=0;
  while(N>0)
{  max=compt[0].montant;
							    
for(i=0;i<N;i++)
{
if(compt[i].montant>max)
{
max=compt[i].montant;
pmax=i;
}
										        	
}
												
												
for(i=pmax;i<N;i++)	
{
compt[i].montant=compt[i+1].montant;
}
												
compt[N-1].montant=max;
N--;
}
for(i=p-1;i>=0;i--)
{
printf("%f \n",compt[i].montant);
}
}


  void operation(){
      char choix;
  char cin[20];
  float montant;

     printf("Enter CIN: ");
    scanf("%s",cin);
for(i=0; i<p; i++){
    if(strcmp(compt[i].CIN,cin)==0){
printf("entrez solde:");
scanf("%f",&montant);


printf("pour clacluer le retrait clique qur R et D pour Depot ");
scanf( "%s" ,&choix);
if(choix=='R'|| choix=='r' ){
printf(" le retrait est:%f Dh\n.",compt[i].montant - montant );
break;
}
 if (choix=='D'|| choix=='d'){
  printf(" Depot est:%f Dh\n.",compt[i].montant + montant );
break;
}

    }



}
    
  }



void afficher(){
  FILE *cp;
  cp = fopen("Gestion_Bancaire.txt","r");
  char bef[100][100];
  i = 0;
 while(fgets(bef[i], 100, cp)){
   printf("%s",bef[i]);
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
printf("\n 2.pour afficher Fichies");
printf("\n 3.pour Operation");
printf("\n 4.pour afficher");
printf("\n 5.Rechercher");
printf("\n 6.Ascendant");
printf("\n 7.Descendant");
printf("\n 8.QUITTER");
do{
printf("\n entre votre choix :")
;
scanf("%d",&ops);
fflush(stdin);

switch(ops){
case 1:
Ajouter();
break;
case 2:
afficher();
break;

case 3:
operation();
break;
case 4:

Affichertan();
break;

case 5:
RechercherCompte();
break;
case 6:
Ascendant();
break;
case 7:
 Descendant();
break;
case 8:

break;



}
}while(ops<1 || ops>8);

printf("\n continuez O/N?");
scanf("%s",&qus);
fflush(stdin);
}while (qus=='o' || qus=='O' );
 
}

    