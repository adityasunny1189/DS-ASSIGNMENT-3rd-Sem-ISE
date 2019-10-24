#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct employee
{
  char name[20];
  char id[10];
  int basic_salary;
};

typedef struct employee EMP;

int gross_Salary(EMP Employ[],int i)
{
  int gross_salary;
  if(Employ[i].basic_salary < 5000)
  {
    gross_salary = Employ[i].basic_salary + .1 * Employ[i].basic_salary + .7 * Employ[i].basic_salary;
  }
  else if(Employ[i].basic_salary > 5000 && Employ[i].basic_salary < 10000)
  {
    gross_salary = Employ[i].basic_salary + .15 * Employ[i].basic_salary + .6 * Employ[i].basic_salary;
  }
  else if(Employ[i].basic_salary > 10000 && Employ[i].basic_salary < 20000)
  {
    gross_salary = Employ[i].basic_salary + .2 * Employ[i].basic_salary + .55 * Employ[i].basic_salary;
  }
  else
  {
    gross_salary = Employ[i].basic_salary + .25 * Employ[i].basic_salary + .5 * Employ[i].basic_salary;
  }
  return gross_salary;
}

int main()
{
  EMP Employ[100];
  int n;
  int gross_salary;
  printf("Enter the no of employee: ");
  scanf("%d",&n);
  printf("Enter Employee Details:-\n");
  for(int i = 0 ; i < n ; i++)
  {
    printf("Name: ");
    scanf("%s",Employ[i].name);
    printf("ID: ");
    scanf("%s",Employ[i].id);
    printf("Basic Salary: ");
    scanf("%d",&Employ[i].basic_salary);
  }
  printf("Employee Details are as follows:-\n");
  for(int i = 0 ; i < n ; i++)
  {
    printf("Name: %s\nID: %s\nBase Salary: %d\nGross Salary: %d\n",Employ[i].name,Employ[i].id,Employ[i].basic_salary,gross_Salary(Employ,i));
  }
  return 0;
}
