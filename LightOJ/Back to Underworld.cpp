// hi!thanks for watching my code :)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ff first
#define ss second
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
vector<int>v[100005];
int vis[100005],Vampires,Lykans;
void BFS(int xx)
{
    queue<int>q;
    q.push(xx);
    vis[xx]=1;
    Vampires++;
    while(!q.empty())
    {
        int parent=q.front();
        q.pop();
        for(int i=0;i<v[parent].size();i++)
        {
            int child=v[parent][i];
            if(!vis[child])
            {
                q.push(child);
                if(vis[parent]==1)
                {
                    vis[child]=2;
                    Lykans++;
                }
                else
                {
                    vis[child]=1;
                    Vampires++;
                }
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
        int n,u,vv,ans=0;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>u>>vv;
            v[u].push_back(u);
            v[vv].push_back(vv);
        }
        for(int i=1; i<=n; i++)
        {
            Vampires=0,Lykans=0;
            if(!vis[i] && v[i].size()>0)
            {
                BFS(i);
            }
          //  cout<<Vampires<<" "<<Lykans<<endl;
            ans+=max(Vampires,Lykans);
        }
        printf("Case %d: %d\n",no++,ans);
        memset(v,0,sizeof v);
        memset(vis,0,sizeof vis);
    }
    return 0;
}


//    ***********    THE END  ***********


