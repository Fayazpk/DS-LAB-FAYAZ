#include<stdio.h>
#include<stdlib.h>
int s[5];
struct node
{
int data;
struct node*next;
};
void push();
void pop();
void display();
struct node *top=NULL;
void main(){
int x;
int opt;

do
{
printf("\n Menu \n");
printf("\n 1.push \n 2.pop \n 3.display \n 4.search \n enter the option:");
scanf("%d",&opt);
switch(opt)
     {
   case 1:push();
   break;
   case 2:pop();
   break;
   case 3:display();
   break;
   
}
}
   while(opt!=4);
}

void push()
{
struct node* newnode;
int x;

{
printf("enter element");
scanf("%d",&x);
newnode=(struct node *)malloc(sizeof(struct node));
if(newnode==NULL)
{
printf("stack overflow");
return;
}
newnode->data=x;
newnode->next=top;
top=newnode;
}
}
void display()
{
struct node *ptr=top;
if(top==NULL)
{
printf("stack is empty");
return;
}
else
while(ptr!=NULL)
{
printf("%d",ptr->data);
ptr=ptr->next;
}
}


void pop()
{
struct node *ptr;
ptr=top;
if(top==NULL)
{
 printf("stack is empty");
 return;
}
printf("%d",top->data);
ptr=top;
top=top->next;
free(ptr);
}
void search()
{
int s;
struct node *ptr=top;
printf("enter the element");
scanf("%d",&s);
if(top==NULL)
{
printf("stack s empty");
return;
}
while(ptr!=NULL)
{
if(s==ptr->data)
printf("element is found");
break;
}
ptr=ptr->next;
}



