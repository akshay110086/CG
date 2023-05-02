#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<math.h>

void main()
{
    int gd=DETECT, gm, ch;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    cleardevice();
    cout<<"\t1. Scaling-enlargement \n\n";
    cout<<"\t2. Scaling-shrinking \n\n";
    cout<<"\t3. Translation in x \n\n";
    cout<<"\t4. Translation in y \n\n";
    cout<<"\t5. Translation in x & y both \n\n";
    cout<<"\t6. Reflection through x axis \n\n";
    cout<<"\t7. Reflection through y axis \n\n";
    cout<<"\t8. Reflection through x=y axis \n\n";
    cout<<"\t9. Rotation wrt origin \n\n";
    cout<<"\t10. Shearing in x \n\n";
    cout<<"\t11. Shearing in y \n\n";
    cout<<"\t12. Exit()\n\n";
    cout<<"Enter choice: ";
    cin>>ch;

    switch(ch)
    {
        case 1: 
                {
                    int x1=30,y1=30,x2=70,y2=70,x=2,y=2;
                    cleardevice();
                    cout<<"\nRectangle before scaling-enlargement:\n";
                    rectangle(x1,y1,x2,y2);
                    getch();
                    cleardevice();
                    cout<<"\n\n\nrectangle after scaling-enlargement:\n";
                    rectangle(x1*x,y1*y,x2*x,y2*y);
                    getch();
                    main();
                }
        case 2: 
                {
                    int x1=30,y1=30,x2=70,y2=70,x=2,y=2;
                    cleardevice();
                    cout<<"\nRectangle before scaling-shrinking:\n";
                    rectangle(x1,y1,x2,y2);
                    getch();
                    cleardevice();
                    cout<<"\n\n\nrectangle after scaling-shrinking:\n";
                    rectangle(x1/x,y1/y,x2/x,y2/y);
                    getch();
                    main();
                }
        case 3:
                {
                    int tx=50,ty=50,x1=100,x2=230,y1=100,y2=70;
                    cleardevice();
                    cout<<"Rectangle before translation in x:\n";
                    rectangle(x1,y1,x2,y2);
                    getch();
                    cleardevice();
                    cout<<"Rectangle after translation in x:\n";
                    rectangle(x1+tx,y1,x2+tx,y2);
                    getch();
                    main();
                }
        case 4:
                {
                    int tx=50,ty=50,x1=100,x2=230,y1=100,y2=70;
                    cleardevice();
                    cout<<"Rectangle before translation in y:\n";
                    rectangle(x1,y1,x2,y2);
                    getch();
                    cleardevice();
                    cout<<"Rectangle after translation in y:\n";
                    rectangle(x1,y1+ty,x2,y2+ty);
                    getch();
                    main();
                }
        case 5:
                {
                    int tx=50,ty=50,x1=100,x2=230,y1=100,y2=70;
                    cleardevice();
                    cout<<"Rectangle before translation in x & y both:\n";
                    rectangle(x1,y1,x2,y2);
                    getch();
                    cleardevice();
                    cout<<"Rectangle after translation in x & y both:\n";
                    rectangle(x1+tx,y1+ty,x2+tx,y2+ty);
                    getch();
                    main();
                }
        case 6: 
                {
                    int x1=50,y1=150,x2=75,y2=125,x3=100,y3=150,xt;                    
                    cleardevice();
                    cout<<"\n\n\nTriangle before reflection through x axis:\n";
                    line(x1,y1,x2,y2);
                    line(x1,y1,x3,y3);
                    line(x2,y2,x3,y3);
                    getch();
                    cleardevice();
                    cout<<"\n\n\nTriangle after reflection through x axis:\n";
                    line(-x1+200,y1,-x2+200,y2);
                    line(-x1+200,y1,-x3+200,y3);
                    line(-x2+200,y2,-x3+200,y3);
                    getch();
                    main();
                }
        case 7: 
                {
                    int x1=50,y1=150,x2=75,y2=125,x3=100,y3=150,xt;                    
                    cleardevice();
                    cout<<"\n\n\nTriangle before reflection through y axis:\n";
                    line(x1,y1,x2,y2);
                    line(x1,y1,x3,y3);
                    line(x2,y2,x3,y3);
                    getch();
                    cleardevice();
                    cout<<"\n\n\nTriangle after reflection through y axis:\n";
                    line(x1,-y1+200,x2,-y2+200);
                    line(x1,-y1+200,x3,-y3+200);
                    line(x2,-y2+200,x3,-y3+200);
                    getch();
                    main();
                }
        case 8: 
                {
                    int x1=50,y1=150,x2=75,y2=125,x3=100,y3=150,xt;                    
                    cleardevice();
                    cout<<"\n\n\nTriangle before reflection through x=y axis:\n";
                    line(x1,y1,x2,y2);
                    line(x1,y1,x3,y3);
                    line(x2,y2,x3,y3);
                    getch();
                    cleardevice();
                    cout<<"\n\n\nTriangle after reflection through x=y axis:\n";
                    line(-x1+200,-y1+200,-x2+200,-y2+200);
                    line(-x1+200,-y1+200,-x3+200,-y3+200);
                    line(-x2+200,-y2+200,-x3+200,-y3+200);
                    getch();
                    main();
                }
        case 9: 
                {
                    long x1=100,y1=100,x2=200,y2=200;
                    double d1,xt,yt;
                    cleardevice();
                    cout<<"\n\n\nEnter angle of rotation: ";
                    cin>>d1;
                    d1=(d1*3.14)/180.0;

                    xt=x1+((x2-x1)*cos(d1)-(y2-y1)*sin(d1));
                    yt=y1+((x2-x1)*sin(d1)+(y2-y1)*cos(d1));
                    line(x1,y1,x2,y2);
                    getch();
                    cleardevice();
                    cout<<"\nLine after rotation";
                    line(x1,y1,(int)xt,(int)yt);
                    getch();
                    main();
                }
        case 10: 
                {
                    int x1=100,x2=100,y1=100,y2=30,x3=170,y3=30,x4=170,y4=40,shx=5;                    
                    cleardevice();
                    cout<<"\n\n\nRectangle before shearing in x:\n";
                    line(x1,y1,x2,y2);
                    line(x1,y1,x4,y4);
                    line(x2,y2,x3,y3);
                    line(x3,y3,x4,y4);
                    getch();
                    cleardevice();
                    cout<<"\n\n\nRectangle after shearing in x:\n";
                    line(x1+shx*y1,y1,x2+shx*y2,y2);
                    line(x1+shx*y1,y1,x4+shx*y4,y4);
                    line(x2+shx*y2,y2,x3+shx*y3,y3);                    
                    line(x3+shx*y3,y3,x4+shx*y4,y4);
                    getch();
                    main();
                }
        case 11: 
                {
                    int x1=60,x2=60,y1=100,y2=30,x3=80,y3=30,x4=80,y4=40,shx=5;                    
                    cleardevice();
                    cout<<"\n\n\nRectangle before shearing in y:\n";
                    line(x1,y1,x2,y2);
                    line(x1,y1,x4,y4);
                    line(x2,y2,x3,y3);
                    line(x3,y3,x4,y4);
                    getch();
                    cleardevice();
                    cout<<"\n\n\nRectangle after shearing in y:\n";
                    line(x1,y1+shx*x1,x2,y2+shx*x2);
                    line(x1,y1+shx*x1,x4,y4+shx*x4);
                    line(x2,y2+shx*x2,x3,y3+shx*x3);                    
                    line(x3,y3+shx*x3,x4,y4+shx*x4);
                    getch();
                    main();
                }
        case 12:  
                {
                    cout<<"THANK YOU!!";
                    break;
                }
                
        default:
                 {
                    cout<<"Enter correct choice!!";
                    main();
                 }
    }
    closegraph();
}