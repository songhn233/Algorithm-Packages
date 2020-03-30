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
int T,l,r;
vector<int> nums;
ll f[15][15];
void init()
{
    rep(i,1,9) f[1][i]=1;
    rep(i,1,10)
    {
        rep(j,1,9)
        {
            rep(k,1,9)
            {
                if(k<=j&&j%k==0) f[i][j]+=f[i-1][k];
            }
        }
    }
}
ll calc(int n)
{
    if(!n) return 0;
    nums.clear();
    while(n) nums.push_back(n%10),n/=10;
    ll ans=0;
    if((int)nums.size()==1)
    {
        return nums[0];
    }
    rep(i,1,(int)nums.size()-1)
    {
        rep(j,1,9) ans+=f[i][j];
    }
    rep(i,1,(int)nums.back()-1) ans+=f[(int)nums.size()][i];
    dep(i,(int)nums.size()-1,0)
    {
        int x=nums[i];
        if(i!=(int)nums.size()-1)
        {
            rep(j,1,x-1)
            {
                if(nums[i+1]>=j&&nums[i+1]%j==0) ans+=f[i+1][j];
            }
        }
        if(x==0) break;
        if((i!=((int)nums.size()-1))&&(x>nums[i+1]||nums[i+1]%x!=0)) break;
        if(i==0)
        {
            int flag=1;
            dep(i,(int)nums.size()-1,1)
            {
                if(nums[i]==0||nums[i-1]==0) {flag=0;break;}
                if(nums[i]>=nums[i-1]&&nums[i]%nums[i-1]==0) continue;
                else {flag=0;break;}
            }
            if(flag) ans++;
        }
    }
    return ans;
}
int main()
{
    cin>>T;
    init();
    while(T--)
    {
        cin>>l>>r;
        cout<<calc(r)-calc(l-1)<<endl;
    }
    return 0;
}