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
int T,n,ans,s1[105],s2[105];
string s;
void dfs(int d,int d1,int d2)
{
    if(d==n)
    {
        ans=min(ans,d1+d2);
        return ;
    }
    if(s1[d]-d1>=3&&s2[d]-d2>=2)
    {
        dfs(d+1,d1+s1[d]-d1-2,d2);
        dfs(d+1,d1,d2+s2[d]-d2-1);
    }
    else dfs(d+1,d1,d2);
}
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>s;ans=inf;
        n=s.size();
        mst(s1,0);mst(s2,0);
        for(int i=0;i<n;i++)
        {
            s1[i]=s1[max(0,i-1)];
            if(s[i]=='x') s1[i]++;
        }
        for(int j=n-1;j>=0;j--) 
        {
            s2[j]=s2[j+1];
            if(s[j]=='l') s2[j]++;
        }
        dfs(0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}