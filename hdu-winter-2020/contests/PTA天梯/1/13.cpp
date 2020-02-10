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
int n,num=0;
string s;
int t[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char p[]={'1','0','X','9','8','7','6','5','4','3','2'};
string ans[110];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		int flag=0,sum=0;
		for(int i=0;i<(int)s.size()-1;i++)
		{
			if(!(s[i]>='0'&&s[i]<='9')) 
			{
				flag=1;
				break;
			}
			sum+=t[i]*(s[i]-'0');
		}
		
		if(flag) ans[++num]=s;
		else
		{
			sum%=11;
			if(!(p[sum]==s[(int)s.size()-1]))
				ans[++num]=s;
		}
	}
	if(num==0) puts("All passed");
	else
	{
		for(int i=1;i<=num;i++) cout<<ans[i]<<endl;
	}
	return 0;
}

