#include <iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

int row=1,col=1,ri=0,ci=0,dim,v=0,w=0,r=0,c=0;

void gotoRowCol(int rpos, int cpos)
{
	int xpos=cpos, ypos = rpos;
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}
void init_board(char A[])
{
 for(int i=0;i<63;i++)
    {
        A[i]='_';
    }
}
void Print_Box(int rdim, int cdim,int row,int col,char ch)
{
    for(int i=1;i<=8;i++)
{
    for(int r=1;r<=rdim;r++)
    {
        for(int c=1;c<=cdim;c++)
        {
            if((r==row &&c<=cdim)||(c==col&&r<=rdim)||(r==rdim && c<=cdim)||(c==cdim&&r<=rdim))
            {
                gotoRowCol((r-1)+row,(c-1)+col);
                cout<<ch;
            }
        }
    }
    col=col+6;
}
}
void symbols(char A[],int ri,int ci,int &a)
{
     A[0]='R';
     gotoRowCol(3,4);
     cout<<A[0];
    gotoRowCol(3,10);
    A[1]='N';
    cout<<A[1];
    gotoRowCol(3,16);
    A[2]='B';
    cout<<A[2];
    gotoRowCol(3,22);
    A[3]='K';
    cout<<A[3];
    gotoRowCol(3,28);
    A[4]='Q';
    cout<<A[4];
    gotoRowCol(3,34);
    A[5]='B';
    cout<<A[5];
    gotoRowCol(3,40);
    A[6]='N';
    cout<<A[6];
    gotoRowCol(3,46);
    A[7]='R';
    cout<<A[7];
    ri=6;ci=4;
    for(int i=8;i<=15;i++)
    {
        gotoRowCol(ri,ci);
        A[i]='P';
        cout<<A[i];
        ci=ci+6;
    }
    for(int i=48;i<56;i++)
    {
        if(i==48)
        {
            ci=4;
        }
        ri=21;
        gotoRowCol(ri,ci);
        A[i]='p';
        cout<<A[i];
        ci=ci+6;
    }
    A[56]='r';
     gotoRowCol(24,4);
     cout<<A[56];
    gotoRowCol(24,10);
    A[57]='n';
    cout<<A[57];
    gotoRowCol(24,16);
    A[58]='b';
    cout<<A[58];
    gotoRowCol(24,22);
    A[59]='k';
    cout<<A[59];
    gotoRowCol(24,28);
    A[60]='q';
    cout<<A[60];
    gotoRowCol(24,34);
    A[61]='b';
    cout<<A[61];
    gotoRowCol(24,40);
    A[62]='n';
    cout<<A[62];
    gotoRowCol(24,46);
    A[63]='r';
    cout<<A[63];

}
bool turn_change(bool &turn)
{
    if(turn==0)
    {
     turn=1;
    }
    else
    {
        turn=0;
    }
}
int tD_2_D(char A[],int ri,int ci)
{
    int a;
    a=(ri-1)*8+(ci-1);
    return a;
}
int turn1(char A[],int &a,int &ri,int &ci,int &r,int &c,bool &turn)
{
    if(turn==0)
    {
    if((ri<=8 && ci<=8 && ri>=1 && ci>=1) && (A[a]=='_' || A[a]=='r' || A[a]=='n' || A[a]=='b' || A[a]=='q' || A[a]=='p') && (A[a]!='P' || A[a]!='R' || A[a]!='N' || A[a]!='B' || A[a]!='K' || A[a]!='Q' || A[a]!='k'))
    {
        return 1;
    }
    else{
        return 0;
    }
    }
    else
    {
        return 0;
    }
}
int turn2(char A[],int &a,int &ri,int &ci,int &r,int &c,bool &turn)
{
    if(turn==1)
    {
    if((ri<=8 && ci<=8 && ri>=1 && ci>=1) && (A[a]=='_' || A[a]=='R' || A[a]=='N' || A[a]=='B' || A[a]=='Q' || A[a]=='P') && (A[a]!='p' || A[a]!='r' || A[a]!='n' || A[a]!='b' || A[a]!='k' || A[a]!='q' || A[a]!='K'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    }
    else
    {
        return 0;
    }
}
bool ask_for_move(int &ri,int &ci)
{  gotoRowCol(5,50);
    cout<<"Enter the row you want to move to:";
    cin>>ri;
    gotoRowCol(6,50);
    cout<<"Enter the column you want to move to:";
    cin>>ci;
}
void ask_move(int &r,int &c)
{
gotoRowCol(3,50);
    cout<<"Enter the row you want to move from:";
     cin>>r;
     gotoRowCol(4,50);
     cout<<"Enter the column you want to move from:";
     cin>>c;
}
int legal_pawn1(char A[],int &a,int &ri,int &ci,int &r,int &c,bool &turn,int &y)
{
      if(r==2)
        {
    if(ri<=8 && ci<=8 && ri>=1 && ci>=1 && A[a]=='_')
    {
        if((ri-1==r && ci==c) || (ri-2==r && ci==c))
        {
            return 1;
        }
        else{
            return 0;
        }
    }
    else if((A[a]=='r' || A[a]=='n' || A[a]=='b' || A[a]=='q' || A[a]=='p') && (A[a]!='P' || A[a]!='R' || A[a]!='N' || A[a]!='B' || A[a]!='K' || A[a]!='Q' || A[a]!='k'))
            {
                if(ri-1==r && ci==c-1)
                {
                  return 2;
                }
                else if(ri-1==r && ci==c+1)
                {
                   return 2;
                }
            }
    else
    {
        return 0;
    }
        }
    else{
        if(ri<=8 && ci<=8 && ri>=1 && ci>=1 && ci==c && A[a]=='_' )
    {
        if(ri-1==r && ci==c)
        {
            return 1;
        }
        else{
            return 0;
        }
        }
    else if((A[a]=='r' || A[a]=='n' || A[a]=='b' || A[a]=='q' || A[a]=='p') && (A[a]!='P'  || A[a]!='R' || A[a]!='N' || A[a]!='B' || A[a]!='K' || A[a]!='Q' || A[a]!='k'))
            {
                if(ri-1==r && ci==c-1)
                {
                  return 2;
                }
                else if(ri-1==r && ci==c+1)
                {
                   return 2;
                }
                else
                {
                    return 0;
                }
            }
    else
    {
        return 0;
    }
    }
}
int legal_pawn2(char A[],int &a,int &ri,int &ci,int &r,int &c,bool &turn,int &y)
{
      if(r==7)
        {
    if(ri<=8 && ci<=8 && ri>=1 && ci>=1 && A[a]=='_')
    {
        if((ri+1==r && ci==c) || (ri+2==r && ci==c))
        {
            return 1;
        }
        else{
            return 0;
        }
    }
    else if((A[a]=='R' || A[a]=='N' || A[a]=='B' || A[a]=='Q' || A[a]=='P') && (A[a]!='p' || A[a]!='r' || A[a]!='n' || A[a]!='b' || A[a]!='k' || A[a]!='q' || A[a]!='K'))
            {
                if(ri+1==r && ci==c+1)
                {
                  return 2;
                }
                else if(ri+1==r && ci==c-1)
                {
                   return 2;
                }
            }
    else
    {
        return 0;
    }
        }
    else{
        if(ri<=8 && ci<=8 && ri>=1 && ci>=1 && ci==c && A[a]=='_')
    {
        if(ri+1==r && ci==c)
        {
            return 1;
        }
        else{
            return 0;
        }
    }
    else if((A[a]=='R' || A[a]=='N' || A[a]=='B' || A[a]=='Q' || A[a]=='P') && (A[a]!='p' || A[a]!='r' || A[a]!='n' || A[a]!='b' || A[a]!='k' || A[a]!='q' || A[a]!='K'))
            {
                if(ri+1==r && ci==c-1)
                {
                  return 2;
                }
                else if(ri+1==r && ci==c+1)
                {
                   return 2;
                }
                else{
                    return 0;
                }
            }
    else
    {
        return 0;
    }
    }
}
void move_pawn(char A[],int &a,int &ri,int &ci, bool &turn,int &y)
{  a=tD_2_D(A,ri,ci);
     int d,m=0,n=0,p;
     if(turn==0)
     {
        do
     {
         m=0;
     d=legal_pawn1(A,a,ri,ci,r,c,turn,y);
     if(d==1)
     {
         ri=ri*3;ci=ci*5+(ci-2);
     gotoRowCol(ri,ci);
     A[a]='P';
      cout<<A[a];
     }
     else if(d==2)
     {
         ri=ri*3;ci=ci*5+(ci-2);
     gotoRowCol(ri,ci);
     A[a]='P';
     cout<<A[a];
     }
     else if(d==0)
     {
         m++;
         ask_move(r,c);
         p=ask_for_move(ri,ci);
     }
     }while(m!=0);
     }
     else if(turn==1)
     {
         do
         {
             n=0;
         d=legal_pawn2(A,a,ri,ci,r,c,turn,y);
     if(d==1)
     {
         ri=ri*3;ci=ci*5+(ci-2);
     gotoRowCol(ri,ci);
     A[a]='p';
      cout<<A[a];
     }
     else if(d==2)
     {
         ri=ri*3;ci=ci*5+(ci-2);
     gotoRowCol(ri,ci);
     A[a]='p';
     cout<<A[a];
     }
     else if(d==0)
     {
         n++;
     ask_move(r,c);
         p=ask_for_move(ri,ci);
     }
     }while(n!=0);
     }
}
int legal_knight(char A[],int &a,int &ri,int &ci,int &r,int &c,bool &turn,int &y)
{
    if(turn1(A,a,ri,ci,r,c,turn)==1 || turn2(A,a,ri,ci,r,c,turn)==1)
    {
        if((r-ri==2 && ci==c+1) || (r-ri==2 && ci==c-1))
        {
            return 1;
        }
    else if((ri-r==2 && ci==c+1) || (ri-r==2 && ci==c-1))
    {
        return 1;
    }
    else{
            return 0;
    }
    }
        else
            {
            return 0;
            }
}
void move_knight(char A[],int &a,int &ri,int &ci,int &r,int &c, bool &turn,int &y)
{
    a=tD_2_D(A,ri,ci);
     int d,m=0;
     do
     {
         m=0;
     d=legal_knight(A,a,ri,ci,r,c,turn,y);
     if(d==1)
     {
         ri=ri*3;ci=ci*5+(ci-2);
     gotoRowCol(ri,ci);
     if(turn==0)
     {
     A[a]='N';
      cout<<A[a];
     }
     else
     {
         A[a]='n';
      cout<<A[a];
     }
     }
     else if(d==0)
     {
         m++;
         ask_move(r,c);
         ask_for_move(ri,ci);
     }
     }while(m!=0);
}
int legal_rook(char A[],int &a,int &ri,int &ci,int &r,int &c,bool &turn,int &y)
{
    if(turn1(A,a,ri,ci,r,c,turn)==1 || turn2(A,a,ri,ci,r,c,turn)==1)
    {
        if((r!=ri && ci==c))
        {
            if(a>y)
            {
                int j;
                j=a-y;
            for(int i=1;i<=j/8;i++)
            {
                if (A[y+8]!='_')
                {
                    return 0;
                }
                else{
                    y=y+8;
                }
            }
            return 1;
            }
         else if(a<y)
            {
                int j;
                j=y-a;
            for(int i=1;i<=j/8;i++)
            {
                if (A[y-8]!='_')
                {
                    return 0;
                }
                else{
                    y=y-8;
                }
            }
            return 1;
            }
            else
            {
                return 0;
            }
        }
    else if((r==ri && c!=ci) || (r==ri && c!=ci))
    {
        if(a>y)
            {
                int j;
                j=a-y;
            for(int i=1;i<=j;i++)
            {
                if (A[y+1]!='_')
                {
                    return 0;
                }
                else{
                    y=y+1;
                }
            }
            return 1;
            }
         else if(a<y)
            {
                int j;
                j=y-a;
            for(int i=1;i<=j;i++)
            {
                if (A[y-1]!='_')
                {
                    return 0;
                }
                else{
                    y=y-1;
                }
            }
            return 1;
            }
        else{
            return 0;
        }}
    else{
            return 0;
    }
    }
       else
        {
        return 0;
        }
    }
void move_rook(char A[],int &a,int &ri,int &ci,int &r,int &c, bool &turn,int &y)
{
   a=tD_2_D(A,ri,ci);
     int d,m=0;
     do
     {
         m=0;
     d=legal_rook(A,a,ri,ci,r,c,turn,y);
     if(d==1)
     {
        ri=ri*3;ci=ci*5+(ci-2);
     gotoRowCol(ri,ci);
     if(turn==0)
     {
     A[a]='R';
      cout<<A[a];
     }
     else
     {
         A[a]='r';
      cout<<A[a];
     }
     }
     else if(d==0)
     {
         cout<<"TRY AGAIN";
         m++;
         ask_move(r,c);
         ask_for_move(ri,ci);
     }
     }while(m!=0);
}
int legal_bishop(char A[],int &a,int &ri,int &ci,int &r,int &c,bool &turn,int &y)
{
    int l;
    if(turn1(A,a,ri,ci,r,c,turn)==1 || turn2(A,a,ri,ci,r,c,turn)==1)
    {
        if(a>y)
        {
            int k=ri-r-1;
            if(ci>c)
            {
              l=(r+k)*8+c+1;
            }
            else if(ci<c)
            {
              l=(r+k)*8+c-(k+2);
            }
            if(a==l)
            {
               int m=ri-r-1;
                for(int i=1;i<=m;i++)
                {
                    if(ci<c)
                    {
                    if(A[a-8+i]!='_')
                    {
                        return 0;
                    }
                    else
                    {
                        a=a-7;
                    }
                    }
                   else if(ci>c)
                    {
                    if(A[a-9]!='_')
                    {
                        return 0;
                    }
                    else
                    {
                        a=a-9;
                    }
                    }
                    }
                return 1;
            }
            else {return 0;}
        }
        else if(a<y)
        {
           int k=r-ri-1;
             if(ci>c)
            {
              l=(r-k-2)*8+c+k+1;
            }
            else if(ci<c)
            {
              l=(r-k-2)*8+c-(k+2);
            }
            if(a==l)
            {
               int m=r-ri-1;
                for(int i=1;i<=m;i++)
                {
                    if(ci<c)
                    {
                    if(A[a+8+i]!='_')
                    {
                        return 0;
                    }
                    else{
                        a=a+9;
                    }
                     }
                    else if(ci>c)
                    {
                        if(A[a-7]!='_')
                    {
                        return 0;
                    }
                    else
                    {
                        a=a-7;
                    }
                    }
                }
                return 1;
            }
            else {return 0;}
        }
    }
    else
    {
        return 0;
    }
}
void move_bishop(char A[],int &a,int &ri,int &ci,int &r,int &c, bool &turn,int &y)
{
  a=tD_2_D(A,ri,ci);
     int d,m=0;
     do
     {
         m=0;
     d=legal_bishop(A,a,ri,ci,r,c,turn,y);
     if(d==1)
     {
        ri=ri*3;ci=ci*5+(ci-2);
     gotoRowCol(ri,ci);
     if(turn==0)
     {
     A[a]='B';
      cout<<A[a];
     }
     else{
        A[a]='b';
      cout<<A[a];
     }
     }
     else if(d==0)
     {
         cout<<"TRY AGAIN";
         m++;
         ask_move(r,c);
         ask_for_move(ri,ci);
     }
     }while(m!=0);
}
int legal_queen(char A[],int &a,int &ri,int &ci,int &r,int &c,bool &turn,int &y)
{
    int d;
    if(turn1(A,a,ri,ci,r,c,turn)==1 || turn2(A,a,ri,ci,r,c,turn)==1)
    {
        if((r!=ri && ci==c))
        {
            d=legal_rook(A,a,ri,ci,r,c,turn,y);
        }
        else if((r==ri && c!=ci) || (r==ri && c!=ci))
        {
            d=legal_rook(A,a,ri,ci,r,c,turn,y);
        }
        else if(a>y && ci!=c)
        {
            d=legal_bishop(A,a,ri,ci,r,c,turn,y);
        }
        else if(a<y && ci!=c)
        {
            d=legal_bishop(A,a,ri,ci,r,c,turn,y);
        }
        else
        {
            return 0;
        }
    }
        else
            {
            return 0;
            }
}
void move_queen(char A[],int &a,int &ri,int &ci,int &r,int &c, bool &turn,int &y)
{
   a=tD_2_D(A,ri,ci);
     int d,m=0;
     do
     {
         m=0;
     d=legal_queen(A,a,ri,ci,r,c,turn,y);
     if(d==1)
     {
         ri=ri*3;ci=ci*5+(ci-2);
     gotoRowCol(ri,ci);
     if(turn==0)
     {
         A[a]='Q';
      cout<<A[a];
     }
     else
     {
         A[a]='q';
      cout<<A[a];
     }
     }
     else if(d==0)
     {
         cout<<"TRY AGAIN";
         m++;
         ask_move(r,c);
         ask_for_move(ri,ci);
     }
     }while(m!=0);
}
int legal_king(char A[],int &a,int &ri,int &ci,int &r,int &c,bool &turn,int &y)
{
     if(turn==0)
     {
        if(ri<=8 && ci<=8 && ri>=1 && ci>=1 && (A[a]=='_' || A[a]=='r' || A[a]=='n' || A[a]=='b' || A[a]=='k' || A[a]=='q' || A[a]=='p') && (A[a]!='P' || A[a]!='R' || A[a]!='N' || A[a]!='B' || A[a]!='K' || A[a]!='Q'))
    {
        if(((r==ri+1 || r==ri-1) && (c==ci)) || ((r==ri) && (ci==c+1 || ci==c-1)))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
     }
     else
         {
        if(ri<=8 && ci<=8 && ri>=1 && ci>=1 && (A[a]=='_' || A[a]=='R' || A[a]=='N' || A[a]=='B' || A[a]=='Q' || A[a]=='P') && (A[a]!='p' || A[a]!='r' || A[a]!='n' || A[a]!='b' || A[a]!='K' || A[a]=='q' || A[a]!='k'))
    {
        if(((r==ri+1 || r==ri-1) && (c==ci)) || ((r==ri) && (ci==c+1 || ci==c-1)))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
     }
}
void move_king(char A[],int &a,int &ri,int &ci,int &r,int &c, bool &turn,int &y)
{
    a=tD_2_D(A,ri,ci);
     int d,m=0;
     do
     {
         m=0;
     d=legal_king(A,a,ri,ci,r,c,turn,y);
     if(d==1)
     {
         ri=ri*3;ci=ci*5+(ci-2);
     gotoRowCol(ri,ci);
     if(turn==0)
     {
         A[a]='K';
      cout<<A[a];
     }
     else
     {
         A[a]='k';
      cout<<A[a];
     }
     }
     else if(d==0)
     {
         cout<<"TRY AGAIN";
         m++;
         ask_move(r,c);
         ask_for_move(ri,ci);
     }
     }while(m!=0);
}
int main()
{
    int a,rdim=4,b,d,k,l,m,n,y,z;
    bool turn=0;
    char A[63];
    init_board(A);
    for(rdim;rdim<=25;rdim=rdim+3)
    {
        Print_Box(rdim,7,1,1,219);
    }
    symbols(A,ri,ci,d);
    do
    {
         gotoRowCol(12,60);
    cout<<"turn="<<turn;
        do
        {      r=0;
               c=0;
               y=0;
            ask_move(r,c);
               y=(r-1)*8+(c-1);
               //cout<<"abcd";

        }while(((turn==1) && (A[y]=='P' || A[y]=='R' || A[y]=='N' || A[y]=='B' || A[y]=='K' || A[y]=='Q' || A[y]=='_')) || ((turn==0) && (A[y]=='p' || A[y]=='r' || A[y]=='n' || A[y]=='b' || A[y]=='k' || A[y]=='q' || A[y]=='_')));
    if((A[y]=='P') || (A[y]=='p'))
    {
        m=ask_for_move(ri,ci);
    move_pawn(A,a,ri,ci,turn,y);
    r=r*3;c=c*5+(c-2);
        gotoRowCol(r,c);
        A[y]='_';
        cout<<A[y];
    }
    else if(A[y]=='N' || A[y]=='n')
    {
        n=ask_for_move(ri,ci);
        move_knight(A,a,ri,ci,r,c,turn,y);
        r=r*3;c=c*5+(c-2);
        gotoRowCol(r,c);
        A[y]='_';
        cout<<A[y];
    }
    else if(A[y]=='R' || A[y]=='r')
    {
        n=ask_for_move(ri,ci);
        move_rook(A,a,ri,ci,r,c,turn,y);
        r=r*3;c=c*5+(c-2);
        gotoRowCol(r,c);
        A[y]='_';
        cout<<A[y];
    }
    else if(A[y]=='B' || A[y]=='b')
    {
        n=ask_for_move(ri,ci);
        move_bishop(A,a,ri,ci,r,c,turn,y);
        r=r*3;c=c*5+(c-2);
        gotoRowCol(r,c);
        A[y]='_';
        cout<<A[y];
    }
    else if(A[y]=='Q' || A[y]=='q')
    {
        int b;
         n=ask_for_move(ri,ci);
        move_queen(A,a,ri,ci,r,c,turn,y);
        r=r*3;c=c*5+(c-2);
        gotoRowCol(r,c);
        A[y]='_';
        cout<<A[y];
    }
    else if(A[y]=='K' || A[y]=='k')
    {
        int b;
         n=ask_for_move(ri,ci);
        move_king(A,a,ri,ci,r,c,turn,y);
        r=r*3;c=c*5+(c-2);
        gotoRowCol(r,c);
        A[y]='_';
        cout<<A[y];
    }
    turn_change(turn);
    } while(true);
getch();
    return 0;
}

