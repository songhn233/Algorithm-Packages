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
int T,n;
string s;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        int ans=inf;
        cin>>s;
        rep(i,0,n-1)
        {
            if(s[i]=='>')
            {
                ans=min(ans,i+1);
                break;
            }
        }
        dep(i,n-1,0)
        {
            if(s[i]=='<')
            {
                ans=min(ans,n-1-i+1);
                break;
            }
        }
        cout<<ans-1<<endl;
    }
    return 0;
}