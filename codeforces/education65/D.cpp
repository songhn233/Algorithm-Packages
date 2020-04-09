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
int n;
string s,t;
int ans[maxn];
int main()
{
    cin>>n;
    cin>>t;
    s=" ";s+=t;
    int tt=0,top=0;
    int c1=0,c2=0;
    rep(i,1,n)
    {
        if(s[i]=='(') 
        {
            c1++;
            if(c1&1) ans[i]=1;
        }
        else 
        {
            c2++;
            if(c2&1) ans[i]=1;
        }

    }
    rep(i,1,n) printf("%d",ans[i]);
    cout<<endl;
    return 0;
}