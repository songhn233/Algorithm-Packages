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
const ll N=1000000000;
int T;
ll n;
ll f[maxn];
int num=0;
int main()
{
    cin>>T;
    f[0]=0;
    for(int i=1;;i++)
    {
        f[i]=f[i-1]+3*i-1;
        if(f[i]>N) 
        {
            num=i;
            break;
        }
    }
    while(T--)
    {
        cin>>n;
        int ans=0;
        while(n>=2)
        {
            ll temp=upper_bound(f+1,f+num+1,n)-f;
            temp--;
            n-=f[temp];
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}