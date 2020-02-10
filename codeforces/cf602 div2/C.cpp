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
const int maxn=2050;
int T;
int n,k;
char s[maxn],ans[maxn],temp[maxn];
vector<PII> res;
void calc(int x,int y)
{
	for(int i=x;i<=y;i++) temp[i]=s[i];
	for(int i=x;i<=y;i++) s[i]=temp[y-i+x];
}
int main()
{
	cin>>T;
	while(T--)
	{
		int cnt=0;
		res.clear();
		cin>>n>>k;
		cin>>(s+1);
		k--;
		for(int i=1;i<=n-2*k;i++)
		{
			if(i<=(n-2*k)/2) ans[i]='(';
			else ans[i]=')';
		}
		int pan=1;
		for(int i=n-2*k+1;i<=n;i++)
		{
			if(pan)
			{
				ans[i]='(';
				pan=0;
			}
			else
			{
				ans[i]=')';
				pan=1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(s[i]!=ans[i])
			{
				for(int j=i+1;j<=n;j++)
				{
					if(s[j]==ans[i]) 
					{
						cnt++;
						calc(i,j);
						res.push_back(make_pair(i,j));
						break;
					}
				}
			}
		}
		cout<<cnt<<endl;
		for(int i=0;i<res.size();i++) cout<<res[i].first<<" "<<res[i].second<<endl;
	}
	return 0;
}
