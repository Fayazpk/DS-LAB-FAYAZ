#include<stdio.h>
void disp();
void main()
{
disp(1);
}

void disp(int x)
{printf("%d",x);
if(x!=10)
disp(x+1);
if(x==10)
printf("\nreverse order\n");
printf("%d",x);
}
