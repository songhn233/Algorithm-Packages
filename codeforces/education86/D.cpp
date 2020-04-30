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
int n,k;
int a[maxn],c[maxn];
int num;
vector<int> ans[maxn];
int main()
{
    cin>>n>>k;
    rep(i,1,n) rd(a[i]);
    rep(i,1,k) rd(c[i]);
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        int l=1,r=num;
        while(l<r)
        {
            int mid=l+r>>1;
            if((int)ans[mid].size()+1<=c[a[i]]) r=mid;
            else l=mid+1;
        }
        if(l<=num&&l>=1&&((int)ans[l].size()+1<=c[a[i]])) ans[l].push_back(a[i]);
        else ans[++num].push_back(a[i]);
    }
    printf("%d\n",num);
    for(int i=1;i<=num;i++)
    {
        printf("%d ",ans[i].size());
        for(int j=0;j<ans[i].size();j++) printf("%d ",ans[i][j]);
        printf("\n");
    }
    return 0;
}