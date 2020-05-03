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
int T,n,k;
int a[maxn];
string s,t;
int main()
{
    cin>>T;
    while(T--)
    {
        rd(n),rd(k);
        cin>>s;
        rep(i,0,n-1) a[i]=s[i]-'a';
        sort(a,a+n);
        if(a[k-1]!=a[0]) cout<<char('a'+a[k-1])<<endl;
        else 
        {
            int flag=0;
            for(int i=k+1;i<n;i++) if(a[i]!=a[i-1]) {flag=1;break;}
            if(flag)
            {
                string ans="";
                ans+=char('a'+a[0]);
                for(int i=k;i<n;i++) ans+=char('a'+a[i]);
                cout<<ans<<endl;
            }
            else 
            {
                int cnt=(n-1)/k;
                string ans="";
                ans+=char('a'+a[0]);
                for(int i=1;i<=cnt;i++) ans+=char('a'+a[k]);
                cout<<ans<<endl;
            }
        } 
    }
    return 0;
}