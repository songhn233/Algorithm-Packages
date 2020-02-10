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
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int p=10000;
struct matrix{
    int f[2][2];
    matrix operator*(const matrix&t){
        matrix c;
        memset(c.f,0,sizeof(c.f));
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                for(int k=0;k<2;k++)
                {
                    c.f[i][j]=(c.f[i][j]+f[i][k]*t.f[k][j])%p;
                }
            }
        }
        return c;
    }
};
int n;
matrix ksm(matrix a,int b)
{
    matrix res;
    memset(res.f,0,sizeof(res.f));
    res.f[0][0]=1,res.f[1][1]=1;
    while(b)
    {
        if(b&1) res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}
int main()
{
    while(cin>>n)
    {
        if(n==-1) break;
        else if(n==0) puts("0");
        else if(n==1) puts("1");
        else
        {
            n--;
            matrix g;
            g.f[0][0]=1,g.f[0][1]=1,g.f[1][0]=1,g.f[1][1]=0;
            matrix temp=ksm(g,n);
            //cout<<temp.f[0][0]<<"--"<<endl;
            matrix s;
            memset(s.f,0,sizeof(s.f));
            s.f[0][0]=1;
            matrix ans=s*temp;
            cout<<ans.f[0][0]<<endl;
        }
    }
    return 0;
}

