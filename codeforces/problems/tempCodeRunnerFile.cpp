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
int n,k;
map<int,bool>mp;
int main()
{
    cin>>n>>k;
    int m=n/2;
    int t=k-(m-1);
    if(t<=0)
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
    cout<<t<<" "<<2*t<<" ";
    for(int i=1;i<=m-1;i++)
    {
        int pos=i;
        while(mp[pos]||mp[pos+1]) pos++;
        while(pos==t||pos==2*t||pos+1==t||pos+1==2*t) pos++;
        cout<<pos<<" "<<pos+1<<" ";
    }
    if(n&1) cout<<1000000000<<endl;
    else cout<<endl;
    return 0;
}