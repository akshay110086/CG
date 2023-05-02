#include<iostream.h>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

int x1,x2,y1,y2;
int c;

int arr[2][3]={{0,0,1},{0,0,1}};
int arr2[2][3]={{0,0,1},{0,0,1}};
void input()
{
	cout<<"Enter "<<endl;
	cin>>x1>>y1>>x2>>y2;
	cin>>c;

arr[0][0]=x1;
arr[0][1]=y1;
arr[1][0]=x2;
arr[1][1]=y2;

int h[3][3]={{-1,0,0},
	{0,1,0},
	{0,0,1}};

for(int p=0;p<2;p++)
{
for(int i=0;i<=2;i++)
{	
	int s=0;
	for(int j=0;j<=2;j++)
	{
		s=s+arr[p][j]*h[i][j];
		
	}
		arr2[p][i]=s;
}
}


	
}
void draw()
{
	int x=getmaxx();
	int y=getmaxy();
	line(x/2,0,x/2,y);
	line(0,y/2,x,y/2);
	line(arr2[0][0]+x/2,-arr2[0][1]+y/2,arr2[1][0]+x/2,-arr2[1][1]+y/2);
	
}
void main()
{
	int gd=DETECT,gm;
	clrscr();
	input();
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	draw();
	getch();
	closegraph();
}