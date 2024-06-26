// hi!thanks for watching my code :)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ff first
#define ss second
const int SIZE=1e5+9;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
int n,m,home,a,b,w;
vector<pair<int,int>>g[505];
int dis[505];
void DJS(int xx)
{
    for(int i=0; i<505; i++)dis[i]=INT_MAX;
    dis[xx]=0;
    priority_queue<pair<int,int>, vector<pair<int,int> >,greater<pair<int,int> > >pq;
    pq.push({0,xx});
    while(!pq.empty())
    {
        int u=pq.top().ss;
        pq.pop();
        for(int i=0; i<g[u].size(); i++)
        {
            int v=g[u][i].ff;
            int weight=g[u][i].ss;
            if(dis[v]>max(dis[u],weight))
            {
                dis[v]=max(dis[u],weight);
                pq.push({dis[v],v});
            }
        }
    }
}
int main()
{

    fast;
    int TC,no=1;
    cin>>TC;
    while(TC--)
    {
        cin>>n>>m;
        for(int i=0; i<m; i++)
        {
            cin>>a>>b>>w;
            g[a].push_back({b,w});
            g[b].push_back({a,w});
        }
        cin>>home;
        DJS(home);
        cout<<"Case "<<no<<":"<<endl;
        for(int i=0; i<n; i++)
        {
            if(dis[i]==INT_MAX)cout<<"Impossible"<<endl;
            else cout<<dis[i]<<endl;
            g[i].clear();
        }
        no++;
    }
    return 0;
}


//    ***********    THE END  ***********


