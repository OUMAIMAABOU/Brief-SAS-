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
  
float r[10];

void ajouter(){
FILE* cp;
cp =fopen("Gestion_Bancaire.txt","a");
printf("entrez CIN :");
scanf("%s",compt1.CIN);

printf("entrez nom :");
scanf("%s",compt1.nom);


printf("entrez prenom :");
scanf("%s",compt1.prenom);


printf("entrez montant :");
scanf("%f",&compt1.montant);

fprintf(cp, "%f;%s;%s;%s\n",compt1.montant,compt1.CIN, compt1.nom, compt1.prenom);
printf("bien ajouter:");

fclose(cp);

 

}

void afficher(){
  FILE *cp;
  cp = fopen("Gestion_Bancaire.txt","r");
  char bef[100][100];
  int i = 0;
 while(fgets(bef[i], 100, cp)){
   printf("%s", bef[i]);
   i++;
 }
fclose(cp);

}

void montant(){


FILE *cp;
cp = fopen("Gestion_Bancaire.txt","r");


   do {
     fscanf (cp,"%f",compt1.montant));

    
              printf("%f",compt1.montant);
              }while(!feof(cp));


fclose(cp);

}




/*void affichermontant(){


  FILE *cp;
  cp = fopen("Gestion_Bancaire.txt","r");
  

while(fread(&compt1, sizeof(struct Gestion_Bancaire), 1, cp)) 
  printf("%f",compt1.montant);       
 fclose(cp);}*/
    

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
void Recherche(){
   char cin[40];
   FILE * cp;
   cp= fopen ("Gestion_Bancaire.txt", "r");
   printf("donnez CIN a rechercher :");
   scanf("%s",cin);
    while (fread (&compt1, sizeof(compt1), 4, cp)){
   if (strcmp(compt1.CIN,cin) == 0){
   rewind(cp);
   printf("CIN DE CLIENT :%s\n", compt1.CIN );
   
   printf("nom de client : %s\n", compt1.nom );
   printf("Prenom : %s\n", compt1.prenom );
   printf("Solde : %f dh\n",compt1.montant );
   } else{
        printf("il n'existe pas");
    }while(!feof(cp));
   
   fclose(cp);
 

  
   }
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
  /*void afficmo(){
    FILE *cp ;
cp=fopen("Gestion_Bancaire.txt","r");
do{
fscanf(cp,"%s ;%s; %s ;%.4f \n",compt1.CIN,compt1.nom,compt1.prenom,compt1.montant); 
printf("%f",compt1.montant);

}while(!feof(cp));
   fclose(cp);
  }*/


  void operation(){
        float montant;

printf("entrez solde");
scanf("%f",&montant);
    char choix;
FILE *cp;
cp=fopen("Gestion_Bancaire.txt","r");
do{

fscanf(cp," %s ",compt1.CIN);
fscanf(cp," %s ",compt1.nom);
fscanf(cp," %s ",compt1.prenom);
fscanf(cp," %f ",&compt1.montant);

printf("pour clacluer le retrait clique qur R et D pour Depot ");
scanf( "%s" ,&choix);
if(choix=='R'){
printf(" le retrait est:%f Dh\n.",compt1.montant - montant );
}else if (choix=='R'){
  printf("Dépôt est:%f Dh\n.",compt1.montant + montant );

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
printf("\n 5.SUPRIMER TOUT FICHES");
printf("\n 6.QUITTER");
do{
printf("\n entre votre choix :")
;
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
montant();
break;

case 5:
Recherche();

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
