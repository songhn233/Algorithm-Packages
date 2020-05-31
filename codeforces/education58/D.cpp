// unfinished
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#include<bitset>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define mst(a,b) memset((a),(b),sizeof(a))
#define PII pair<int,int>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
template<class T>inline void rd(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=200010;
int n,a[maxn],d[maxn];
vector<int> e[maxn];
bitset<maxn>b[maxn];
void dfs(int u,int fa)
{
    d[u]=d[fa]+1;
    for(int i=0;i<e[u].size();i++)
    {
        int v=e[u][i];
        if(v==fa) continue;
        b[v]=(b[u]&b[v]);
        dfs(v,u);
    }
}
int main()
{
    cin>>n;
    rep(i,1,n) 
    {
        rd(a[i]);
        int t=a[i];
        for(int j=2;j<=t/j;j++)
        {
            if(t%j==0)
            {
                while(t%j==0) t/=j;
                b[i][j]=1;
            }
        }
        if(t>1) b[i][t]=1;
    }
    rep(i,1,n-1)
    {
        int x,y;rd(x),rd(y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1,0);
    return 0;
}