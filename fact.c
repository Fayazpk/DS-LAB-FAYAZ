#include<stdio.h>
int fact();
void main()
{
int n,f;

printf("enter n");
scanf("%d",&n);
f=fact(n);
printf("factoril is %d",f);

}
int fact(int x)
{
if(x==1)
return 1;
else
return x*fact(x-1);

}

