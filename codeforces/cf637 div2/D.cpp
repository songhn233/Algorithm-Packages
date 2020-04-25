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
const int maxn=2050;
int n,k;
string s[maxn];
int tt[10][7]={{1,1,1,0,1,1,1},{0,0,1,0,0,1,0},{1,0,1,1,1,0,1},{1,0,1,1,0,1,1},{0,1,1,1,0,1,0},{1,1,0,1,0,1,1},{1,1,0,1,1,1,1},{1,0,1,0,0,1,0},{1,1,1,1,1,1,1},{1,1,1,1,0,1,1}};
int b[maxn][10];
int mp[maxn][maxn],pre[maxn][maxn];
int pan(int t[],int tt[])
{
    int res=0;
    for(int i=0;i<7;i++)
    {
        if(t[i]==1&&tt[i]==0) return -1;
        else if(t[i]==0&&tt[i]==1) res++;
    }
    return res;
}
void calc(int id,string s)
{
    int t[7],ttt[7];mst(t,0);
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1') t[i]++;
    }  
    for(int i=0;i<=9;i++)
    {
        for(int j=0;j<7;j++) ttt[j]=tt[i][j];
        int temp=pan(t,ttt);
        if(temp==-1) b[id][i]=-1;
        else b[id][i]=temp;
    }
}
int main()
{
    cin>>n>>k;
    rep(i,1,n) 
    {
        cin>>s[i];
        calc(i,s[i]);
    }
    mp[n+1][0]=1;
    for(int i=n;i>=1;i--)
    {
        for(int j=0;j<=9;j++)
        {
            if(b[i][j]==-1) continue;
            else
            {
                for(int l=0;l<=2000;l++)
                {
                    if(mp[i+1][l]==0) continue;
                    if(l+b[i][j]>k) continue;
                    mp[i][l+b[i][j]]=max(mp[i][l+b[i][j]],j+1);
                }
            }
            
        }
    }
    if(!mp[1][k]) puts("-1");
    else
    {
        cout<<mp[1][k]-1;
        int rest=k;
        for(int i=2;i<=n;i++) {
            rest-=b[i-1][mp[i-1][rest]-1];
            cout<<mp[i][rest]-1;
        }
        cout<<endl;
    }
    return 0;
}