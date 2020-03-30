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
int n,k,mp[30],res[30];
string s;
int main()
{
    cin>>n>>k;
    cin>>s;
    rep(i,0,n-1)
    {
        if(i>0&&s[i]==s[i-1])
        {
            mp[s[i]-'a']++;
        }
        else
        {
            if(i>0) 
            {
                res[s[i-1]-'a']+=mp[s[i-1]-'a']/k;
                mp[s[i-1]-'a']=0;
            }
            mp[s[i]-'a']++;
        }
    }
    res[s[n-1]-'a']+=mp[s[n-1]-'a']/k;
    int ans=0;
    rep(i,0,25) ans=max(ans,res[i]);
    cout<<ans<<endl;
    return 0;
}