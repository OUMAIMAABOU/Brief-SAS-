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

printf("entrez CIN :");
scanf("%s",compt1.CIN);
fprintf(cp,"%s;",compt1.CIN);
fflush(stdin);

printf("entrez nom :");
scanf("%s",compt1.nom);
fprintf(cp,"%s;",compt1.nom);
fflush(stdin);

printf("entrez prenom :");
scanf("%s",compt1.prenom);
fprintf(cp,"%s;",compt1.prenom);
fflush(stdin);

printf("entrez montant :");
scanf("%f",&compt1.montant);
fprintf(cp,"%f\n",compt1.montant);
fflush(stdin);


fclose(cp);

 

}


void afficher(){
  FILE *cp = fopen("Gestion_Bancaire.txt","r");
 while(fread(&compt1, sizeof(struct Gestion_Bancaire), 1, cp))
        printf (" %s %s %s %f\n", compt1.CIN,
       compt1.nom, compt1.prenom,compt1.montant);
fclose(cp);

}

/*void montant(float solde){
float t[100];
int i ;
for(i=0;i<100;i++){
  t[i]=solde;
}
}*/

void affichermontant(){


  FILE *cp;
  cp = fopen("Gestion_Bancaire.txt","r");
  

while(fread(&compt1, sizeof(struct Gestion_Bancaire), 1, cp))
    
printf("%f",compt1.montant); 
    
        
fclose(cp);

}
    

/*void rechercher(){
  char cin[20];
  FILE *cp = fopen("Gestion_Bancaire.txt","r");
  printf("donnez CIN de recherche :");
  scanf("%s",cin);

  while(1){
    
 fscanf(cp,"%s ",compt1.montant);
  if (strcmp(fgets (compt1.CIN, 30, cp),cin) == 0){

  fscanf(cp,"%s ,%s , %s , %f", compt1.CIN, compt1.nom, 
  compt1.prenom, &compt1.montant);
  printf("CIN\t: %s" ,compt1.CIN);
  printf("CIN\t: %s", compt1.nom);
  printf("CIN\t: %s", compt1.prenom);
  printf("CIN\t: %f", compt1.montant);
  fflush(stdin);

  }
  else {
    printf("n'exist pas");
  }
  break ;}
  fclose(cp);

}*/
void re(){
  char cin[20];

   FILE * cp;

   cp = fopen ("Gestion_Bancaire.txt", "w+");
 rewind(cp);
    printf("donnez CIN de recherche :");
  scanf("%s",cin);
  do{
       fscanf(cp, " %s %s %s %f", compt1.CIN,compt1.nom, compt1.prenom,compt1.montant);
 
   if (strcmp(compt1.CIN,cin) == 0){
   

   
   printf("CIN DE CLIENT :%s\n", compt1.CIN );
   printf("nom de client : %s\n", compt1.nom );
   printf("Prenom : %s\n", compt1.prenom );
   printf("Solde : %f dh\n",compt1.montant );
   }
  
   }while(!feof(cp));
 fclose(cp);
}


 

/*void supprimer(){
FILE *cp ,*c;
cp=fopen("Gestion_Bancaire.txt","r");
c=fopen("compte.txt","a");
do{
fscanf(cp,"%s ;%s; %s ;%.4f \n",&compt1.CIN,&compt1.nom,&compt1.prenom,&compt1.montant);
fscanf(c,"%s ;%s; %s ;%.4f \n",&compt1.CIN,&compt1.nom,&compt1.prenom,&compt1.montant);
} while(!feof(cp));
fclose(cp);
fclose(c);
remove("compte.txt");
rename("compte.txt","Gestion_Bancaire.txt");
printf("bien suppr");
}*/
  void amo(){
    FILE *cp ;
cp=fopen("Gestion_Bancaire.txt","r");
do{
fscanf(cp,"%s ;%s; %s ;%.4f \n",compt1.CIN,compt1.nom,compt1.prenom,compt1.montant); 
printf("%f",compt1.montant);

}while(!feof(cp));
   fclose(cp);
  }


  void operation(){
        float monatant

printf("entrez solde");
scanf("%f",&montant);
    char choix;
FILE *cp;
cp=fopen("Gestion_Bancaire.txt","r");
do{

fscanf(cp," %s ",&compt1.CIN);
fscanf(cp," %s ",&compt1.nom);
fscanf(cp," %s ",&compt1.prenom);
fscanf(cp," %f ",&compt1.montant);
print()
printf("pour clacluer le retrait clique qur R et D pour Dépôt ");
scanf("%c",choix);
if(choix=='R'){
printf(" le retrait est:%f Dh\n.",compt1.montant - solde );
}else if (choix=='R'){
  printf("Dépôt est:%f Dh\n.",compt1.montant + solde );

}else {
 printf("choix incorrect" );
 
}
fflush(stdin);



} while(!feof(cp));
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
printf("\n 5.Quitter");
do{
printf("\n entre votre choix :");
scanf("%d",&ops);

switch(ops){
case 1:
ajouter();
break;
case 2:
afficher();

break;
case 3:
operation();
break;
case 4:
amo();



break;
case 5:

break;
   default:
   printf("\n le choix n'existe pas");

}
}while(ops<1 || ops>5);

printf("\n continuez O/N?");
scanf("%s",&qus);
fflush(stdin);
}while (qus=='o' || qus=='O' );



    return 0;
}