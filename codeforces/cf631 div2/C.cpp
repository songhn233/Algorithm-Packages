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
struct node{
    int val,id;
    bool operator<(const node&t) const{
        return val>t.val;
    }
}a[maxn];
ll n,m,sum,s[maxn],ans[maxn];
int main()
{
    cin>>n>>m;
    rep(i,1,m) rd(a[i].val),sum+=a[i].val,s[i]=s[i-1]+a[i].val,a[i].id=i;
    if(sum<n)
    {
        puts("-1");
    }
    else
    {
        int flag=0;
        for(int i=1;i<=m;i++)
        {
            if(i+a[i].val-1>n)
            {
                flag=1;
                break;
            }
        }
        if(flag)
        {
            puts("-1");
        }
        else
        {
            rep(i,1,m)
            {
                ans[a[i].id]=i;
            }
            if(m+a[m].val-1==n)
            {
                rep(i,1,m) cout<<ans[i]<<" ";
                cout<<endl;
            }
            else
            {
                ans[a[m].id]=n-a[m].val+1;
                int last=n-a[m].val;
                dep(i,m-1,1)
                {
                    if(last>i+a[i].val-1)
                    {
                        ans[a[i].id]=last-a[i].val+1;
                        last=last-a[i].val;
                    }
                    else break;
                }
                rep(i,1,m) cout<<ans[i]<<" ";
                cout<<endl;
            }
        }
    }
    return 0;
}