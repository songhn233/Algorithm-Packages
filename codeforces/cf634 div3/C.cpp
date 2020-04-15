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
int n,a[maxn];
map<int,int> mp;
int main()
{
    cin>>T;
    while(T--)
    {
        mp.clear();
        cin>>n;
        rep(i,1,n) rd(a[i]);
        if(n==1) puts("0");
        else
        {
            rep(i,1,n) 
            {
                mp[a[i]]++;
            }
            int ans=0;
            rep(i,1,n) 
            {
                ans=max(ans,min(mp[a[i]],(int)mp.size()-1));
                if(mp[a[i]]>1) ans=max(ans,min(mp[a[i]]-1,(int)mp.size()));
            }
            cout<<ans<<endl;
        }
        
    }
    return 0;
}