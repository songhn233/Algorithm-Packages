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
const int maxn=600005;
const int mod=10000;
string s;
ll sta[maxn];
int top,pp;
ll getnum(int pos)
{
    ll res=0;
    int flag=0;
    for(int i=pos;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9') res=res*10+(s[i]-'0');
        else
        {
            pp=i;
            flag=1;
            break;
        }
    }
    if(!flag) pp=s.size();
    return res;
}
int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='+') 
        {
            ll t=getnum(i+1);
            sta[++top]=t%mod;
            i=pp-1;
        }
        else if(s[i]=='*') 
        {
            ll t=getnum(i+1);
            sta[top]=(sta[top]*t)%mod;
            i=pp-1;
        }
        else
        {
            sta[++top]=getnum(i);
            i=pp-1;
        }
    }
    ll ans=0;
    rep(i,1,top) ans=(ans+sta[i])%mod;
    cout<<ans<<endl;
    return 0;
}