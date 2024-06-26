#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
int col[25][25];
int r,c;
int x,y;
void BFS(int x,int y)
{
    queue<pair <int,int> >q;
    q.push({x,y});
    col[x][y]=1;
    while(!q.empty())
    {
        pair<int,int> x=q.front();

        q.pop();

        if(col[x.f-1][x.s]==0 && x.f-1>=0)
            col[x.f-1][x.s]=1,q.push({x.f-1,x.s});
        if(col[x.f][x.s-1]==0 && x.s-1>=0)
            col[x.f][x.s-1]=1,q.push({x.f,x.s-1});
        if(col[x.f+1][x.s]==0 && x.f+1<r)
            col[x.f+1][x.s]=1,q.push({x.f+1,x.s});
        if(col[x.f][x.s+1]==0 && x.s+1<c)
            col[x.f][x.s+1]=1,q.push({x.f,x.s+1});
    }
}
int main()
{
    int t,no=1;
    cin>>t;
    while(t--)
    {
        cin>>c>>r;
        for(int i=0; i<=r; i++)
        {
            for(int j=0; j<=c; j++)
            {
                col[i][j]=0;
            }
        }
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                char ch;
                cin>>ch;
                if(ch=='.')col[i][j]=0;
                if(ch=='#')col[i][j]=2;
                if(ch=='@')x=i,y=j;
            }
        }
        BFS(x,y);
        int coun=0;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(col[i][j]==1)
                {
                    coun++;
                }
            }
        }
        printf("Case %d: %d\n",no++,coun);
    }
    return 0;
}
