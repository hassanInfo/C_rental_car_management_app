#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
typedef struct Voiture
{
       int   idVoiture;
       char  marque[15];
       char  nomVoiture[15];
       char  couleur[7];
       int   nbplaces;
       int   prixJour;
       char  EnLocation[4];

}voiture;

typedef struct
{

       int   j;
       int   m;
       int   a;

}date;

typedef struct contratLocation
{
       float numContrat;
       int   idVoiture;
       int   idClient;
       date  debut;
       date  fin;
       int   cout;
}contrat;

typedef struct Client
{
       int  idClient;
       char nom[20];
       char prenom[20];
       int  cin;
       char adresse[15];
       int  telephone;

}client;
///**********************************************
void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}
///**********************************************

int lire(char *chaine, int longueur)
{
    char *positionEntree = NULL;

    if (fgets(chaine, longueur, stdin) != NULL)
    {
        positionEntree = strchr(chaine, '\n');
        if (positionEntree != NULL)
        {
            *positionEntree = '\0';
        }
        else
        {
            viderBuffer();
        }
        return 1;
    }
    else
    {
        viderBuffer();
        return 0;
    }
}
///**********************************************

int lireChInt(void)
{
    char  ch[6];
          lire(ch,6);
          if(!atoi(ch))
          {
              printf("la saisie est invalide( reessayer )!!! \n");
              return lireChInt();
          }
    return atoi(ch);
}
///**********************************************

void M_NO(int id,char *NO )
{
          FILE     *fp;

          voiture  V ,*Tab;

          int      n=1 , i;

          fp=fopen("Voitures.bin","rb");

          if(!fp)
          {
              printf("Problème !!!!\n");
              exit(1);
         }

        Tab=(voiture*)malloc(n*sizeof(voiture));

        while(fread(&V,sizeof(V),1,fp)){

                  if(V.idVoiture==id)
                     strcpy(V.EnLocation,NO);

                  Tab[n-1]=V;

                   n++;

                  Tab=(voiture*)realloc(Tab,n*sizeof(voiture));


          }

            fclose(fp);

            fp=fopen("Voitures.bin","wb");


            fwrite(Tab,sizeof(Tab[0]),n-1,fp);

            fclose(fp);

}
///**********************************************

int R_E(int id,char *fichier)
{
        FILE *fp;

        fp=fopen(fichier,"rb");

        if(!fp)
        {
            printf("Problème !!!!\n");
            exit(3);
        }

       if(fichier=="Voitures.bin")
       {
            voiture V;

            while(fread(&V,sizeof(V),1,fp)){

                   if(V.idVoiture==id)
                    {
                         fclose(fp);

                         return 1;
                   }

               }
       }

       else if(fichier=="Clients.bin")
      {
              client Cl;

              while(fread(&Cl,sizeof(Cl),1,fp)){

                      if(Cl.idClient==id)
                      {
                         fclose(fp);

                         return 1;
                      }

                  }
       }

       else
       {
             contrat Con;

             while(fread(&Con,sizeof(Con),1,fp)){

                       if(Con.idVoiture==id)
                       {
                           fclose(fp);

                          return 1;
                       }

                 }
       }

       fclose(fp);

    return 0;

}
///**********************************************

void retourner_v(char *fichier ,int a,int b)
{
         int id;



printf("\n\n\n\n\n\n\n\n");
printf("   Entrer le ID de cette voiture\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");

        id=lireChInt();

        if(!R_E(id,fichier))
         {
printf("   Pas de voiture de cet ID      \n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");
         }
        else
        {
               S_E("ContratsLocations.bin",-1,id);
               M_NO(id,"non");
       }

printf("\n\xb1 terminee \xb1\n");

}
///**********************************************

