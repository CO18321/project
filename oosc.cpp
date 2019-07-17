#include<iostream>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<gtk/gtk.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;



int fact(int a)
	{
	if(a==1)
		return 1;
	else
		{return a*fact(a-1);
		}
	}




const char *entry_string;
char symbol;
GtkWidget *entry;



//GtkWidget *entry;
int t=0;
float first_no=0.0;
float second_no=0.0;

int f_no_int=0;
int s_no_int=0;
int r_int=0;

void submit(GtkWidget *w,gpointer data);
float t_1=0.0,t_2=0.0;
//const char *entry_string;

float i=10;
const char *back;




void get_entry_value()
	{
	 const char *entry_string=gtk_entry_get_text(GTK_ENTRY(entry));
       float entry_int=(*entry_string) -'0';
	float entry_int2;
	entry_string++;
	while(*entry_string!=symbol)
		{
			if(*entry_string=='.')
				{
				entry_string++;
				
				while(*entry_string!=symbol)
					{
					t_1+=(*entry_string -'0')/i;
					i=i*10;				
					entry_string++;
					}

				}
			else
				{	
 	        		entry_int=10*(entry_int) +(*entry_string -'0');//
				entry_string++; 
				}
		}

	first_no=entry_int+t_1;
	i=10;
	entry_string++;
	entry_int2=(*entry_string)-'0';
	entry_string++;
        while(*entry_string!='\0')
		{
			if(*entry_string=='.')
				{
				entry_string++;
				while(*entry_string!='\0')
					{
					//float i=10;
					t_2+=(*entry_string -'0')/i;
					i*=10;
					entry_string++;
					
					}

				}
			else
				{
		 		entry_int2=10*(entry_int2) +(*entry_string -'0');//
				entry_string++;
				}
		}
	second_no=(entry_int2) +(t_2);
	}








void prtm(GtkWidget *w, gpointer data)
{symbol='%';
gtk_entry_append_text(GTK_ENTRY(entry),"%");}
void prtp(GtkWidget *w, gpointer data)
{symbol='^';
gtk_entry_append_text(GTK_ENTRY(entry),"^");}	
void prtlog(GtkWidget *w, gpointer data) 
{symbol='l';
gtk_entry_append_text(GTK_ENTRY(entry),"l");}

void prt7(GtkWidget *w, gpointer data) 
{
gtk_entry_append_text(GTK_ENTRY(entry),"7");}
void prt8(GtkWidget *w, gpointer data) 
{
gtk_entry_append_text(GTK_ENTRY(entry),"8");}
void prt9(GtkWidget *w, gpointer data) 
{
gtk_entry_append_text(GTK_ENTRY(entry),"9");}
void prtmul(GtkWidget *w, gpointer data) 
{symbol='*';
gtk_entry_append_text(GTK_ENTRY(entry),"*");}
void prt4(GtkWidget *w, gpointer data) 
{
gtk_entry_append_text(GTK_ENTRY(entry),"4");}
void prt5(GtkWidget *w, gpointer data)
 {
gtk_entry_append_text(GTK_ENTRY(entry),"5");}
void prt6(GtkWidget *w, gpointer data) 
{
gtk_entry_append_text(GTK_ENTRY(entry),"6");}
void prtdiv(GtkWidget *w, gpointer data) 
{symbol='/';
gtk_entry_append_text(GTK_ENTRY(entry),"/");}
void prt3(GtkWidget *w, gpointer data) 
{
gtk_entry_append_text(GTK_ENTRY(entry),"3");}
void prt2(GtkWidget *w, gpointer data) 
{
gtk_entry_append_text(GTK_ENTRY(entry),"2");}
void prt1(GtkWidget *w, gpointer data) 
{
gtk_entry_append_text(GTK_ENTRY(entry),"1");}
void prtminus(GtkWidget *w, gpointer data) 
{symbol='-';
gtk_entry_append_text(GTK_ENTRY(entry),"-");}
void prtdot(GtkWidget *w, gpointer data) 
{
gtk_entry_append_text(GTK_ENTRY(entry),".");}
void prt0(GtkWidget *w, gpointer data) 
{
gtk_entry_append_text(GTK_ENTRY(entry),"0");}
void prtplus(GtkWidget *w, gpointer data) 
{
symbol='+';
gtk_entry_append_text(GTK_ENTRY(entry),"+");}

