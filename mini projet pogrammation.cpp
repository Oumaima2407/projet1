#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int comparfich(char fich1[50],char fich2[50]){
char ch1[50],ch2[50];
int m,p,q;
p=q=0;
 FILE *f,*fo;
f=fopen(fich1,"r");
if(f==NULL ){
printf("erreur d'ouverture %s\n",fich1);
m=3;
} else
{

printf("ouverture %s avec succes\n",fich1);


fo=fopen(fich2,"r");
if(fo==NULL ){
printf("erreur d'ouverture %s\n",fich2);
m=3;
}
else{
m=1;
printf("ouverture %s avec succes\n",fich2);
do{
	if(fgets(ch1,50,f)==NULL)
	{
		p=1;
	}
	if(fgets(ch2,50,fo)==NULL)
	{
		q=1;
	}

if(strcmp(ch1,ch2)!=0)
{
m=0;
}
}while(q!=1||p!=1);
}
} 
return m;

fclose(f);
fclose(fo);				

}

void concatfich(char fich1[50],char fich2[50]){
	
	char ch1[50],ch2[50];
        FILE *f,*fo,*fc;
     f=fopen(fich1,"r");
      if(f==NULL )
	  {
        printf("erreur d'ouverture %s\n ",fich1);
      } 
	  else
      {
       printf("ouverture %s avec succes\n ",fich1);
        
	fo=fopen(fich2,"r");
    if(fo==NULL ){
        printf("\nerreur d'ouverture %s ",fich2);
        
    } 
    else{
    
    printf("ouverture %s avec succes\n",fich2);
    
    fc=fopen("fichier3.txt","w");

    
    while(fgets(ch1,50,f)!= NULL)
	{
    
    fputs(ch1,fc);
    }
    fprintf(fc,"\n");
    while(fgets(ch2,50,fo)!= NULL)
	{
    
    fputs(ch2,fc);
    }
fclose(f);
fclose(fo);	
fclose(fc);
	}}}
	
	
void RemplMot(char fich[50],char mot1[50],char mot2[50])
{   char t[25],c;                                                                                 
    int i;
	FILE *f;
	FILE *fo;
	f=fopen(fich,"r");
	if(f==NULL )
	  {
        printf("erreur d'ouverture %s\n ",fich);
      } 
	  else
      {
       printf("ouverture %s avec succes\n ",fich);
       
       fo=fopen("fichier4.txt","w");
       
       while(fscanf(f,"%s",t)!=EOF)
       {
       	
       	if(strcmp(t,mot1)==0)
			{
			   fputs(mot2,fo);
			}
			else
			{
			   fputs(t,fo);
			}
			
			c=fgetc(f);
			if(c!='ÿ')
			fputc(c,fo);
			 	
	   }
  	fclose(f);
    fclose(fo);				
	remove(fich);
    rename("fichier4.txt",fich);
    
			}

        	
   
      }
      
      main()
      {
      	char nomF[50],nomf[50];
      	char mot1[50],mot2[50];
      	int choix,sorti;
      	int s;
      	sorti=0;
      	do{
		 
      	printf("------------------Menu------------------\n");
      	printf("Taper 1 pour comparer le contenu de deux fichiers\n");
      	printf("Taper 2 pour concatener le contenu de deux fichiers\n");
      	printf("Taper 3 pour remplacer un mot dans un fichier\n");
      	printf("Taper 0 pour sortir du programme\n");
      	printf("-----------------------------------------\n");
      	printf("Votre choix : ");
      	scanf("%d",&choix);
      	switch(choix){
      		 case 1:{
      		 	
      		 	      printf("entrer le nom du fichier1: ");
      		 	      fflush(stdin);
                      gets(nomF);
                      printf("entrer le nom du fichier2: ");
                      fflush(stdin);
                      gets(nomf);
                      s=comparfich(nomF,nomf);
                      if(s==1)
                      {
                       printf("!!les deux fichier %s et %s sont identiques!!\n",nomF,nomf);
                      }
                      else if(s==0)
                      {
                       printf("!!les deux fichier %s et %s sont differents!!\n",nomF,nomf);
                      }
      		 	
      		 	
      		 	
				break;
			   }
			 case 2:{
			 	      
			 	      printf("entrer le nom du fichier1: ");
			 	      fflush(stdin);
                      gets(nomF);
                      printf("entrer le nom du fichier2: ");
                      fflush(stdin);
                      gets(nomf);

                      concatfich(nomF,nomf);
                      printf("!!!!!les deux fichier %s et %s sont concatener avec succes!!!!!\n",nomF,nomf);
			 	
			 	
			 	
			 	
			 	
			 	
				break;
			 }  
			 case 3:{
			 	      
			 	      printf("entrer le nom du fichier: ");
			 	      fflush(stdin);
                      gets(nomf);
                      printf("entrer le mot a remplacer : ");
                     
                      gets(mot1);
                      printf("entrer le nom du fichier: ");
                      gets(mot2);

                      RemplMot(nomf,mot1,mot2);

                      printf("!!!!!le mot '%s' a ete remplacer par le mot '%s' avec succes!!!!!\n",mot1,mot2);

			 	
			 	
			 	
			 	
			 	
				break;
			 }
			 case 0:{
			 	       
			 	       sorti=1;
			 	
				break;
			 }
      		
      		
      		
      		
		  }
      	
      	}while(sorti==0);
      	
      	
      	
      	
      	
      	
      	
      	
	  }




