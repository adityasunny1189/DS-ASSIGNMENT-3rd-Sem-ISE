#include<stdio.h>
#include<stdlib.h>

struct stack
{
  int data[10];
  int top;
}Bin;

void d2b(int n)
{
  if(n == 1 || n == 0)
  {
    Bin.data[++Bin.top] = n;
    return;
  }
  else
  {
    int qut , rem;
    qut = n / 2;
    rem = n % 2;
    Bin.data[++Bin.top] = rem;
    d2b(qut);
  }
}

int main()
{
  int dec;
  Bin.top = -1;
  printf("Enter Decimal no : ");
  scanf("%d",&dec);
  printf("Binary Form of %d is: ",dec);
  d2b(dec);
  while(Bin.top != -1)
  {
    printf("%d",Bin.data[Bin.top--]);
  }
  printf("\n");
  return 0;
}
