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
ll T,n;
ll a[maxn];
vector<ll> ans;
int main()
{
    cin>>T;
    while(T--)
    {
        ans.clear();
        cin>>n;
        rep(i,1,n) rd(a[i]);
        sort(a+1,a+n+1);
        int j=n;
        rep(i,1,n/2)
        {
            ans.push_back(a[i]);
            ans.push_back(a[j]);
            j--;
        }
        if(n&1) ans.push_back(a[(n/2)+1]);
        for(int i=(int)ans.size()-1;i>=0;i--) printf("%lld ",ans[i]);
        cout<<endl;
    }
    return 0;
}