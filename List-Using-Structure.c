#include<stdio.h>
#include<stdlib.h>
 struct node
{
 int data;
struct node*link;
};
int main()
{
struct node*head=malloc(sizeof(struct node));
  head->data=20;
    head->link-NULL;
printf("%d,head->data");

  struct node*current=malloc(sizeof(struct node));
  current->data=30;
  current->link=NULL;
  head->link=current;
  printf("%d,current->data");

  struct node*current2=malloc(sizeof(struct node));
  current2->data=40;
  current2->link=NULL;
  current->link=current2;
  printf("%d",current2->data);
  return 0
  
}