void louer_v(char *fichier ,int a,int b)
{
          int id;

printf("\n\n\n\n\n\n\n\n");
printf("   Entrez le ID du clients\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");

          b=lireChInt();

         if(!R_E(b,"Clients.bin"))
         {
                system("cls");
printf("\n\n\n\n\n\n\n\n");
printf("   Vous devrez remplir ces information\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");
printf("   par l'option ajouter[2] apres 7s\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");

              Sleep(7000);
              system("cls");
              menu_cli();
       }
       else
        {
               L_E(fichier, 1,-1);

printf("   Il suffit de donner le ID de voiture (regardez la liste ci-dessus)\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 ");
printf("\xc4 \xc4 \xc4 \xc4 \xc4 \xc4 ");
printf("\xc4 \xc4 \xc4 \xc4 \xc4 \xc4 ");
printf("\xc4 \xc4 \xc4 \xc4 \xc4 \xc4 ");
printf("\xc4 \xc4 \xc4 \xc4 \xc4 \xc4 ");
printf("\xc4 \xc4 \xc4 \xc4 \n");

              id=lireChInt();

              system("cls");


             if(!R_E(id,fichier))
              {
printf("   la voiture n'existe pas!!!\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4");
printf(" \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");
              }

            else if(R_E(id,"ContratsLocations.bin"))
            {
printf("\n\n\n\n\n\n\n\n");
printf("   la voiture est en location!!!\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 ");
printf("\xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");
            }

         else
            {
                   A_E("ContratsLocations.bin",id,b);
                   M_NO(id,"oui");
            }
      }
printf("\n\xb1 terminee \xb1\n");

}
///**********************************************

void S_E(char *fichier ,int a,int b)
{
          FILE *fp=NULL;

          int i , n=0;

          int id=b;

printf("\n\n\n\n\n\n\n\n");



         if(b==-1)
         {
printf("   Entrez le ID de l'element à supprimer\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 ");
printf("\xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");

                if(!strcmp(fichier,"ContratsLocations.bin"))
                    {
printf("   (le ID c'est du voiture de cette contrat)\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4");
printf("\xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");
                    }

                     id=lireChInt();

         }


         if(!R_E(id,fichier))
         {
printf("   Il faut d'abord que l'element à\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 ");
printf("\xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");
printf("   suprimer soit existe dans la liste\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 ");
printf("\xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");

        }
        else
        {
                 fp=fopen(fichier,"rb");

                if(!fp)
                {
                     printf("Problème !!!!\n");
                     exit(1);
                }


               if(fichier=="Voitures.bin")
                {
                     voiture  *Tab ;

                     Tab=(voiture*)malloc(n*sizeof(voiture));

                   do{

                    Tab=(voiture*)realloc(Tab,++n*sizeof(voiture));

                     }while(fread(&Tab[n-1],sizeof(voiture),1,fp));


                     fclose(fp);

                     fp=fopen(fichier,"wb");

                     for(i=0;i<n-1;i++)
                     {
                           if(Tab[i].idVoiture!=id)
                                    fwrite(&Tab[i],sizeof(voiture),1,fp);
                     }
               }
              else if(fichier=="Clients.bin")
              {
                    client *Tab ;

                    Tab=(client*)malloc(n*sizeof(client));

                    do{
                         Tab=(client*)realloc(Tab,++n*sizeof(client));
                         }while(fread(&Tab[n-1],sizeof(client),1,fp));

                fclose(fp);
                fp=fopen(fichier,"wb");

                for(i=0;i<n-1;i++)
                 {
                       if(Tab[i].idClient!=id)
                              fwrite(&Tab[i],sizeof(client),1,fp);

                }
             fclose(fp);
           }
           else
            {
                contrat *Tab ;

                Tab=(contrat*)malloc(n*sizeof(contrat));

               do{
                   Tab=(contrat*)realloc(Tab,++n*sizeof(contrat));

                    }while(fread(&Tab[n-1],sizeof(contrat),1,fp));

                   fclose(fp);
                   fp=fopen(fichier,"wb");

                for(i=0;i<n-1;i++)
                {
                    if(Tab[i].idVoiture!=id)
                              fwrite(&Tab[i],sizeof(contrat),1,fp);
                }

           }

            fclose(fp);
        }

  printf("\n\xb1 terminee \xb1\n");

}
///**********************************************

