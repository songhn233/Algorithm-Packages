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
const int maxn=20050;
int T,n,m,k;
int head[maxn],num,vis[maxn],match[maxn];
int pan[maxn];
vector<PII> a[maxn];
struct node{
    int v,nex;
}e[maxn];
void add(int u,int v)
{
    e[++num].nex=head[u];
    e[num].v=v;
    head[u]=num;
}
bool dfs(int u)
{
	for(int i=head[u];i;i=e[i].nex)
	{
		int v=e[i].v;
		if(!vis[v])
		{
			vis[v]=1;
			if(!match[v]||dfs(match[v]))
			{
				match[v]=u;
				return true;
			}
		}
	}
	return false;
}
int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        if(!n&&!k) break;
        memset(pan,0,sizeof(pan));
        for(int i=1;i<=50;i++) a[i].clear();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int x;read(x);
                pan[x]=1;
                a[x].push_back(make_pair(i,j));
            }
        }
        int flag=0;
        for(int t=1;t<=50;t++)
        {
            if(!pan[t]) continue;
            int ans=0;
            memset(head,0,sizeof(head));num=0;
            memset(match,0,sizeof(match));
            for(int i=0;i<a[t].size();i++)
            {
                add(a[t][i].first,n+a[t][i].second);
            }
            for(int i=1;i<=n;i++)
            {
                memset(vis,0,sizeof(vis));
                if(dfs(i)) ans++;
            }
            if(ans>k)
            {
                if(!flag) 
                {
                    cout<<t;
                    flag=1;
                }
                else cout<<" "<<t;
            }
        }
        if(flag) cout<<endl;
        else puts("-1");
    }
    return 0;
}
