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
const int maxn=150;
int T,a[maxn][maxn],n;
int main()
{
    cin>>T;
    for(int tim=1;tim<=T;tim++)
    {
        cin>>n;
        rep(i,1,n) rep(j,1,n) rd(a[i][j]);
        int sum=0,ans1=0,ans2=0;
        rep(i,1,n)  sum+=a[i][i];
        rep(i,1,n)
        {
            map<int,int> mp;mp.clear();
            int flag=0;
            rep(j,1,n)
            {
                if(mp[a[i][j]]) flag=1;
                mp[a[i][j]]=1;
            }
            if(flag) ans1++;
        }
        rep(i,1,n)
        {
            map<int,int> mp;mp.clear();
            int flag=0;
            rep(j,1,n)
            {
                if(mp[a[j][i]]) flag=1;
                mp[a[j][i]]=1;
            }
            if(flag) ans2++;
        }
        printf("Case #%d: ",tim);
        cout<<sum<<" "<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}