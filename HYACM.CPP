#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<iomanip.h>
#include<time.h>
#include<ctype.h>

int n,i,k=0,l,choice;
long j=0,z=5000000;
char pn[20],un[20],cdat[9],ctim[9],nun[20],c,open1[30],open2[30];
fstream f,f1,f2,f3;

void kv();
void mdd();
void fo();
void fo1();
void view1();
void fs(char*,char*,char*);
void dt();
int tab(int,int,int,int);

void dt()//---------------------------------------------------------------------void dt()
{  _strdate(cdat);
	_strtime(ctim);
	cout<<"\n DATE: "<<cdat<<"\t\t\t\t\t\t\tTIME: "<<ctim;}//-----------------------------------------------------------------------------end void dt()

class phone
	{char no[11];
	 char name[20];
	public:
		char c;
		void addcontact();
		void updatecontact();
		void removecontact();
		void searchname();
		void searchno();
		void showall();
		void psin();
		void sh()
	 {       i+=2;
				gotoxy(1,i+4);
				cout<<"\t"<<name;
				gotoxy(30,i+4);
				cout<<"\t"<<no;}
		void disp(int z)
		{     gotoxy(1,z);
				cout<<"\t"<<name;
				gotoxy(30,z);
				cout<<"\t"<<no;}
			}s;

class user//--------------------------------------------------------------------class user
 {char uname[20],pass[20];
	public:
			 user()
			 { strcpy(uname,"Guest");
				strcpy(pass,"N.A.");}
			 ~user() {}
			 void flog()
			 { strcpy(uname,"administrator");
				strcpy(pass,"system");}
			 void log1();
			 void log1_c();
			 void logz();
			 void logzc();
			 void log2();
			 void log2_c();
			 void log3();
			 void log3_c();
			 void run()
			 {cout<<"USER : "<<uname;}
			 char*retuname()
			 {return uname;}
}u,p,r;//-----------------------------------------------------------------------end class user

class visual//------------------------------------------------------------------class visual
{public:
			void welcome();
			void menu1dc();
			void menuz();
			void menu1ec();
			void menuy();
			void menu1fc();
			void menux();
			void guest();
			void menugu();
			void exit1();
}v;//---------------------------------------------------------------------------end class visual

class userset//-----------------------------------------------------------------class userset
 { int mds;
	public:
			 userset()
			 {mds=0;}
			 ~userset() {}
			 void mdc();
			 void md1();
			 void md2();
			 void md3();
			 void md4();
			 void md5();
			 void md6();
			 void md7();
			 void menu();
			 void menu_c();
}t,t1;//------------------------------------------------------------------------end class userset

void phone::showall()
			{ i=2;
				kv();
				cout<<"\tNAME \t\t\tNUMBER  "<<endl;
				fstream A("hy",ios::binary|ios::in);
				while(1)
					{  A.read((char*)this,sizeof(phone));
						if(A.eof())
							break;
							sh();}
				 A.close();
				 getche();}

void phone :: addcontact()
	{    char c='y';
			yu:
			clrscr();
			ofstream A("hy",ios::app|ios::binary);
				do
				 {char it[20];
					kv();
					cout<<"\t\t## ADD CONTACT  ##"<<endl;
					cout<<"\t\t\t ENTER NAME -> ";
					gets(it);
					ifstream B("hy",ios::binary);
					int flag=1;
					while(1)
						{ B.read((char*)this,sizeof(phone));
							if(B.eof())
								break;
							if(strcmpi(name,it)==0)
								flag=0;}
					B.close();
					if(flag==1)
						strcpy(name,it);
						if(flag==0)
						{char ch='n';
							cout<<" CONTACT HAVING THIS NAME ALREADY EXISTS  "<<endl;
							cout<<" DO YOU WANT TO GOTO UPDATE(Y/N) : ";
							cin>>ch;
								if(ch=='y'||ch=='Y')
									updatecontact();
								else
									{  cout<<"\t\tDO YOU WANT TO ADD CONTACT(Y/N) : ";
										cin>>ch;
										if(ch=='y'||ch=='Y')
											goto yu;
										else
											return;}}
				cout<<"\t\t\t ENTER NUMBER -> ";
				cin>>no;
				A.write((char*)this,sizeof(phone));
				cout<<"________________________________________________________________________________"<<endl;
				cout<<"\t\t DO YOU WANT TO ADD MORE (Y/N) :-";
					cin>>c;
					if(c=='y'||c=='Y')
					goto yu;
					else
					return;}while(c=='y'||c=='Y');
				A.close();}

void phone :: updatecontact()
	{ ud:
		clrscr();
			kv();
			cout<<"\t\t        ## UPDATE CONTACT ##"<<endl;
			fstream A("hy",ios::binary|ios::in|ios::out|ios::binary);
			ofstream  a1("temp");
			char ino[20];
			cout<<"\t\t ENTER NAME WHICH YOU WANT TO UPDATE   -> ";
			gets(ino);
			int flag=0;
			while(1)
				{  A.read((char*)this,sizeof(phone));
					if(A.eof())
						break;
					if(strcmpi(name,ino)==0)
						{  flag=1;
							cout<<"\n\t\t\tENTER NEW NAME     -> ";
							gets(name);
							cout<<"\t\t\tENTER NUMBER  -> ";
							cin>>no;}
					a1.write((char*)this,sizeof(phone));}
			if(flag==0)
				{  char ch;
					cout<<"\n\t\tTHERE IS NO SUCH NAME !!!";
					cout<<"\n\t\tDO YOU WANT TO ADD THIS CONTACT(Y/N) -> ";
					cin>>ch;
					if(ch=='y'||ch=='Y')
						addcontact();
					else
						return;}
				A.close();
			  a1.close();
			  remove("hy");
			rename("temp","hy");
			char y;
			cout<<"\t\t DO YOU WANT TO REMOVE MORE (Y/N) -> ";
			cin>>y;
			if(y=='Y'||y=='y')
			{goto ud;}
			else
			{return;}}

void phone :: removecontact()
{ rc:
			clrscr();
				kv();
			cout<<"\t\t        ## REMOVE CONTACT ##"<<endl;
			ifstream A("hy",ios::binary);
			ofstream  a1("temp");
			char ino[20];
			cout<<"\t\t ENTER NAME WHICH YOU WANT TO REMOVE   -> ";
			gets(ino);
			while(1)
				{  A.read((char*)this,sizeof(phone));
					if(A.eof())
						break;
					if(strcmpi(name,ino)==0)
						{continue;}
					 else
					 a1.write((char*)this,sizeof(phone));}
         A.close();
			a1.close();
			remove("hy");
			rename("temp","hy");
			char y;
			cout<<"\t\t DO YOU WANT TO REMOVE MORE (Y/N) -> ";
			cin>>y;
			if(y=='Y'||y=='y')
			{goto rc;}
			else
			{return;}}

