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
const int maxn=150;
struct node{
    int b,c;
}a[maxn];
int T,n;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        int flag=0;
        rep(i,1,n) 
        {
            rd(a[i].b),rd(a[i].c);
            if(a[i].c>a[i].b)
            {
                flag=1;
            }
        }
        if(flag) puts("NO");
        else
        {
            int flag=0;
            rep(i,2,n)
            {
                if(a[i].c-a[i-1].c>a[i].b-a[i-1].b) flag=1;
                else if(a[i].b<a[i-1].b||a[i].c<a[i-1].c) flag=1;
                else continue;
            }
            if(flag) puts("NO");
            else puts("YES");
        }
    }
    return 0;
}