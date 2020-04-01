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
const int maxn=200050;
int T;
int n,k;
char c[maxn];
int mp[maxn][27],ans;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>k;
        rep(i,0,n) for(int j=0;j<=25;j++) mp[i][j]=0;
        scanf("%s",c+1);
        ans=0;
        for(int i=1;i<=n;i++)
        {
            int t=i%k;
            if(t==0) t=k;
            mp[t][c[i]-'a']++;
        }
        int l=1,r=k;
        while(l<r)
        {
            int sum=0;
            rep(i,0,25) 
            {
                sum+=mp[l][i];
                sum+=mp[r][i];
            }
            int minx=inf;
            rep(i,0,25)
            {
                if(sum-mp[l][i]-mp[r][i]<minx)
                {
                    minx=sum-mp[l][i]-mp[r][i];
                }
            }
            ans+=minx;
            l++,r--;
        }
        if(l==r) 
        {
            int sum=0,maxx=0;
            rep(i,0,25) sum+=mp[l][i],maxx=max(maxx,mp[l][i]);
            ans+=sum-maxx;
        }
        cout<<ans<<endl;
    }
    return 0;
}