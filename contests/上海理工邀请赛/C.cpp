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
map<string,bool> mp;
int n,m,num;
string a[1050];
bool cmp(string &a,string &b)
{
    return (int)a.size()<(int)b.size();
}
int main()
{
    cin>>n>>m;
    rep(i,1,m)
    {
        string s;cin>>s;
        mp[s]=true;
    }
    for(auto x:mp) a[++num]=x.first;
    sort(a+1,a+num+1,cmp);
    int t=0,ans=0;
    for(int i=1;i<=num;i++)
    {
        t+=a[i].size();
        if(t<=n) ans++;
        t++;
    }
    cout<<ans<<endl;
    return 0;
}