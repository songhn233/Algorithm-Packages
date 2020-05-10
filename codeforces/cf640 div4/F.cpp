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
const int maxn=505;
int T,a,b,c;
int t[maxn];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>a>>b>>c;
        if(b==0)
        {
            if(c>0) for(int i=1;i<=c+1;i++) printf("1");
            if(a>0) for(int i=1;i<=a+1;i++) printf("0");
            cout<<endl;
            continue;
        } 
        for(int i=1;i<=c+1;i++) printf("1");
        for(int i=1;i<=a+1;i++) printf("0");
        for(int i=1;i<=b-1;i++) 
        {
            if(i&1) printf("1");
            else printf("0");
        }
        cout<<endl; 
    }
    return 0;
}