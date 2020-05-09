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
vector<int> a;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        int ans=0;a.clear();
        int base=1;
        while(n)
        {
            if(n%10!=0) 
            {
                a.push_back((n%10)*base);
                ans++;
            }
            n/=10;
            base*=10;
        }
        cout<<ans<<endl;
        for(int i=0;i<a.size();i++) cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}