void phone :: searchname()
	{ clrscr();
		char nm[20];
		ifstream A("hy",ios::binary);
		kv();
		cout<<"\n\t\t\t ENTER THE NAME -> ";
		gets(nm);
		int flag=0;
			while(1)
				{ A.read((char*)this,sizeof(phone));
					if(A.eof())
						break;
					if(strcmpi(name,nm)==0)
						{  flag=1;
							cout<<"\n\t\t\tNAME     >>> "<<name<<endl;
							cout<<"\t\t\tNUMBER  >>> "<<no<<endl;
							getche();}}
			if(flag==0)
				{cout<<"\n\t\tTHERE IS NO SUCH NAME !!!";
				 getche();
						return;}
				A.close();}

void phone :: searchno()
	{  char num[11];
		ifstream A("hy",ios::binary);
		kv();
		cout<<"\n\t\t\t ENTER THE NUMBER -> ";
		cin>>num;
			int flag=0;
			while(1)
				{ A.read((char*)this,sizeof(phone));
					if(A.eof())
						break;
					if(strcmpi(no,num)==0)
						{  flag=1;
							cout<<"\n\t\t\tNAME     >>> "<<name<<endl;
							cout<<"\t\t\tNUMBER >>> "<<no<<endl;
						  getche();}}
			if(flag==0)
				{ cout<<"\n\t\tTHERE IS NO SUCH NUMBER !!!";
				  getche();
						return;}
				  A.close();}

void phone :: psin()
 {  char in[50],c;
	int n=0,r,p,z=21;
	while(int(in[n-1])!=13)
	{  p=7;
		if(n>0)
		{ for(i=0;i<n;i++)
			{cout<<in[i];}
			ifstream f1;
			f1.open("hy",ios::in|ios::binary);
			if(!f1)
			{  clrscr();
				cout<<"\n\n\n\n\n\n\n\n\n\t\t!!! ERROR OPENING FILE : "<<" !!!";
				getch();
				psin();}
			while(!f1.eof())
			{  r=0;
				f1.read((char*)this,sizeof(phone));
				if(!f1.eof())
				{ for(i=0;i<n;i++)
					{if((char(tolower(in[i])==name[i]))||(char(toupper(in[i]))==name[i]))
						{++r;}}
					if(r==n)
					{  disp(p);
						p=p+2;}}}
			 gotoxy(z,4);
			  {c=getch();
				if(int(c)==8)
				{ cout<<"\b\b";
					--n;
					z=z-2;
					if(n==0)
					{z=20;}}
				else
				{ in[n]=c;
					++n;}}
			  ++z;
			  f1.close();}
		clrscr();
		cout<<"\n\nENTER NAME : ";
		if(n==0)
		{  c=getch();
			if(int(c)==8)
			{break;}
			else
			{in[n]=c;
			++n;}}}}

int tab(int x,int y,int g,int e)//----------------------------------------------int tab(int x,int y,int g,int e)
{ int z=1,w=y;
  while(1)
	{gotoxy(x,y-1);
		{for(int i=0;i<35;i++)
			{cout<<"-";}}
		gotoxy(x,y+1);
		{for(int i=0;i<35;i++)
			{cout<<"-";}}
		gotoxy(x,y);
			cout<<">";
		gotoxy(x+34,y);
			cout<<"|";
		gotoxy(50,50);
			char ch=getch();
		if(int(ch)==9)
		{ gotoxy(x+35,y-1);
			{ for(int i=0;i<35;i++)
				{cout<<"\b";}}
			gotoxy(x+35,y+1);
			{for(int i=0;i<35;i++)
				{cout<<"\b";}}
			gotoxy(x+1,y);
				cout<<"\b";
			gotoxy(x+35,y);
				cout<<"\b";
			if(y==e)
			{ y=w-g;
				z=0;}
			y=y+g;
			++z;}
		else if(int(ch)==13)
		{return z;}
		else
		{ cout<<"\b\b";
			return -1;}}}

void visual :: welcome()//------------------------------------------------------void visual :: welcome()
  {clrscr();
	dt();
	t.md4();
	l=0;
	while(1)
	{ if((j==z)&&(l==0))
		{ gotoxy(30,7);
				cout<<"TELEPHONE DIRECTORY";
		j=0;
		l=1;}
		if((j==z)&&(l==1))
		{ gotoxy(45,8);
			cout<<"2013-14";
		j=0;
		l=2;}
		if((j==z)&&(l==2))
		{ gotoxy(16,12);
			cout<<"BY : HIMMAT YADAV";
		j=0;
		l=3;}
		if((j==z)&&(l==3))
		{  gotoxy(13,13);
			cout<<"YEAR : BTECH-1";
		j=0;
		l=4;}
		if((j==z)&&(l==4))
		{gotoxy(10,14);
		cout<<"ROLL NO. : U13CO055";
		j=0;
		l=5;}
		if((j==z)&&(l==5))
		{     gotoxy(14,15);
				cout<<"SUB. : ACM FAIR";
		j=0;
		l=6;}
		if((j==z)&&(l==6))
		{    gotoxy(11,16);
				cout<<"SESSION : 2013-14";
		j=0;
		l=7;}
		if((j==z)&&(l==7))
		{ gotoxy(6,17);
			cout<<"TYPE : C++ PROGRAM ";
		j=0;
		l=8;}
		if((j==z)&&(l==8))
		{    gotoxy(12,18);
				cout<<"COLLEGE : SVNIT SURAT";
		j=0;
		l=9;}
		if((j==z)&&(l==9))
		{  gotoxy(10,23);
				{  cout<<"PRESS ANY KEY TO CONTINUE............. ";
					getch();}
		break;}
		j++;}}//-----------------------------------------------------------------------------end void visual :: welcome()

