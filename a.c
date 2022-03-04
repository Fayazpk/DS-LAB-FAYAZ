#include<stdio.h>
void sum(int a,int b);
void main()
{
int a,b;
printf("enter a and b");
scanf("%d%d",&a,&b);
sum(a,b);
}

void sum(int a,int b)
{
int sum;
sum=a+b;
printf("%d",sum);
}
