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
ll T,n;
ll c[150],num;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;num=0;
        ll temp=1,sum=1;
        c[++num]=1;
        while(sum<=n) 
        {
            temp<<=1,sum+=temp;
            c[++num]=temp;
        }
        sum-=temp;
        num--;
        temp>>=1;
        ll rest=n-sum;
        if(rest) c[++num]=rest;
        sort(c+1,c+num+1);
        cout<<num-1<<endl;
        for(int i=2;i<=num;i++) printf("%lld ",c[i]-c[i-1]);
        cout<<endl;
    }
    return 0;
}