void visual :: exit1()//--------------------------------------------------------void visual :: exit1()
  {clrscr();
	dt();
	t.md5();
	l=0;
	while(1)
	{if((j==z)&&(l==0))
		{  gotoxy(8,9);
				cout<<"YOU WERE SUCCESSFULLY LOGGED OUT ...";
		j=0;
		l=1;}
		if((j==z)&&(l==1))
		{gotoxy(20,12);
		cout<<"THANK U FOR USING TELEPHONE DIRECTORY";
		j=0;
		l=2;}
		if((j==z)&&(l==2))
		{gotoxy(59,13);
				cout<<"2013-14";
		j=0;
		l=3;}
		if((j==z)&&(l==3))
		{gotoxy(10,23);
			{cout<<"PRESS ANY KEY TO EXIT............. ";
			getch();	}
		break;}
		j++;}
	f1.close();
	f2.close();
	f3.close();
	f.close();
	exit(0);}//-----------------------------------------------------------------------------end void visual :: exit1()

void userset :: md1()//---------------------------------------------------------void userset :: md1()
  {l=0;
	while(1)
	{
		if((j==z)&&(l==0))
		{
			gotoxy(0,3);
				for(i=0;i<40;i++)
					cout<<"* ";
		j=0;
		l=1;
		}
		if((j==z)&&(l==1))
		{
			for(i=4;i<21;i++)
			{
				gotoxy(0,i);
					cout<<"*";
			}
		j=0;
		l=2;
		}
		if((j==z)&&(l==2))
		{
			for(i=4;i<21;i++)
			{
				gotoxy(79,i);
					cout<<"*";
			}
		j=0;
		l=3;
		}
		if((j==z)&&(l==3))
		{
			gotoxy(0,21);
				for(i=0;i<40;i++)
					cout<<"* ";
		break;
		}
		++j;
	}
}//-----------------------------------------------------------------------------end void userset :: md1()

void userset :: md2()//---------------------------------------------------------void userset :: md2()
{
	l=0;
	while(1)
	{
		if((j==z)&&(l==0))
		{
			gotoxy(0,3);
				for(i=0;i<40;i++)
					cout<<"_ ";
		j=0;
		l=1;
		}
		if((j==z)&&(l==1))
		{
			for(i=4;i<21;i++)
			{
				gotoxy(0,i);
					cout<<"|";
			}
		j=0;
		l=2;
		}
		if((j==z)&&(l==2))
		{
			for(i=4;i<21;i++)
			{
				gotoxy(79,i);
					cout<<"|";
			}
		j=0;
		l=3;
		}
		if((j==z)&&(l==3))
		{
			gotoxy(0,21);
				for(i=0;i<40;i++)
					cout<<"_ ";
		break;
		}
		++j;
	}
}//-----------------------------------------------------------------------------end void userset :: md2()

void userset :: md3()//---------------------------------------------------------void userset :: md3()
{
	l=0;
	while(1)
	{
		if((j==z)&&(l==0))
		{
			gotoxy(0,3);
				for(i=0;i<80;i++)
					cout<<"_";
		j=0;
		l=1;
		}
		if((j==z)&&(l==1))
		{
			for(i=4;i<21;i++)
			{
				gotoxy(0,i);
					cout<<"||";
			}
		j=0;
		l=2;
		}
		if((j==z)&&(l==2))
		{
			for(i=4;i<21;i++)
			{
				gotoxy(79,i);
					cout<<"||";
			}
		j=0;
		l=3;
		}
		if((j==z)&&(l==3))
		{
			gotoxy(0,21);
				for(i=0;i<80;i++)
					cout<<"_";
		break;
		}
		++j;
	}
}//-----------------------------------------------------------------------------end void userset :: md3()

void userset :: md4()//---------------------------------------------------------void userset :: md4()
{
	l=0;
	while(1)
	{
		if((j==z)&&(l==0))
		{
			gotoxy(0,3);
				for(i=0;i<40;i++)
					cout<<"/\\";
		j=0;
		l=1;
		}
		if((j==z)&&(l==1))
		{
			for(i=5;i<20;i++)
				{
					gotoxy(0,i);
						cout<<"||";
				}
		j=0;
		l=2;
		}
		if((j==z)&&(l==2))
		{
			for(i=5;i<20;i++)
				{
					gotoxy(79,i);
						cout<<"||";
				}
		j=0;
		l=3;
		}
		if((j==z)&&(l==3))
		{
			gotoxy(0,21);
				for(i=0;i<40;i++)
					cout<<"/\\";
		break;
		}
		j++;
	}
}//-----------------------------------------------------------------------------end void userset :: md4()

void userset :: md5()//---------------------------------------------------------void userset :: md5()
{
	l=0;
	while(1)
	{
		if((j==z)&&(l==0))
		{
			gotoxy(0,3);
				for(i=0;i<40;i++)
					cout<<"-_";
		j=0;
		l=1;
		}
		if((j==z)&&(l==1))
		{
			for(i=4;i<21;i++)
				{
					gotoxy(0,i);
						cout<<"||";
				}
		j=0;
		l=2;
		}
		if((j==z)&&(l==2))
		{
			for(i=4;i<21;i++)
				{
					gotoxy(79,i);
						cout<<"||";
				}
		j=0;
		l=3;
		}
		if((j==z)&&(l==3))
		{
			gotoxy(0,21);
				for(i=0;i<40;i++)
					cout<<"_-";
		break;
		}
		j++;
	}
}//-----------------------------------------------------------------------------end void userset :: md5()

void userset :: md6()//---------------------------------------------------------void userset :: md6()
{
	l=0;
	while(1)
	{
		if((j==z)&&(l==0))
		{
			gotoxy(0,3);
				for(i=0;i<40;i++)
					cout<<"~ ";
		j=0;
		l=1;
		}
		if((j==z)&&(l==1))
		{
			for(i=4;i<21;i++)
			{
				gotoxy(0,i);
					cout<<"~";
			}
		j=0;
		l=2;
		}
		if((j==z)&&(l==2))
		{
			for(i=4;i<21;i++)
			{
				gotoxy(79,i);
					cout<<"~";
			}
		j=0;
		l=3;
		}
		if((j==z)&&(l==3))
		{
			gotoxy(0,21);
				for(i=0;i<40;i++)
					cout<<"~ ";
		break;
		}
		++j;
	}
}//-----------------------------------------------------------------------------end void userset :: md6()

