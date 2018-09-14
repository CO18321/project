#include<stdio.h>
int func(int a,int b);
main()
{
int m,n;
float res;
printf("enter values of m and n");
scanf("%d %d",&m,&n);
res=func( m,n );
printf("%f",res);
}
int func(int a,int b)
{
float c;
	if((b%a)==0)
	{
		c=(a/b);
	}
	else
	{
		c=0;
	}
return(c);
}
