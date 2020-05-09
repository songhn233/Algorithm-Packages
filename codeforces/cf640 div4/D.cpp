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
const int maxn=1050;
int T,n;
int a[maxn];
int main()
{
    cin>>T;
    while(T--)
    {
        rd(n);
        rep(i,1,n) rd(a[i]);
        int ans=0;
        int l=0,r=n+1;
        int pre=0;
        int sum1,sum2;sum1=sum2=0;
        if(n==1) 
        {
            cout<<1<<" "<<a[1]<<" "<<0<<endl;
            continue;
        }
        if(n==2)
        {
            cout<<2<<" "<<a[1]<<" "<<a[2]<<endl;
            continue;
        }
        while(l<r)
        {
            l++;
            int t1=a[l];
            while(l+1<r&&t1<=pre) l++,t1+=a[l];
            if(t1<=pre||l+1==r)
            {
                ans++;
                sum1+=t1;
                break;
            }
            else sum1+=t1,ans++;
            pre=t1;
            r--;
            int t2=a[r];
            while(r-1>l&&t2<=pre) r--,t2+=a[r];
            if(t2<=pre||r-1==l)
            {
                ans++;
                sum2+=t2;
                break;
            }
            else sum2+=t2,ans++;
            pre=t2;
        }
        cout<<ans<<" "<<sum1<<" "<<sum2<<endl;
    }
    return 0;
}