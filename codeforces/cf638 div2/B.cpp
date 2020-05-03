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
const int maxn=10050;
int T,n,k,a[maxn],ans[maxn],maxx;
vector<int> t;
map<int,int> mp;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>k;
        mp.clear();
        maxx=0;
        rep(i,1,n) 
        {
            rd(a[i]);
            mp[a[i]]++;
        }
        if(mp.size()>k) puts("-1");
        else
        {
            int m=mp.size();
            t.clear();
            for(auto x:mp) 
            {
                t.push_back(x.first);
                maxx=max(maxx,x.second);
            }
            for(int i=1;i<=n*k;i++) ans[i]=0;
            for(int i=0;i<m;i++)
            {
                for(int j=1;j<=n;j++) ans[(j-1)*k+i+1]=t[i];
            }
            printf("%d\n",n*k);
            for(int i=1;i<=n*k;i++) 
            {
                if(ans[i]==0) printf("1 ");
                else printf("%d ",ans[i]);
            }
            printf("\n");
        }
        
    }
    return 0;
}