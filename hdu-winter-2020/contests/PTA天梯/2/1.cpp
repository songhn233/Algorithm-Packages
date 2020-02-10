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
string a,b;
int calc(string s)
{
	int flag=0,res=0;
	for(int i=0;i<s.size();i++)
	{
		if(!(s[i]>='0'&&s[i]<='9'))
		{
			flag=1;
			break;
		}
		else res=res*10+s[i]-'0';
	}
	if(flag) return -1;
	if(res<1||res>1000) return -1;
	return res;
}
int main()
{
	cin>>a;getchar();
	getline(cin,b);
	int t1=calc(a);
	int t2=calc(b);
	if(t1!=-1&&t2!=-1)
	{
		printf("%d + %d = %d\n",t1,t2,t1+t2);
	}
	else if(t1!=-1&&t2==-1) printf("%d + ? = ?\n",t1);
	else if(t1==-1&&t2!=-1) printf("? + %d = ?\n",t2);
	else puts("? + ? = ?");
	return 0;
}

