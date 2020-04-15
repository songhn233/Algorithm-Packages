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
const int maxn=20;
int T;
char c[maxn][maxn];
int main()
{
    cin>>T;
    while(T--)
    {
        rep(i,1,9) cin>>(c[i]+1);
        rep(i,1,9)
        {
            rep(j,1,9)
            {
                if(i==1&&j==1) c[i][j]=(c[i][j]+1<='9')?c[i][j]+1:c[i][j]-1;
                if(i==2&&j==4) c[i][j]=(c[i][j]+1<='9')?c[i][j]+1:c[i][j]-1;
                if(i==3&&j==7) c[i][j]=(c[i][j]+1<='9')?c[i][j]+1:c[i][j]-1;
                if(i==4&&j==2) c[i][j]=(c[i][j]+1<='9')?c[i][j]+1:c[i][j]-1;
                if(i==5&&j==5) c[i][j]=(c[i][j]+1<='9')?c[i][j]+1:c[i][j]-1;
                if(i==6&&j==8) c[i][j]=(c[i][j]+1<='9')?c[i][j]+1:c[i][j]-1;
                if(i==7&&j==3) c[i][j]=(c[i][j]+1<='9')?c[i][j]+1:c[i][j]-1;
                if(i==8&&j==6) c[i][j]=(c[i][j]+1<='9')?c[i][j]+1:c[i][j]-1;
                if(i==9&&j==9) c[i][j]=(c[i][j]+1<='9')?c[i][j]+1:c[i][j]-1;
            }
        }
        rep(i,1,9)
        {
            rep(j,1,9) cout<<c[i][j];
            cout<<endl;
        }
    }
    return 0;
}