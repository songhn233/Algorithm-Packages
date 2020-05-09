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
int T;
int n,k;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>k;
        int temp=k-1;
        if(n-temp<=0) {puts("NO"); continue;}
        if((n-temp)%2==1)
        {
            puts("YES"); 
            for(int i=1;i<k;i++) cout<<1<<" ";
            cout<<n-temp<<endl;
            continue;
        }
        temp=(k-1)*2;
        if(n-temp<=0) {puts("NO"); continue;}
        if((n-temp)%2==0)
        {
            puts("YES"); 
            for(int i=1;i<k;i++) cout<<2<<" ";
            cout<<n-temp<<endl;
            continue;
        }
        puts("NO");
        continue;
    }
    return 0;
}