#include <iostream>
#include <math.h>
using namespace std;

double r;
int a,b,map[200][200]={0},ra,
mo[2][10]={
    {-1,-1,-1,0,1,1,1,0,-1,-1},//x
    {-1,0,1,1,1,0,-1,-1,-1,0},//y
};
int v[177][177]={0};

double getDistance(double x,double y)
{
    double num;
    num = sqrt((x-r)*(x-r) + (y-r)*(y-r));
    return num;
}

void findCircle(int x, int y)
{        
    if (x < 0 || x > 2*ra || y < 0 || y > 2*ra) 
    {
        return;
    }
    if( v[x][y])
        return ;
    else
    {
        v[x][y] = 1;
        if(x <= ra && y >= 0 && y < ra)//2
        {
            a=1;b=3;
        }
        else if(x < ra && y >= ra && y <= 2*ra)//1
        {
            a=3;b=5;
        }
        else if(x >= ra && y <= 2*ra && y> ra)//3
        {
            a=5;b=7;
        }
        else if(x > ra && y <= ra && y >= 0)//4
        {
            a=7;b=9;
        }
        //
        double sum[3],min = INFINITY;
        for(int n=0,i=a;i<=b;i++,n++)
        {
            double x1 = mo[0][i] + x;
            double y1= mo[1][i] + y;
            sum[n] = fabs(getDistance(x1,y1)-r);
            if(sum[n] < min)
                min=sum[n];
        }
        for(int n=0,i=a;i<=b;i++,n++)
        {
           if(min == sum[n])
           {
                int xx = x+mo[0][a+n],yy = y+mo[1][a+n];
                findCircle(xx,yy);
           } 
        }
    }
}

void display(double r)
{
    for(int i=0;i<r*2+1;i++)
    {
        for(int j=0;j<r*2+1;j++)
        {
            if(v[i][j] == 1)
            {
                cout<<"\033[32m"<<"@ " << "\033[0m";
                continue;
            }
            else if(!v[i][j])
                cout<<"@ ";
            else if(v[i][j] == -1)
                cout<<"\033[33m"<<"@ " << "\033[0m";
            
        }
        cout<<endl;
    }
}

int main()
{
    cout<<"Please enter a positive integer as the radius, which should not exceed 44:";
    scanf("%lf",&r);
    if(r > 88)
    {
        cout<<"ERROR!";
        return 0;
    }
    ra = (int)r;
    v[ra][ra] = -1;
    findCircle(2*ra,ra);
    display(r);

    cout << endl << "Press any key to exit..." << endl;
    system("pause >nul");
    
    return 0;
}