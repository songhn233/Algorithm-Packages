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

int main()
{
	string s;
	cin>>s;
	if(s=="SUN") puts("7");
	else if(s=="MON") puts("6");
	else if(s=="TUE") puts("5");
	else if(s=="WED") puts("4");
	else if(s=="THU") puts("3");
	else if(s=="FRI") puts("2");
	else if(s=="SAT") puts("1");
	return 0;
}

