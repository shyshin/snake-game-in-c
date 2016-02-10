#include<conio.h>
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
int a[20][20],dir=0,i,j;
int posx,posy,food=3;bool run;

void getfood()
{
    int x,y;
    do
    {
        x=rand()%18;
        y=rand()%18;
    }while(a[x][y]!=0);
    a[x][y]=-2;
}
void init()
{ int i,j;
  posx=10;
    posy=10;
    a[posx][posy]=1;
 for(i=0;i<20;i++)
 {
     for(j=0;j<20;j++)
     {  if(i==0||i==19||j==0||j==19)
           {
               a[i][j]=-1;
           }
         else
         {
             a[i][j]=0;
         }
     }
 }
 getfood();
}
void getdir(char k)
{
  switch(k)
  {
  case 72://up
    if(dir!=1)//checking for down
    {
        dir=0;
    }
    break;
  case 80://down
    if(dir!=0)
    {
        dir=1;
    }
    break;
    case 77://right
    if(dir!=3)
    {
        dir=2;
    }
    break;
    case 75://left
    if(dir!=2)
    {
        dir=3;
    }
    break;
  }

}

void move(int dx,int dy)
{
    int nx=posx+dx;
    int ny=posy+dy;
    if(a[nx][ny]==-2)
    {
        food++;
        getfood();
    }
    else if(a[nx][ny]!=0)
    {
        run=false;
    }
    posx=nx;
    posy=ny;
    a[posx][posy]=food + 1;
}
void update()
{
    switch(dir)
    {  case 0:
        move(-1,0);
        break;
       case 1:
        move(1,0);
        break;
       case 2:
        move(0,1);
        break;
        case 3:
        move(0,-1);
        break;
    }
    for(i=0;i<20;i++)
    {
        for(j=0;j<20;j++)
        {
            if(a[i][j]>0)
            {
                a[i][j]--;
            }
        }
    }
}
char getval(int x)
{
    if(x>0)
    {
        return '#';
    }
    switch(x)
    {
    case -1:
        return 'X';break;
    case -2:
        return '0';break;
    }

}
void print()
{ //ios::sync_with_stdio(0);
    for(i=0;i<20;i++)
    {
        for(j=0;j<20;j++)
        {
            printf("%c",getval(a[i][j]));
        }
     printf("\n");
    }
}
int main()
{   //ios::sync_with_stdio(0);
    run=true;
    init();
    while(run)
    {
        if(kbhit())
        {
            getdir(getch());
        }
        Sleep(100);
        system("cls");
        update();
        printf("----------Snake Game----------\n");
        print();

    }
    printf("\n\nGame Over!!!");
    printf("\nYour Score is %d",food-3);
    return 0;
}
