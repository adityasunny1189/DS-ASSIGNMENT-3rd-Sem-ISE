#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
  FILE *fp1;
  char name[20] ,passw[20] , passwt[20] = "Aditya98716";
  printf("Enter the file name to open: ");
  scanf("%s",name);
  fp1 = fopen(name , "r");
  if(fp1 == NULL)
  {
    printf("Invalid file name or destination\n");
    exit(1);
  }
  else
  {
    printf("Enter Password: ");
    scanf("%s",passw);
    if(!strcmp(passwt , passw))
    {
      printf("Opening File\n");
    }
    else
    {
      printf("Invalid Password\n");
      exit(1);
    }
  }
  return 0;
}
