#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>
#include<dos.h>
//*****************************  CLASS DEFINED 	*****************************
class lib
{
public:
void give_fine();
void check_record();
void issue1();
void homepage();
void password();
void menu();
void issue();
void return_book();
void settings();
void settings_menu();
void deactivate_password();
void add_book_list();
void add_student_list();
void check_status();
void student_list();
char name[50],batch[5],book_name[100];
int long en_no;
int book_no;
int book_no_issue;
int long en_no_issue;
int long en_no_return;
int long fine_return;
int dd1,mm1,yy1,dd2,mm2,yy2,ddp,mmp,yyp;
int check_settings;
int d3,m3,y3;
int set_pwd;
char pwd[50];
}obj,o;
//**************************** HOMEPAGE *************************************
void lib::homepage()
{
setcolor(56);
setbkcolor(WHITE);
settextstyle(4,0,5);
outtextxy(160,100,"library Management");
setcolor(RED);
settextstyle(2,0,4);
outtextxy(620,430,"Developed By Sushil Kumar");
for(int i=620;i>=250;i--)
{
setcolor(RED);
outtextxy(i,430,"Developed By Sushil Kumar");
delay(7);
setcolor(WHITE);
outtextxy(i,430,"Developed By Sushil Kumar");
}
setcolor(RED);
outtextxy(250,430,"Developed By Sushil Kumar");
outtextxy(250,450,"Press any key to continue...........");
getch();
}
//********************************** MENU ***********************************
void lib::menu()
{
setbkcolor(15);
cleardevice();
setcolor(RED);
setbkcolor(15);
settextstyle(4,0,3);
outtextxy(250,60,"main menu");
line(250,90,360,90);
line(250,92,360,92);
setcolor(56);
settextstyle(2,0,5);
outtextxy(250,150,"Issue Book");
outtextxy(250,200,"Return Book");
outtextxy(250,250,"Pay Fine");
outtextxy(250,300,"Settings");
outtextxy(250,350,"Exit");
int x=225,y=150,code,count=0;
char w;
setcolor(56);
outtextxy(x,y,">>");
do
{
count++;
w=getch();
if(w=='\0'+'H')
{
setcolor(15);
outtextxy(x,y,">>");
y-=50;
if(y<150)
{
y=350;
sound(500);
setcolor(56);
outtextxy(x,y,">>");
delay(80);
nosound();
code=5;
}
else if(y==150)
{
setcolor(56);
sound(500);
outtextxy(x,y,">>");
delay(80);
code=1;
nosound();
}
else if(y==200)
{
setcolor(56);
sound(500);
outtextxy(x,y,">>");
delay(80);
code=2;
nosound();
}
else if(y==250)
{
setcolor(56);
sound(500);
delay(80);
nosound();
outtextxy(x,y,">>");
code=3;
}
else if(y==300)
{
sound(500);
delay(80);
nosound();
setcolor(56);
outtextxy(x,y,">>");
code=4;
}
else if(y==350)
{
sound(500);
delay(80);
nosound();
setcolor(56);
outtextxy(x,y,">>");
code=5;
}
}
else if(w=='\0'+'P')
{
setcolor(15);
outtextxy(x,y,">>");
y+=50;
if(y>350)
{
sound(500);
delay(80);
nosound();
y=150;
setcolor(56);
outtextxy(x,y,">>");
code=1;
}
else if(y==150)
{
sound(500);
delay(80);
nosound();
setcolor(56);
outtextxy(x,y,">>");
code=1;
}
else if(y==200)
{
sound(500);
delay(80);
nosound();
setcolor(56);
outtextxy(x,y,">>");
code=2;
}
else if(y==250)
{
sound(500);
delay(80);
nosound();
setcolor(56);
outtextxy(x,y,">>");
code=3;
}
else if(y==300)
{
sound(500);
delay(80);
nosound();
setcolor(56);
outtextxy(x,y,">>");
code=4;
}
else if(y==350)
{
sound(500);
delay(80);
nosound();
setcolor(56);
outtextxy(x,y,">>");
code=5;
}
}
else if(count==1 && w==13)
code=1;
}
while(w!=13);

switch(code)
{
case 1:
issue();
break;
case 2:
return_book();
break;
case 3:
give_fine();
break;
case 4:
settings_menu();
break;
case 5:
exit(7);
}
}
//******************************** ISSUE ************************************
void lib::issue()
{
setbkcolor(15);
cleardevice();
setcolor(56);
setbkcolor(15);
fstream f2,f4,f5,f6,f7;
struct date d;
getdate(&d);
int found=0;
int found1=0;
int long no;
setcolor(RED);
settextstyle(4,0,3);
outtextxy(250,60,"book issue");
setcolor(56);
setbkcolor(15);
f2.open("students.dat",ios::in);
outtextxy(220,120,"Enrollment No.");
line(220,150,360,150);
line(220,150,220,180);
line(360,150,360,180);
line(220,180,360,180);
gotoxy(29,11);
cin>>no;
while(!f2.eof())
{
f2.read((char*)&obj,sizeof(obj));
if(obj.en_no==no)
{
cout<<"Student's Details Present";
cout<<"\n";
f4.open("issue.dat",ios::app|ios::out);
outtextxy(220,210,"Book No.:");
line(220,240,360,240);
line(220,240,220,280);
line(360,240,360,280);
line(220,280,360,280);
gotoxy(29,17);
cin>>obj.book_no_issue;
int bno;
bno=obj.book_no_issue;
f5.open("books.dat",ios::in);
while(!f5.eof())
{
f5.read((char*)&obj,sizeof(obj));
if(obj.book_no==bno)
{
cout<<"Book Name :"<<obj.book_name;

f6.open("issue.dat",ios::in);
while(!f6.eof())
{
f6.read((char*)&obj,sizeof(obj));
if(obj.book_no_issue==bno)
{
cout<<"\n";
cout<<"Book is issued to  Enrollment no :"<<obj.en_no_issue;
cout<<"\a";
f6.close();
getch();
menu();
}
}

f7.open("issue.dat",ios::in);
while(!f7.eof())
{
f7.read((char*)&obj,sizeof(obj));
if(obj.en_no_issue==no)
{
cout<<"\n";
cout<<"You have already a book of no :"<<obj.book_no_issue;
cout<<"\a";
f7.close();
getch();
menu();
}
}
obj.book_no_issue=bno;
obj.en_no_issue=no;
obj.dd1=d.da_day;
obj.mm1=d.da_mon;
obj.yy1=d.da_year;
f4.write((char*)&obj,sizeof(obj));
f4.close();
cout<<"\n";
cout<<"Book issued......";
cout<<"\a";
found1=1;
f5.close();
break;
}
}
if(found1==0)
{
cout<<"\n";
cout<<"Enter valid book no"<<"\n";
cout<<"Start afresh";
cout<<"\a";
getch();
menu();
}
found=1;
f2.close();
break;
}
}
if(found==0)
{
cout<<"Student not registered";
cout<<"\a";
getch();
menu();
}
getch();
menu();
}
//**************************** STUDENT LIST *********************************
void lib::student_list()
{
setbkcolor(15);
cleardevice();
setcolor(56);
setbkcolor(15);
fstream f;
int long nor;
int found=0;
outtextxy(220,120,"Enrollment No.");
line(220,150,360,150);
line(220,150,220,180);
line(360,150,360,180);
line(220,180,360,180);
gotoxy(29,11);
cin>>nor;
f.open("students.dat",ios::in);
while(!f.eof())
{
f.read((char*)&obj,sizeof(obj));
if(obj.en_no==nor)
{
setbkcolor(15);
cleardevice();
setcolor(RED);
settextstyle(4,0,3);
outtextxy(210,60,"student's information");
line(220,150,400,150);
line(220,150,220,210);
line(400,150,400,210);
line(220,210,400,210);
gotoxy(29,11);
cout<<"Enrollment No."<<obj.en_no;
gotoxy(29,12);
cout<<"Name :"<<name;
gotoxy(29,13);
cout<<"Batch :"<<batch;
found=1;
getch();
break;
}
}
if(found==0)
{
setbkcolor(15);
cleardevice();
setcolor(RED);
settextstyle(4,0,3);
outtextxy(220,150,"Student not registered");
cout<<"\a";
getch();
menu();
}
else
{
menu();
}
}

