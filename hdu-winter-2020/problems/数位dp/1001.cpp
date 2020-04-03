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
ll f[20][10];
void init()
{
    rep(i,0,9) f[1][i]=1;
    rep(i,2,19)
    {
        rep(j,0,9)
            rep(k,0,9)
            {
                if(j==4&&k==9) continue;
                f[i][j]+=f[i-1][k];
            }
    }
}
ll calc(ll n)
{
    ll ans=0;
    vector<int> nums;nums.clear();
    int flag=1;
    while(n) nums.push_back(n%10),n/=10;
    int last=0;
    for(int i=(int)nums.size()-1;i>=0;i--)
    {
        int x=nums[i];
        for(int j=0;j<=x-1;j++) ans+=f[i+1][j];
        if(last==4&&x==9) break;
        last=x;
        if(!i) ans++;
    }
    return ans;
}
int main()
{
    cin>>T;
    init();
    while(T--)
    {
        cin>>n;
        cout<<n+1-calc(n)<<endl;
    }
    return 0;
}