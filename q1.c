#include<stdio.h>
void main()
{
int a,b,c,t;
printf("enter 3 integers\n");
scanf("%d %d %d",&a,&b,&c);
if(a==b||b==c||a==c)
	{
	t=0;
	}
else
	{
	t=1;
	}
printf("%d",t);
}
