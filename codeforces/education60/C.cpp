#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define int long long
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
int x1,y1,x2,y2,n;
int p1,p2;
string s,t;
bool calc(int mid)
{
    int t=mid/n;
    int x,y;x=x1,y=y1;
    x1+=t*p1,y1+=t*p2;
    int temp=abs(x1-x2)+abs(y1-y2);
    if(temp<=mid) return true;
    return false;
}
signed main()
{
    cin>>x1>>y1>>x2>>y2>>n;
    cin>>t;
    for(int i=0;i<t.size();i++)
    {
        if(t[i]=='U') p2++;
        if(t[i]=='D') p2--;
        if(t[i]=='L') p1--;
        if(t[i]=='R') p1++;
    }
    if(x1==x2&&y1==y2) 
    {
        puts("0");
        return 0;
    }
    int l=1,r=2e9;
    while(l<r)
    {
        int mid=l+r>>1;
        if(calc(mid)) r=mid;
        else l=mid+1;
    }
    if(!calc(l)) puts("-1");
    else cout<<l<<endl;
    return 0;
}