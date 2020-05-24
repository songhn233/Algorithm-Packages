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
const int maxn=100010;
int n,ans;
map<string,bool> mp;
map<string,bool> vis;
string s[maxn];
bool calc(string s)
{
    if(s.size()>=4)
    {
        if(s.substr((int)s.size()-4)==".eoj") return true;
    }
    return false;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        string t="";
        int flag=0;
        for(int j=0;j<s[i].size();j++)
        {
            if(s[i][j]=='/'&&flag)
            {
                if(mp[t]&&calc(t)&&vis[t]) 
                {
                    ans--;
                    vis[t]=false;
                }
                mp[t]=true;
                t+='/';
            }
            else if(s[i][j]=='/') t+='/',flag=1;
            else t+=s[i][j];
        }
        if(!mp[t])
        {
            mp[t]=true;
            if(calc(t))
            {
                ans++;
                vis[t]=true;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}