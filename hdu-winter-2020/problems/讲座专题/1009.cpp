//hdu3949 XOR 线性基
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
int T;
ll n,q,a[maxn],b[100];
ll flag=0,cnt=0;
vector<ll> p;
void init()
{
    mst(b,0);
    flag=cnt=0;
    p.clear();
}
void pre()
{
    rep(i,1,n)
    {
        rd(a[i]);
        dep(j,60,0)
        {
            if(a[i]>>j&1)
            {
                if(b[j]) a[i]^=b[j];
                else
                {
                    b[j]=a[i];cnt++;
                    rep(k,0,j-1) if(b[k]&&(b[j]>>k&1)) b[j]^=b[k];
                    rep(k,j+1,60) if(b[k]>>j&1) b[k]^=b[j];
                    break;
                }
            }
        }
    }
    flag=(cnt!=n);
    rep(i,0,60) if(b[i]) p.push_back(b[i]);
}
ll query(ll k)
{
    if(flag) k--;
    if(k>=(1ll<<((ll)p.size()))) return -1;
    ll res=0;
    rep(i,0,(ll)p.size()-1) if(k>>i&1) res^=p[i];
    return res;
}
int main()
{
    cin>>T;
    rep(tim,1,T)
    {
        cin>>n;
        init();
        pre();
        cin>>q;
        printf("Case #%d:\n",tim);
        while(q--)
        {
            ll k;rd(k);
            cout<<query(k)<<endl;
        }
    }
    return 0;
}