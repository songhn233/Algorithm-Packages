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
const int maxn=1050;
int T,n,x,siz[maxn],d[maxn];
vector<int> e[maxn];
void dfs(int u,int fa)
{
    siz[u]=1;
    d[u]=d[fa]+1;
    for(int i=0;i<e[u].size();i++)
    {
        int v=e[u][i];
        if(v==fa) continue;
        dfs(v,u);
        siz[u]+=siz[v];
    }
}
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>x;
        rep(i,1,n) e[i].clear();
        rep(i,1,n-1)
        {
            int u,v;
            rd(u),rd(v);
            e[u].push_back(v);
            e[v].push_back(u);  
        }
        if(n==1)
        {
            puts("Ayush");
            continue;
        }
        d[0]=0;
        dfs(x,0);
        int temp=0;
        for(int i=0;i<e[x].size();i++)
        {
            int v=e[x][i];
            temp+=siz[v];
        }
        temp--;
        if(e[x].size()==1) puts("Ayush");
        else
        {
            if(temp&1) puts("Ashish");
            else puts("Ayush");
        }  
    }
    return 0;
}