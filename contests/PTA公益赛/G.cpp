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
ll k,n;
ll ksm(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1) res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}
vector<int>p;
int main()
{
    cin>>n>>k;
    ll res=1,cnt=0;
    ll base=ksm(10,k+1);
    for(ll i=1;i<=n;i++)
    {
        res=res*i;
        while(res%10==0) res/=10,cnt++;
        res%=base;
    }
    ll t=res%ksm(10,k);
    while(t) p.push_back(t%10),t/=10;
    if(p.size()<k) 
    {
        int num=k-(int)p.size();
        for(int i=1;i<=num;i++) cout<<"0";
    }
    for(int i=(int)p.size()-1;i>=0;i--) cout<<p[i];
    cout<<" "<<cnt<<endl;
    return 0;
}