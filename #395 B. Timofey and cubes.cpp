//Author:CookiC
//#include"stdafx.h"
#include<iostream>
//#pragma warning(disable : 4996)
using namespace std;

const int maxn=2*1e5+10;

int n;
int a[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i;
	cin>>n;
	for(i=1;i<=n;++i)
		cin>>a[i];
	int t;
	for(i=1;i<=n/2;++i)
		if(i%2){
			t=a[i];
			a[i]=a[n-i+1];
			a[n-i+1]=t;
		}
	for(i=1;i<=n;++i)
		cout<<a[i]<<' ';
	cout<<endl;
	return 0;
}

