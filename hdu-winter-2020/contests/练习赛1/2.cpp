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
int n,t1,t2,ans1,ans2;
string s;
int main()
{
	cin>>n;
	cin>>s;
	t1=t2=-1;
	int f1,f2;
	f1=f2=0;
	ans1=ans2=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='R') 
		{
			ans1=i;
			t1=i;
			break;
		}
	}
	for(int i=n-1;i>=0;i--)
	{
		if(s[i]=='L')
		{
			ans2=n-1-i;
			t2=i;
			break;
		}
	}
	if(t1==-1||t2==-1) cout<<s.size()<<endl;
	else
	{
		cout<<ans1+ans2+1<<endl;
	}
	return 0;
}

