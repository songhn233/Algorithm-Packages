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
int T,n;
ll a[maxn],t[maxn];
int ans[maxn],top;
int main()
{
    cin>>T;
    while(T--)
    {
        top=0;
        rd(n);
        rep(i,1,n) rd(a[i]);
        rep(i,2,n) t[i]=a[i]-a[i-1];
        int flag=0;
        rep(i,2,n)
        {
            if(flag>0&&t[i]>0) continue;
            if(flag<0&&t[i]<0) continue;
            flag=t[i];
            ans[++top]=i-1;
        }
        if(ans[top]!=n) ans[++top]=n;
        printf("%d\n",top);
        rep(i,1,top) printf("%d ",a[ans[i]]);
        cout<<endl;
    }
    return 0;
}