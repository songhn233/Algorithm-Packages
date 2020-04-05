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
struct node{
    int l,r,id;
    bool operator<(const node&t) const{
        return l<t.l;
    }
}a[maxn];
int T,n;
struct edge{
    int val,id;
    bool operator<(const edge&t) const{
        return id<t.id;
    }
}ans[maxn];
int main()
{
    cin>>T;
    for(int tim=1;tim<=T;tim++)
    {
        cin>>n;
        mst(ans,0);
        rep(i,1,n)
        {
            int x,y;rd(x),rd(y);
            a[i]={x,y,i};
        }
        sort(a+1,a+n+1);
        int t1,t2;t1=t2=0;
        int flag=1;
        rep(i,1,n)
        {
            if(a[i].l>=t1)
            {
                ans[i].val=0;
                ans[i].id=a[i].id;
                t1=a[i].r;
            }
            else if(a[i].l>=t2)
            {
                ans[i].val=1;
                ans[i].id=a[i].id;
                t2=a[i].r;
            }
            else
            {
                flag=0;
                break;
            }
        }
        printf("Case #%d: ",tim);
        sort(ans+1,ans+n+1);
        if(flag)
        {
            rep(i,1,n) 
            {
                if(ans[i].val) cout<<"C";
                else cout<<"J";
            }
            cout<<endl;
        }
        else puts("IMPOSSIBLE");
    }
    return 0;
}