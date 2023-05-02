// Scan line Polygon filling algo
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

void main()
{
    int n,i,j,k,gd=DETECT,gm,dy,dx;
    int x,y,temp;
    int a[20][2],xi[20];
    float slope[20];

    clrscr();
    cout<<"Enter the no. of vertices or edges of polygon: ";
    cin>>n;
    cout<<"Enter the coordinates of polygon:\n\n";
    
     for (i = 0; i < n; i++) 
    {
        cout << "X" << i << "  Y" << i<<" : ";
        cin >> a[i][0]>>a[i][1];
    }
    a[i][0]=a[0][0];
    a[i][1]=a[0][1];
    initgraph(&gd,&gm,"c:\\turboc3\\bgi");
    
    
    for(i=0;i<n;i++)
    {
        line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
    }
    getch();

    for(i=0;i<n;i++)
    {
        dy=a[i+1][1]-a[i][1];
        dx=a[i+1][0]-a[i][0];

        if(dy==0) slope[i]=1;
        if(dx==0) slope[i]=0;
        if((dy!=0)&&(dx!=0))
        {slope[i]=(float)dx/dy;}

        for(y=0;y<480;y++)
        {
            k=0;
            for(i=0;i<n;i++)
            {
                if(((a[i][1]<=y)&&(a[i+1][1]>y))||((a[i][1]>y)&&(a[i+1][1]<=y)))
                {
                    xi[k]=(int)(a[i][0]+slope[i]*(y-a[i][1]));
                    k++;
                }
            }
    
            for(j=0;j<k-1;j++)
            for(i=0;i<k-1;i++)
            {
                if(xi[i]>xi[i+1])
                {
                    temp=xi[i];
                    xi[i]=xi[i+1];
                    xi[i+1]=temp;
                }
            }
    
            setcolor(2);
            for(i=0;i<k;i+=2)
            {
                line(xi[i],y,xi[i+1],y);
                delay(20);
            }
        } // for loop 480
        getch();
        closegraph();
    }
    
}