void userset :: md7()//---------------------------------------------------------void userset :: md7()
{
	l=0;
	while(1)
	{
		if((j==z)&&(l==0))
		{
			gotoxy(0,3);
				for(i=0;i<40;i++)
					cout<<"^ ";
		j=0;
		l=1;
		}
		if((j==z)&&(l==1))
		{
			for(i=4;i<21;i++)
			{
				gotoxy(0,i);
					cout<<"^";
			}
		j=0;
		l=2;
		}
		if((j==z)&&(l==2))
		{
			for(i=4;i<21;i++)
			{
				gotoxy(79,i);
					cout<<"^";
			}
		j=0;
		l=3;
		}
		if((j==z)&&(l==3))
		{
			gotoxy(0,21);
				for(i=0;i<40;i++)
					cout<<"^ ";
		break;
		}
		++j;
	}
}//-----------------------------------------------------------------------------end void userset :: md7()
void userset :: menu()//--------------------------------------------------------void userset :: menu()
 { clrscr();
	dt();
	t.mdc();
	l=0;
	while(1)
	{if((j==z)&&(l==0))
		{   gotoxy(4,4);
				p.run();
		j=0;
		l=1;}
		if((j==z)&&(l==1))
		{  gotoxy(25,8);
				cout<<"[ ] : CHANGE OUTLINING DESIGN";
		j=0;
		l=2;}
		if((j==z)&&(l==2))
		{gotoxy(25,12);
		cout<<"[ ] : BACK";
		j=0;
		l=3;}
		if((j==z)&&(l==3))
		{gotoxy(25,16);
		cout<<"[ ] : EXIT";
		break;}
		j++;}
	gotoxy(15,23);
		cout<<"PRESS 'TAB' TO SCROLL";
	choice=tab(26,8,4,16);
	if(choice==-1)
	{menu();}
	menu_c();}//-----------------------------------------------------------------------------end void userset :: menu()

void userset :: menu_c()//------------------------------------------------------void userset :: menu_c()
 {switch(choice)
	{ case 1 : char ch;
					s:
					clrscr();
					dt();
					cout<<"\n\n      ___________________________________________________________________      ";
					cout<<"\n                                OUTLINING DESIGN";
					cout<<"\n      ___________________________________________________________________      ";
					cout<<"\n\n\n\t\t1 : DESIGN 1\t\t2 : DESIGN 2";
					cout<<"\n\n\t\t3 : DESIGN 3\t\t4 : DESIGN 4";
					cout<<"\n\n\t\t5 : DESIGN 5\t\t6 : DESIGN 6";
					cout<<"\n\n\t\t7 : DESIGN 7";
					cout<<"\n\n\n\t\t\tENTER YOUR CHOICE : ";
					cin>>mds;
					switch(mds)
					{
						case 1 : md1();
									goto s1;
						case 2 : md2();
									goto s1;
						case 3 : md3();
									goto s1;
						case 4 : md4();
									goto s1;
						case 5 : md5();
									goto s1;
						case 6 : md6();
									goto s1;
						case 7 : md7();
									goto s1;
						default: clrscr();
									dt();
									cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\tNO SUCH CHOICE AVAILABLE";
									getch();
									goto s;}
					s1:
					cout<<"\n\n\t\t\tSELECT THIS DESIGN [y/n] : ";
					cin>>ch;
					if((ch=='Y')||(ch=='y'))
					{ f3.open(p.retuname(),ios::in|ios::binary);
						f3.read((char*)&t1,sizeof(t1));
						f3.close();
						t1.mds=mds;
						remove(p.retuname());
						f3.open(p.retuname(),ios::out|ios::binary);
						f3.write((char*)&t1,sizeof(t1));
						f3.close();
						menu();}
					else
					{goto s;}
		case 2 : r.log2();
		case 3 : v.exit1();
		default: clrscr();
					dt();
					cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\tNO SUCH CHOICE AVAILABLE";
					getch();
					menu();}}//-----------------------------------------------------------------------------end void userset :: menu_c()

 void user :: log1()//-----------------------------------------------------------void user :: log1()
  {clrscr();
	dt();
	t.md4();
	l=0;
	while(1)
	{ if((j==z)&&(l==0))
		{  gotoxy(15,12);
				cout<<"WELCOME";
		j=0;
		l=1;}
		if((j==z)&&(l==1))
		{  gotoxy(30,8);
				cout<<"[ ] : ADMINISTRATOR";
		j=0;
		l=2;}
		if((j==z)&&(l==2))
		{gotoxy(30,12);
				cout<<"[ ] : OTHER USER";
		j=0;
		l=3;}
		if((j==z)&&(l==3))
		{gotoxy(30,16);
				cout<<"[ ] : EXIT";
		break;}
		j++;}
	gotoxy(15,23);
		cout<<"PRESS 'TAB' TO SCROLL";
	choice=tab(31,8,4,16);
	if(choice==-1)
	{log1();}
	log1_c();}//-----------------------------------------------------------------------------end void user :: log1()

void user :: log1_c()//---------------------------------------------------------void user :: log1_c()
 { int l;
	switch(choice)
	{  case 1 : clrscr();
					f1.open("himmat",ios::in|ios::binary);
					if(!f1)
					{ clrscr();
						dt();
						cout<<"\n\n\n\n\n\n\n\n\n\t\t!!! ERROR OPENING FILE : 'himmat' !!!";
						getch();
						log1();}
					k=0;
					dt();
					cout<<"\n _____________________________________________________________________________ ";
					cout<<"\n                              ADMINISTRATOR LOGIN";
					cout<<"\n _____________________________________________________________________________ ";
					cout<<"\n\n\n\n\n\n\n\n\t\t\tPASSWORD : ";
					for(i=0;i>=0;i++)
					{ c=getch();
						cout<<"*";
						if(int(c)==13)
						{break;}
						else if(int(c)==8)
						{cout<<"\b\b";
							i=i-2;
							continue;}
						pn[i]=c;}
					while(!f1.eof())
					{f1.read((char*)&u,sizeof(u));
						if(!f1.eof())
						{l=0;
							for(i=0;u.pass[i]!='\0';i++)
							{if((toupper(pn[i])==u.pass[i])||(tolower(pn[i])==u.pass[i]))
								{	++l;}}
							i=strlen(u.pass);
							if((strcmpi(u.uname,"administrator")==0)&&(l==i))
							{ p=u;
								k=1;
								f1.close();
								clrscr();
								cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t!!! LOGIN SUCCESSFUL !!!";
								getch();
								f1.close();
								fo1();
								log2();}}}
					if(k==0)
					{ clrscr();
						dt();
						cout<<"\n\n\n\n\n\n\n\n\n\t\t\t!!! ACCOUNT NOT FOUND !!!";
						getch();
						f1.close();
						log1();}
		case 2 : logz();
		case 3 : v.exit1();
		default: clrscr();
					dt();
					cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\tNO SUCH CHOICE AVAILABLE";
					getch();
					log1();}}//-----------------------------------------------------------------------------end void user :: log1_c()
