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
int T;
int n,k,a[maxn];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>k;
        int flag=0;
        rep(i,1,n) 
        {
            rd(a[i]);
            if(a[i]==k) flag=1;
        }
        if(!flag) puts("no");
        else
        {
            if(n==1) puts("yes");
            else
            {
                for(int i=1;i<=n-1;i++)
                {
                    if(a[i]>=k&&a[i+1]>=k) flag=0;
                }
                for(int i=1;i<=n-2;i++)
                {
                    if(a[i]>=k&&a[i+2]>=k) flag=0;
                }
                if(!flag) puts("yes");
                else puts("no");
            }
        }
        
    }
    return 0;
}