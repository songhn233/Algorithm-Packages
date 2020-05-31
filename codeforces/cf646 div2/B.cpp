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
int T,n,t;
char s[maxn];
int s1[maxn],s2[maxn];
int main()
{
    cin>>T;
    while(T--)
    {
        scanf("%s",s+1);n=strlen(s+1);
        s1[0]=0;t=0;
        for(int i=1;i<=n;i++)
        {
            s1[i]=s1[i-1]+s[i]-'0';
            if(s[i]=='1') t++;
        }
        int ans=inf;
        for(int i=1;i<=n;i++)
        {
            ans=min(ans,i-s1[i]+(t-s1[i]));
            ans=min(ans,s1[i]+(n-i)-(t-s1[i]));
        }
        ans=min(ans,s1[n]);
        ans=min(ans,n-s1[n]);
        cout<<ans<<endl;
    }
    return 0;
}