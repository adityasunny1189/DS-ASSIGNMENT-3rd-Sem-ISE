#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct stack
{
  int data[20];
  int top;
}st;

int b2d(int bin)
{
  if(bin == 1 || bin == 0)
    st.data[++st.top] = bin;
  else
  {
    st.data[++st.top] = bin%10;
    b2d(bin/10);
  }
}

int main()
{
  st.top = -1;
  int bin;
  int sum = 0;
  printf("Enter Binary no: ");
  scanf("%d",&bin);
  b2d(bin);
  for(int i = 0 ; i <= st.top ; i++)
  {
    sum = sum + st.data[i]*pow(2,i);
  }
  printf("Decimal form of %d is: %d\n",bin,sum);
  return 0;
}
