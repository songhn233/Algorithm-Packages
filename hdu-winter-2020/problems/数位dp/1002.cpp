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
ll n,f[15][15][2][15];
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
void init()
{
    for(ll i=0;i<=9;i++) f[1][i][0][i]=1;
    for(ll len=2;len<=9;len++)
    {
        for(ll i=0;i<=9;i++)
        {
            for(ll r=0;r<13;r++)
            {
                for(ll j=0;j<=9;j++)
                {
                    if(i==1&&j==3) 
                    {
                        f[len][i][1][(r+i*ksm(10,len-1))%13]+=f[len-1][j][0][r];
                        f[len][i][1][(r+i*ksm(10,len-1))%13]+=f[len-1][j][1][r];
                    }
                    else 
                    {
                        f[len][i][0][(r+i*ksm(10,len-1))%13]+=f[len-1][j][0][r];
                        f[len][i][1][(r+i*ksm(10,len-1))%13]+=f[len-1][j][1][r];
                    }
                }
            }
        }
    }
}
ll calc(ll n)
{
    vector<ll> nums;nums.clear();
    while(n) nums.push_back(n%10),n/=10;
    ll ans=0;
    ll f1,f2,last;
    f1=f2=last=0;
    for(ll i=(ll)nums.size()-1;i>=0;i--)
    {
        ll x=nums[i];
        ll len=i+1;
        for(ll j=1;j<x;j++) 
        {
            ans+=f[len][j][1][((13-f2*ksm(10,len))%13+13)%13];
            if(last==1&&j==3&&f1==0) ans+=f[len][j][0][((13-f2*ksm(10,len))%13+13)%13];
        }
        if(f1)
        {
            for(ll j=1;j<x;j++) ans+=f[len][j][0][((13-f2*ksm(10,len))%13+13)%13];
        }
        if(i!=(ll)nums.size()-1)
        {
            for(ll j=1;j<=9;j++) ans+=f[len][j][1][0];
        }
        if(i!=(ll)nums.size()-1&&nums[i]==3&&nums[i+1]==1) f1=1;
        f2=(f2*10+x)%13;
        if((!i)&&f1&&(!f2)) ans++;
        last=x;
    }
    return ans;
}
int main()
{
    init();
    while(cin>>n)
    {
        if(n==1000000000) n--;
        cout<<calc(n)<<endl;
    }
    return 0;
}
// TODO