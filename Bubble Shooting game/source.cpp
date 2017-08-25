#include<bits/stdc++.h>
#include<graphics.h>
#define object_speed 5
#include<String>
#include<dos.h>
using namespace std ;
char str[100];
char no_ballon[100];

char ch ;
int score = 0 ;
int sy , flag  = 0 ,lx , ly ;
int x1 = 0 , x2 = 0, x3 = 0;
int bf1 = 1, bf2 = 1, bf3 = 1;
int sum=0;
void level_1(int y1,int y2,int y3,int delay_time,int num_ballon)
{

    while(num_ballon--)
    {
        sprintf(str,"Score = %d ",score);
        sprintf(no_ballon,"Time= %d ",num_ballon);
        settextstyle(1,0,0);
        setcolor(10);
        //settextjustify(CENTER_TEXT, CENTER_TEXT);
        setusercharsize(40,50,40,40);
        outtextxy(500,50,str);
        outtextxy(500,100,no_ballon);
        delay(delay_time);
        cleardevice();
        // keybord input
        if(kbhit())
        {
            ch = getch();
            //cout << (int) ch << endl;
            if(ch == 72)
            {
                if(sy>0)
                {
                    sy-=20 ;
                }
            }
            if(ch == 80)
            {
                if(sy<600)
                {
                    sy+=20;
                }
            }
            if(ch == 'a')
            {
                flag = 1 ;
                ly = sy ;
            }
        }
        // bullete
        if(flag == 1)
        {
            setcolor(4);
            setlinestyle(0,2,10);
            line(lx,ly,lx+10,ly);
            if(lx<600)
            {
                lx+=40;
            }
            else
            {
                lx = 0 ;
                flag = 0 ;
            }
        }

        // sooter crcle
        settextstyle(1,0,0);
        setcolor(4);
        setusercharsize(40,30,60,30);
        outtextxy(3,sy-34,"|=");
        /// ranndom circle section one
        y1-=object_speed;
        if(bf1 == 1)
        {
            setcolor(5);
            setlinestyle(0,2,1);
            circle(x1,y1,35);
        }
        if(y1<=0)
        {
            y1 = 600 ;
            x1 = rand() % 500 + 50 ;
            bf1 = 1;
        }


        /// ranndom circle section two
        y2-=object_speed + 2 ;
        if(bf2 == 1)
        {
            setcolor(1);
            setlinestyle(0,2,1);
            circle(x2,y2,45);
        }
        if(y2<=0)
        {
            y2 = 600 + rand() % 200  ;
            x2 = rand() % 400 + 50 ;
            bf2 = 1 ;
        }


        /// ranndom circle section three
        y3-=object_speed + 4  ;
        if(bf3 == 1)
        {
            setcolor(3);
            setlinestyle(0,2,1);
            circle(x3,y3,35);
        }
        if(y3<=0)
        {
            y3 = 600 + rand()%100 ;
            x3 = rand() % 300 + 50 ;
            bf3 = 1 ;
        }

        /// bullete hitiing the ballon
        /// claculating the distance between the first baloon and the bullete
        int dist = abs( ( x1 - (lx+50) ) *  ( x1 - (lx+50) ) + (ly - y1) * (ly - y1)) ;
        //dist = dist * dist ;
        //dist = dist  ;

        dist = sqrt(dist);

        if(dist<40)
        {
            bf1 = 0 ;
            score++;
            Beep(30,100);
            floodfill(50,30, RED);
        }

        /// baloon 2 hit
        dist = abs( ( x2 - (lx+50) ) *  ( x2 - (lx+50) ) + (ly - y2) * (ly - y2)) ;
        dist = sqrt(dist);

        if(dist<30)
        {
            bf2 = 0 ;
            score++;
            // sound(1200);
            //printf("\a\n");
            Beep(30,100);
            floodfill(50,30, RED);
            // printf("%d\n",dist);
            //printf("hit");
        }

        /// baloon 3
        dist = abs( ( x3 - (lx+50) ) *  ( x3 - (lx+50) ) + (ly - y3) * (ly - y3)) ;
        //dist = dist * dist ;
        //dist = dist  ;

        dist = sqrt(dist);

        if(dist<30)
        {
            bf3 = 0 ;
            score++;
//            sound(1200);
            //printf("\a\n");
            Beep(30,100);
            floodfill(50,30,RED);
            // printf("%d\n",dist);
            //printf("hit");
        }

    }

}
void start()
{
    settextstyle(1,0,0);
    setcolor(4);
    setusercharsize(90,100,50,6);
    outtextxy(190,60,"BUBBLE SHOOTING");
    settextstyle(1,0,0);
    setcolor(13);
    setusercharsize(40,100,40,30);
    outtextxy(100,400,"RULES:");
    settextstyle(1,0,0);
    setcolor(13);
    setusercharsize(40,100,40,40);
    outtextxy(150,450,"1.Press a key for shotting ");
    outtextxy(150,500,"2.Press up and down key to setup the range of the GUN ");
    delay(7000);//10 second
    int t=30;
    int y1 = 0 , y2 = 0, y3 = 0;
    level_1(y1,y2,y3,t,1000);
}
void scoreboard()
{
    char sc[100];
    sprintf(sc,"FINAL SCORE : %d",score);
    settextstyle(1,0,0);
    setcolor(9);
    setusercharsize(100,100,100,20);
    outtextxy(100,100,sc);
    settextstyle(1,0,0);
    setcolor(10);
    setusercharsize(100,100,100,20);
    outtextxy(300,400,"THANKS.........");
    delay(10000);
}
int main()
{
    int i;
    initwindow(800,800);
    start();
    cleardevice();
    scoreboard();
    return 0 ;
}
