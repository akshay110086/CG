//To apply transformations on an object(say table)
//1. Rotation
//2. Scaling
//3. Reflection


#include<graphics.h>
#include<math.h>
#include<iostream.h>
#include<conio.h>
#include<dos.h>


int r=300;
int s=r;
double tab[27][3]={
			{0,0,1},
			{150,0,1},
			{0,-10,1},
			{150,-10,1},
			{150,0,1},
			{200,-30,1},
			{200,-40,1},
			{150,0,1},
			{50,-40,1},
			{10,0,1},
			{10,50,1},
			{15,0,1},
			{15,50,1},
			{20,46,1},
			{130,0,1},
			{130,50,1},
			{135,0,1},
			{135,50,1},
			{140,0,1},
			{140,46,1},
			{190,-23,1},
			{190,20,1},
			{195,-26,1},
			{195,17,1},
			{185,-21,1},
			{185,20,1},
			{20,0,1}

		  };

void make_table(double table[27][3])
{

	line(r+table[0][0],r+table[0][1],r+table[1][0],r+table[1][1]);
	line(r+table[2][0],r+table[2][1],r+table[3][0],r+table[3][1]);
	line(r+table[0][0],r+table[0][1],r+table[2][0],r+table[2][1]);
	line(r+table[1][0],r+table[1][1],r+table[3][0],r+table[3][1]);
	line(r+table[1][0],r+table[1][1],r+table[5][0],r+table[5][1]);
	line(r+table[6][0],r+table[6][1],r+table[5][0],r+table[5][1]);
	line(r+table[3][0],r+table[3][1],r+table[6][0],r+table[6][1]);
	line(r+table[2][0],r+table[2][1],r+table[8][0],r+table[8][1]);
	line(r+table[8][0],r+table[8][1],r+table[6][0],r+table[6][1]);
	line(r+table[9][0],r+table[9][1],r+table[10][0],r+table[10][1]);
	line(r+table[11][0],r+table[11][1],r+table[12][0],r+table[12][1]);
	line(r+table[10][0],r+table[10][1],r+table[12][0],r+table[12][1]);
	line(r+table[12][0],r+table[12][1],r+table[13][0],r+table[13][1]);
	line(r+table[26][0],r+table[26][1],r+table[13][0],r+table[13][1]);
	line(r+table[14][0],r+table[14][1],r+table[15][0],r+table[15][1]);
	line(r+table[16][0],r+table[16][1],r+table[17][0],r+table[17][1]);
	line(r+table[15][0],r+table[15][1],r+table[17][0],r+table[17][1]);
	line(r+table[18][0],r+table[18][1],r+table[19][0],r+table[19][1]);
	line(r+table[17][0],r+table[17][1],r+table[19][0],r+table[19][1]);
	line(r+table[20][0],r+table[20][1],r+table[21][0],r+table[21][1]);
	line(r+table[22][0],r+table[22][1],r+table[23][0],r+table[23][1]);
	line(r+table[24][0],r+table[24][1],r+table[25][0],r+table[25][1]);
	line(r+table[25][0],r+table[25][1],r+table[21][0],r+table[21][1]);
	line(r+table[21][0],r+table[21][1],r+table[23][0],r+table[23][1]);
}


void multix(double temp[27][3]){
     for(int i=0;i<27;i++)
	temp[i][0]=(1.5)*(temp[i][0]);
     make_table(temp);
}
void multiy(double temp[27][3]){
     for(int i=0;i<27;i++)
	temp[i][1]=(1.5)*(temp[i][1]);
     make_table(temp);
}
void reflectx(double temp[27][3]){
     for(int i=0;i<27;i++)
	temp[i][0]=-1*(temp[i][0]);
     make_table(temp);
}
void reflecty(double temp[27][3]){
     for(int i=0;i<27;i++)
	temp[i][1]=-1*(temp[i][1]);
     make_table(temp);
}
void matrox(double angle,double temp[3][3]){
	temp[0][0]=temp[1][1]=cos(angle);
	temp[0][1]=sin(angle);
	temp[0][2]=temp[1][2]=temp[2][0]=temp[2][1]=0;
	temp[2][2]=1;
	temp[1][0]=-1*sin(angle);
}

void rotatex(double temp1[27][3],double theta,double temp[27][3]){
	double temp2[3][3];
	for(int m=0;m<27;m++){
		for(int n=0;n<3;n++)
			temp[m][n]=0;
	}
	matrox(theta,temp2);
	for(int i=0;i<27;i++)
		for(int j=0;j<3;j++)
			for(int k=0;k<3;k++)
				temp[i][j]+=temp1[i][k]*temp2[k][j];

}



void main()
{


	int gm,gd=DETECT;
	int mode;
	char *name,*driver;
	double show[27][3];
	double angle=0;
	cout<<"Enter the angle in degrees : ";
	cin>>angle;
	angle=angle*(3.147/180);
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	make_table(tab);
	getch();
	cleardevice();
	rotatex(tab,angle,show);
	make_table(show);

	getch();
	cleardevice();
	multix(tab);
	getch();
	cleardevice();
	multiy(tab);
	getch();
	cleardevice();
	reflectx(tab);
	getch();
	cleardevice();
	reflecty(tab);
	getch();
	closegraph();



}