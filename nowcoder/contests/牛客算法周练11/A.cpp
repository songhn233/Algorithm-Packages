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
ll n,t;
ll a,b;
struct node
{
    ll a,b;
}c[maxn],t1[maxn],t2[maxn];
int n1,n2;
bool cmp1(node &p1,node &p2) {
    return p1.a<p2.a;
}
int main()
{
    cin>>n>>t;
    cin>>a>>b;
    rep(i,1,n) 
    {
        rd(c[i].a);rd(c[i].b);
    }
    rep(i,1,n)
    {
        if(c[i].b<a) t1[++n1]=c[i];
    }
    sort(t1+1,t1+n1+1,cmp1);
    ll sum=0,cnt1=0;
    rep(i,1,n1)
    {
        if(sum+t1[i].a<=t) sum+=t1[i].a,cnt1++;
    }
    cout<<cnt1<<" ";
    rep(i,1,n)
    {
        if(c[i].b<b) t2[++n2]=c[i];
        else {
            t2[++n2]=c[i];
            t2[n2].a=c[i].a*2;
        }
    }
    sort(t2+1,t2+n2+1,cmp1);
    sum=0,cnt1=0;
    rep(i,1,n2)
    {
        if(sum+t2[i].a<=t) sum+=t2[i].a,cnt1++;
    }
    cout<<cnt1<<endl;
    return 0;
}