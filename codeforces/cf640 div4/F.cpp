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
const int maxn=505;
int T,a,b,c;
int t[maxn];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>a>>b>>c;
        if(b==1&&c==0)
        {
            printf("10");
            for(int i=1;i<=a;i++) printf("0");
            cout<<endl;
            continue;
        }
        if(b==1&&a==0)
        {
            printf("01");
            for(int i=1;i<=c;i++) printf("1");
            cout<<endl;
            continue;
        }
        if(a>0&&b==0&&c==0)
        {
            for(int i=1;i<=a+1;i++) printf("0");
            cout<<endl;
            continue;
        }
        if(c>0&&b==0&&a==0)
        {
            for(int i=1;i<=c+1;i++) printf("1");
            cout<<endl;
            continue;
        }
        if(c==0)
        {
            for(int i=1;i<=a+1;i++) printf("0");
            if(b%2==1) 
            {
                printf("1");
                int t=(b-1)/2;
                for(int i=1;i<=t;i++) printf("01");
            }
            else
            {
                int t=b/2;
                for(int i=1;i<=t;i++) printf("10");
            }
            cout<<endl;
            continue;
        }
        if(a==0)
        {
            for(int i=1;i<=c+1;i++) printf("1");
            if(b%2==1) 
            {
                printf("0");
                int t=(b-1)/2;
                for(int i=1;i<=t;i++) printf("10");
            }
            else
            {
                int t=b/2;
                for(int i=1;i<=t;i++) printf("01");
            }
            cout<<endl;
            continue;
        }
        if(b%2==1)
        {
            for(int i=1;i<=c+1;i++) printf("1");
            int t=(b-1)/2;
            for(int i=1;i<=t;i++) printf("01");
            for(int i=1;i<=a+1;i++) printf("0");
            cout<<endl;
        }
        else
        {
            printf("0");
            for(int i=1;i<=c+1;i++) printf("1");
            for(int i=1;i<=a+1;i++) printf("0");
            int t=(b/2)-1;
            for(int i=1;i<=t;i++) printf("10");
            cout<<endl;
        }
    }
    return 0;
}