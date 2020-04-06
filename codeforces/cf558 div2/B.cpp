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
int n,a[maxn];
map<int,int> mp;
map<int,int> c;
int main()
{
    cin>>n;
    rep(i,1,n) rd(a[i]);
    int ans=0;
    rep(i,1,n)
    {
        if(mp[a[i]]==0) 
        {
            c[1]++;
            mp[a[i]]++;
        }
        else
        {
            c[mp[a[i]]]--;
            c[mp[a[i]]+1]++;
            if(c[mp[a[i]]]==0) c.erase(mp[a[i]]);
            mp[a[i]]++;
        }
        if(c.size()==2)
        {
            int t1,p1,t2,p2;
            int cnt=1;
            for(auto x:c)
            {
                if(cnt==1)
                {
                    t1=x.first;p1=x.second;
                    cnt++;
                }
                else
                {
                    t2=x.first;p2=x.second;
                }
            }
            if(t2==t1+1&&p2==1)
            {
                ans=i;
            }
            else if(t1==t2+1&&p1==1)
            {
                ans=i;
            }
            else if(t1==1&&p1==1)
            {
                ans=i;
            }
            else if(t2==1&&p2==1)
            {
                ans=i;
            }
        }
        if(c.size()==1)
        {
            int t,p;
            for(auto x:c) t=x.first,p=x.second;
            if(t==1) ans=i;
            if(p==1) ans=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}