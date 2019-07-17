#include<math.h>
#include<ctype.h>
#include<iostream>
#include<string.h>
#include <stdlib.h>

#include<stdio.h>
using namespace std;
int n,p;
int aa[10];

int hexa_to_decimal(char *x,int y)
	{
	int i=4;
	p=0;
	while(*x!='\0')
		{
		if(isdigit(*x)==0){
		n=(*x);
		p+=(n-87)*pow(16,i);
		x++;
		i--;}
		else{
		n=(*x);
		p+=(n-48)*pow(16,i);
		x++;
		i--;}

		}
	return p;
	}

int desired_to_decimal(int y,int x)
	{
	 int p=0;
          int temp=x;
          int base=1;
                while(temp)
                        {
                        int ld=temp%10;
                        temp=temp/10;
                        p+=ld*base;
                        base*=y;
                        }
        return p;

	}



void decimal_to_desired(int x,int y)
	{
	int i=10;
                while(x!=0)
                {
                	aa[i]=x%y;
               	 	x=x/y;
                	i--;
                }
                for(int j=i+1;j<=10;j++)
			{
				if(aa[j]>9)
					{
				char hex;
				hex=65+aa[j]-10;
				cout<<hex;
					}
				else
                		cout<<aa[j];
			}

	}
class conv
	{
	public:

	int d;
	char  h[5];

	void input_d(){cin>>d;}

	void input_h(){
		for(int i=0;i<5;i++)
			cin>>h[i];  }

	void convt(){
	if(n==1){ cout<<"2.binary\n3.hexadecimal\n4.octal\n";}
	else if(n==2){cout<<"1.decimal\n3.hexadecimal\n4.octal\n";}
	else if(n==3){cout<<"1.decimal\n2.binary\n4.octal\n";}
	else if(n==4){cout<<"1.decimal\n2.binary\n3.hexadecimal\n";}
	else{cout<<"soory not known to me";}
	}



	void result()
		{
	if((n==1)&&(p==2)) {decimal_to_desired(d,2);}


	else if((n==1)&&(p==3)) {decimal_to_desired(d,16);}


	else if((n==1)&&(p==4)) {decimal_to_desired(d,8);}


	else if((n==2)&&(p==1)){int r=desired_to_decimal(2,d);
				cout<<r;}


	else if((n==2)&&(p==3))
                {
                int r=desired_to_decimal(2,d);
		decimal_to_desired(r,16);
		}


	else if((n==2)&&(p==4))
                {
                int r=desired_to_decimal(2,d);
                decimal_to_desired(r,8);
		}



	 else if((n==3)&&(p==1))
		{
		int r=hexa_to_decimal(&h[0],5);
		cout<<r;
		}



	 else if((n==3)&&(p==2))
		{
		int r=hexa_to_decimal(&h[0],5);
		decimal_to_desired(r,2);
		}



 	else if((n==3)&&(p==4))
		{
		int r=hexa_to_decimal(&h[0],5);
		decimal_to_desired(r,8);
		}



	 else if((n==4)&&(p==1))
                {
		int r=desired_to_decimal(8,d);
		cout<<r;
                }



         else if((n==4)&&(p==2))
                {
		int r=desired_to_decimal(8,d);
		decimal_to_desired(r,2);
                }



        else if((n==4)&&(p==3))
                {
		int r=desired_to_decimal(8,d);
		decimal_to_desired(r,16);
                }
	}

};
conv obj;
main()
{
system("clear");
cout<<"____________enter number system____________\n";
cout<<"1.decimal\n";
cout<<"2.binary\n";
cout<<"3.hexadecimal\n";
cout<<"4.octal\n";
cin>>n;
cout<<"enter number";
system("clear");

	if((n==1)||(n==2)||(n==4)){obj.input_d();}
	else if(n==3){obj.input_h();}
	else{cout<<" not known";}

cout<<"_______enter number system to convert_______\n";
obj.convt();
cin>>p;
obj.result();
}

