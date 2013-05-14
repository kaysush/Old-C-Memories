#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<process.h>
#include<dos.h>
#include<math.h>

void homepage()
{
int i;
setbkcolor(15);
cleardevice();
setcolor(56);
setbkcolor(WHITE);
settextstyle(4,0,5);
outtextxy(160,100,"ALARM CLOCK");
setcolor(RED);
settextstyle(2,0,4);
outtextxy(620,430,"Developed By Sushil & Namit ");
for(i=620;i>=250;i--)
{
setcolor(RED);
outtextxy(i,430,"Developed By Sushil & Namit");
delay(7);
setcolor(WHITE);
outtextxy(i,430,"Developed By Sushil & Namit");
}
setcolor(RED);
outtextxy(250,430,"Developed By Sushil & Namit");
outtextxy(250,450,"Press any key to continue...........");
getch();
}

void clock()
{
int hh,mm,ss;
struct alarm
{
int hour;
int min;
int snooze;
};
struct alarm obj;
FILE *fp;
int x,y;
int i;
float j;
int a,b,c,m;
float d,e,f,g;
struct  time t;
gettime(&t);
setbkcolor(15);
cleardevice();
setcolor(9);
circle(300,200,170);
circle(300,200,180);
for(i=170;i<=180;i++)
{
setcolor(13);
circle(300,200,i);
}

while(!kbhit())
{
fp=fopen("alarm.dat","r+");
while(fscanf(fp,"%d%d%d",&obj.hour,&obj.min,&obj.snooze)!=EOF)
{
hh=obj.hour;
mm=obj.min;
ss=obj.snooze;
break;
}
if((a==hh||a==hh+1)&&(m==mm||m==mm+ss))
{
sound(500);
}
else
{
nosound();
}
setbkcolor(15);
setcolor(56);
settextstyle(2,0,5);
outtextxy(272,100,"Quartz");
settextstyle(2,0,2);
outtextxy(279,280,"Created By:-");
outtextxy(275,288,"Sushil & Namit");
for(i=0;i<=360;i+=30)
{
d=(i*3.14159)/180;
x=300-(160*sin(d));
y=200-(160*cos(d));
if(i==0)
outtextxy(x,y,"12");
else if(i==30)
outtextxy(x,y,"11");
else if(i==60)
outtextxy(x,y,"10");
else if(i==90)
outtextxy(x,y,"9");
else if(i==120)
outtextxy(x,y,"8");
else if(i==150)
outtextxy(x,y,"7");
else if(i==180)
outtextxy(x,y,"6");
else if(i==210)
outtextxy(x,y,"5");
else if(i==240)
outtextxy(x,y,"4");
else if(i==270)
outtextxy(x,y,"3");
else if(i==300)
outtextxy(x,y,"2");
else if(i==330)
outtextxy(x,y,"1");
}
a=t.ti_hour;
m= t.ti_min;
c= t.ti_sec;
d=(((c+15)*6)*3.14159)/180;
x=300-(160*cos(d));
y=200-(160*sin(d));
setcolor(4);
setlinestyle(0,0,0);
line(300,200,x,y);
d=(((m+15)*6)*3.14159)/180;
x=300-(140*cos(d));
y=200-(140*sin(d));
setlinestyle(0,0,10);
setcolor(BLUE);
line(300,200,x,y);
if(a>12)
{
d=((((a-12)*30)+(m*0.5)+90)*3.14159)/180;
x=300-(110*cos(d));
y=200-(110*sin(d));
}
else
{
d=((((a)*30)+(m*0.5)+90)*3.14159)/180;
x=300-(110*cos(d));
y=200-(110*sin(d));
}
setlinestyle(0,0,5);
setcolor(GREEN);
line(300,200,x,y);

setcolor(56);
gotoxy(2,2);
printf("Current time :%2d:%02d:%02d",a,m,c);

delay(1000);



setcolor(15);
d=(((c+15)*6)*3.14159)/180;
x=300-(160*cos(d));
y=200-(160*sin(d));
setcolor(15);
setlinestyle(0,0,0);
line(300,200,x,y);
d=(((m+15)*6)*3.14159)/180;
x=300-(140*cos(d));
y=200-(140*sin(d));
setlinestyle(0,0,10);
setcolor(15);
line(300,200,x,y);
if(a>12)
{
d=((((a-12)*30)+(m*0.5)+90)*3.14159)/180;
x=300-(110*cos(d));
y=200-(110*sin(d));
}
else
{
d=((((a)*30)+(m*0.5)+90)*3.14159)/180;
x=300-(110*cos(d));
y=200-(110*sin(d));
}
setlinestyle(0,0,5);
setcolor(15);
line(300,200,x,y);

gotoxy(2,2);
printf("Current time :%2d:%02d:%02d",a,m,c);


gettime(&t);
d=(((c+15)*6)*3.14159)/180;
x=300-(160*cos(d));
y=200-(160*sin(d));
setcolor(15);
setlinestyle(0,0,0);
line(300,200,x,y);
d=(((m+15)*6)*3.14159)/180;
x=300-(140*cos(d));
y=200-(140*sin(d));
setlinestyle(0,0,10);
setcolor(15);
line(300,200,x,y);
if(a>12)
{
d=((((a-12)*30)+(m*0.5)+90)*3.14159)/180;
x=300-(110*cos(d));
y=200-(110*sin(d));
}
else
{
d=((((a)*30)+(m*0.5)+90)*3.14159)/180;
x=300-(110*cos(d));
y=200-(110*sin(d));
}
setlinestyle(0,0,5);
setcolor(15);
line(300,200,x,y);

setcolor(56);
gotoxy(2,2);
printf("Current time :%2d:%02d:%02d",a,m,c);
setlinestyle(0,0,3);
nosound();
}
}