//******************************* RETURN BOOK *******************************
void lib::return_book()
{
int a,b,c;
int long d,e,f,fine;
setbkcolor(15);
cleardevice();
setcolor(56);
setbkcolor(15);
fstream f8,f9;
int found3=0;
int long nor;
setcolor(RED);
settextstyle(4,0,3);
outtextxy(250,60,"book return");
setcolor(56);
f8.open("issue.dat",ios::in);
f9.open("temp.dat",ios::out);
outtextxy(220,120,"Enrollment No.");
line(220,150,360,150);
line(220,150,220,180);
line(360,150,360,180);
line(220,180,360,180);
gotoxy(29,11);
cin>>nor;
while(!f8.eof())
{
f8.read((char*)&obj,sizeof(obj));
if(obj.en_no_issue==nor)
{
found3=1;
a=obj.dd1;
b=obj.mm1;
c=obj.yy1;
}
else
{
f9.write((char*)&obj,sizeof(obj));
}
}
if(found3==0)
{
cout<<"No such Record Exists";
cout<<"\a";
}
else
{
struct date z;
getdate(&z);
dd2=z.da_day;
mm2=z.da_mon;
yy2=z.da_year;
d=dd2+(mm2*30)+(yy2*365);
e=a+(b*30)+(c*365);
f=d-e;
if(f<=14)
{
fine=0;
}
else
{
fine=(f-14)*10;
}
cout<<"Book Returned....."<<"\n";
cout<<"Fine : Rs."<<fine<<"\n";
cout<<"\a";
if(fine!=0)
{
fstream f10;
f10.open("fine.dat",ios::app|ios::out);
obj.en_no_return=nor;
obj.fine_return=fine;
f10.write((char*)&obj,sizeof(obj));
f10.close();
}
}
f8.close();
f9.close();
remove("issue.dat");
rename("temp.dat","issue.dat");
getch();
menu();
}
//***************************** CHECK FINE **********************************
void lib::check_record()
{
fstream f15;
f15.open("fine.dat",ios::in);
while(!f15.eof())
{
f15.read((char*)&obj,sizeof(obj));
cout<<"Enrollment No."<<en_no_return<<"\n";
cout<<"Fine :"<<fine_return<<"\n";
}
f15.close();
getch();
}
//**************************** CHECK ISSUED BOOKS ***************************
void lib::issue1()
{
setbkcolor(15);
cleardevice();
setcolor(56);
setbkcolor(15);
fstream f1;
f1.open("issue.dat",ios::in);
while(!f1.eof())
{
f1.read((char*)&obj,sizeof(obj));
cout<<"Enrollment no :"<<obj.en_no_issue<<"\n";
cout<<"Book no :"<<obj.book_no_issue<<"\n";
cout<<"Date :"<<obj.dd1<<"."<<obj.mm1<<"."<<obj.yy1<<"\n";

}

f1.close();
getch();
}