void prtfact(GtkWidget *w, gpointer data) 
{
symbol='!';
gtk_entry_append_text(GTK_ENTRY(entry),"!");}
void prtsin(GtkWidget *w, gpointer data) 
{
symbol='s';
gtk_entry_append_text(GTK_ENTRY(entry),"s");}
void prtcos(GtkWidget *w, gpointer data) 
{
symbol='c';
gtk_entry_append_text(GTK_ENTRY(entry),"c");}
void prttan(GtkWidget *w, gpointer data) 
{
symbol='t';
gtk_entry_append_text(GTK_ENTRY(entry),"t");}
void prtsqrt(GtkWidget *w, gpointer data) 
{
symbol='r';
gtk_entry_append_text(GTK_ENTRY(entry),"r");}
void prttani(GtkWidget *w, gpointer data) 
{
symbol='y';
gtk_entry_append_text(GTK_ENTRY(entry),"y");}
void prtcosi(GtkWidget *w, gpointer data) 
{
symbol='v';
gtk_entry_append_text(GTK_ENTRY(entry),"v");}

void prtsini(GtkWidget *w, gpointer data) 
{
symbol='d';
gtk_entry_append_text(GTK_ENTRY(entry),"d");}
void prtsqrtxy(GtkWidget *w, gpointer data) 
{
symbol='p';
gtk_entry_append_text(GTK_ENTRY(entry),"p");}
void clear(GtkWidget *w,gpointer data){ 
gtk_entry_set_text(GTK_ENTRY(entry),"0");}


void prtln(GtkWidget *w, gpointer data) 
{

back=gtk_entry_get_text(GTK_ENTRY(entry));
char *temp;
char *t;
t=(char*)back;
int size=0;

while(*t!='\0')
	{
	size+=1;
	t++;
	}
size-=2;
strncpy(temp,back,size);
cout<<size<<endl;

cout<<temp;
cout<<endl;
gtk_entry_set_text(GTK_ENTRY(entry),temp);

}


float calculate(char symbol)
	{
	float r;
	switch(symbol)
		{
		case'+':
		r=(first_no)+(second_no);
		break;

		case'-':
		r=(first_no)-(second_no);
		break;

		case'/':
		r=(first_no)/(second_no);
		break;

		case'l':
		f_no_int=first_no;
		s_no_int=second_no;
		r=log(s_no_int)/log(10);	 	
		break;

		case'^':
		f_no_int=first_no;
		s_no_int=second_no;
		r=pow(f_no_int,s_no_int);
		break;

		case'*':
		r=(first_no)*(second_no);
		break;

		case'%':
		f_no_int=first_no;
		s_no_int=second_no;
		r=(f_no_int)%(s_no_int);
		break;
		
		case'!':
		f_no_int=first_no;
		r=fact(f_no_int);
		break;

		case 's':
		r=sin((second_no/57.2958));
		break;

		case 'c':
		r=cos((second_no/57.2958));
		break;

		case 't':
		r=tan((second_no/57.2958));
		break;
		
		case 'r':
		r=pow(second_no,0.5);
		break;
	
		case 'y':
		r=atan(second_no)*(57.2958);
		break;

		case 'v':
		r=acos(second_no)*(57.2958);
		break;
		
		case 'd':
		r=asin(second_no)*(57.2958);
		break;

		case 'p':
		r=pow(first_no,(1/second_no));
		break;

		case 'n':
		r=log(second_no);
		break;


		default:
		r=0;
		gtk_entry_set_text(GTK_ENTRY(entry),"0");
		g_print("please give valid input!!!");
		break;



		}
	return r;
	}




void submit(GtkWidget *w,gpointer data)
	{

	get_entry_value();
	//second_no=temp-first_no;
	long double  result=calculate(symbol);
cout<<first_no<<"\t"<<second_no<<"\n";
//g_print("%f %c %f \n ",first_no,symbol,second_no);
g_print("%f     %f\n",t_1,t_2);
g_print("%Lf\n",result);
//g_print("%c",entry_string);
//cout<<back;
	int s=sizeof(char)*10;
	char result_string[s];
	memset(result_string,0,10);
	sprintf(result_string,"%Lf",result);
	gtk_entry_set_text(GTK_ENTRY(entry),result_string);
	}







class inter
{
	protected:	
	GtkWidget *p;//,*menu_bar,*menu_item,*file_menu;
	public:
	
	void make(char*s,int x,int y){
	p = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(p),s);
	g_signal_connect(p,"delete_event",G_CALLBACK(gtk_main_quit),NULL);
	gtk_widget_set_size_request(p,x,y);
	gtk_widget_show_all(p);
	}	
		
};

