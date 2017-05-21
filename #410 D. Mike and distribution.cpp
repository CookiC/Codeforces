//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#define maxn 100010
//#pragma warning(disable : 4996)
using namespace std;

struct Pair{
	int a,b,id;
	bool operator < (const Pair &b) const{
		return a>b.a;
	}
};

Pair a[maxn];
int cnt;
int ans[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int n,i;
	cin>>n;
	for(i=0;i<n;++i)
		cin>>a[i].a;
	for(i=0;i<n;++i){
		cin>>a[i].b;
		a[i].id=i+1;
	}
	sort(a,a+n);
	
	cnt=1;
	ans[0]=a[0].id;
	for(i=1;i+1<n;i+=2)
		ans[cnt++]=a[i].b>a[i+1].b?a[i].id:a[i+1].id;
	if(n%2==0)
		ans[cnt++]=a[n-1].id;
	cout<<cnt<<endl;
	for(i=0;i<cnt;++i)
		cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}

