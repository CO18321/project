o#include<stdio.h>
void main()
{
int e, cash=0,a,f=1000,b,c,d,t=0;

printf("what is capital of india \n");
printf("1. newdelhi\n 2.pune \n 3. goa \n 4. jaipur");
scanf("%d",&a);
	switch(a)
	{
	case 1:
	printf("congratulations correct answer\n");
	cash=1000;
	t=1;
	break;
	default :
	printf("sorry wrong answer\n");
	printf("cash is%d:",cash);

	} 
if(t==1)
{
printf("what is value of g ?\n");
printf("1. 3.1\n 2.10 \n 3. 9.8 \n 4. 4");
scanf("%d",&b);
        switch(b)
        {
        case 3:
        printf("congratulations correct answer\n");
	printf("cash is%d:",cash);

        cash*=2;
        t=2;
	 break;

        default :
        printf("sorry wrong answer\n");
        printf("cash is%d:",cash);

        } 


}
if(t==2)
{
printf("who is prime minister of india ?\n");
printf("1. manmohan singh\n 2.narendir modi \n 3. rahul gandhi \n 4. sonia gandhi");
scanf("%d",&c);
        switch(c)
        {
        case 2:
        printf("congratulations correct answer\n");
	printf("cash is%d:",cash);

        cash*=2;
        t=3;
	 break;

        default :
        printf("sorry wrong answer\n");
        printf("cash is%d:",cash);

        } 

}
if(t==3)
{
printf("which festival is called festival of lights ?\n");
printf("1. holi\n 2. rakhi \n 3. id \n 4. diwali");
scanf("%d",&d);
        switch(d)
        {
        case 4:
        printf("congratulations correct answer\n");
	printf("cash is%d:",cash);

        cash*=2;
        t=4;
	 break;

        default :
        printf("sorry wrong answer\n");
        printf("cash is%d:",cash);

        } 

}
if(t==4)
{
printf("where burj khalifa is present ?\n");
printf("1. dubai\n 2. china \n 3. india\n 4. london");
scanf("%d",&e);
        switch(e)
        {
        case 1:
        printf("congratulations correct answer\n");
	printf("cash is%d:",cash);

        cash*=2;
	 break;

        default :
        printf("sorry wrong answer\n");
        printf("cash is%d:",cash);

        } 

}

}


