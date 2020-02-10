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
int n,num;
map<int,int> mp;
struct node{
	int a,b;
	string name;
	bool operator<(const node&t) const{
		if(a==t.a) return a*t.b>t.a*b;
		else return a>t.a;
	}
}c[150];
int main()
{
	cin>>n;
	int temp=n;
	while(n--)
	{
		int k;
		string s;
		cin>>s>>k;
		mp.clear();
		for(int i=1;i<=k;i++)
		{
			int x;read(x);
			mp[x]=1;
		}
		c[++num]={(int)mp.size(),k,s};
		//cout<<s<<"  "<<mp.size()<<"---"<<endl; 
	}
	sort(c+1,c+temp+1);
	if(temp==1) cout<<c[1].name<<" - -"<<endl;
	else if(temp==2) cout<<c[1].name<<" "<<c[2].name<<" -"<<endl;
	else 
	{
		cout<<c[1].name<<" "<<c[2].name<<" "<<c[3].name<<endl;
	}
	return 0;
}

