#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<iostream.h>

int x0,x1,y0,y1;
void input()
{
	cout<<"Enter x0: ";
	cin>>x0;
	cout<<"Enter y0: ";
	cin>>y0;
	cout<<"Enter x1: ";
	cin>>x1;
	cout<<"Enter y1: ";
	cin>>y1;
	
}
void midpoint()
{
	int dy=y1-y0;
	int dx=x1-x0;
	int d=dy-dx/2;
	int de=dy;
	int dne=dy-dx;

	int x= x0;
	int y=y0;
	
	while(x<=x1)
	{
		putpixel(x,y,WHITE);
		if(d>0)
		{
			x=x+1;
			y=y+1;
			d=d+dne;
		}
		else
		{
			x=x+1;
			d=d+de;
		}
	}
		
}

void main()
{
	int gd=DETECT, gm;
	clrscr();
	input();
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	midpoint();
	getch();
	closegraph();

}