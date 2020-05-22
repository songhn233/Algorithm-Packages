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
int T,k;
string s;
int num[10];
int ans[10],temp[10];
int flag;
void dfs(int d,int rest,int mod)
{
    if(d<0)
    {
        if(rest!=0||mod!=0) return ;
        flag=1;
        for(int i=9;i>=0;i--)
            if(ans[i]<temp[i])
            {
                for(int j=9;j>=0;j--) ans[j]=temp[j];
                break;
            }
        return ;
    }
    int t=min(rest,num[d]);
    if(d==0&&rest==k)
    {
        t=min(t,1);
    }
    for(int i=t;i>=max(0,t-2);i--) 
    {
        temp[d]=i;
        dfs(d-1,rest-i,(mod+i*d)%3);
    }
}
int main()
{
    cin>>T;
    while(T--)
    {
        flag=0;
        cin>>s>>k;
        mst(num,0);
        mst(ans,0);
        for(int i=0;i<s.size();i++) num[s[i]-'0']++;
        dfs(9,k,0);
        if(!flag){puts("-1"); continue;}
        for(int i=9;i>=0;i--)
        {
            for(int j=1;j<=ans[i];j++) printf("%d",i);
        }
        cout<<endl;
    }
    return 0;
}