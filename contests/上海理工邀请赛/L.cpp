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
int T,c[15],t[15],res[15],t1,t2;
int main()
{
    cin>>T;
    while(T--)
    {
        mst(res,0);t1=t2=0;
        rep(i,0,9) rd(c[i]);
        int ans=-1;
        if(c[0]) ans=0;
        if(c[4]) ans=4;
        if(c[8]) ans=8;
        if(c[0]>=2)
        {
            c[0]-=2;
            int flag=0;
            for(int j=9;j>=1;j--) if(c[j]) {flag=1;break;}
            if(flag) 
            {
                for(int j=9;j>=0;j--) res[j]=c[j];
                t1=t2=0;
            }
            c[0]+=2;
        }
        for(int i=12;i<100;i+=4)
        {
            int a=i%10,b=(i/10)%10;
            if(a==b)
            {
                if(c[a]>=2)
                {
                    c[a]-=2;
                    for(int i=9;i>=0;i--) t[i]=c[i];
                    int flag=0;
                    for(int i=9;i>=0;i--)
                    {
                        if(t[i]>res[i]) {flag=1;break;}
                        else if(t[i]<res[i]) {flag=-1;break;}
                    }
                    if(flag==1)
                    {
                        for(int i=9;i>=0;i--) res[i]=t[i];
                        t1=b,t2=a;
                    }
                    if(flag==0)
                    {
                        if(t1==b) 
                        {
                            if(a>t2) t2=a;
                        }
                        else if(t1<b) t1=b,t2=a;
                    }
                    c[a]+=2;
                }
            }
            else if(c[a]&&c[b])
            {
                c[a]--,c[b]--;
                for(int i=9;i>=0;i--) t[i]=c[i];
                int flag=0;
                for(int i=9;i>=0;i--)
                {
                    if(t[i]>res[i]) {flag=1;break;}
                    else if(t[i]<res[i]) {flag=-1;break;}
                }
                if(flag==1)
                {
                    for(int i=9;i>=0;i--) res[i]=t[i];
                    t1=b,t2=a;
                }
                if(flag==0)
                {
                    if(t1==b) 
                    {
                        if(a>t2) t2=a;
                    }
                    else if(t1<b) t1=b,t2=a;
                }
                c[a]++,c[b]++;
            }
        }
        int pan=0;
        for(int i=9;i>=1;i--)
        {
            for(int j=0;j<res[i];j++) printf("%d",i),pan=1;
        }
        if(pan) 
        {
            for(int i=0;i<res[0];i++) printf("0");
            cout<<t1<<t2<<endl;
        }
        else
        {
            if(t1) cout<<t1<<t2<<endl;
            else cout<<ans<<endl;
        }   
    }
    return 0;
}