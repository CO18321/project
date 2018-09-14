#include<stdio.h>
void main()
{
int a,b,c;
printf("enter values of a,b,c\n");
scanf("%d %d %d",&a,&b,&c);
if(a+b<=c||b+c<=a||c+a<=b)
	{
	printf("0");
	}
else
printf("1");
}
