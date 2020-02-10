#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
int x1,y1,x2,y2;
int x3,y3,x4,y4;
int x5,y5,x6,y6;
int mp[50],num=0;
int a[100][100];
int main()
{
	cin>>x1>>y1>>x2>>y2;
	mp[++num]=x1,mp[++num]=y1,mp[++num]=x2,mp[++num]=y2;
	cin>>x3>>y3>>x4>>y4;
	mp[++num]=x3,mp[++num]=y3,mp[++num]=x4,mp[++num]=y4;
	cin>>x5>>y5>>x6>>y6;
	mp[++num]=x5,mp[++num]=y5,mp[++num]=x6,mp[++num]=y6;
	sort(mp+1,mp+num+1);
	num=unique(mp+1,mp+num+1)-(mp+1);
	x1=lower_bound(mp+1,mp+num+1,x1)-mp;
	x2=lower_bound(mp+1,mp+num+1,x2)-mp;
	x3=lower_bound(mp+1,mp+num+1,x3)-mp;
	x4=lower_bound(mp+1,mp+num+1,x4)-mp;
	x5=lower_bound(mp+1,mp+num+1,x5)-mp;
	x6=lower_bound(mp+1,mp+num+1,x6)-mp;
	
	
	y1=lower_bound(mp+1,mp+num+1,y1)-mp;
	y2=lower_bound(mp+1,mp+num+1,y2)-mp;
	y3=lower_bound(mp+1,mp+num+1,y3)-mp;
	y4=lower_bound(mp+1,mp+num+1,y4)-mp;
	y5=lower_bound(mp+1,mp+num+1,y5)-mp;
	y6=lower_bound(mp+1,mp+num+1,y6)-mp;
	for(int i=x3;i<=x4-1;i++) for(int j=y3;j<=y4-1;j++) a[i][j]=1;
	for(int i=x5;i<=x6-1;i++) for(int j=y5;j<=y6-1;j++) a[i][j]=1;
	int flag=0;
	for(int i=x1;i<=x2-1;i++) for(int j=y1;j<=y2-1;j++) if(a[i][j]==0) flag=1;
	
	if(flag) puts("YES");
	else puts("NO");
	return 0;
}