void M_E(char *fichier ,int a,int b)
{
          FILE *fp=NULL;

          int i , id , n=1;

printf("\n\n\n\n\n\n\n\n");
printf("   Entrez le ID de l'element à modifier\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 ");
printf("\xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");

         if(fichier=="ContratsLocations.bin")
            {
printf("   (le ID c'est du voiture de cette contrat)\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4");
printf("\xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");
           }

            id=lireChInt();

           if(!R_E(id,fichier))
           {
printf("   Il faut d'abord que l'element à\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 ");
printf("\xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");
printf("   modifier soit existe dans la liste\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 ");
printf("\xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");
          }
         else
          {
                 fp=fopen(fichier,"rb");

                 if(!fp)
                 {
                      printf("Problème !!!!\n");
                      exit(2);
                 }

                if(fichier=="Voitures.bin")
                {
                      voiture V ,*Tab ;

                      Tab=(voiture*)malloc(n*sizeof(voiture));

                      while(fread(&V,sizeof(V),1,fp)){

                              if(V.idVoiture==id)
                              {
printf("   Entrer les informations comme format\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4");
printf(" \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");
printf("   ID,Marque,Nom,Couleur,Nombre de places\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 ");
printf("\xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");
printf("   Prix/jour est en location(oui/non)\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 ");
printf("\xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");
printf("   Attention l'ordre est imprtant\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 ");
printf("\xc4 \xc4 \xc4 \xc4\n");

                             V.idVoiture=lireChInt();
                             lire(V.marque,15);
                             lire(V.nomVoiture,15);
                             lire(V.couleur,7);
                             V.nbplaces=lireChInt();
                             V.prixJour=lireChInt();
                             lire(V.EnLocation,4);

                           }

                            strlwr(V.EnLocation);
                           Tab[n-1]=V;
                            Tab=(voiture*)realloc(Tab,++n*sizeof(voiture));

                          }

                          fclose(fp);
                          fp=fopen(fichier,"wb");
                          fwrite(Tab,sizeof(voiture),n-1,fp);

                }

              else if(fichier=="Clients.bin")
               {
                     client  Cl , *Tab  ;

                     Tab=(client*)malloc(n*sizeof(client));
                     while(fread(&Cl,sizeof(Cl),1,fp)){

                           if(Cl.idClient==id)
                            {
printf("   Entrer les informations comme format\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 ");
printf("\xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");
printf("   ID,Nom,Prenom,CIN,Adresse et telephone\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 ");
printf("\xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");
printf("   Attention l'ordre est imprtant!!!!\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 ");
printf("\xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");

                                Cl.idClient=lireChInt();
                                lire(Cl.nom,20);
                                lire(Cl.prenom,20);
                                Cl.cin=lireChInt();
                                lire(Cl.adresse,15);
                                Cl.telephone=lireChInt();

                            }
                           Tab[n-1]=Cl;
                           Tab=(client*)realloc(Tab,++n*sizeof(client));
                       }

                  fclose(fp);
                  fp=fopen(fichier,"wb");
                  fwrite(Tab,sizeof(client),n-1,fp);
             }

            else
            {
                  contrat Con,*Tab ;

                  Tab=(contrat*)malloc(n*sizeof(contrat));

                  while(fread(&Con,sizeof(Con),1,fp)){

                        if(Con.idVoiture==id)
                        {
printf("   Entrer les informations comme format\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 ");
printf("\xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");
printf("   Numero de contrat,ID voiture,ID client,la date de \n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4");
printf(" \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \n");
printf("   de debut et fin(jour,mois,année),et le cout\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 ");
printf("\xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");
printf("   Attention l'ordre est imprtant!!!!\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");

                        Con.numContrat=lireChInt();
                        Con.idVoiture=lireChInt();
                        Con.idClient=lireChInt();
                        Con.debut.j=lireChInt();
                        Con.debut.m=lireChInt();
                        Con.debut.a=lireChInt();
                        Con.fin.j=lireChInt();
                        Con.fin.m=lireChInt();
                        Con.fin.a=lireChInt();
                        Con.cout=lireChInt();

                        }
                      Tab[n-1]=Con;
                       Tab=(contrat*)realloc(Tab,++n*sizeof(contrat));
                  }

                fp=fopen(fichier,"wb");
                fwrite(Tab,sizeof(contrat),n-1,fp);
           }

           fclose(fp);
        }
printf("\n\xb1 terminee \xb1\n");
}
///**********************************************

