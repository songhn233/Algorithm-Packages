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
const int maxn=100050;
int T,n;
ll a[maxn],t[40];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        rep(i,1,n) 
        {
            rd(a[i]);
        }
        ll ans=-1;
        if(n==1) puts("0");
        else
        {
            rep(i,2,n)
            {
                if(a[i]<a[i-1])
                {
                    ll temp=a[i-1]-a[i];
                    mst(t,40);
                    for(ll j=0;j<=30;j++) if(temp>>j&1) t[j]=1;
                    for(ll j=30;j>=0;j--)
                    {
                        if(t[j]==1)
                        {
                            ans=max(ans,j);
                            break;
                        }
                    }
                    a[i]+=temp;
                }
                
            }
            cout<<ans+1<<endl;
        }
        
        
    }
    return 0;
}