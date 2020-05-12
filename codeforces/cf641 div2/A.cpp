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
ll T,n,k;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>k;
        int temp=0;
        for(int i=2;i<=n/i;i++)
        {
            if(n%i==0)
            {
                temp=i;
                break;
            }
        }
        if(temp==0) 
        {
            ll ans=n*2;
            k--;
            ans+=k*2;
            cout<<ans<<endl;
        }
        else
        {
            ll ans=n+temp;
            k--;
            ans+=k*2;
            cout<<ans<<endl;
        }
        
    }
    return 0;
}