void alarm()
{
struct alarm
{
int hour;
int min;
int snooze;
};
struct alarm obj;
FILE *fp;
start:
setbkcolor(15);
cleardevice();
setcolor(56);
setcolor(4);
settextstyle(4,0,2);
outtextxy(255,80,"set alarm");
line(250,110,350,110);
line(250,112,350,112);
rectangle(275,150,350,180);
line(312,150,312,180);
gotoxy(37,9);
printf("hh");
gotoxy(42,9);
printf("mm");
gotoxy(30,15);
printf("Snooze time(more than 1 min.)");
rectangle(275,250,350,280);
gotoxy(40,17);
printf("min.");
gotoxy(36,11);
fp=fopen("alarm.dat","w");
scanf("%d",&obj.hour);
gotoxy(41,11);
scanf("%d",&obj.min);
gotoxy(36,17);
scanf("%d",&obj.snooze);

if(obj.hour>24||obj.hour<0||obj.min<0||obj.min>60||obj.snooze<0||obj.snooze>60)
{
outtextxy(270,300,"invalid input.....");
getch();
goto start;
}
fprintf(fp,"%d\n%d\n%d",obj.hour,obj.min,obj.snooze);
fflush(stdin);
fclose(fp);
outtextxy(270,300,"Alarm On....");
getch();
clock();
}


void main()
{
struct alarm
{
int hour;
int min;
int snooze;
};

struct alarm obj;
FILE *fp;
int gd,gm,errorcode;
char w;
int x=225,y=150,code,count=0;
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"C:\\TC\\BGI");
errorcode=graphresult();
if(errorcode!=grOk)
{
printf("Unable to load user settings");
getch();
exit(0);
}
homepage();
setbkcolor(15);
cleardevice();
setcolor(4);
settextstyle(4,0,2);
outtextxy(250,80,"alarm menu");
line(250,110,350,110);
line(250,112,350,112);
setcolor(56);
settextstyle(2,0,5);
outtextxy(260,150,"set alarm");
outtextxy(260,200,"go to clock");
setbkcolor(15);
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
y=200;
setcolor(56);
outtextxy(x,y,">>");
code=2;
}
else if(y==150)
{
setcolor(56);
outtextxy(x,y,">>");
code=1;
}
else if(y==200)
{
setcolor(56);
outtextxy(x,y,">>");
code=2;
}
}
else if(w=='\0'+'P')
{
setcolor(15);
outtextxy(x,y,">>");
y+=50;
if(y>200)
{
y=150;
setcolor(56);
outtextxy(x,y,">>");
code=1;
}
else if(y==150)
{
setcolor(56);
outtextxy(x,y,">>");
code=1;
}
else if(y==200)
{
setcolor(56);
outtextxy(x,y,">>");
code=2;
}
}
else if(count==1 && w==13)
code=1;
}
while(w!=13);

switch(code)
{
case 1:
alarm();
break;

case 2:
clock();
break;


}
getch();
closegraph();
}