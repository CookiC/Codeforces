//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxn 200010
//#pragma warning(disable : 4996)
using namespace std;

int n;
int a[maxn],d[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i;
	cin>>n;
	for(i=0;i<n;++i)
		cin>>a[i];
	int ans=n;
	for(i=0;i<n;++i){
		if(a[i]==0)
			ans=0;
		else
			++ans;
		d[i]=ans;
	}
	ans=n;
	for(i=n-1;i>=0;--i){
		if(a[i]==0)
			ans=0;
		else
			++ans;
		d[i]=min(ans,d[i]);
	}
	for(i=0;i<n;++i)
		cout<<d[i]<<' ';
	cout<<endl;
	return 0;
}

