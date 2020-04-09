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
const int maxn=100050;
ll n,k;
char s[maxn];
int a[maxn];
vector<int> v[maxn];
int main()
{
    scanf("%lld%lld",&n,&k);
    scanf("%s",s);
    rep(i,1,n)
    {
        if(s[i-1]=='R') a[i]=1;
        else a[i]=0;
    }
    int flag=1;
    ll cnt=0,sum=0;
    while(flag)
    {
        flag=0;
        sum++;
        for(int i=1;i<=n-1;i++)
        {
            if(a[i]==1&&a[i+1]==0)
            {
                cnt++;
                flag=1;
                swap(a[i],a[i+1]);
                v[sum].push_back(i);
                i++;
            }
        }
    }
    sum--;
    if(k>=sum&&k<=cnt)
    {
        rep(i,1,sum)
        {
            ll t=0,pan=0;
            while(!v[i].empty()&&k>sum-i+1)
            {
                printf("1 %d\n",v[i].back());
                v[i].pop_back();
                k--;
            }
            if(!v[i].empty())
            {
                printf("%d ",(int)v[i].size());
                for(int j=0;j<v[i].size();j++) printf("%d ",v[i][j]);
                printf("\n");
                k--;
            }
        }
    }
    else puts("-1");
    return 0;
}