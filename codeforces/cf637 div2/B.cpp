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
int n,k,a[maxn];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>k;
        rep(i,1,n) rd(a[i]);
        int ans=0,l=1;
        for(int i=1;i<=k;i++)
        {
            if(i>1&&a[i-1]<a[i])
            {
                if(i<k&&a[i+1]<a[i]) ans++;
            }
        }
        int temp=ans;
        for(int i=k+1;i<=n;i++)
        {
            if(a[i-2]<a[i-1])
            {
                if(i-2>=1&&a[i]<a[i-1]) temp++;
            }
            if(a[i-k]<a[i-k+1]&&a[i-k+1]>a[i-k+2]) temp--;
            if(temp>ans)
            {
                ans=temp;
                l=i-k+1;
            }
        }
        cout<<ans+1<<" "<<l<<endl;
    }
    return 0;
}