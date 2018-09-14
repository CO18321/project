#include<stdio.h>
int convert(char);
 main()
{
char rn[10];
int d=0;
printf("enter roman no.\n");
scanf("%s",&rn);
for( int i=0;i<10;i++)
	{
	if(convert(rn[i])>=convert(rn[i+1]))
		{
		d+=convert(rn[i]);
		}
	else
		{
		d=d+ (convert(rn[i+1])-convert(rn[i]));
		i++;
		}
	}
printf("decimal equivalent is %d",d);
}
convert( char c)
{
int value;
switch(c)
	{
	case'I': value=1;
	break;
	 case'V': value=5;
        break;
	 case'X': value=10;
        break;
	 case'L': value=50;
        break;
	 case'C': value=100;
        break;
	 case'D': value=500;
        break;
	 case'M': value=1000;
        break;
	 case'\0':value=0;
	break;
	}
return(value);
} 
