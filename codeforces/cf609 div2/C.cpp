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
const int maxn=200050;
int n,k;
string s;
int ans[maxn];
int main()
{
	cin>>n>>k;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		if(i<k) ans[i]=s[i]-'0';
		else ans[i]=ans[i-k];
	}
	int flag=1;
	for(int i=0;i<n;i++)
	{
		if(ans[i]>s[i]-'0') break;
		if(ans[i]<s[i]-'0')
		{
			flag=0;
			break;
		}
	}
	if(flag) 
	{
		cout<<n<<endl;
		for(int i=0;i<n;i++) cout<<ans[i];
		puts("");
	}
	else
	{
		for(int i=k-1;i>=0;i--)
		{
			if(ans[i]==9) continue;
			else 
			{
				ans[i]++;
				for(int j=i+1;j<k;j++) ans[j]=0;
				for(int j=0;j<n;j++) ans[j]=ans[j%k];
				cout<<n<<endl;
				for(int j=0;j<n;j++) cout<<ans[j];
				puts("");
				break;
			}
		}
	}
	return 0;
}

