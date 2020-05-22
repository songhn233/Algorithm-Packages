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
double cnt1,cnt2;
double n1,n2;
int main()
{
    cin>>n;
    rep(i,1,n)
    {
        int x,y;
        cin>>x>>y;
        if(x==1)
        {
            cnt1++;
            n1+=y;
        }
        else
        {
            cnt2++;
            n2+=y;
        }
    }
    double ans=(n1+n2)/(cnt1+cnt2);
    printf("%.1lf ",ans);
    if(cnt1==0) printf("X ");
    else printf("%.1lf ",(n1)/(cnt1));
    if(cnt2==0) printf("X ");
    else printf("%.1lf ",(n2)/(cnt2));
    return 0;
}