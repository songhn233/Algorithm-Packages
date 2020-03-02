#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define mst(a,b) memset((a),(b),sizeof(a))
#define PII pair<int,int>
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=100050;
int n,m,k;
vector<int> e[maxn];
map<PII,bool> mp;
void add(int u,int v){
	e[u].push_back(v);
}
int dis[maxn],vis[maxn];
int dij(int s,int t)
{
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    priority_queue<PII,vector<PII>,greater<PII> > q;
    dis[s]=0;
    q.push(make_pair(0,s));
    while(!q.empty())
    {
        int u=q.top().second;q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=0;i<e[u].size();i++)
        {
            int v=e[u][i];
            if(mp[make_pair(v,u)]) continue;
            if(dis[v]>dis[u]+1)
            {
                dis[v]=dis[u]+1;
                q.push(make_pair(dis[v],v));
            }
        }
    }
    return dis[t];
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) add(i,i/2),add(i/2,i);
	while(m--)
	{
		char opt[5];int t;
		cin>>opt;
		if(opt[0]=='-')
		{
			read(t);
			mp[make_pair(t,t/2)]=mp[make_pair(t/2,t)]=true;
		}
		else
		{
			read(k);
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(dij(i,j)<=k) ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

