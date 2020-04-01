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
int T;
ll a,b,c,d;
ll x,y,x1,y1,x2,y2;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>a>>b>>c>>d;
        cin>>x>>y>>x1>>y1>>x2>>y2;
        ll xx=b-a,yy=c-d;
        if((x==x1)&&(x==x2)&&(a!=0||b!=0))
        {
            puts("No");
        }
        else if((y==y1)&&(y==y2)&&(c!=0||d!=0))
        {
            puts("No");
        }
        else
        {
            if(x+xx<=x2&&x+xx>=x1&&y+yy<=y2&&y+yy>=y1)
            {
                puts("Yes");
            }
            else puts("No");
        }
        
    }
    return 0;
}