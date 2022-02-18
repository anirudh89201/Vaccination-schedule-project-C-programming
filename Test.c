#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//Program written by Anirudh Reddy 1342
char name[100],fathername[100],mothername[100],surname[100],pan[7],password[100],mobilenumber[11],count;
int aadhar,dateofbirth;
void login()
{
        system("cls");
          char username[100],password[100],c[1000];
          printf("\n\t\t\t\t Note that the name and password are case-sensitive");
          printf("\n\t\t\t\t Enter the name:");
          scanf("%s",username);
          printf("\n\t\t\t\t Enter the password:");
          scanf("%s",password);
          FILE *fptr = fopen(username,"r+");
          if(fptr == NULL)
          {
              printf("Error could not open the file:");
              exit(-1);
          }
          else
          {
              fscanf(fptr,"%[^\n]",c);
              if(strcmp(c,password) == 0)
              {
                  system("cls");
                  int op = 0;
                  printf("\n\t\t\t\t ********************\n");
                  printf("\n\t\t\t\t Main menu:");
                  printf("\n\t\t\t\t 1.Register the Vaccine\n");
                  printf("\n\t\t\t\t 2.View the details\n");
                  printf("\n\t\t\t\t 3.Exit\n");
                  printf("\n\t\t\t\t **********************\n");
                  scanf("%d",&op);
                  if(op == 1)
                  {
                    char ch1,crct;
                    system("cls");
                    printf("\t\tPlease check whether all your details are correct or not:");
                    do
                    {
                        ch1 = fgetc(fptr);
                        printf("%c",ch1);
                    }while(ch1!=EOF);
                    printf("If correct enter Y If wrong Then press N:");
                    scanf(" %c",&crct);
                    printf("%c",crct);
                    if(crct == 'Y' || crct == 'y')
                    {
                        system("cls");
                        int slot;
                        printf("\t\t\t We have three Nurses with us \n Dr.Anirudh with 10 yrs experience \nDr.Hithasree with 5 yrs experience \nDr.Sahithi with 2 yrs experience");
                        printf("\n which Nurses u want to select:");
                        scanf("%d",&slot);
                        fprintf(fptr,"slot:%d",slot);
                        system("cls");
                        printf("Please wait while we are booking the slot:");
                        sleep(10);
                        system("cls");
                        printf("\t\t\t\t*****************\t\t");
                        if(slot == 1)
                        {
                            printf("\n\t\t\t\t Your slot is Dr.Anirudh is sucessfully booked:");
                        }
                        else if(slot == 2)
                        {
                            printf("\n\t\t\t\t Your slot is Dr.Hithasree is sucessfully booked:");
                        }
                        else if(slot == 3)
                        {
                            printf("\n\t\t\t\t Your slot is Dr.Sahithi is sucessfull booked:");
                        }
                        else
                            printf("\n\t\t\t\tYou entered the wrong number plz try again by restarting the application:");
                        sleep(2);
                        printf("\n\t\t\t\tPlease visit to nearest government hospital to u you will get notified there:");
                        sleep(1);
                        printf("\n\t\t\t\t Please do not book the other slot and after 84 days please get your second dose:");
                        fclose(fptr);
                    }

                  }
                  else if(op == 2)
                  {
                    char ch;
                    do
                    {
                        ch = fgetc(fptr);
                        printf("%c",ch);
                    }while(ch != EOF);
                    printf("\n\t\t\tPlease login again to do any other functions:");
                    sleep(5);
                    login();
                  }
              }
          }
}
void searchfile()
{
    char search[100],yn;
    system("cls");
    printf("\n\t\t\t Enter the file name to search:");
    scanf("%s",search);
    FILE *sfile = fopen(search,"r+");
    if(sfile == NULL)
    {
        system("cls");
        printf("\n\t\t\t The person is not listed:");
        printf("\n\t\t\t Do you want to create the record If yes press Y else press N:");
        scanf(" %c",&yn);
        if(yn == 'y' || yn == 'Y')
        {
            createfile();
        }
        else if(yn == 'N' || yn == 'n')
        {
            searchfile();
        }
    }
    else
    {
        char ch;
        do
        {
            ch = fgetc(sfile);
            printf(" %c",ch);
        }while(ch !=EOF);
    }
}
void createfile()
{
    system("cls");
          printf("\n\t\t\t Enter the name:");
          scanf("%s",name);
          FILE *file = fopen(name,"w");
          printf("\n\t\t\t Enter the surname:");
          scanf("%s",surname);
          printf("\n\t\t\t Enter the date of birth in ddmmyy without giving any spaces:");
          scanf("%d",&dateofbirth);
          printf("\n\t\t\t Enter the mobile number:");
          scanf("%s",&mobilenumber);
          printf("\n\t\t\t Enter the father name:");
          scanf("%s",fathername);
          printf("\n\t\t\t Enter the mother name:");
          scanf("%s",mothername);
          printf("\n\t\t\tEnter your password:\n");
          scanf("%s",password);
          fprintf(file,"%s\n",password);
          fprintf(file,"name:%s\n",name);
          fprintf(file,"surname:%s\n",surname);
          fprintf(file,"date of birth in dd-mm-yy format:%d\n",dateofbirth);
          fprintf(file,"mobile number:%s\n",mobilenumber);
          fprintf(file,"father nam e:%s\n",fathername);
          fprintf(file,"mother name:%s\n",mothername);
          fclose(file);
          printf("\n\t\t\t You will be redirected to the login page in 5 seconds:");
          sleep(5);
          login();


}
int main()
{
char username[6],pass[5],op;
  int option;
  printf("\n\t\t\t ************\n");
  printf("\n\t\t\t 1.Register for vaccine:");
  printf("\n\t\t\t 2.Login as the admin:");
  printf("\n\t\t\t 3.Exit:\n");
  printf("\n\t\t\t ***************\n");
  scanf("%d",&option);
  if(option == 1)
  {
      char ch[2];
      system("cls");
      printf("\n\t\t\t Do you have the account or want to create the account\n");
      printf("\n\t\t\t For creating the account press Y or for login press N");
      scanf("%s",ch);
      if(strcmp(ch,"Y") == 0 )
      {
            createfile();
      }
      else if(strcmp(ch,"N") == 0)
      {
         login();
      }

  }
  else if(option ==2)
  {
      char adminame[100],adminpwd[100];
      int token;
      system("cls");
      printf("\n\t\t\t Enter the name:");
      scanf("%s",adminame);
      printf("\n\t\t\t Enter the password:");
      scanf("%s",adminpwd);
      if(strcmp(adminame,"Admin") == 0 && strcmp(adminpwd,"Hithasree") == 0)
      {
        system("cls");
        printf("\n\t\t\t Welcome Admin:");
        printf("\n\t\t\t Plz enter your token No:");
        scanf("%d",&token);
        if(token == 1914)
        {
            searchfile();
        }
        else
        {
            system("cls");
            printf("\n\t\t You entered the wrong token no:");
            printf("\n\t\t Sorry but due to security reasons we are exiting the application:");
            sleep(4);
            exit(-1);
        }
      }

  }
  else if(option == 3)
  {
      printf("Wait a moment we are exiting from application:");
      exit(-1);
  }


}