void A_E(char* fichier ,int a,int b)
{
             FILE *fp=NULL;

             fp=fopen(fichier,"ab");

             if(!fp)
             {
                  printf("Problème !!!!\n");
                  exit(1);
             }

            fflush(stdin);

printf("\n\n\n\n\n\n\n\n");


            if(fichier=="Voitures.bin")
             {
                     voiture V ;

printf("   Entrer le ID de cette voiture\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 ");
printf("\xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");

                    V.idVoiture= lireChInt();

                    if(!R_E(V.idVoiture,"Voitures.bin"))
                     {
printf("   Entrer les informations comme format\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");
printf("   Marque,Nom,Couleur,Nombre de places\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");
printf("   et Prix/jour\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");
printf("   Attention l'ordre est imprtant\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");

                             strcpy(V.EnLocation,"non");

                             lire(V.marque,15);
                             lire(V.nomVoiture,15);
                             lire(V.couleur,7);
                             V.nbplaces= lireChInt();
                             V.prixJour=lireChInt();

                            fwrite(&V,sizeof(V),1,fp);
                      }
                   else
                    {
printf("   le ID que vous choisissez peut etre\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 ");
printf("\xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");
printf("   pris par une autre voiture!!!\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");
                    }

              }

             else if(fichier=="Clients.bin")
             {
                  client Cl;

printf("   entrer le ID du client\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");

                   Cl.idClient=lireChInt();

                if(!R_E(Cl.idClient,"Clients.bin"))
                 {
printf("   Entrer les informations comme format\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4");
printf(" \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");
printf("   Nom,Prenom,CIN,Adresse et Telephone\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4");
printf(" \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");
printf("   Attention l'ordre est imprtant!!!!\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 ");
printf("\xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");

                     lire(Cl.nom,20);
                     lire(Cl.prenom,20);
                     Cl.cin=lireChInt();
                     lire(Cl.adresse,15);
                     Cl.telephone=lireChInt();

                    fwrite(&Cl,sizeof(Cl),1,fp);
                 }

               else
                {
printf("   le ID que vous choisissez peut etre\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");
printf("   pris par un autre client!!!\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");
              }
        }


        else
        {
               contrat Con;

              Con.idVoiture=a;

             Con.idClient=b ;

              if(!R_E(Con.idVoiture,"ContratsLocations.bin"))
               {

printf("   Entrer les informations comme format\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");
printf("   Numero de contrat,la date de \n");
printf("    \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");
printf("   de debut et fin(jour,mois,année),et le cout\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");
printf("   Attention l'ordre est imprtant!!!!\n");
printf("   \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4 \xc4\n");

                        Con.numContrat=lireChInt();
                        Con.debut.j=lireChInt();
                        Con.debut.m=lireChInt();
                        Con.debut.a=lireChInt();
                        Con.fin.j=lireChInt();
                        Con.fin.m=lireChInt();
                        Con.fin.a=lireChInt();
                        Con.cout=lireChInt();

                      fwrite(&Con,sizeof(Con),1,fp);
               }

         }

         fclose(fp);

  printf("\n\xb1 terminee \xb1\n");
}
///**********************************************

