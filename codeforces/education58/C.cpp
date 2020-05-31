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
int T,n;
struct node{
    int id,l,r,ans;
    bool operator<(const node &t) const{
        if(l==t.l) return r<t.r;
        return l<t.l;
    }
}a[maxn];
bool cmp(node &a,node &b)
{
    return a.id<b.id;
}
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        rep(i,1,n)
        {
            rd(a[i].l),rd(a[i].r);
            a[i].id=i;
        }
        sort(a+1,a+n+1);
        int r=a[1].r;
        a[1].ans=1;
        int p=0;
        for(int i=2;i<=n;i++)
        {
            if(a[i].l<=r) 
            {
                r=max(r,a[i].r);
                a[i].ans=1;
            }
            else {p=i;break;}
        }
        if(p==0) puts("-1");
        else
        {
            for(int i=p;i<=n;i++) a[i].ans=2;
            sort(a+1,a+n+1,cmp);
            for(int i=1;i<=n;i++) cout<<a[i].ans<<" ";
            cout<<endl;
        }
        
    }
    return 0;
}