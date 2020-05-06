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
const int maxn=1000010;
bitset<maxn> mp,temp;
int n;
int l[maxn],r[maxn];
int main()
{
    cin>>n;
    rep(i,1,n) rd(l[i]),rd(r[i]);
    for(int i=l[1];i<=r[1];i++) mp[i*i]=1;
    rep(i,2,n)
    {
       temp.reset();
       rep(j,l[i],r[i]) temp|=mp<<(j*j);
       mp=temp;
    }
    cout<<mp.count()<<endl;
    return 0;
}