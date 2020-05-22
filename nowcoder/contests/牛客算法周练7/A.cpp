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
int n,vis[25],a[25],x[25],y[25];
int T,sx,sy,ans,p1,p2;
void dfs(int d)
{
	if(d==n+1)
	{
        int res=0;
        int prex=sx,prey=sy;
		for(int i=1;i<=n;i++) 
        {
            res+=abs(prex-x[a[i]])+abs(prey-y[a[i]]);
            prex=x[a[i]];prey=y[a[i]];
        }
        res+=abs(prex-sx)+abs(prey-sy);
        ans=min(ans,res);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			a[d]=i;
			dfs(d+1);
			vis[i]=0;
			a[d]=0;
		}
	}
}
int main()
{
    cin>>T;
    while(T--)
    {
        ans=inf;
        mst(vis,0);
        cin>>p1>>p2;
        cin>>sx>>sy;
        cin>>n;
        rep(i,1,n) cin>>x[i]>>y[i];
	    dfs(1);
        cout<<"The shortest path has length "<<ans<<endl;
    }
	
	return 0;
}