class text:public inter
{
	protected:	
	GtkWidget *vbox;
	GtkWidget *hbox;
	public:	
	void display(int x,int y){
	vbox=gtk_vbox_new(0,0);
	gtk_container_add(GTK_CONTAINER(p),vbox);


	
	hbox=gtk_hbox_new(0,0);
	gtk_container_add(GTK_CONTAINER(vbox),hbox);
	entry=gtk_entry_new();

	gtk_editable_set_editable(GTK_EDITABLE(entry),FALSE);
	gtk_entry_set_visibility(GTK_ENTRY(entry),TRUE);
	gtk_widget_set_size_request(entry,x,y);
	gtk_entry_set_text(GTK_ENTRY(entry),"0");
	gtk_container_add(GTK_CONTAINER(hbox),entry);
	gtk_widget_show_all(p);}




};


class icon:public text
{
	//protected:
	GtkWidget *button;
	GtkWidget *hbox1;
	GtkWidget *hbox2;
	GtkWidget *hbox3;
	GtkWidget *hbox4;
	GtkWidget *hbox5;
	//GtkWidget *hbox6;
	public:



	void form1()
	{
	gtk_widget_show(hbox);
	
	 hbox1=gtk_hbox_new(FALSE,0);
        gtk_container_add(GTK_CONTAINER(vbox),hbox1);
	button=gtk_button_new_with_label(          "%"     );
	gtk_box_pack_start(GTK_BOX(hbox1),button,0,0,0);
	gtk_widget_set_size_request(button,80,50);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(prtm),NULL);
	
