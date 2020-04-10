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
int n;
string s;
int main()
{
    cin>>n>>s;
    int flag=0,t1,t2;
    rep(i,0,n-2)
    {
        if(s[i]>s[i+1])
        {
            flag=1;
            t1=i+1,t2=i+2;
            break;
        }
    }
    if(flag)
    {
        puts("YES");
        cout<<t1<<" "<<t2<<endl;
    }
    else puts("NO");
    return 0;
}