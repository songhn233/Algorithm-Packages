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
int T,n,a[maxn];
map<int,int> vis;
int ans[maxn],num;
void calc(int n,int id)
{
    int flag=0;
    for(int i=2;i<=n/i;i++)
    {
        if(n%i==0)
        {
            flag=1;
            if(vis[i])
            {
                ans[id]=vis[i];
                break;
            }
            else
            {
                vis[i]=++num;
                ans[id]=vis[i];
                break;
            }
            
        }
    }
    if(!flag)
    {
        num++;
        ans[id]=num;
        vis[n]=num;
    }
}
int main()
{
    cin>>T;
    while(T--)
    {
        
        cin>>n;
        vis.clear();
        rep(i,1,n) rd(a[i]);
        rep(i,1,n) ans[i]=0;
        num=0;
        int t=n;
        for(int i=1;i<=n;i++)
        {
            calc(a[i],i);
        }
        cout<<num<<endl;
        for(int i=1;i<=n;i++) printf("%d ",ans[i]);
        cout<<endl;
    }
    return 0;
}