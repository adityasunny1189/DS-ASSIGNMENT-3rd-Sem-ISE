#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
  printf("File Encryption Program\n");
  FILE *fp1 , *fp2;
  char file1[20] , file2[20];
  printf("Enter the name of the file to read: ");
  scanf("%s",file1);
  fp1 = fopen(file1, "r");
  if(fp1 == NULL)
  {
    printf("File does not exist!\n");
    exit(1);
  }
  printf("Enter the name of the output file: ");
  scanf("%s",file2);
  fp2 = fopen(file2 , "w");
  if(fp2 == NULL)
  {
    printf("Invalid Destination\n");
    fclose(fp1);
    exit(1);
  }
  char ch;
  while(1)
  {
    ch = fgetc(fp1);
    if(ch == EOF)
      break;
    ch = ch + 1;
    fputc(ch, fp2);
  }
  fclose(fp1);
  fclose(fp2);
  printf("File Sucessfully Encrypted\n");
  return 0;
}
