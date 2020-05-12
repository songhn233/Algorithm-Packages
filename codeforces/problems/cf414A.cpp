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
const int N=2e8+1;
int n,k;
int main()
{
    cin>>n>>k;
    int m=n/2;
    if(m>k)
    {
        puts("-1");
        return 0;
    }
    if(n==1)
    {
        if(k==0) puts("1");
        else puts("-1");
        return 0;
    }
    int t=k-(m-1);
    cout<<t<<" "<<2*t<<" ";
    for(int i=3;i<=n;i++)
    {
        cout<<2*t+i<<" ";
    }
    cout<<endl;
    return 0;
}