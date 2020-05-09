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
const int maxn=1050;
int n,cnt0,cnt1,a,b,w[maxn][maxn];
int f1[maxn][maxn],f2[maxn][maxn];
string s,t;
int main()
{
    cin>>n>>cnt0>>cnt1>>a>>b;
    cin>>s>>t;
    int x,y;x=y=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0') x++;
        else y++;
        if(x>=0&&x<=cnt0&&y>=0&&y<=cnt1) w[x][y]+=a;
    }
    x=cnt0,y=cnt1;
    for(int i=(int)s.size()-1;i>=0;i--)
    {
        if(s[i]=='0') x--;
        else y--;
        if(x>=0&&x<=cnt0&&y>=0&&y<=cnt1) w[x][y]+=b;
    }
    mst(f1,0x3f);
    mst(f2,0xcf);
    f1[0][0]=f2[0][0]=w[0][0];
    for(int i=0;i<=cnt0;i++)
    {
        for(int j=0;j<=cnt1;j++)
        {
            if(t[i+j]=='0')
            {
                f1[i+1][j]=min(f1[i+1][j],f1[i][j]+w[i+1][j]);
                f2[i+1][j]=max(f2[i+1][j],f2[i][j]+w[i+1][j]);
            }
            else if(t[i+j]=='1')
            {
                f1[i][j+1]=min(f1[i][j+1],f1[i][j]+w[i][j+1]);
                f2[i][j+1]=max(f2[i][j+1],f2[i][j]+w[i][j+1]);
            }
            else
            {
                f1[i+1][j]=min(f1[i+1][j],f1[i][j]+w[i+1][j]);
                f2[i+1][j]=max(f2[i+1][j],f2[i][j]+w[i+1][j]);
                f1[i][j+1]=min(f1[i][j+1],f1[i][j]+w[i][j+1]);
                f2[i][j+1]=max(f2[i][j+1],f2[i][j]+w[i][j+1]);
            }
        }
    }
    cout<<f1[cnt0][cnt1]<<" "<<f2[cnt0][cnt1]<<endl;
    return 0;
}