void user :: logz()//-----------------------------------------------------------void user :: log1()
 { 	clrscr();
	dt();
	t.md4();
	l=0;
	while(1)
	{ if((j==z)&&(l==0))
		{ gotoxy(15,12);
			cout<<"WELCOME";
		j=0;
		l=1;}
		if((j==z)&&(l==1))
		{gotoxy(30,8);
				cout<<"[ ] : REGISTERED USER";
		j=0;
		l=2;}
		if((j==z)&&(l==2))
		{  gotoxy(30,12);
				cout<<"[ ] : GUEST";
		j=0;
		l=3;}
		if((j==z)&&(l==3))
		{gotoxy(30,16);
				cout<<"[ ] : BACK";
		break;}
		j++;}
	gotoxy(15,23);
		cout<<"PRESS 'TAB' TO SCROLL";
	choice=tab(31,8,4,16);
	if(choice==-1)
	{logz();}
	logzc();}//-----------------------------------------------------------------------------end void user :: log1()

void user :: logzc()//---------------------------------------------------------void user :: log1_c()
 { int l;
	char d[10]="system";
	switch(choice)
	{  case 1 : clrscr();
					k=0;
					f1.open("himmat",ios::in|ios::binary);
					if(!f1)
					{ clrscr();
						dt();
						cout<<"\n\n\n\n\n\n\n\n\n\t\t!!! ERROR OPENING FILE : 'himmat' !!!";
						getch();
						log1();}
					clrscr();
					dt();
					cout<<"\n _____________________________________________________________________________ ";
					cout<<"\n                                  USER LOGIN";
					cout<<"\n _____________________________________________________________________________ ";
					cout<<"\n\n\n\n\n\t\t\tUSER NAME : ";
					gets(un);
					cout<<"\n\n\t\t\tPASSWORD : ";
					for(i=0;i>=0;i++)
					{c=getch();
						cout<<"*";
						if(int(c)==13)
						{	break;}
						else if(int(c)==8)
						{cout<<"\b\b";
							i=i-2;
							continue;}
						pn[i]=c;}
					for(i=0;i<6;i++)
					{if(i<strlen(pn))
						{	continue;}
						pn[i]=d[i];}
					while(!f1.eof())
					{ f1.read((char*)&u,sizeof(u));
						if(!f1.eof())
						{l=0;
							for(i=0;u.pass[i]!='\0';i++)
							{	if((toupper(pn[i])==u.pass[i])||(tolower(pn[i])==u.pass[i]))
								{	++l;}}
							i=strlen(u.pass);
							if((strcmpi(u.uname,un)==0)&&(i==l))
							{p=u;
								k=1;
								f1.close();
								clrscr();
								cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t!!! LOGIN SUCCESSFUL !!!";
								getch();
								f1.close();
								fo1();
								log2();}}}
					if(k==0)
					{ clrscr();
						dt();
						cout<<"\n\n\n\n\n\n\n\n\n\t\t\t!!! ACCOUNT NOT FOUND !!!";
						getch();
						f1.close();
						log1();}
		 case 2:{	  v.guest();	}
		 case 3 : log1();
		 default: clrscr();
					dt();
					cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\tNO SUCH CHOICE AVAILABLE";
					getch();
					logz();}}//-----------------------------------------------------------------------------end void user :: log1_c()
 void user :: log2()//-----------------------------------------------------------void user :: log2()
  {  clrscr();
	dt();
	t.mdc();
	l=0;
	while(1)
	{if((j==z)&&(l==0))
		{gotoxy(4,4);
				p.run();
		j=0;
		l=1;}
		if((j==z)&&(l==1))
		{ gotoxy(25,6);
				cout<<"[ ] : MANAGE CONTACTS";
		j=0;
		l=2;}
		if((j==z)&&(l==2))
		{ gotoxy(25,9);
				cout<<"[ ] : USER ACCOUNT's SETTINGS";
		j=0;
		l=3;}
		if((j==z)&&(l==3))
		{gotoxy(25,12);
				cout<<"[ ] : VISUAL SETTINGS";
		j=0;
		l=4;}
		if((j==z)&&(l==4))
		{gotoxy(25,15);
				cout<<"[ ] : LOGOUT";
		j=0;
		l=5;}
		if((j==z)&&(l==5))
		{gotoxy(25,18);
				cout<<"[ ] : EXIT";
		break;}
		j++;}
	gotoxy(15,23);
		cout<<"PRESS 'TAB' TO SCROLL";
	choice=tab(26,6,3,18);
	if(choice==-1)
	{log2();}
	log2_c();}//-----------------------------------------------------------------------------end void user :: log2()

void user :: log2_c()//---------------------------------------------------------void user :: log2_c()
{switch(choice)
	{case 1 : v.menuy();
	 case 2 : log3();
	 case 3 : t.menu();
	 case 4 : log1();
	 case 5 : v.exit1();
	default: clrscr();
					dt();
					cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\tNO SUCH CHOICE AVAILABLE";
					getch();
					log2();}}//-----------------------------------------------------------------------------end void user :: log2_c()

void user :: log3()//-----------------------------------------------------------void user :: log3()
 {	clrscr();
	dt();
	t.mdc();
	l=0;
	while(1)
	{if((j==z)&&(l==0))
		{gotoxy(4,4);
				p.run();
		j=0;
		l=1;}
		if((j==z)&&(l==1))
		{gotoxy(25,7);
				cout<<"[ ] : CREATE ACCOUNT";
		j=0;
		l=2;}
		if((j==z)&&(l==2))
		{gotoxy(25,9);
				cout<<"[ ] : CHANGE USERNAME";
		j=0;
		l=3;}
		if((j==z)&&(l==3))
		{gotoxy(25,11);
				cout<<"[ ] : CHANGE PASSWORD";
		j=0;
		l=4;}
		if((j==z)&&(l==4))
		{gotoxy(25,13);
				cout<<"[ ] : DELETE ACCOUNT";
		j=0;
		l=5;}
		if((j==z)&&(l==5))
		{  gotoxy(25,15);
				cout<<"[ ] : BACK";
		j=0;
		l=6;}
		if((j==z)&&(l==6))
		{gotoxy(25,17);
				cout<<"[ ] : EXIT";
		break;}
		j++;}
	gotoxy(15,23);
		cout<<"PRESS 'TAB' TO SCROLL";
	choice=tab(26,7,2,17);
	if(choice==-1)
	{log3();}
	log3_c();}//-----------------------------------------------------------------------------end void user :: log3()

