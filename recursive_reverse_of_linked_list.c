#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct stack
{
  int data[20];
  int tp;
}st;

typedef struct Node NODE;

void insert(NODE **top, int data)
{
  NODE *temp;
  temp = (NODE *)malloc(sizeof(NODE));
  if(!temp)
  {
    printf("Memory allocation error\n");
    return ;
  }
  temp->data = data;
  temp->next = *top;
  *top = temp;
}

void display(NODE *top)
{
  NODE *p ;
  p = top;
  if(p == NULL)
  {
    printf("Empty List\n");
    return;
  }
  while(p != NULL)
  {
    printf("%d ",p->data);
    p = p->next;
  }
  printf("\n");
}

void reverse(NODE *top)
{
  NODE *temp;
  temp = top;
  if(temp == NULL)
  {
    printf("Empty List\n");
    return;
  }
  else
  {
    st.data[++st.tp]=temp->data;
    temp = temp->next;
    reverse(temp);
  }
}

int main()
{
  st.tp = -1;
  NODE *head = NULL;
  int choice;
  char ch;
  do {
    printf("1.Insert\n2.Display\n3.Reverse\nChoice: ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1: printf("Insert Call\n");
              int ele;
              printf("Enter Element : ");
              scanf("%d",&ele);
              insert(&head , ele);
              break;

      case 2: printf("Display Call\n");
              display(head);
              break;

      case 3: reverse(head);
              for(int i = st.tp ; i >= 0 ; i--)
              {
                printf("%d ",st.data[i]);
              }
              printf("\n");
              break;

      default: printf("Invalid Choice\n");
    }
    printf("Do you want to continue(y/n): ");
    scanf(" %c",&ch);
  } while(ch == 'y');
  return 0;
}
