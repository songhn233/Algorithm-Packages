#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=b;i--)

int a[200010];
int b[200010];
bool vis[200010];

int main(){
	int n,z;
	scanf("%d",&z);
	while(z--){
		scanf("%d",&n);
		int maxe=0;
		rep(i,1,n){
			scanf("%d",&a[i]);
			b[i]=a[i];
			maxe=max(maxe,a[i]);
		}
		//sit1
		sort(a+1,a+n-maxe+1);
		sort(a+n-maxe+1,a+n+1);
		bool flag1=1,flag2=1;
		if(maxe*2==n) flag1=0;
		if(flag1){
			for(int i=1;i<=n-maxe;i++){
				if(a[i]!=i){
					//cout<<"!1"<<endl;
					flag1=0;break;
				}
			}
		}
		if(flag1){
			for(int i=n-maxe+1;i<=n;i++){
				if(a[i]!=i-n+maxe){
					//cout<<"!2"<<endl;
					flag1=0;break;
				}
			}
		}
		//sit2
		sort(b+1,b+maxe+1);
		sort(b+maxe+1,b+n+1);
		for(int i=1;i<=maxe;i++){
			if(b[i]!=i){
				//cout<<"!1"<<endl;
				flag2=0;break;
			}
		}
		if(flag2){
			for(int i=maxe+1;i<=n;i++){
				if(b[i]!=i-maxe){
					//cout<<"!2"<<endl;
					flag2=0;break;
				}
			}
		}
		if(flag1&&flag2){
			cout<<2<<endl;
			cout<<n-maxe<<' '<<maxe<<endl;
			cout<<maxe<<' '<<n-maxe<<endl;
		}
		else if(flag1){
			cout<<1<<endl;
			cout<<n-maxe<<' '<<maxe<<endl;
		}
		else if(flag2){
			cout<<1<<endl;
			cout<<maxe<<' '<<n-maxe<<endl;
		}
		else cout<<0<<endl;
	}
}
