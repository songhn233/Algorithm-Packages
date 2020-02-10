#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
int T,n,a,b,c,ans;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		cin>>b>>c>>a;
		string s;cin>>s;
		int t1,t2,t3;
		t1=t2=t3=0;
		ans=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='S') t1++;
			else if(s[i]=='R') t2++;
			else t3++;
		}
		ans+=min(t1,b);
		ans+=min(t2,c);
		ans+=min(t3,a);
		if(ans<(n+1)/2) puts("NO"); 
		else
		{
			puts("YES");
			int p1,p2,p3;
			p1=p2=p3=0;
			for(int i=0;i<s.size();i++)
			{
				if(s[i]=='S')
				{
					if(p1<min(t1,b)) cout<<"R",p1++;
					else if(c>t2) cout<<"P",c--;
					else if(a>t3) cout<<"S",a--;
				}
				
				if(s[i]=='R')
				{
					if(p2<min(t2,c)) cout<<"P",p2++;
					else if(b>t1) cout<<"R",b--;
					else if(a>t3) cout<<"S",a--;
				}
				
				if(s[i]=='P')
				{
					if(p3<min(t3,a)) cout<<"S",p3++;
					else if(b>t1) cout<<"R",b--;
					else if(c>t2) cout<<"P",c--;
				}
			}
			puts("");
		}
	}
	return 0;
}
