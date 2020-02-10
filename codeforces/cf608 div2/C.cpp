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
int l,r,up,down;
int n,sx,sy;
int main()
{
	cin>>n>>sx>>sy;
	int t1,t2,t3,t4,p1,p2,p3,p4;
	t1=t2=t3=t4=p1=p2=p3=p4=0;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		read(x),read(y);
		if(x>sx&&y>sy) t1++;
		if(x>sx&&y<sy) t2++;
		if(x<sx&&y>sy) t3++;
		if(x<sx&&y<sy) t4++;
		if(x==sx&&y>sy) p4++;
		if(x==sx&&y<sy) p2++;
		if(y==sy&&x>sx) p1++;
		if(y==sy&&x<sx) p3++;
	}
	p1+=t1+t2,p2+=t2+t4,p3+=t4+t3,p4+=t3+t1;
	cout<<max(max(p1,p2),max(p3,p4))<<endl;
	int temp=max(max(p1,p2),max(p3,p4));
	if(p1==temp) cout<<sx+1<<" "<<sy<<endl;
	else if(p2==temp) cout<<sx<<" "<<sy-1<<endl;
	else if(p3==temp) cout<<sx-1<<" "<<sy<<endl;
	else if(p4==temp) cout<<sx<<" "<<sy+1<<endl;
	return 0;
}

