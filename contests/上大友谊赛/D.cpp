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
int n;
int main()
{
    cin>>n;
    if(n==1)
    {
        cout<<1<<endl<<1<<endl;
    }
    else if(n==2)
    {
        cout<<2<<endl<<0<<endl<<11<<endl;
    }
    else
    {
        cout<<n-1<<endl;
        rep(i,2,n)
        {
            cout<<0;
            rep(j,1,i-2) cout<<1;
             cout<<0<<endl;
        }
    }
    
    return 0;
}