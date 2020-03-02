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
const int maxn=100050;
ll n,dx,dy,dz;
ll x[maxn],y[maxn],z[maxn];
bool calc(int i,int j)
{
	int x1=x[i],x2=x[j],y1=y[i],y2=y[j],z1=z[i],z2=z[j];
	int f1,f2,f3;
	if((x1>=x2&&x1<=x2+dx)||(x1+dx>=x2&&x1+dx<=x2+dx)) f1=1;
	else f1=0;
	if((y1>=y2&&y1<=y2+dy)||(y1+dy>=y2&&y1+dy<=y2+dy)) f2=1;
	else f2=0;
	if((z1>=z2&&z1<=z2+dz)||(z1+dz>=z2&&z1+dz<=z2+dz)) f3=1;
	else f3=0;
	if(f1&&f2&&f3) return true;
	else return false;
}
int main()
{
	cin>>n>>dx>>dy>>dz;
	for(int i=1;i<=n;i++)
	{
		read(x[i]),read(y[i]),read(z[i]);
	}
	int flag=0;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(calc(i,j))
			{
				cout<<i<<endl;
				flag=1;
				break;
			}
		}
	}
	if(!flag) puts("0");
	return 0;
}

