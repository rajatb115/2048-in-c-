#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>

void movement();

using namespace std;

void gotoxy(int x, int y)
    {
    COORD dwCursorPosition = { x, y };
    SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), dwCursorPosition);
    }

int q,a[5][5],win=0,lose=0,x=0,y=0,s=0,coun=0,aa[5][5];

int pu()
{
    int raj;
    srand(time(0));
    q=rand()%50;
    srand(q);
    raj=rand()%2;
    if(raj==0)
    {
        cout<<"2";
        return 2;
    }
    else
    {
        cout<<"4";
        return 4;
    }
}

void ran()
{
    int put=0;
    srand(time(0));
    int r=1+rand()%16;
    while(put==0)
    {
        switch (r)
        {
        case 1:
            if(a[1][1]==0)
            {
                gotoxy(2,3);
                a[1][1]=pu();
                put=1;
            }
            else
            {
                r=2;
            }
            break;
            case 2:
             if(a[2][1]==0)
            {
                gotoxy(8,3);
                a[2][1]=pu();
                put=1;
            }
            else
            {
                r=3;
            }
            break;
            case 3:
             if(a[3][1]==0)
            {
                gotoxy(14,3);
                a[3][1]=pu();
                put=1;
            }
            else
            {
                r=4;
            }
            break;
            case 4:
             if(a[4][1]==0)
            {
                gotoxy(20,3);
                a[4][1]=pu();
                put=1;
            }
            else
            {
                r=5;
            }
            break;
            case 5:
            if(a[1][2]==0)
            {
                gotoxy(2,7);
                a[1][2]=pu();
                put=1;
            }
            else
            {
                r=6;
            }
            break;
            case 6:
             if(a[2][2]==0)
            {
                gotoxy(8,7);
                a[2][2]=pu();
                put=1;
            }
            else
            {
                r=7;
            }
            break;
            case 7:
             if(a[3][2]==0)
            {
                gotoxy(14,7);
                a[3][2]=pu();
                put=1;
            }
            else
            {
                r=8;
            }
            break;
            case 8:
             if(a[4][2]==0)
            {
                gotoxy(20,7);
                a[4][2]=pu();
                put=1;
            }
            else
            {
                r=9;
            }
            break;
            case 9:
            if(a[1][3]==0)
            {
                gotoxy(2,11);
                a[1][3]=pu();
                put=1;
            }
            else
            {
                r=10;
            }
            break;
            case 10:
             if(a[2][3]==0)
            {
                gotoxy(8,11);
                a[2][3]=pu();
                put=1;
            }
            else
            {
                r=11;
            }
            break;
            case 11:
             if(a[3][3]==0)
            {
                gotoxy(14,11);
                a[3][3]=pu();
                put=1;
            }
            else
            {
                r=12;
            }
            break;
            case 12:
             if(a[4][3]==0)
            {
                gotoxy(20,11);
                a[4][3]=pu();
                put=1;
            }
            else
            {
                r=13;
            }
            break;
            case 13:
            if(a[1][4]==0)
            {
                gotoxy(2,15);
                a[1][4]=pu();
                put=1;
            }
            else
            {
                r=14;
            }
            break;
            case 14:
             if(a[2][4]==0)
            {
                gotoxy(8,15);
                a[2][4]=pu();
                put=1;
            }
            else
            {
                r=15;
            }
            break;
            case 15:
             if(a[3][4]==0)
            {
                gotoxy(14,15);
                a[3][4]=pu();
                put=1;
            }
            else
            {
                r=16;
            }
            break;
            case 16:
             if(a[4][4]==0)
            {
                gotoxy(20,15);
                a[4][4]=pu();
                put=1;
            }
            else
            {
                r=1;
            }
            break;
        }
    }
}