//**************************** STUDENTS REGISTRATION ************************

void lib::add_student_list()
{
setbkcolor(15);
cleardevice();
setcolor(56);
setbkcolor(15);
fstream f1,f2;
int long nor;
int found=0;
f2.open("students.dat",ios::in);
f1.open("students.dat",ios::app|ios::out);
cout<<"Enter enrollment no :";
cin>>nor;
while(!f2.eof())
{
f2.read((char*)&obj,sizeof(obj));
if(obj.en_no==nor)
{
cout<<"Students details present"<<"\n";
cout<<"Enrollment No. :"<<obj.en_no<<"\n";
cout<<"Name :"<<obj.name<<"\n";
cout<<"Batch :"<<obj.batch<<"\n";
found=1;
break;
}
}
if(found==0)
{
obj.en_no=nor;
printf("Name :");
gets(obj.name);
printf("Batch :");
gets(obj.batch);
f1.write((char*)&obj,sizeof(obj));
f1.close();
cout<<"Student Registered.....";
cout<<"\a";

}
f2.close();
}

//************************** PAY FINE ***************************************
void lib::give_fine()
{
setbkcolor(15);
cleardevice();
setcolor(56);
setbkcolor(15);
int long norf;
int found30=0,fine_at_return;
fstream f20,f30;
f20.open("fine.dat",ios::in);
f30.open("temp_fine.dat",ios::out);
cout<<"Enrollment No.";
cin>>norf;
while(!f20.eof())
{
f20.read((char*)&obj,sizeof(obj));
if(obj.en_no_return==norf)
{
found30=1;
fine_at_return=obj.fine_return;
}
else
{
f30.write((char*)&obj,sizeof(obj));
}
}
if(found30==0)
{
cout<<"No fine to return";
cout<<"\a";
}
else
{
cout<<"Enrollment No."<<norf<<"\n";
cout<<"Fine :"<<fine_at_return<<"\n";
cout<<"fine paid....";
cout<<"\a";
}
f20.close();
f30.close();
remove("fine.dat");
rename("temp_fine.dat","fine.dat");
getch();
}

