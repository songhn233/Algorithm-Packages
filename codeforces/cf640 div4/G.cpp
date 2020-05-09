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
int T,n;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        if(n==2||n==3) puts("-1");
        else if(n==4) puts("3 1 4 2");
        else if(n==5) puts("5 3 1 4 2");
        else
        {
            int t=n;
            if(t%2==0) t--;
            for(int i=t;i>=1;i-=2) cout<<i<<" ";
            cout<<4<<" "<<2<<" "<<6<<" ";
            for(int i=8;i<=n;i+=2) cout<<i<<" ";
            cout<<endl;
        }
    }
    return 0;
}