void won()
{
    lose=0;
    win=0;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            if(a[i][j]==2048)
            {
                win=win+1;
            }
            if(a[i][j]==0)
            {
                lose=lose+1;
            }
        }
    }
    if(lose==0&&win==0)
    {
        gotoxy(10,22);
        cout<<"YOU LOSE";
    }
    else if(lose>=1&&win==0)
    {
        ran();
        movement();
    }
    else if(win>0)
    {
        gotoxy(10,22);
        cout<<"YOU WON";
        ran();
        movement();
    }
}

void pri()
{
    x=2;
    y=3;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            if(a[j][i]!=0)
            {
                gotoxy(x,y);
                cout<<"     ";
                gotoxy(x,y);
                cout<<a[j][i];
            }
            else if(a[j][i]==0)
            {
                gotoxy(x,y);
                cout<<"     ";
            }
            x=x+6;
        }
        y=y+4;
        x=2;
    }
    gotoxy(1,1);
}

void score()
{
    gotoxy(10,20);
    cout<<"SCORE="<<s;
}

void movement()
{
    coun=0;
    char ch=getch();
    if(ch=='a')
    {
        for(int i=1;i<=4;i++)
        {
            if(a[1][i]==a[2][i]&&a[3][i]==a[4][i]&&a[1][i]!=0&&a[2][i]!=0&&a[3][i]!=0&&a[4][i]!=0)
            {
                a[1][i]=a[1][i]*2;
                a[2][i]=a[3][i]*2;
                a[3][i]=0;
                a[4][i]=0;
                coun=1;
                s=s+a[1][i]+a[2][i];
            }
            else if(a[1][i]==a[2][i]&&a[1][i]!=0&&a[2][i]!=0)
            {
                a[1][i]=a[1][i]*2;
                a[2][i]=a[3][i];
                a[3][i]=a[4][i];
                a[4][i]=0;
                coun=1;
                s=s+a[1][i];
            }
            else if(a[3][i]==a[4][i]&&a[3][i]!=a[2][i]&&a[3][i]!=0&&a[4][i]!=0)
            {
                a[3][i]=a[3][i]*2;
                a[4][i]=0;
                coun=1;
                s=s+a[3][i];
                if(a[1][i]==0&&a[2][i]==0)
                {
                    a[1][i]=a[3][i];
                    a[2][i]=a[4][i];
                    a[3][i]=0;
                    a[4][i]=0;
                }
                else if(a[1][i]==0&&a[2][i]!=0)
                {
                    a[1][i]=a[2][i];
                    a[2][i]=a[3][i];
                    a[3][i]=a[4][i];
                    a[4][i]=0;
                }
                else if(a[1][i]!=0&&a[2][i]==0)
                {
                    a[2][i]=a[3][i];
                    a[3][i]=a[4][i];
                    a[4][i]=0;
                }
            }
            else if(a[3][i]==a[2][i]&&a[3][i]!=0&&a[2][i]!=0)
            {
                a[2][i]=a[2][i]*2;
                a[3][i]=a[4][i];
                a[4][i]=0;
                coun=1;
                s=s+a[2][i];
                if(a[1][i]==0)
                {
                    a[1][i]=a[2][i];
                    a[2][i]=a[3][i];
                    a[3][i]=a[4][i];
                    a[4][i]=0;
                }
            }
            else if(a[1][i]==a[3][i]&&a[1][i]!=0&&a[2][i]==0)
            {
                a[1][i]=a[1][i]*2;
                a[2][i]=a[4][i];
                a[3][i]=0;
                a[4][i]=0;
                coun=1;
                s=s+a[1][i];
            }
            else if(a[1][i]==a[4][i]&&a[2][i]==0&&a[3][i]==0&&a[1][i]!=0)
            {
                a[1][i]=a[1][i]*2;
                a[2][i]=0;
                a[3][i]=0;
                a[4][i]=0;
                coun=1;
                s=s+a[1][i];
            }
            else if(a[2][i]==a[4][i]&&a[2][i]!=0&&a[3][i]==0)
            {
                a[2][i]=a[2][i]*2;
                a[3][i]=0;
                a[4][i]=0;
                if(a[1][i]==0)
                {
                    a[1][i]=a[2][i];
                    a[2][i]=a[3][i];
                    a[3][i]=a[4][i];
                    a[4][i]=0;
                }
                coun=1;
                s=s+a[1][i];
            }
        }
        for(int i=1;i<=4;i++)
        {
            if((a[1][i]==0&&a[2][i]!=0&&a[3][i]!=0&&a[4][i]!=0)||(a[1][i]==0&&a[2][i]!=0&&a[3][i]!=0&&a[4][i]==0)||(a[1][i]==0&&a[2][i]!=0&&a[3][i]==0&&a[4][i]==0))
            {
                a[1][i]=a[2][i];
                a[2][i]=a[3][i];
                a[3][i]=a[4][i];
                a[4][i]=0;
                coun=1;
            }
            else if(a[1][i]==0&&a[3][i]==0&&a[2][i]!=0&&a[4][i]!=0)
            {
                a[1][i]=a[2][i];
                a[2][i]=a[4][i];
                a[3][i]=0;
                a[4][i]=0;
                coun=1;
            }
            else if(a[1][i]==0&&a[2][i]==0&&a[3][i]!=0)
            {
                a[1][i]=a[3][i];
                a[2][i]=a[4][i];
                a[3][i]=0;
                a[4][i]=0;
                coun=1;
            }
            else if(a[1][i]==0&&a[2][i]==0&&a[3][i]==0&&a[4][i]!=0)
            {
                a[1][i]=a[4][i];
                a[2][i]=0;
                a[3][i]=0;
                a[4][i]=0;
                coun=1;
            }
            else if(a[1][i]!=0&&a[2][i]==0&&a[3][i]!=0)
            {
                a[2][i]=a[3][i];
                a[3][i]=a[4][i];
                a[4][i]=0;
                coun=1;
            }
            else if(a[1][i]!=0&&a[2][i]==0&&a[3][i]==0&&a[4][i]!=0)
            {
                a[2][i]=a[4][i];
                a[3][i]=0;
                a[4][i]=0;
                coun=1;
            }
            else if(a[1][i]!=0&&a[2][i]!=0&&a[3][i]==0&&a[4][i]!=0)
            {
                a[3][i]=a[4][i];
                a[4][i]=0;
                coun=1;
            }
        }
    }
    if(ch=='d')
    {
        for(int i=1;i<=4;i++)
        {
            if(a[4][i]==a[3][i]&&a[2][i]==a[1][i]&&a[4][i]!=0&&a[3][i]!=0&&a[2][i]!=0&&a[1][i]!=0)
            {
                a[4][i]=a[4][i]*2;
                a[3][i]=a[2][i]*2;
                a[2][i]=0;
                a[1][i]=0;
                coun=1;
                s=s+a[4][i]+a[3][i];
            }
            else if(a[4][i]==a[3][i]&&a[4][i]!=0&&a[3][i]!=0)
            {
                a[4][i]=a[4][i]*2;
                a[3][i]=a[2][i];
                a[2][i]=a[1][i];
                a[1][i]=0;
                coun=1;
                s=s+a[4][i];
            }
            else if(a[2][i]==a[1][i]&&a[2][i]!=a[3][i]&&a[2][i]!=0&&a[1][i]!=0)
            {
                a[2][i]=a[2][i]*2;
                a[1][i]=0;
                coun=1;
                s=s+a[2][i];
                if(a[4][i]==0&&a[3][i]==0)
                {
                    a[4][i]=a[2][i];
                    a[3][i]=a[1][i];
                    a[2][i]=0;
                    a[1][i]=0;
                }
                else if(a[4][i]==0&&a[3][i]!=0)
                {
                    a[4][i]=a[3][i];
                    a[3][i]=a[2][i];
                    a[2][i]=a[1][i];
                    a[1][i]=0;
                }
                else if(a[4][i]!=0&&a[3][i]==0)
                {
                    a[3][i]=a[2][i];
                    a[2][i]=a[1][i];
                    a[1][i]=0;
                }
            }
            else if(a[2][i]==a[3][i]&&a[2][i]!=0&&a[3][i]!=0)
            {
                a[3][i]=a[3][i]*2;
                a[2][i]=a[1][i];
                a[1][i]=0;
                coun=1;
                s=s+a[3][i];
                if(a[4][i]==0)
                {
                    a[4][i]=a[3][i];
                    a[3][i]=a[2][i];
                    a[2][i]=a[1][i];
                    a[1][i]=0;
                }
            }
            else if(a[4][i]==a[2][i]&&a[4][i]!=0&&a[3][i]==0)
            {
                a[4][i]=a[4][i]*2;
                a[3][i]=a[1][i];
                a[2][i]=0;
                a[1][i]=0;
                coun=1;
                s=s+a[4][i];
            }
            else if(a[4][i]==a[1][i]&&a[3][i]==0&&a[2][i]==0&&a[4][i]!=0)
            {
                a[4][i]=a[4][i]*2;
                a[3][i]=0;
                a[2][i]=0;
                a[1][i]=0;
                coun=1;
                s=s+a[4][i];
            }
            else if(a[3][i]==a[1][i]&&a[3][i]!=0&&a[2][i]==0)
            {
                a[3][i]=a[3][i]*2;
                a[2][i]=0;
                a[1][i]=0;
                if(a[4][i]==0)
                {
                    a[4][i]=a[3][i];
                    a[3][i]=a[2][i];
                    a[2][i]=a[1][i];
                    a[1][i]=0;
                }
                coun=1;
                s=s+a[4][i];
            }
        }
        for(int i=1;i<=4;i++)
        {
            if((a[4][i]==0&&a[3][i]!=0&&a[2][i]!=0&&a[1][i]!=0)||(a[4][i]==0&&a[3][i]!=0&&a[2][i]!=0&&a[1][i]==0)||(a[4][i]==0&&a[3][i]!=0&&a[2][i]==0&&a[1][i]==0))
            {
                a[4][i]=a[3][i];
                a[3][i]=a[2][i];
                a[2][i]=a[1][i];
                a[1][i]=0;
                coun=1;
            }
            else if(a[4][i]==0&&a[2][i]==0&&a[3][i]!=0&&a[1][i]!=0)
            {
                a[4][i]=a[3][i];
                a[3][i]=a[1][i];
                a[2][i]=0;
                a[1][i]=0;
                coun=1;
            }
            else if(a[4][i]==0&&a[3][i]==0&&a[2][i]!=0)
            {
                a[4][i]=a[2][i];
                a[3][i]=a[1][i];
                a[2][i]=0;
                a[1][i]=0;
                coun=1;
            }
            else if(a[4][i]==0&&a[3][i]==0&&a[2][i]==0&&a[1][i]!=0)
            {
                a[4][i]=a[1][i];
                a[3][i]=0;
                a[2][i]=0;
                a[1][i]=0;
                coun=1;
            }
            else if(a[4][i]!=0&&a[3][i]==0&&a[2][i]!=0)
            {
                a[3][i]=a[2][i];
                a[2][i]=a[1][i];
                a[1][i]=0;
                coun=1;
            }
            else if(a[4][i]!=0&&a[3][i]==0&&a[2][i]==0&&a[1][i]!=0)
            {
                a[3][i]=a[1][i];
                a[2][i]=0;
                a[1][i]=0;
                coun=1;
            }
            else if(a[4][i]!=0&&a[3][i]!=0&&a[2][i]==0&&a[1][i]!=0)
            {
                a[2][i]=a[1][i];
                a[1][i]=0;
                coun=1;
            }
        }
    }
    if(ch=='w')
    {
        for(int ss=1;ss<=4;ss++)
        {
            for(int sss=1;sss<=4;sss++)
            {
                aa[ss][sss]=a[sss][ss];
            }
        }
        for(int ss=1;ss<=4;ss++)
        {
            for(int sss=1;sss<=4;sss++)
            {
                a[ss][sss]=aa[ss][sss];
            }
        }
        for(int i=1;i<=4;i++)
        {
            if(a[1][i]==a[2][i]&&a[3][i]==a[4][i]&&a[1][i]!=0&&a[2][i]!=0&&a[3][i]!=0&&a[4][i]!=0)
            {
                a[1][i]=a[1][i]*2;
                a[2][i]=a[3][i]*2;
                a[3][i]=0;
                a[4][i]=0;
                coun=1;
                s=s+a[1][i]+a[2][i];
            }
            else if(a[1][i]==a[2][i]&&a[1][i]!=0&&a[2][i]!=0)
            {
                a[1][i]=a[1][i]*2;
                a[2][i]=a[3][i];
                a[3][i]=a[4][i];
                a[4][i]=0;
                coun=1;
                s=s+a[1][i];
            }
            else if(a[3][i]==a[4][i]&&a[3][i]!=a[2][i]&&a[3][i]!=0&&a[4][i]!=0)
            {
                a[3][i]=a[3][i]*2;
                a[4][i]=0;
                coun=1;
                s=s+a[3][i];
                if(a[1][i]==0&&a[2][i]==0)
                {
                    a[1][i]=a[3][i];
                    a[2][i]=a[4][i];
                    a[3][i]=0;
                    a[4][i]=0;
                }
                else if(a[1][i]==0&&a[2][i]!=0)
                {
                    a[1][i]=a[2][i];
                    a[2][i]=a[3][i];
                    a[3][i]=a[4][i];
                    a[4][i]=0;
                }
                else if(a[1][i]!=0&&a[2][i]==0)
                {
                    a[2][i]=a[3][i];
                    a[3][i]=a[4][i];
                    a[4][i]=0;
                }
            }
            else if(a[3][i]==a[2][i]&&a[3][i]!=0&&a[2][i]!=0)
            {
                a[2][i]=a[2][i]*2;
                a[3][i]=a[4][i];
                a[4][i]=0;
                coun=1;
                s=s+a[2][i];
                if(a[1][i]==0)
                {
                    a[1][i]=a[2][i];
                    a[2][i]=a[3][i];
                    a[3][i]=a[4][i];
                    a[4][i]=0;
                }
            }
            else if(a[1][i]==a[3][i]&&a[1][i]!=0&&a[2][i]==0)
            {
                a[1][i]=a[1][i]*2;
                a[2][i]=a[4][i];
                a[3][i]=0;
                a[4][i]=0;
                coun=1;
                s=s+a[1][i];
            }
            else if(a[1][i]==a[4][i]&&a[2][i]==0&&a[3][i]==0&&a[1][i]!=0)
            {
                a[1][i]=a[1][i]*2;
                a[2][i]=0;
                a[3][i]=0;
                a[4][i]=0;
                coun=1;
                s=s+a[1][i];
            }
            else if(a[2][i]==a[4][i]&&a[2][i]!=0&&a[3][i]==0)
            {
                a[2][i]=a[2][i]*2;
                a[3][i]=0;
                a[4][i]=0;
                if(a[1][i]==0)
                {
                    a[1][i]=a[2][i];
                    a[2][i]=a[3][i];
                    a[3][i]=a[4][i];
                    a[4][i]=0;
                }
                coun=1;
                s=s+a[1][i];
            }
        }
        for(int i=1;i<=4;i++)
        {
            if((a[1][i]==0&&a[2][i]!=0&&a[3][i]!=0&&a[4][i]!=0)||(a[1][i]==0&&a[2][i]!=0&&a[3][i]!=0&&a[4][i]==0)||(a[1][i]==0&&a[2][i]!=0&&a[3][i]==0&&a[4][i]==0))
            {
                a[1][i]=a[2][i];
                a[2][i]=a[3][i];
                a[3][i]=a[4][i];
                a[4][i]=0;
                coun=1;
            }
            else if(a[1][i]==0&&a[3][i]==0&&a[2][i]!=0&&a[4][i]!=0)
            {
                a[1][i]=a[2][i];
                a[2][i]=a[4][i];
                a[3][i]=0;
                a[4][i]=0;
                coun=1;
            }
            else if(a[1][i]==0&&a[2][i]==0&&a[3][i]!=0)
            {
                a[1][i]=a[3][i];
                a[2][i]=a[4][i];
                a[3][i]=0;
                a[4][i]=0;
                coun=1;
            }
            else if(a[1][i]==0&&a[2][i]==0&&a[3][i]==0&&a[4][i]!=0)
            {
                a[1][i]=a[4][i];
                a[2][i]=0;
                a[3][i]=0;
                a[4][i]=0;
                coun=1;
            }
            else if(a[1][i]!=0&&a[2][i]==0&&a[3][i]!=0)
            {
                a[2][i]=a[3][i];
                a[3][i]=a[4][i];
                a[4][i]=0;
                coun=1;
            }
            else if(a[1][i]!=0&&a[2][i]==0&&a[3][i]==0&&a[4][i]!=0)
            {
                a[2][i]=a[4][i];
                a[3][i]=0;
                a[4][i]=0;
                coun=1;
            }
            else if(a[1][i]!=0&&a[2][i]!=0&&a[3][i]==0&&a[4][i]!=0)
            {
                a[3][i]=a[4][i];
                a[4][i]=0;
                coun=1;
            }
        }
        for(int ss=1;ss<=4;ss++)
        {
            for(int sss=1;sss<=4;sss++)
            {
                aa[ss][sss]=a[sss][ss];
            }
        }
        for(int ss=1;ss<=4;ss++)
        {
            for(int sss=1;sss<=4;sss++)
            {
                a[ss][sss]=aa[ss][sss];
            }
        }
    }
    if(ch=='s')
    {
        for(int ss=1;ss<=4;ss++)
        {
            for(int sss=1;sss<=4;sss++)
            {
                aa[ss][sss]=a[sss][ss];
            }
        }
        for(int ss=1;ss<=4;ss++)
        {
            for(int sss=1;sss<=4;sss++)
            {
                a[ss][sss]=aa[ss][sss];
            }
        }
        for(int i=1;i<=4;i++)
        {
            if(a[4][i]==a[3][i]&&a[2][i]==a[1][i]&&a[4][i]!=0&&a[3][i]!=0&&a[2][i]!=0&&a[1][i]!=0)
            {
                a[4][i]=a[4][i]*2;
                a[3][i]=a[2][i]*2;
                a[2][i]=0;
                a[1][i]=0;
                coun=1;
                s=s+a[4][i]+a[3][i];
            }
            else if(a[4][i]==a[3][i]&&a[4][i]!=0&&a[3][i]!=0)
            {
                a[4][i]=a[4][i]*2;
                a[3][i]=a[2][i];
                a[2][i]=a[1][i];
                a[1][i]=0;
                coun=1;
                s=s+a[4][i];
            }
            else if(a[2][i]==a[1][i]&&a[2][i]!=a[3][i]&&a[2][i]!=0&&a[1][i]!=0)
            {
                a[2][i]=a[2][i]*2;
                a[1][i]=0;
                coun=1;
                s=s+a[2][i];
                if(a[4][i]==0&&a[3][i]==0)
                {
                    a[4][i]=a[2][i];
                    a[3][i]=a[1][i];
                    a[2][i]=0;
                    a[1][i]=0;
                }
                else if(a[4][i]==0&&a[3][i]!=0)
                {
                    a[4][i]=a[3][i];
                    a[3][i]=a[2][i];
                    a[2][i]=a[1][i];
                    a[1][i]=0;
                }
                else if(a[4][i]!=0&&a[3][i]==0)
                {
                    a[3][i]=a[2][i];
                    a[2][i]=a[1][i];
                    a[1][i]=0;
                }
            }
            else if(a[2][i]==a[3][i]&&a[2][i]!=0&&a[3][i]!=0)
            {
                a[3][i]=a[3][i]*2;
                a[2][i]=a[1][i];
                a[1][i]=0;
                coun=1;
                s=s+a[3][i];
                if(a[4][i]==0)
                {
                    a[4][i]=a[3][i];
                    a[3][i]=a[2][i];
                    a[2][i]=a[1][i];
                    a[1][i]=0;
                }
            }
            else if(a[4][i]==a[2][i]&&a[4][i]!=0&&a[3][i]==0)
            {
                a[4][i]=a[4][i]*2;
                a[3][i]=a[1][i];
                a[2][i]=0;
                a[1][i]=0;
                coun=1;
                s=s+a[4][i];
            }
            else if(a[4][i]==a[1][i]&&a[3][i]==0&&a[2][i]==0&&a[4][i]!=0)
            {
                a[4][i]=a[4][i]*2;
                a[3][i]=0;
                a[2][i]=0;
                a[1][i]=0;
                coun=1;
                s=s+a[4][i];
            }
            else if(a[3][i]==a[1][i]&&a[3][i]!=0&&a[2][i]==0)
            {
                a[3][i]=a[3][i]*2;
                a[2][i]=0;
                a[1][i]=0;
                if(a[4][i]==0)
                {
                    a[4][i]=a[3][i];
                    a[3][i]=a[2][i];
                    a[2][i]=a[1][i];
                    a[1][i]=0;
                }
                coun=1;
                s=s+a[4][i];
            }
        }
        for(int i=1;i<=4;i++)
        {
            if((a[4][i]==0&&a[3][i]!=0&&a[2][i]!=0&&a[1][i]!=0)||(a[4][i]==0&&a[3][i]!=0&&a[2][i]!=0&&a[1][i]==0)||(a[4][i]==0&&a[3][i]!=0&&a[2][i]==0&&a[1][i]==0))
            {
                a[4][i]=a[3][i];
                a[3][i]=a[2][i];
                a[2][i]=a[1][i];
                a[1][i]=0;
                coun=1;
            }
            else if(a[4][i]==0&&a[2][i]==0&&a[3][i]!=0&&a[1][i]!=0)
            {
                a[4][i]=a[3][i];
                a[3][i]=a[1][i];
                a[2][i]=0;
                a[1][i]=0;
                coun=1;
            }
            else if(a[4][i]==0&&a[3][i]==0&&a[2][i]!=0)
            {
                a[4][i]=a[2][i];
                a[3][i]=a[1][i];
                a[2][i]=0;
                a[1][i]=0;
                coun=1;
            }
            else if(a[4][i]==0&&a[3][i]==0&&a[2][i]==0&&a[1][i]!=0)
            {
                a[4][i]=a[1][i];
                a[3][i]=0;
                a[2][i]=0;
                a[1][i]=0;
                coun=1;
            }
            else if(a[4][i]!=0&&a[3][i]==0&&a[2][i]!=0)
            {
                a[3][i]=a[2][i];
                a[2][i]=a[1][i];
                a[1][i]=0;
                coun=1;
            }
            else if(a[4][i]!=0&&a[3][i]==0&&a[2][i]==0&&a[1][i]!=0)
            {
                a[3][i]=a[1][i];
                a[2][i]=0;
                a[1][i]=0;
                coun=1;
            }
            else if(a[4][i]!=0&&a[3][i]!=0&&a[2][i]==0&&a[1][i]!=0)
            {
                a[2][i]=a[1][i];
                a[1][i]=0;
                coun=1;
            }
        }
         for(int ss=1;ss<=4;ss++)
        {
            for(int sss=1;sss<=4;sss++)
            {
                aa[ss][sss]=a[sss][ss];
            }
        }
        for(int ss=1;ss<=4;ss++)
        {
            for(int sss=1;sss<=4;sss++)
            {
                a[ss][sss]=aa[ss][sss];
            }
        }
    }
    if(coun==1)
    {
        pri();
        score();
        won();
    }
    if(coun==0)
    {
        movement();
    }
}

int main()
{

   cout<<"Press 'W' to move up | Press 'S' to move down | Press 'A' to move Left | Press 'D' to move Right";
    ran();
    ran();
    movement();
}

