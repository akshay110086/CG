// C Implementation for setlinestyle()
#include <graphics.h>
#include<conio.h>
#include<iostream.h>

// driver code
int main()
{
	int gd = DETECT, gm, x = 200, y = 100;

	// initial coordinate to
	// draw line
	// int x = 200, y = 100;
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");

    cout<<"Menu-Driven Program to draw a line of following style:\n";
	cout<<"(1) Dashed Line\n";
	cout<<"(2) Dotted Line\n";
	cout<<"(3) Dashed & Dotted Line\n";
	cout<<"Enter your choice: ";
	int choice;
	cin>>choice;

    switch (choice)
	{
	case 1:
	    // setlinestyle function
	    setlinestyle(DASHED_LINE, 0, 1);  //Dashed Line

	    // Drawing line
	    line(x, y, x+200, y);
	    // y = y + 25;
		break;

	case 2:
	    // setlinestyle function
	    setlinestyle(DOTTED_LINE, 0, 1);   //Dotted Line

	    // Drawing line
	    line(x, y, x+200, y);
	    // y = y + 25;
		break;

	case 3:
        // To keep track of lines
        	for ( int c = 0 ; c < 2 ; c++ )
        {
        	// setlinestyle function
			if(c==0)
        	setlinestyle(DASHED_LINE, 0, 1);
            else
			setlinestyle(DOTTED_LINE, 0, 1);
        
        	// Drawing line
        	line(x, y, x+200, y);
        	y = y + 25;
        }
		break;
	
	default:
	    cout<<"Enter correct choice!!\n";
		break;
	}



	getch();

	closegraph();

	return 0;
}
