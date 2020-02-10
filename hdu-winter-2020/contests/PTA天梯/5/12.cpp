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
const int maxn=1050;
const double eps=1e-9;
bool calc_cmp(double x,double y)
{
	if(fabs(x-y)<eps) return true;
	return false;
}
int n,m;
int x,y;
int pan[maxn];
double a[maxn][maxn];
int calc(int x,int y)
{
	if(x<0) return y;
	else return -y;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int k;read(k);
		vector<int> temp;
		temp.clear();
		for(int j=1;j<=k;j++)
		{
			int x;
			read(x);
			if(x<0)
			{
				x=-x;
				pan[x]=-1;
			}
			else pan[x]=1;
			temp.push_back(x);
		}
		for(int i=0;i<temp.size();i++)
		{
			for(int j=i+1;j<temp.size();j++)
			{
				a[temp[i]][temp[j]]+=(double)1/(double)k;
				a[temp[j]][temp[i]]+=(double)1/(double)k;
			}
		}
	}
	cin>>x>>y;
	double t1,t2;
	t1=t2=0;
	for(int i=0;i<n;i++)
	{
		if(pan[i]*pan[abs(x)]<0)t1=max(t1,a[abs(x)][i]);
		if(pan[i]*pan[abs(y)]<0)t2=max(t2,a[abs(y)][i]);
	}
	if(calc_cmp(t1,t2)&&calc_cmp(t1,a[abs(x)][abs(y)])&&calc_cmp(t2,a[abs(y)][abs(x)]))
	{
		cout<<x<<" "<<y<<endl;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(calc_cmp(a[abs(x)][i],t1)&&pan[i]*pan[x]<=0)
			{
				cout<<x<<" "<<calc(x,i)<<endl;
			}
		}
		
		for(int i=0;i<n;i++)
		{
			if(calc_cmp(a[abs(y)][i],t2)&&pan[i]*pan[y]<=0)
			{
				cout<<y<<" "<<calc(y,i)<<endl;
			}
		}
	}
	return 0;
}