void user :: log3_c()//---------------------------------------------------------void user :: log3_c()
 { char c,a[30],b[30];
	user u1;
	switch(choice)
	{case 1 : clrscr();
					dt();
					cout<<"\n _____________________________________________________________________________ ";
					cout<<"\n                                    NEW ACCOUNT";
					cout<<"\n _____________________________________________________________________________ ";
					cout<<"\n\n\n\n\n\t\t\tUSER NAME : ";
					gets(un);
					if((strcmpi(un,"USER")==0)||(strcmpi(un,"ADMINISTRATOR")==0))
					{ clrscr();
						cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t!!! NOT ALLOWED !!!";
						getch();
						log3();}
					cout<<"\n\n\t\t\tPASSWORD : ";
					for(i=0;i>=0;i++)
					{c=getch();
						cout<<"*";
						if(int(c)==13)
						{	break;}
						else if(int(c)==8)
						{cout<<"\b\b";
							i=i-2;
							continue;}
						pn[i]=c;}
					strcpy(u1.uname,un);
					strcpy(u1.pass,pn);
					f1.open("himmat",ios::out|ios::binary|ios::app);
					if(!f1)
					{ clrscr();
						dt();
						cout<<"\n\n\n\n\n\n\n\n\n\t\t!!! ERROR OPENING FILE : 'himmat' !!!";
						getch();
						log3();}
					f1.write((char*)&u1,sizeof(u1));
					clrscr();
					cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t!!! ACCOUNT CREATED !!!";
					getch();
					f1.close();
					log3();
		case 2 : clrscr();
					dt();
					cout<<"\n _____________________________________________________________________________ ";
					cout<<"\n                                    CHANGE USERNAME";
					cout<<"\n _____________________________________________________________________________ ";
					cout<<"\n\n\n\n\n\t\t\tOLD USER NAME : ";
					gets(un);
					if((strcmpi(un,"administrator")==0)||(strcmpi(un,"USER")==0))
					{  clrscr();
						cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t!!! NOT ALLOWED !!!";
						getch();
						log3();}
					cout<<"\n\n\t\t\tPASSWORD : ";
					for(i=0;i>=0;i++)
					{  c=getch();
						cout<<"*";
						if(int(c)==13)
						{break;}
						else if(int(c)==8)
						{ cout<<"\b\b";
							i=i-2;
							continue;}
						pn[i]=c;}
					cout<<"\n\n\n\t\t\tNEW USER NAME : ";
					gets(nun);
					f1.open("himmat",ios::in,ios::binary);
					if(!f1)
					{  clrscr();
						dt();
						cout<<"\n\n\n\n\n\n\n\n\n\t\t!!! ERROR OPENING FILE : 'himmat' !!!";
						getch();
						log3();}
					f2.open("temp",ios::out|ios::binary);
					while(!f1.eof())
					{ f1.read((char*)&u1,sizeof(u1));
						if(!f1.eof())
						{if(strcmpi(u1.uname,un)==0)
							{	k=1;
								strcpy(u1.uname,nun);
								f2.write((char*)&u1,sizeof(u1));}
							else
							{f2.write((char*)&u1,sizeof(u1));}	}}
					f1.close();
					f2.close();
					remove("user");
					rename("temp","user");
					if(k==1)
					{clrscr();
						cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t!!! USERNAME CHANGED !!!";
						getch();
						if(strcmpi(un,p.retuname())==0)
						{	clrscr();
							cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tPLEASE LOGOUT AND LOGIN AGAIN TO VIEW CHANGES";
							getch();
							log3();}}
					else
					{clrscr();
						cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t!!! USERNAME CHANGING FAILED !!!";
						getch();}
					log3();
		case 3 : clrscr();
					k=0;
					dt();
					cout<<"\n _____________________________________________________________________________ ";
					cout<<"\n                                    CHANGE PASSWORD";
					cout<<"\n _____________________________________________________________________________ ";
					cout<<"\n\n\n\n\n\t\t\tUSER NAME : ";
					gets(un);
					if(strcmpi(un,"administrator")==0)
					{ clrscr();
						cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t!!! NOT ALLOWED !!!";
						getch();
						log3();}
					cout<<"\n\n\t\t\tOLD PASSWORD : ";
					for(i=0;i>=0;i++)
					{c=getch();
						cout<<"*";
						if(int(c)==13)
						{	break;}
						else if(int(c)==8)
						{cout<<"\b\b";
							i=i-2;
							continue;}
						pn[i]=c;}
					cout<<"\n\n\n\t\t\tNEW PASSWORD : ";
					for(i=0;i>=0;i++)
					{c=getch();
						cout<<"*";
						if(int(c)==13)
						{	break;}
						else if(int(c)==8)
						{cout<<"\b\b";
							i=i-2;
							continue;}
						nun[i]=c;}
					f1.open("himmat",ios::in|ios::binary);
					if(!f1)
					{clrscr();
						dt();
						cout<<"\n\n\n\n\n\n\n\n\n\t\t!!! ERROR OPENING FILE : 'himmat' !!!";
						getch();
						log3();}
					f2.open("temp",ios::out|ios::binary);
					while(!f1.eof())
					{f1.read((char*)&u1,sizeof(u1));
						if(!f1.eof())
						{	if(strcmpi(u1.pass,pn)==0)
							{	k=1;
								strcpy(u1.pass,nun);
								f2.write((char*)&u1,sizeof(u1));}
							else
							{f2.write((char*)&u1,sizeof(u1));}}}
					f1.close();
					f2.close();
					remove("user");
					rename("temp","user");
					if(k==1)
					{ clrscr();
						cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t!!! PASSWORD CHANGED !!!";
						getch();
						if(strcmpi(un,p.retuname())==0)
						{clrscr();
							cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tPLEASE LOGOUT AND LOGIN AGAIN TO VIEW CHANGES";
							getch();
							log3();}}
					else
					{ clrscr();
						cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t!!! PASSWORD CHANGING FAILED !!!";
						getch();}
					log3();
case 4 : clrscr();
					k=0;
					dt();
					cout<<"\n _____________________________________________________________________________ ";
					cout<<"\n                                   DELETE ACCOUNT";
					cout<<"\n _____________________________________________________________________________ ";
					cout<<"\n\n\n\n\n\t\t\tUSER NAME : ";
					gets(un);
					if((strcmpi(un,"administrator")==0)||(strcmpi(un,p.retuname())==0))
					{clrscr();
						cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t!!! NOT ALLOWED !!!";
						getch();
						log3();}
					cout<<"\n\n\n\t\t\tPASSWORD : ";
					for(i=0;i>=0;i++)
					{c=getch();
						cout<<"*";
						if(int(c)==13)
						{	break;}
						else if(int(c)==8)
						{ cout<<"\b\b";
							i=i-2;
							continue;}
						pn[i]=c;}
					f1.open("himmat",ios::in|ios::binary);
					if(!f1)
					{clrscr();
						dt();
						cout<<"\n\n\n\n\n\n\n\n\n\t\t!!! ERROR OPENING FILE : 'himmat' !!!";
						getch();
						log3();}
					f2.open("temp",ios::out|ios::binary);
					while(!f1.eof())
					{f1.read((char*)&u1,sizeof(u1));
						if(!f1.eof())
						{if((strcmpi(u1.uname,un)==0)&&(strcmpi(u1.pass,pn)==0))
							{  k=1;
								remove(u1.uname);
								fs(un,a,b);
								remove(a);
								remove(b);	}
							else
							{f2.write((char*)&u1,sizeof(u1));}}}
					f1.close();
					f2.close();
					remove("user");
					rename("temp","user");
					if(k==1)
					{clrscr();
						cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t!!! ACCOUNT DELETED !!!";
						getch();}
					else
					{clrscr();
						cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t!!! DELETING FAILED !!!";
						getch();}
					log3();
		case 5 : log2();
		case 6 : v.exit1();
		default: clrscr();
					dt();
					cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\tNO SUCH CHOICE AVAILABLE";
					getch();
					log1();}}//-----------------------------------------------------------------------------end void user :: log3_c()