	button=gtk_button_new_with_label(          "xʸ"     );
	gtk_box_pack_start(GTK_BOX(hbox1),button,0,0,0);
	gtk_widget_set_size_request(button,80,50);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(prtp),NULL);

	button=gtk_button_new_with_label(      "CLEAR"     );
	gtk_box_pack_start(GTK_BOX(hbox1),button,0,0,0);
	gtk_widget_set_size_request(button,80,50);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(clear),NULL);

	button=gtk_button_new_with_label(       "log"      );
	gtk_widget_set_size_request(button,80,50);
	gtk_box_pack_start(GTK_BOX(hbox1),button,0,0,0);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(prtlog),NULL);	

	button=gtk_button_new_with_label(       "⌫	"      );
	gtk_widget_set_size_request(button,80,50);
	gtk_box_pack_start(GTK_BOX(hbox1),button,0,0,0);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(prtln),NULL);	
      
      
        button=gtk_button_new_with_label(       "!"      );
	gtk_widget_set_size_request(button,80,50);
	gtk_box_pack_start(GTK_BOX(hbox1),button,0,0,0);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(prtfact),NULL);	
     


	//GtkWidget *hbox2;
	hbox2=gtk_hbox_new(FALSE,0);
	gtk_container_add(GTK_CONTAINER(vbox),hbox2);

	button=gtk_button_new_with_label(          "7"   );
	gtk_box_pack_start(GTK_BOX(hbox2),button,0,0,0);
	gtk_widget_set_size_request(button,80,50);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(prt7),NULL);

	button=gtk_button_new_with_label(          "8"   );
	gtk_box_pack_start(GTK_BOX(hbox2),button,0,0,0);
	gtk_widget_set_size_request(button,80,50);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(prt8),NULL);

	button=gtk_button_new_with_label(          "9"   );
	gtk_box_pack_start(GTK_BOX(hbox2),button,0,0,0);
	gtk_widget_set_size_request(button,80,50);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(prt9),NULL);

	button=gtk_button_new_with_label(          "*"   );
	gtk_box_pack_start(GTK_BOX(hbox2),button,0,0,0);
	gtk_widget_set_size_request(button,80,50);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(prtmul),NULL);

	button=gtk_button_new_with_label(          "√"   );
	gtk_box_pack_start(GTK_BOX(hbox2),button,0,0,0);
	gtk_widget_set_size_request(button,80,50);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(prtsqrt),NULL);

	button=gtk_button_new_with_label(          "ʸ√x"   );
	gtk_box_pack_start(GTK_BOX(hbox2),button,0,0,0);
	gtk_widget_set_size_request(button,80,50);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(prtsqrtxy),NULL);



	//GtkWidget *hbox3;
	hbox3=gtk_hbox_new(FALSE,0);
	gtk_container_add(GTK_CONTAINER(vbox),hbox3);

	button=gtk_button_new_with_label(          "4"   );
	gtk_box_pack_start(GTK_BOX(hbox3),button,0,0,0);
	gtk_widget_set_size_request(button,80,50);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(prt4),NULL);

	button=gtk_button_new_with_label(          "5"   );
	gtk_box_pack_start(GTK_BOX(hbox3),button,0,0,0);
	gtk_widget_set_size_request(button,80,50);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(prt5),NULL);

	button=gtk_button_new_with_label(          "6"   );
	gtk_box_pack_start(GTK_BOX(hbox3),button,0,0,0);
	gtk_widget_set_size_request(button,80,50);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(prt6),NULL);

	button=gtk_button_new_with_label(          "  ÷"   );
	gtk_box_pack_start(GTK_BOX(hbox3),button,0,0,0);
	gtk_widget_set_size_request(button,80,50);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(prtdiv),NULL);

	button=gtk_button_new_with_label(          "sin"   );
	gtk_box_pack_start(GTK_BOX(hbox3),button,0,0,0);
	gtk_widget_set_size_request(button,80,50);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(prtsin),NULL);

	button=gtk_button_new_with_label(          "sin-¹     "   );
	gtk_box_pack_start(GTK_BOX(hbox3),button,0,0,0);
	gtk_widget_set_size_request(button,80,50);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(prtsini),NULL);
	
	
	// GtkWidget *hbox4;
        hbox4=gtk_hbox_new(FALSE,0);
        gtk_container_add(GTK_CONTAINER(vbox),hbox4);

	button=gtk_button_new_with_label(          "1"   );
	gtk_box_pack_start(GTK_BOX(hbox4),button,0,0,0);
	gtk_widget_set_size_request(button,80,50);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(prt1),NULL);

	button=gtk_button_new_with_label(          "2"   );
	gtk_box_pack_start(GTK_BOX(hbox4),button,0,0,0);
	gtk_widget_set_size_request(button,80,50);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(prt2),NULL);


	button=gtk_button_new_with_label(          "3"   );
	gtk_box_pack_start(GTK_BOX(hbox4),button,0,0,0);
	gtk_widget_set_size_request(button,80,50);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(prt3),NULL);


	button=gtk_button_new_with_label(          "-"   );
	gtk_box_pack_start(GTK_BOX(hbox4),button,0,0,0);
	gtk_widget_set_size_request(button,80,50);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(prtminus),NULL);


	button=gtk_button_new_with_label(          "cos"   );
	gtk_box_pack_start(GTK_BOX(hbox4),button,0,0,0);
	gtk_widget_set_size_request(button,80,50);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(prtcos),NULL);

	button=gtk_button_new_with_label(          "cos-¹    "   );
	gtk_box_pack_start(GTK_BOX(hbox4),button,0,0,0);
	gtk_widget_set_size_request(button,80,50);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(prtcosi),NULL);
	
	
     

	 //GtkWidget *hbox5;
        hbox5=gtk_hbox_new(FALSE,0);
        gtk_container_add(GTK_CONTAINER(vbox),hbox5);

	button=gtk_button_new_with_label(          "."   );
	gtk_box_pack_start(GTK_BOX(hbox5),button,0,0,0);
	gtk_widget_set_size_request(button,80,50);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(prtdot),NULL);

	button=gtk_button_new_with_label(          "0"   );
	gtk_box_pack_start(GTK_BOX(hbox5),button,0,0,0);
	gtk_widget_set_size_request(button,80,50);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(prt0),NULL);

	button=gtk_button_new_with_label(          "+"   );
	gtk_box_pack_start(GTK_BOX(hbox5),button,0,0,0);
	gtk_widget_set_size_request(button,80,50);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(prtplus),NULL);


	button=gtk_button_new_with_label(          "="   );
	gtk_box_pack_start(GTK_BOX(hbox5),button,0,0,0);
	gtk_widget_set_size_request(button,80,50);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(submit),NULL);

	
	button=gtk_button_new_with_label(          "tan"   );
	gtk_box_pack_start(GTK_BOX(hbox5),button,0,0,0);
	gtk_widget_set_size_request(button,80,50);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(prttan),NULL);
	
	button=gtk_button_new_with_label(          "tan-¹"   );
	gtk_box_pack_start(GTK_BOX(hbox5),button,0,0,0);
	gtk_widget_set_size_request(button,80,50);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(prttani),NULL);

	gtk_widget_show_all(p);}
	
};






int main(int argc,char* argv[])
{

	gtk_init(&argc,&argv);
	icon one1;
	one1.make("CALCULATOR",480,600);
	one1.display(480,40);
	one1.form1();//"%");
	//one1.form1("X^y");
	gtk_main();
return 0;
}	
