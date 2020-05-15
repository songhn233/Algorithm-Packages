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
const int maxn=1000050;
int T,n,k;
string s;
int f[maxn][2];
int sum[maxn];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>k;
        cin>>s;
        if(n==1) {puts("0");continue;}
        for(int i=0;i<s.size();i++) sum[i+1]=sum[i]+s[i]-'0';
        for(int i=1;i<=n;i++) f[i][0]=f[i][1]=inf;
        f[0][0]=0;
        for(int i=1;i<=n;i++)
        {
            f[i][0]=min(f[i][0],min(f[i-1][0],f[i-1][1])+(s[i-1]=='1'?1:0));
            if(i-k>=1) f[i][1]=min(f[i][1],min(f[i-k][1]+sum[i-1]-sum[i-k],sum[i-1])+(s[i-1]=='1'?0:1));
            else f[i][1]=min(f[i][1],sum[i-1]+(s[i-1]=='1'?0:1));
        }
        cout<<min(f[n][0],f[n][1])<<endl;
    }
    return 0;
}