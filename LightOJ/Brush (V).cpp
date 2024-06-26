// hi!thanks for watching my code :)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ff first
#define ss second
const int SIZE=1e5+9;

ll maax(ll num1,ll num2,ll num3)
{
    if(num1>=num2)num2=num1;
    if(num2>=num3)num3=num2;
    return num3;
}
ll miin(ll num1,ll num2,ll num3)
{
    if(num1<=num2)num2=num1;
    if(num2<=num3)num3=num2;
    return num3;
}
ll GCD(ll a, ll b)
{

    if(b == 0)
        return a;
    else
        return GCD(b, a % b);
}
ll MOD(ll num1,ll num2)
{
    ll Ans;
    Ans= (num1-((num1/num2)*num2));
    return Ans;
}
ll power (ll num,ll poww)
{
    ll anss=1;
    for(ll i=0; i<poww; i++)
    {
        anss*=num;
    }
    return anss;
}
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
int n,m,w,a,b;
vector<pair<int,int>>g[109];
int vis[109],dis[109];
void DJS(int xx)
{
    for(int i=1; i<=n; i++)
    {
        dis[i]=INT_MAX/1000;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    dis[xx]=0,pq.push({0,xx});
    while(!pq.empty())
    {
        int u=pq.top().ss;
        pq.pop();
        if(!vis[u])
        {
            for(int i=0; i<g[u].size(); i++)
            {
                int child=g[u][i].ff,weight=g[u][i].ss;
                if(dis[u]+weight<dis[child])
                {
                    dis[child]=dis[u]+weight;
                    pq.push({dis[child],child});
                }
            }
            vis[u]=1;
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
        DJS(1);
        for(int i=1; i<=n; i++)
        {
            g[i].clear();
        }
        if(dis[n]==INT_MAX/1000)printf("Case %d: Impossible\n",no++);
        else printf("Case %d: %d\n",no++,dis[n]);
        memset(vis,0,sizeof vis);
        memset(dis,0,sizeof dis);
    }
    return 0;
}


//    ***********    THE END  ***********


