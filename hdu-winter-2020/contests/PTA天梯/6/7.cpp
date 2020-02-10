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
const int maxn=150;
char a[maxn][maxn];
string s;
int n,m,num;
int main()
{
	cin>>n;getchar();
	getline(cin,s);
	int len=s.size();
	if((len/n)*n==len) m=len/n;
	else m=(len/n)+1;
	for(int i=m-1;i>=0;i--)
	{
		for(int j=0;j<n;j++) 
		{
			if(num<len) a[j][i]=s[num++];
			else a[j][i]=' ';
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++) cout<<a[i][j];
		cout<<endl;
	}
	return 0;
}