void userset :: mdc()//---------------------------------------------------------void userset :: mdc()
 {f3.open(p.retuname(),ios::in|ios::binary);
	if(!f3)
	{	return;}
	f3.read((char*)&t1,sizeof(t1));
	switch(t1.mds)
	{case 1 : md1();
					break;
		case 2 : md2();
					break;
		case 3 : md3();
					break;
		case 4 : md4();
					break;
		case 5 : md5();
					break;
		case 6 : md6();
					break;
		case 7 : md7();
					break;
		default : break;}
	f3.close();}//-----------------------------------------------------------------------------end void
void fs(char*a,char*b,char*c)//-------------------------------------------------void fs(char*a,char*b,char*c)
{if(strlen(a)>5)
	{	strncpy(b,a,5);
		strncpy(c,a,5);}
	else
	{strcpy(b,a);
		strcpy(c,a);}
	strcat(b,"sin");
	strcat(c,"out");}//-----------------------------------------------------------------------------end void fs(char*a,char*b,char*c)

void fo()//---------------------------------------------------------------------void fo()
{f3.open("user",ios::out|ios::app|ios::binary);
	f3.seekg(0,ios::end);
	if(f3.tellp()==0)
	{	u.flog();
		f3.write((char*)&u,sizeof(u));}
	f3.close();
	f3.open("user",ios::in|ios::binary);
	while(!f3.eof())
	{f3.read((char*)&r,sizeof(r));
		if(!f3.eof())
		{	f1.open(r.retuname(),ios::out|ios::app|ios::binary);
			f1.close();}}
	f3.close();}//-----------------------------------------------------------------------------end void fo()

void fo1()//--------------------------------------------------------------------void fo1()
{	if(strcmpi(p.retuname(),"administrator")==0)
	{strcpy(open1,"adm");
	strcpy(open2,"adm");}
	else if(strlen(p.retuname())>5)
	{strncpy(open1,p.retuname(),5);
	strncpy(open2,p.retuname(),5);}
	else
	{strcpy(open1,p.retuname());
		strcpy(open2,p.retuname());}
	strcat(open1,"sin");
	strcat(open2,"out");
	f3.open(open1,ios::out|ios::app|ios::binary);
	f3.close();
	f3.open(open2,ios::out|ios::app|ios::binary);
	f3.close();}//-----------------------------------------------------------------------------end void fo1()

void view1()//------------------------------------------------------------------void view1()
{  gotoxy(5,5);
	cout<<"NAME";
	gotoxy(50,5);
	cout<<"NUMBER";}//-----------------------------------------------------------------------------end void view1()

void visual :: menuz()//--------------------------------------------------------void visual :: menu1()
	{ clrscr();
	dt();
	t.mdc();
	l=0;
	while(1)
	{if((j==z)&&(l==0))
		{	gotoxy(4,4);
				p.run();
		j=0;
		l=1;}
		if((j==z)&&(l==1))
		{   gotoxy(25,6);
				cout<<"[ ] : ADD CONTACTS";
		j=0;
		l=2;}
		if((j==z)&&(l==2))
		{gotoxy(25,9);
				cout<<"[ ] : REMOVE CONTACTS";
		j=0;
		l=3;}
		if((j==z)&&(l==3))
		{gotoxy(25,12);
				cout<<"[ ] : UPDATE CONTACTS";
		j=0;
		l=4;}
		if((j==z)&&(l==4))
		{gotoxy(25,15);
				cout<<"[ ] : BACK";
		j=0;
		l=5;}
		if((j==z)&&(l==5))
		{gotoxy(25,18);
				cout<<"[ ] : EXIT";
		break;}
		j++;}
	gotoxy(15,23);
		cout<<"PRESS 'TAB' TO SCROLL";
	choice=tab(26,6,3,18);
	if(choice==-1)
	{menuz();}
	menu1dc();}//-----------------------------------------------------------------------------end void visual :: menu1()

void visual :: menu1dc()//------------------------------------------------------void visual :: menu1_c()
 {switch(choice)
	{	case 1 : {s.addcontact(); menuz();}
		case 2 : {s.removecontact(); menuz();}
		case 3 : {s.updatecontact(); menuz();}
		case 4 : menuy();
		case 5 : exit1();
	  default: clrscr();
					dt();
					cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\tNO SUCH CHOICE AVAILABLE";
					getch();
					menuz();}}//-----------------------------------------------------------------------------end void visual :: menu1_c()

