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
const ll p=1e9+7;
const int maxn=100010;
int T;
string s;
vector<int> nums;
ll f[maxn];
ll ksm(ll a,ll b)
{
    if(b<0) return 0;
    ll res=1;
    while(b)
    {
        if(b&1) res=(res*a)%p;
        a=(a*a)%p;
        b>>=1;
    }
    return res;
}
void init()
{
    for(int i=0;i<=100000;i++) f[i]=ksm(10,i)%p;
}
ll pp(ll n)
{
    if(n<0) return 0;
    else return f[n];
}
ll calc(string s)
{
    nums.clear();
    int n=s.size();
    nums.push_back(0);
    for(int i=0;i<s.size();i++) nums.push_back(s[i]-'0');
    ll ans=0,flag=0;
    ans=(ans+(n-1)*pp(n-2)%p)%p;
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            ans=(ans+(nums[i]-1)%p*pp(n-i-1)*(n-i)%p)%p;
            if(nums[i]-1>=7) ans=(ans+pp(n-i))%p;
        }
        else
        {
            ans=(ans+(nums[i])%p*pp(n-i-1)*(n-i)%p)%p;
            if(nums[i]-1>=7) ans=(ans+pp(n-i))%p;
            ans=(ans+flag*nums[i]%p*pp(n-i)%p)%p;
        }
        if(nums[i]==7) flag++;
    }
    if(flag) ans=(ans+flag)%p;
    return ans%p;
}
int main()
{
    cin>>T;
    init();
    while(T--)
    {
        cin>>s;
        if(s.size()==1)
        {
            int t=s[0]-'0';
            if(t>=7) puts("1");
            else puts("0");
        }
        else 
        {
            ll ans=calc(s);
            printf("%lld\n",ans);
        }
    }
    return 0;
}