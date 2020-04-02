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
const int maxn=5050;
int n,a[maxn],mp[maxn];
int f[maxn][maxn];
map<int,int> pp;
int main()
{
    cin>>n;
    rep(i,1,n) 
    {
        rd(a[i]);
        mp[a[i]]++;
    }
    ll ans=inf;
    for(int col=1;col<=5000;col++)
    {
        if(!mp[col]) continue;
        pp.clear();
        ll temp=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=col)
            {
                pp[a[i]]++;
            }
            else
            {
                temp+=(int)pp.size();
                pp.clear();
            }
        }
        if(pp.size()) temp+=(int)pp.size();
        ans=min(ans,temp);
    }
    
    cout<<ans<<endl;
    return 0;
}