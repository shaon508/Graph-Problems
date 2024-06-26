// hi!thanks for watching my code :)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ff first
#define ss second
const int SIZE=1e5+9;
vector<pair<int,int>>graph[105];
int n,a,b,w,sum1,sum2,dis[105],vis[105],parent,child,weight;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
void DJS1(int xx)
{
    for(int i=0; i<=n; i++)
    {
        dis[i]=0;
        vis[i]=0;
    }
    dis[xx]=0;
    priority_queue<pair<int,int>>pq;
    pq.push({0,0});
    while(!pq.empty())
    {
        parent=pq.top().ss;
        pq.pop();
        vis[parent]=1;
        for(int i=0; i<graph[parent].size(); i++)
        {
            child=graph[parent][i].ff,weight=graph[parent][i].ss;
            if(!vis[child] && dis[child]<weight)
            {
                dis[child]=weight;
                pq.push({dis[child],child});
            }
        }
    }
    for(int i=0; i<=n; i++)sum1+=dis[i];

}
void DJS2(int xx)
{
    for(int i=0; i<=n; i++)
    {
        dis[i]=INT_MAX;
        vis[i]=0;
    }
    dis[xx]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,0});
    while(!pq.empty())
    {
        parent=pq.top().ss;
        pq.pop();
        vis[parent]=1;
        for(int i=0; i<graph[parent].size(); i++)
        {
            child=graph[parent][i].ff,weight=graph[parent][i].ss;
            if(!vis[child] && dis[child]>weight)
            {
                dis[child]=weight;
                pq.push({dis[child],child});
            }
        }
    }
    for(int i=0; i<=n; i++)sum2+=dis[i];

}
int main()
{

    fast;
    int TC,no=1;
    cin>>TC;
    while(TC--)
    {
        cin>>n;
        while(1)
        {
            cin>>a>>b>>w;
            if(!a && !b && !w)break;
            graph[a].push_back({b,w});
            graph[b].push_back({a,w});
        }
        DJS1(0);
        DJS2(0);
        if((sum1+sum2)%2==0)printf("Case %d: %d\n",no++,(sum1+sum2)/2);
        else printf("Case %d: %d/2\n",no++,(sum1+sum2));
        sum1=0,sum2=0;
        for(int i=0; i<=n; i++)graph[i].clear();
    }
    return 0;
}


//    ***********    THE END  ***********



