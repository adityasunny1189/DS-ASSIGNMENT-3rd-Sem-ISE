//To be done , not completed yet

#include<stdio.h>
#include<stdlib.h>

struct stack
{
  int data[10];
  int top;
};

int isEmpty(struct stack *S1)
{
  if(S1->top == -1)
    return 1;
  else
    return 0;
}

void push(struct stack *S1 , int ele)
{
  if(!isEmpty(S1))
  {
    printf("No space left to insert\n");
    return ;
  }
  S1->data[++S1->top] = ele;
}

int pop(struct stack *S1)
{
  if(isEmpty(S1))
  {
    printf("Empty List!..\n");
    return 0;
  }
  return S1->data[S1->top--];
}

struct queue
{
  struct stack *S1;
  struct stack *S2;
};

typedef struct queue QUEUE;

// struct queue *createqueue()
// {
//   struct queue Q = malloc(sizeof(struct queue));
//   return Q;
// }

void insert(QUEUE *Q , int ele)
{
  push(Q->S1,ele);
}

void delete(QUEUE *Q)
{
  while(!isEmpty(Q->S1))
  {
    push(Q->S2, pop(Q->S1));
  }
  printf("Deleted element is: %d",pop(Q->S2));
}

void display(QUEUE *Q)
{
  while(!isEmpty(Q->S1))
  {
    push(Q->S2, pop(Q->S1));
  }
  for(int i = 0 ; i <= Q->S2->top ; i++)
  {
    printf("%d ",Q->S2->data[i]);
  }
}

int main()
{
  QUEUE *Q;
  Q = (QUEUE *)malloc(sizeof(QUEUE));
  Q->S1->top = -1;
  Q->S2->top = -1;
  int ele;
  int choice;
  char ch;
  do {
    printf("1.Insert\n2.Delete\n3.Display\nChoice: ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1: printf("Enter no to add: ");
              scanf("%d",&ele);
              insert(&Q,ele);
              break;

      case 2: delete(&Q);
              break;

      case 3: display(&Q);
              break;

      default: printf("Invalid Choice\n");
    }
    printf("\nDo you want to continue: ");
    scanf("%c",&ch);
    printf("\n");
  } while(ch == 'y');
  return 0;
}