void visual :: menuy()//--------------------------------------------------------void visual :: menu1()
	{ clrscr();
	dt();
	t.mdc();
	l=0;
	while(1)
	{if((j==z)&&(l==0))
		{	gotoxy(4,4);
				p.run();
		j=0;
		l=1;}
		if((j==z)&&(l==1))
		{gotoxy(25,6);
				cout<<"[ ] : EDIT TELEPHONE DIRECTORY";
		j=0;
		l=2;}
		if((j==z)&&(l==2))
		{gotoxy(25,9);
				cout<<"[ ] : SEARCH";
		j=0;
		l=3;}
		if((j==z)&&(l==3))
		{gotoxy(25,12);
				cout<<"[ ] : VIEW ALL";
		j=0;
		l=4;}
		if((j==z)&&(l==4))
		{gotoxy(25,15);
				cout<<"[ ] : BACK";
		j=0;
		l=5;}
		if((j==z)&&(l==5))
		{gotoxy(25,18);
				cout<<"[ ] : EXIT";
		break;}
		j++;}
	gotoxy(15,23);
		cout<<"PRESS 'TAB' TO SCROLL";
	choice=tab(26,6,3,18);
	if(choice==-1)
	{menuy();}
	menu1ec();}//-----------------------------------------------------------------------------end void visual :: menu1()

void visual :: menu1ec()//------------------------------------------------------void visual :: menu1_c()
 {switch(choice)
	{	case 1 : menuz();
		case 2 : menux();
		case 3 : {s.showall(); menuy();}
		case 4 : r.log2();
		case 5 : exit1();
		default: clrscr();
					dt();
					cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\tNO SUCH CHOICE AVAILABLE";
					getch();
					menuy();}}//-----------------------------------------------------------------------------end void visual :: menu1_c()

void visual :: menux()//--------------------------------------------------------void visual :: menu1()
	{ clrscr();
	dt();
	t.mdc();
	l=0;
	while(1)
	{if((j==z)&&(l==0))
		{	gotoxy(4,4);
				p.run();
		j=0;
		l=1;}
		if((j==z)&&(l==1))
		{gotoxy(25,6);
				cout<<"[ ] : SEARCH BY NAME";
		j=0;
		l=2;}
		if((j==z)&&(l==2))
		{gotoxy(25,9);
				cout<<"[ ] : SEARCH BY NUMBER";
		j=0;
		l=3;}
		if((j==z)&&(l==3))
		{gotoxy(25,12);
				cout<<"[ ] : PARTIAL SEARCH";
		j=0;
		l=4;}
		if((j==z)&&(l==4))
		{gotoxy(25,15);
				cout<<"[ ] : BACK";
		j=0;
		l=5;}
		if((j==z)&&(l==5))
		{gotoxy(25,18);
				cout<<"[ ] : EXIT";
		break;}
		j++;}
	gotoxy(15,23);
		cout<<"PRESS 'TAB' TO SCROLL";
	choice=tab(26,6,3,18);
	if(choice==-1)
	{menux();}
	menu1fc();}//-----------------------------------------------------------------------------end void visual :: menu1()

void visual :: menu1fc()//------------------------------------------------------void visual :: menu1_c()
 {switch(choice)
	{	case 1 : {s.searchname(); menux();}
		case 2 : {s.searchno();  menux();}
		case 3 : {s.psin();     menux();}
		case 4 : menuz();
		case 5 : exit1();
		default: clrscr();
					dt();
					cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\tNO SUCH CHOICE AVAILABLE";
					getch();
					menux();}}//-----------------------------------------------------------------------------end void visual :: menu1_c()

void visual :: guest()//--------------------------------------------------------void visual :: menu1()
	{ clrscr();
	dt();
	mdd();
	l=0;
	while(1)
	{if((j==z)&&(l==0))
		{	gotoxy(4,4);
				u.run();
		j=0;
		l=1;}
		if((j==z)&&(l==1))
		{gotoxy(25,6);
				cout<<"[ ] : SEARCH BY NAME";
		j=0;
		l=2;}
		if((j==z)&&(l==2))
		{gotoxy(25,9);
				cout<<"[ ] : SEARCH BY NUMBER";
		j=0;
		l=3;}
		if((j==z)&&(l==3))
		{gotoxy(25,12);
				cout<<"[ ] : PARTIAL SEARCH";
		j=0;
		l=4;}
		if((j==z)&&(l==4))
		{gotoxy(25,15);
				cout<<"[ ] : VIEW ALL";
		j=0;
		l=5;}
		if((j==z)&&(l==5))
		{gotoxy(25,18);
				cout<<"[ ] : BACK ";
		break;}
		j++;}
	gotoxy(15,23);
		cout<<"PRESS 'TAB' TO SCROLL";
	choice=tab(26,6,3,18);
	if(choice==-1)
	{guest();}
	menugu();}//-----------------------------------------------------------------------------end void visual :: menu1()

void visual :: menugu()//------------------------------------------------------void visual :: menu1_c()
 {switch(choice)
	{	case 1 : {s.searchname(); guest();}
		case 2 : {s.searchno();  guest();}
		case 3 : {s.psin(); guest();}
		case 4 : {s.showall(); guest();}
		case 5 : r.logz();
		default: clrscr();
					dt();
					cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\tNO SUCH CHOICE AVAILABLE";
					getch();
					guest();}}//-----------------------------------------------------------------------------end void visual :: menu1_c()

void mdd()//---------------------------------------------------------void userset :: md6()
 { l=0;
	while(1)
	{	if((j==z)&&(l==0))
		{	gotoxy(0,3);
				for(i=0;i<40;i++)
					cout<<"~ ";
		j=0;
		l=1;}
		if((j==z)&&(l==1))
		{for(i=4;i<21;i++)
			{	gotoxy(0,i);
					cout<<"~";}
		j=0;
		l=2;}
		if((j==z)&&(l==2))
		{for(i=4;i<21;i++)
			{	gotoxy(79,i);
					cout<<"~";}
		j=0;
		l=3;}
		if((j==z)&&(l==3))
		{gotoxy(0,21);
				for(i=0;i<40;i++)
					cout<<"~ ";
		break;}
		++j;	}}//-----------------------------------------------------------------------------end void userset :: md6()

void kv()
{ clrscr();
					cout<<"________________________________________________________________________________"<<endl;
					cout<<"****************** ACM SVNIT SURAT TELEPHONE DIRECTORY****************";
					cout<<"________________________________________________________________________________"<<endl;
}

void main()
{
v.welcome();
r.log1();
}


