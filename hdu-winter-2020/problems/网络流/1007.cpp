#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=25;
const int maxm=20000;
int s[maxm],f[maxn][maxm],num,n;
int a[maxn][maxn];
int get(int c,int x)
{
    int res=0;
    for(int i=0;i<n;i++)
        if(x>>i&1) res+=a[c][i+1];
    return res;
}
int main()
{
    while(cin>>n)
    {
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
        memset(f,0,sizeof(f));
        memset(s,0,sizeof(s));num=0;
        for(int i=0;i<(1<<n);i++)
        {
            if(i&(i>>1)) continue;
            s[num++]=i;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<num;j++)
            {
                for(int k=0;k<num;k++)
                {
                    if(s[j]&s[k]) continue;
                    f[i][k]=max(f[i][k],f[i-1][j]+get(i,s[k]));
                }
            }
        }
        int ans=0;
        for(int i=0;i<num;i++) ans=max(ans,f[n][i]);
        cout<<ans<<endl;
    }
    return 0;
}
