#include<stdio.h>
#include<stdlib.h>

int b2d(int bin)
{
  int sum = 0;
  if(bin == 1)
    return 1;
  if(bin == 0)
    return 0;
  else
  {
    sum = b2d(bin % 10) + b2d(bin / 10);
  }
  return sum;
}

int main()
{
  int bin;
  printf("Enter Binary no: ");
  scanf("%d",&bin);
  printf("Decimal form of %d is: %d\n",bin, b2d(bin));
  return 0;
}
