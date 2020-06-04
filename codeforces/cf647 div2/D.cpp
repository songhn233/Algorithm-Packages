#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#include<bitset>
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
const int maxn=500010;
int n,m;
vector<int> e[maxn];
int t[maxn];
struct node{
    int id,val;
    bool operator<(const node&t){
        if(val==t.val) return id<t.id;
        else return val<t.val;
    }
}a[maxn];
int main()
{
    cin>>n>>m;
    rep(i,1,m)
    {
        int x,y;rd(x),rd(y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    int flag=1;
    rep(i,1,n) 
    {
        rd(a[i].val);
        a[i].id=i;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        if(t[a[i].id]!=a[i].val-1) {flag=0;break;}
        for(int j=0;j<e[a[i].id].size();j++)
        {
            int v=e[a[i].id][j];
            if(t[v]==t[a[i].id]) t[v]++;
        }
    }
    if(!flag) puts("-1");
    else
    {
        for(int i=1;i<=n;i++) printf("%d ",a[i].id);
        printf("\n");
    } 
    return 0;
}