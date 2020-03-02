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
int k,t1,t2;
int main()
{
	while(cin>>k)
	{
	if(k<=25)
	{
		cout<<"a"<<char('a'+k)<<endl;
	}
	else
	{
		int p=(k/25);
		if(k%25) p+=1;
		//cout<<k%25<<"--"<<endl;
		int temp=25;
		if(k%25==0)
		{
			for(int i=1;i<=p+1;i++)
			{
				if(i%2==1) cout<<"a";
				else cout<<"z";
			}
			cout<<endl;
		}
		else
		{
			int t=25-(25-(k%25))/2;
			for(int i=1;i<=2;i++)
			{
				if(i%2==1) cout<<"a";
				else cout<<char('a'+t);
			}
			for(int i=3;i<=p;i++)
			{
				if(i%2==1) cout<<"a";
				else cout<<"z";
			}
			if(p%2==1) cout<<char('a'+(k%25)+(25-t)*2)<<endl;
			else cout<<char('a'+25-(k%25)-(25-t)*2)<<endl;
		}
	}
}
	return 0;
}

