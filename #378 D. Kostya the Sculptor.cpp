//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#define maxn 100010
//#pragma warning(disable : 4996)
using namespace std;

struct Rec{
	int a[3],i;
	void assign(int x,int y,int z,int j){
		if(x<y)
			swap(x,y);
		if(x<z)
			swap(x,z);
		if(y<z)
			swap(y,z);
		a[0]=x;
		a[1]=y;
		a[2]=z;
		i=j;
	}
	
	bool operator < (const Rec &b) const{
		for(int i=0;i<3;++i)
			if(a[i]!=b.a[i])
				return a[i]>b.a[i];
		return false;
	}
};

int n;
Rec a[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int x,y,z,i;
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>x>>y>>z;
		a[i].assign(x,y,z,i);
	}
	sort(a+1,a+n+1);
	int k=1,l=a[n].a[2];
	x=n;
	for(i=1;i<n;++i){
		if(a[i].a[0]==a[i+1].a[0]&&a[i].a[1]==a[i+1].a[1]){
			z=min(a[i].a[1],a[i].a[2]+a[i+1].a[2]);
			if(z>l){
				l=z;
				k=2;
				x=a[i].i;
				y=a[i+1].i;
			}
		}
		else if(a[i].a[2]>l){
			l=a[i].a[2];
			k=1;
			x=a[i].i;
		}
	}
	cout<<k<<endl;
	if(k==1)
		cout<<x<<endl;
	else
		cout<<x<<' '<<y<<endl;
	return 0;
}
