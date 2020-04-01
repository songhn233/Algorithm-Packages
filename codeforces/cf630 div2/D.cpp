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
int k;
int main()
{
    cin>>k;
    puts("3 3");
    int cnt=-1;
    dep(i,30,0)
    {
        if(k>>i&1)
        {
            cnt=i;
            break;
        }
    }
    if(cnt==-1)
    {
        puts("1 1");
        puts("1");
    }
    else
    {
        puts("3 3");
        cout<<((1<<(cnt+2))-1)<<" "<<((1<<(cnt+2))-1)<<" "<<(1<<(cnt+1))<<endl;
        cout<<((1<<(cnt+2))-1)<<" "<<k<<" "<<((1<<(cnt+2))-1)<<endl;
        cout<<(1<<(cnt+1))<<" "<<((1<<(cnt+2))-1)<<" "<<k<<endl;
    }
    
    return 0;
}