void L_E(char *fichier ,int a,int b)
{
                 FILE *fp=NULL;

                 fp=fopen(fichier,"rb");

printf("\n\n\n\n\n\n\n\n");


               if(!fp)
               {
                     printf("Problème !!!!\n");
                      exit(1);
               }

              if(fichier=="Voitures.bin")
              {
printf(" ID  Marque       Nom       Couleur    Nombre de places    Prix/jour    En location\n");
printf(" \xc4\xc4  \xc4\xc4\xc4\xc4\xc4\xc4       \xc4\xc4\xc4       \xc4");
printf("\xc4\xc4\xc4\xc4\xc4\xc4    \xc4\xc4\xc4\xc4");
printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
printf("\xc4\xc4    \xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
printf("\xc4    \xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\n");


           voiture V;

           switch(a)
{
                                case 1: {

                                     while(fread(&V,sizeof(V),1,fp)){

                                                 if(!strcmp(V.EnLocation,"non"))
printf("\n   %d    %s    %s    %s    %d    %d    %s\n",V.idVoiture,V.marque,V.nomVoiture,V.couleur,V.nbplaces,V.prixJour,V.EnLocation);

                                           }  break ;}

                                case -1:{

                                      while(fread(&V,sizeof(V),1,fp)){

printf("\n   %d    %s    %s    %s    %d    %d    %s\n",V.idVoiture,V.marque,V.nomVoiture,V.couleur,V.nbplaces,V.prixJour,V.EnLocation);

                                          }  break ;}
   }


                }


               else if(fichier=="Clients.bin")
                {
                    client Cl;
printf(" ID de client       Nom       Prenom     CIN     Adresse    Telephone\n");
printf(" \xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
printf("\xc4\xc4       \xc4\xc4\xc4       \xc4\xc4\xc4\xc4");
printf("\xc4\xc4     \xc4\xc4\xc4     \xc4\xc4\xc4\xc4\xc4");
printf("\xc4\xc4    \xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\n");


                    while(fread(&Cl,sizeof(Cl),1,fp)){

printf("\n    %d       %s       %s     %d    %s    %d\n",Cl.idClient,Cl.nom,Cl.prenom,Cl.cin,Cl.adresse,Cl.telephone);

                         }

               }

              else
                {
                    contrat Con;

printf(" Numero de Contrat       ID de voiture       ID de client     Debut     Fin    Cout\n");
printf(" \xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4       \xc4\xc4");
printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
printf("\xc4       \xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
printf("\xc4\xc4     \xc4\xc4\xc4\xc4\xc4     \xc4\xc4\xc4    \xc4");
printf("\xc4\xc4\xc4\n");




                     while(fread(&Con,sizeof(Con),1,fp)){

printf("\n   %f              %d         %d             %d/%d/%d                 %d/%d/%d            %d\n",Con.numContrat,Con.idVoiture,Con.idClient,Con.debut.j,Con.debut.m,Con.debut.a,Con.fin.j,Con.fin.m,Con.fin.a,Con.cout);
                       }

            }

            fclose(fp);

    printf("\n\xb1 terminee \xb1\n");
}
///**********************************************
void menu_voi(void)
{
    int j;

    void(*Tab_voi[])(char *,int a,int b)={L_E,A_E,M_E,S_E};

    system("COLOR 4");


    do{

printf("\n\n\n              \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
printf("\n              \xb3 Gestion des Voitures \xb3");
printf("\n              \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
printf("\n\n");
printf("   \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
printf("\xcd\xcd\xcd\xcd\xcd\xbb\n");
printf("   \xba                                              \xba\n");
printf("   \xba                                              \xba\n");
printf("   \xba     Liste des voitures-------------<<1>>     \xba\n");
printf("   \xba                                              \xba\n");
printf("   \xba     Ajouter  voiture---------------<<2>>     \xba\n");
printf("   \xba                                              \xba\n");
printf("   \xba     Modifier voiture---------------<<3>>     \xba\n");
printf("   \xba                                              \xba\n");
printf("   \xba     Supprimer voiture--------------<<4>>     \xba\n");
printf("   \xba                                              \xba\n");
printf("   \xba     Retour-------------------------<<5>>     \xba\n");
printf("   \xba                                              \xba\n");
printf("   \xba                                              \xba\n");
printf("   \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
printf("\xcd\xcd\xcd\xcd\xcd\xbc\n");
printf("                 votre choix :");



      j=lireChInt();

     system("cls");

    }while(j<1 || j>5 );



   if(j!=5)
    {
        Tab_voi[j-1]("Voitures.bin",-1,-1);

printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\n");
printf("Tapper sur une touche pour revenir en arriere\n");
printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\n");





        getch();

        system("cls");

        return menu_voi();
    }

}
///**********************************************

void menu_loca(void)
{
             int j;

             void(*Tab_loca[])(char *,int a,int b)={L_E,louer_v,retourner_v,M_E,S_E};

            system("COLOR 9");


            do{

printf("\n\n\n              \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
printf("\n              \xb3Location d'une voiture\xb3");
printf("\n              \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
printf("\n\n");
printf("   \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd")
;printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
printf("   \xba                                              \xba\n");
printf("   \xba                                              \xba\n");
printf("   \xba     Visualiser Contrat--------------<<1>>    \xba\n");
printf("   \xba                                              \xba\n");
printf("   \xba     Louer voiture-------------------<<2>>    \xba\n");
printf("   \xba                                              \xba\n");
printf("   \xba     Retourner voiture---------------<<3>>    \xba\n");
printf("   \xba                                              \xba\n");
printf("   \xba     Modifier contrat----------------<<4>>    \xba\n");
printf("   \xba                                              \xba\n");
printf("   \xba     Supprimer contrat---------------<<5>>    \xba\n");
printf("   \xba                                              \xba\n");
printf("   \xba     Retour--------------------------<<6>>    \xba\n");
printf("   \xba                                              \xba\n");
printf("   \xba                                              \xba\n");
printf("   \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
printf("                 votre choix :");


    j=lireChInt();

    system("cls");

    }while(j<1 || j>6);

    if(j!=6)
    {
        if(j==2 || j==3)
           Tab_loca[j-1]("Voitures.bin",-1,-1);

        else

          Tab_loca[j-1]("ContratsLocations.bin",-1,-1);

          printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
          printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
          printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
          printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\n");
          printf("Tapper sur une touche pour revenir en arriere\n");
          printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
          printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
          printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
          printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\n");



        getch();

        system("cls");

        return menu_loca();
    }


}
///**********************************************

void menu_cli(void)
{
        int j;

        void(*Tab_cli[])(char *,int a, int b)={L_E,A_E,M_E,S_E};

        system("COLOR 6");


        do{
printf("\n\n\n              \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
printf("\n              \xb3 Gestion des Clients \xb3");
printf("\n              \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
printf("\n\n");
printf("   \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
printf("\xcd\xbb\n");
printf("   \xba                                              \xba\n");
printf("   \xba                                              \xba\n");
printf("   \xba     Liste des clients--------------<<1>>     \xba\n");
printf("   \xba                                              \xba\n");
printf("   \xba     Ajouter des client-------------<<2>>     \xba\n");
printf("   \xba                                              \xba\n");
printf("   \xba     Modifier clients---------------<<3>>     \xba\n");
printf("   \xba                                              \xba\n");
printf("   \xba     Supprimer clients--------------<<4>>     \xba\n");
printf("   \xba                                              \xba\n");
printf("   \xba     Retour-------------------------<<5>>     \xba\n");
printf("   \xba                                              \xba\n");
printf("   \xba                                              \xba\n");
printf("   \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
printf("                 votre choix :");



                    j=lireChInt();

                    system("cls");

         }while(j<1 || j>5);

         if(j!=5)
         {
                   Tab_cli[j-1]("Clients.bin",-1,-1);

printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\n");
printf("Tapper sur une touche pour revenir en arriere\n");
printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\n");


                    getch();

                    system("cls");

                    return menu_cli();
            }
}
///**********************************************

void menu_principal(void)
{
      int i;

      void(*Tab_menu[])(void)={menu_loca,menu_voi,menu_cli};

      system("COLOR A");

      do{

printf("\n\n\n                \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
printf("\n                \xb3   Menu Principal \xb3");
printf("\n                \xc0\xc4\xc4\xc4\xc4\xc4\xc4");
printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
printf("\n\n");
printf("   \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
printf("   \xba                                              \xba\n");
printf("   \xba                                              \xba\n");
printf("   \xba         Location--------------<<1>>          \xba\n");
printf("   \xba                                              \xba\n");
printf("   \xba         Gestion voitures------<<2>>          \xba\n");
printf("   \xba                                              \xba\n");
printf("   \xba         Gestion clients-------<<3>>          \xba\n");
printf("   \xba                                              \xba\n");
printf("   \xba         Quitter---------------<<4>>          \xba\n");
printf("   \xba                                              \xba\n");
printf("   \xba                                              \xba\n");
printf("   \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
printf("               votre choix :");




                 i=lireChInt();

                 system("cls");

      }while(i<1 || i>4);

      if(i!=4)
      {
                  Tab_menu[i-1]();

                  system("cls");

                  return menu_principal();

      }

}

///**********************************************

int main()
{    FILE *fp=NULL;
     ///fp=fopen("Clients.bin","wb");
     ///fclose(fp);
    ///fp=fopen("Voitures.bin","wb");
     ///fclose(fp);
     ///fp=fopen("ContratsLocations.bin","wb");
     ///fclose(fp);

     menu_principal();


  return 0;
}

