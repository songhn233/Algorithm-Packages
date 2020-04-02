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
int n,a,b;
int p[maxn];
map<int,int> mp;
int fa[maxn];
int get(int x){if(x!=fa[x]) fa[x]=get(fa[x]); return fa[x];}
void merge(int x,int y)
{
    x=get(x),y=get(y);
    if(x==y) return;
    fa[x]=y;
}
int main()
{
    cin>>n>>a>>b;
    rep(i,1,n+2) fa[i]=i;
    rep(i,1,n) rd(p[i]),mp[p[i]]=i;
    int A=n+1,B=n+2;
    rep(i,1,n)
    {
        if(mp[a-p[i]]) merge(i,mp[a-p[i]]);
        else merge(i,B);

        if(mp[b-p[i]]) merge(i,mp[b-p[i]]);
        else merge(i,A);
    }
    if(get(A)==get(B)) puts("NO");
    else
    {
        puts("YES");
        rep(i,1,n)
        {
            if(get(i)==get(A)) printf("0 ");
            else printf("1 ");
        }
        cout<<endl;
    }
    
    return 0;
}