//**************************** ADD BOOK TO LIST *****************************

void lib::add_book_list()
{
setbkcolor(15);
cleardevice();
setcolor(56);
setbkcolor(15);
fstream f3;
f3.open("books.dat",ios::app|ios::out);
printf("Book No :");
cin>>obj.book_no;
printf("Book Name :");
gets(obj.book_name);
f3.write((char*)&obj,sizeof(obj));
f3.close();
cout<<"Book added to list....";
cout<<"\a";
}
//******************************** SETTINGS**********************************
void lib::settings()
{
setbkcolor(15);
cleardevice();
setcolor(56);
setbkcolor(15);
fstream f40;
int x=0;
f40.open("settings.dat",ios::out);
outtextxy(220,120,"Enter new password");
line(220,150,360,150);
line(220,150,220,180);
line(360,150,360,180);
line(220,180,360,180);
int j=0;
char ch;
int num;
gotoxy(29,11);
while(num!=13)
{
obj.pwd[j]=getch();
x++;
obj.set_pwd=1;
num=obj.pwd[j];
if(num==13)
{
break;
}
else
{
setcolor(RED);
cout<<"*";
j++;
}
}
f40.write((char*)&obj,sizeof(obj));
setcolor(56);
outtextxy(180,200,"Database now password protected");
cout<<"\a";
f40.close();
}

