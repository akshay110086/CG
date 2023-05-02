// TRANSFORMATIONS

# include <iostream.h>
# include <conio.h>
# include <graphics.h>
# include <process.h>
# include <math.h>

struct point
{
	int x;
	int y;
};

class transform
{
	private:
		int n;
		point p[10];
	public:
		void input();
		void joinpts(int);
		void translate();
		void mat_multiply(float mata[10][3], float matb[3][3], float matc[10][3]);
		void rotate();
		void scale();
};

void transform :: input()
{
	cout << "Enter the no of points to be transformed";
	cin >> n;

	cout << "Enter the coordinates of each point\n";
	for (int i = 0 ; i < n ; i++)
	{
		cout << "\nEnter the coordinates of vertex " << i + 1;
		cout << "\nEnter the x coordinate";
		cin >> p[i].x;
		cout << "Enter the y coordinate";
		cin >> p[i].y;
	}
}

void transform :: joinpts(int color)
{
	int maxx = getmaxx() / 2;
	int maxy = getmaxy() / 2;

	setcolor(color);
	for (int i = 0 ; i < n - 1 ; i++)
		line (p[i].x + maxx , p[i].y + maxy , p[i+1].x + maxx , p[i+1].y + maxy);
	line (p[n - 1].x + maxx , p[n - 1].y + maxy, p[0].x + maxx, p[0].y + maxy);
}

void transform :: translate()
{
	int tx , ty;
	float mata[10][3] , matc[10][3];

	cout << "Enter the value by which u want to translate x coordinate";
	cin >> tx;
	cout << "Enter the value by which u want to translate y coordinate";
	cin >> ty;
	for (int i = 0 ; i < n ; i++)
	{
		mata[i][0] = p[i].x;
		mata[i][1] = p[i].y;
		mata[i][2] = 1;
	}
	float matb[3][3] = { { 1 , 0 , 0 } ,
			   { 0 , 1 , 0 } ,
			   { tx , ty , 1} };

	mat_multiply (mata , matb , matc);

	for (i = 0 ; i < n ; i++)
	{
		p[i].x = matc[i][0];
		p[i].y = matc[i][1];
	}
}

void transform :: scale()
{
	float sx , sy;
	float mata[10][3] , matc[10][3];

	cout << "Enter the value by which u want to modify x coordinate";
	cin >> sx;
	cout << "Enter the value by which u want to modify y coordinate";
	cin >> sy;

	for (int i = 0 ; i < n ; i++)
	{
		mata[i][0] = p[i].x;
		mata[i][1] = p[i].y;
		mata[i][2] = 1;
	}
	float matb[3][3] = { { sx , 0 , 1} ,
			   { 0 , sy , 1} ,
			   { 0 , 0 , 1} };

	mat_multiply (mata , matb , matc);

	for (i = 0 ; i < n ; i++)
	{
		p[i].x = matc[i][0];
		p[i].y = matc[i][1];
	}
}

void transform :: rotate()
{
	float mata[10][3] , matc[10][3];
	float theta;

	cout << "Enter the angle by which u want to rotate (anticlkwise)";
	cin >> theta;

	for (int i = 0 ; i < n ; i++)
	{
		mata[i][0] = p[i].x;
		mata[i][1] = p[i].y;
		mata[i][2] = 1;
	}

	theta *= M_PI / 180;
	float ct = cos(theta);
	float st = sin(theta);

	float matb[3][3] = { { ct , st , 0 } ,
			   { -1 * st , ct , 0 } ,
			   { 0 , 0 , 1} };

	mat_multiply (mata , matb , matc);

	for (i = 0 ; i < n ; i++)
	{
		p[i].x = matc[i][0];
		p[i].y = matc[i][1];
	}
}

void transform :: mat_multiply(float mata[10][3] , float matb[3][3] , float matc[10][3])
{
	for (int i = 0 ; i < n ; i++)
	{
		for (int j = 0 ; j < 3 ; j++)
		{
			matc[i][j] = 0;
			for (int k = 0 ; k < 3 ; k++)
				matc[i][j] += mata[i][k] * matb[k][j];
		}
	}
}

void main()
{
	clrscr();

	transform ob;
	int ch , ch1;
	int gdriver = DETECT, gmode, errorcode;

	initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

	errorcode = graphresult();

	if (errorcode != grOk)
	{
		cout << "Graphics error:\n" << grapherrormsg(errorcode);
		cout << "Press any key to halt:";
		getch();
		exit(1);
	}
	ob.input();
	cout << "Want to perform\n";
	cout << "1. Translation\n";
	cout << "2. Rotation\n";
	cout << "3. Scaling\n";
	cout << "Enter your choice";
	cin >> ch;

	cleardevice();    // clear the screen by this since in graphics mode

	// DRAWING AXIS
	line (getmaxx() / 2 , 0 , getmaxx() / 2 , 479);
	line (0 , getmaxy() / 2 , 639 , getmaxy() / 2 );

	ob.joinpts(MAGENTA);

	switch (ch)
	{
		case 1: ob.translate();
			ob.joinpts(WHITE);
			break;
		case 2: ob.rotate();
			ob.joinpts(WHITE);
			break;
		case 3: ob.scale();
			ob.joinpts(WHITE);
			break;
		default: cout << "Wrong choice entered";
			 exit(0);
	}

	getch();
	closegraph();
}