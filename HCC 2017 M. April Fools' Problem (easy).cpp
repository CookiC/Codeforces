//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#define maxn 3000
//#pragma warning(disable : 4996)
using namespace std;

int n,k;
int ans=0;
int a[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i;
	cin>>n>>k;
	for(i=0;i<n;++i)
		cin>>a[i];
	sort(a,a+n);
	for(i=0;i<k;++i)
		ans+=a[i];
	cout<<ans<<endl;
	return 0;
}

