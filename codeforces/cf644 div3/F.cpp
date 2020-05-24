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
const int maxn=15;
int T,n,m;
string s[maxn],ans;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        int pan=0;
        rep(i,1,n) cin>>s[i];
        rep(i,1,n)
        {
            if(pan) break;
            for(int j=0;j<m;j++)
            {
                if(pan) break;
                for(int k=1;k<=n;k++)
                {
                    string temp=s[i];
                    temp[j]=s[k][j];
                    int flag=1;
                    for(int l=1;l<=n;l++)
                    {
                        int t=0;
                        for(int tt=0;tt<m;tt++)
                        {
                            if(temp[tt]!=s[l][tt]) t++;
                        }
                        if(t<=1) continue;
                        else
                        {
                            flag=0;
                            break;
                        }
                    }
                    if(flag)
                    {
                        pan=1;
                        ans=temp;
                        break;
                    }
                }
            }
        }
        if(pan) cout<<ans<<endl;
        else puts("-1");
    }
    return 0;
}