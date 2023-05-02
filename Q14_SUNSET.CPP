
#include<IOSTREAM.H>
#include<CONIO.H>
#include<GRAPHICS.H>
#include<DOS.H>

void mountain()
  {
    int mount[24]={0,200,
		   100,100,
		   150,150,
		   200,105,
		   270,180,
		   310,150,
		   330,160,
		   400,100,
		   450,160,
		   500,110,
		   640,200,
		   0,200};
    drawpoly(12,mount);
    setcolor(BROWN);
    setfillstyle(1,6);
    fillpoly(12,mount);
   }
void sky()
   {
     int sky[28]={0,200,
		  100,100,
		  150,150,
		  200,105,
		  270,180,
		  310,150,
		  330,160,
		  400,100,
		  450,160,
		  500,110,
		  640,200,
		  640,0,
		  0,0};
    drawpoly(14,sky);
    setcolor(9);
    setfillstyle(1,9);
    fillpoly(14,sky);
  }
  void sky2()
   {
     int sky2[28]={0,200,
		  100,100,
		  150,150,
		  200,105,
		  270,180,
		  310,150,
		  330,160,
		  400,100,
		  450,160,
		  500,110,
		  640,200,
		  640,0,
		  0,0};
    drawpoly(14,sky2);
    setcolor(BLACK);
    setfillstyle(1,0);
    fillpoly(14,sky2);
  }
  void grass()
  {
    int grass[10]={0,200,
		   640,200,
		   640,280,
		   0,480,
		   0,200};
     drawpoly(5,grass);
    setcolor(GREEN);
    setfillstyle(1,2);
    fillpoly(5,grass);
  }
  void sun()
  {
    setcolor(14);
    setfillstyle(1,14);
    ellipse(450,140,0,360,25,20);
    fillellipse(450,140,25,20);
  }
  void sunrise()
   {
     sky();
     sun();
     mountain();
     grass();
    }
  void sunrise2(int *k)
    {
     delay(500);
     sky();
     setcolor(14);
     setfillstyle(1,14);
     ellipse(450,140-*k,340,182,25,20);
     fillellipse(450,140-*k,25,20);
     *k=*k+20;
     mountain();
     }
   void sunset(int *K)
    {
     delay(500);
     sky();
     setcolor(14);
     setfillstyle(1,14);
     ellipse(450,40+*K,340,182,25,20);
     fillellipse(450,40+*K,25,20);
     *K=*K+20;
     }
     void sunset2(int *K)
     {
      delay(500);
     sky2();
     grass();
     setcolor(14);
     setfillstyle(1,14);
     ellipse(450,40+*K,340,182,25,20);
     fillellipse(450,40+*K,25,20);
     *K=*K+20;
     mountain();
     }
     void sunset3(int *K)
     {
      delay(500);
     sky2();
     grass();
     setcolor(14);
     setfillstyle(1,14);
     ellipse(450,40+*K,340,182,20,10);
     fillellipse(450,40+*K,20,10);
     *K=*K+20;
     mountain();
     }
     void main()
      {
	clrscr();
	int gdriver=DETECT,gmode,errorcode;
	initgraph(&gdriver,&gmode,"..\\bgi");
	clearviewport();

	sun();
	sunrise();
	getch();
	int i;
	int k=10;
	sunrise2(&k);
	for(i=0;i<5;i++)
	 {
	  delay(500);
	  sky();
	  setcolor(14);
	  setfillstyle(1,14);
	  ellipse(450,140-k,0,360,25,25);
	  fillellipse(450,140-k,25,25);
	  k=k+20;
	 }

	 getch();
	 k=10;
	 for(i=0;i<5;i++)
	 sunset2(&k);
	 sunset3(&k);
	 mountain();
	 getch();
	 closegraph();
     }


