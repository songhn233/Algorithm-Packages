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
ll a,b;
int main()
{
    cin>>a>>b;
    ll c=a+b;
    if(c<0)
    {
        cout<<"-"<<endl;
        c=-c;
        vector<int> p;p.clear();
        while(c)
        {
            p.push_back(c%10);
            c/=10;
        }
        for(int i=(int)p.size()-1;i>=0;i--) cout<<p[i]<<endl;
    }
    else
    {
        if(c==0)
        {
            puts("0");
            return 0;
        }
        vector<int> p;p.clear();
        while(c)
        {
            p.push_back(c%10);
            c/=10;
        }
        for(int i=(int)p.size()-1;i>=0;i--) cout<<p[i]<<endl;
    }
    return 0;
}