//******************************* PASSWORD ********************************
void lib::password()
{
setbkcolor(15);
cleardevice();
setcolor(56);
setbkcolor(15);
fstream f60;
char pwdd[50];
f60.open("settings.dat",ios::in);
outtextxy(220,120,"Enter Password");
line(220,150,360,150);
line(220,150,220,180);
line(360,150,360,180);
line(220,180,360,180);
int j=0;
char ch;
int num;
gotoxy(29,11);
while(num!=13)
{
pwdd[j]=getch();
num=pwdd[j];
if(num==13)
{
break;
}
else
{
cout<<"*";
j++;
}
}
pwdd[j]='\0';
while(!f60.eof())
{
f60.read((char*)&obj,sizeof(obj));
int l;
l=strcmp(obj.pwd,pwdd);
if(l==0)
{
setbkcolor(15);
cleardevice();
homepage();
for(;;)
menu();

}
else
{
setbkcolor(15);
cleardevice();
setcolor(RED);
settextstyle(4,0,2);
cout<<"wrong password";
cout<<"\a";
getch();
exit(0);
}
}
f60.close();
}
//******************************* DEACTIVATE PASSWORD **********************
void lib::deactivate_password()
{
setbkcolor(15);
cleardevice();
setcolor(56);
setbkcolor(15);
fstream f70;
f70.open("settings.dat",ios::out);
obj.set_pwd=0;
f70.write((char*)&obj,sizeof(obj));
setcolor(RED);
settextstyle(4,0,2);
outtextxy(250,150,"password removed");
cout<<"\a";
delay(1000);
menu();
}
//******************************* SEETINGS MENU *****************************
void lib::settings_menu()
{
setbkcolor(15);
cleardevice();
setcolor(56);
setbkcolor(15);
setcolor(RED);
setbkcolor(15);
settextstyle(4,0,3);
outtextxy(250,60,"settings menu");
line(250,90,360,90);
line(250,92,360,92);
setcolor(56);
settextstyle(2,0,5);
outtextxy(250,150,"Activate Password");
outtextxy(250,200,"Deactivate Password");
outtextxy(250,250,"Students List");
outtextxy(250,300,"Books List");
outtextxy(250,350,"Register student");
outtextxy(250,400,"Add Book");
outtextxy(250,450,"Back");
int x=225,y=150,code,count=0;
char w;
setcolor(56);
outtextxy(x,y,">>");
do
{
count++;
w=getch();
if(w=='\0'+'H')
{
setcolor(15);
outtextxy(x,y,">>");
y-=50;
if(y<150)
{
sound(500);
delay(80);
nosound();
y=450;
setcolor(56);
outtextxy(x,y,">>");
code=7;
}
else if(y==150)
{
sound(500);
delay(80);
nosound();
setcolor(56);
outtextxy(x,y,">>");
code=1;
}
else if(y==200)
{
sound(500);
delay(80);
nosound();
setcolor(56);
outtextxy(x,y,">>");
code=2;
}
else if(y==250)
{
sound(500);
delay(80);
nosound();
setcolor(56);
outtextxy(x,y,">>");
code=3;
}
else if(y==300)
{
sound(500);
delay(80);
nosound();
setcolor(56);
outtextxy(x,y,">>");
code=4;
}
else if(y==350)
{
sound(500);
delay(80);
nosound();
setcolor(56);
outtextxy(x,y,">>");
code=5;
}
else if(y==400)
{
sound(500);
delay(80);
nosound();
setcolor(56);
outtextxy(x,y,">>");
code=6;
}
else if(y==450)
{
sound(500);
delay(80);
nosound();
setcolor(56);
outtextxy(x,y,">>");
code=7;
}
}
else if(w=='\0'+'P')
{
setcolor(15);
outtextxy(x,y,">>");
y+=50;
if(y>450)
{
y=150;
sound(500);
delay(80);
nosound();
setcolor(56);
outtextxy(x,y,">>");
code=1;
}
else if(y==150)
{
sound(500);
delay(80);
nosound();
setcolor(56);
outtextxy(x,y,">>");
code=1;
}
else if(y==200)
{
sound(500);
delay(80);
nosound();
setcolor(56);
outtextxy(x,y,">>");
code=2;
}
else if(y==250)
{
sound(500);
delay(80);
nosound();
setcolor(56);
outtextxy(x,y,">>");
code=3;
}
else if(y==300)
{
sound(500);
delay(80);
nosound();
setcolor(56);
outtextxy(x,y,">>");
code=4;
}
else if(y==350)
{
sound(500);
delay(80);
nosound();
setcolor(56);
outtextxy(x,y,">>");
code=5;
}
else if(y==400)
{
sound(500);
delay(80);
nosound();
setcolor(56);
outtextxy(x,y,">>");
code=6;
}
else if(y==450)
{
sound(500);
delay(80);
nosound();
setcolor(56);
outtextxy(x,y,">>");
code=7;
}
}

else if(count==1 && w==13)
code=1;
}
while(w!=13);

switch(code)
{
case 1:
settings();
break;
case 2:
deactivate_password();
break;
case 3:
student_list();
break;
case 5:
add_student_list();
break;
case 6:
add_book_list();
break;
case 7:
menu();
break;
}
}
//******************************** MAIN ************************************
void main()
{
int gd,gm,errorcode;
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"C:\\TC\\BGI");
errorcode=graphresult();
if(errorcode!=grOk)
{
printf("Unable to load graphics settings");
cout<<"\n";
printf("Press any key to terminate.....");
cout<<"\a";
getch();
exit(1);
}
fstream f50;
f50.open("settings.dat",ios::in);
while(!f50.eof())
{
f50.read((char*)&obj,sizeof(obj));
if(obj.set_pwd==0)
{
obj.homepage();
for(;;)
obj.menu();
}
else
{
obj.password();
}
break;
}
obj.add_book_list();
getch();
closegraph();
}