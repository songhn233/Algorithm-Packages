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
const int maxn=200050;
int T,n,ans;
string s;
int c[maxn][3],p[maxn];
bool calc(int mid,int t)
{
    int t1=c[t][0]-c[mid][0];
    int t2=c[t][1]-c[mid][1];
    int t3=c[t][2]-c[mid][2];
    if(t1>=1&&t2>=1&&t3>=1) return true;
    return false;
}
int main()
{
    cin>>T;
    while(T--)
    {
        ans=inf;
        cin>>s;n=s.size();
        c[0][0]=c[0][1]=c[0][2]=0;
        for(int i=1;i<=n;i++)
        {
            c[i][0]=c[i-1][0];
            c[i][1]=c[i-1][1];
            c[i][2]=c[i-1][2];
            c[i][s[i-1]-'0'-1]++;
        }
        for(int i=1;i<=n;i++)
        {
            int l=0,r=i;
            while(l<r)
            {
                int mid=l+r+1>>1;
                if(calc(mid,i)) l=mid;
                else r=mid-1;
            }
            if(calc(l,i)) 
            {
                ans=min(ans,i-l);
            }
        }
        if(ans==inf) puts("0");
        else cout<<ans<<endl;
    }
    return 0;
}