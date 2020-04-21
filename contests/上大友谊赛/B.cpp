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
const int maxn=250;
const double eps=1e-6;
struct node{
    int d,id;
    double t;
    bool operator<(const node&p) const{
        if(d!=p.d) return d>p.d;
        if(t!=p.t) return t>p.t;
        if(id!=p.id) return id<p.id;
    }
}a[maxn],b[maxn];
int n,num;
int main()
{
    cin>>n;
    rep(i,1,n)
    {
        cin>>a[i].d>>a[i].id>>a[i].t;
    }
    rep(i,1,n)
    {
        if(a[i].t<38.0) continue;
        b[++num]=a[i];
    }
    sort(b+1,b+num+1);
    cout<<num<<endl;
    rep(i,1,num)
    {
        cout<<b[i].d<<" "<<b[i].id<<" ";
        printf("%.1lf\n",b[i].t);
    }
    return 0;
}