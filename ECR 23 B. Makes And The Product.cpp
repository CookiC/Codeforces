//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#define LL long long
#define maxn 100010
//#pragma warning(disable : 4996)
using namespace std;

int n;
int a[maxn];
int b[3],cnt[3];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	LL i;
	cin>>n;
	for(i=0;i<n;++i)
		cin>>a[i];
	sort(a,a+n);
	LL ans=0;
	if(a[0]==a[1]&&a[1]==a[2]){
		for(i=3;i<n&&a[i]==a[0];++i);
		ans=i*(i-1)*(i-2)/6;
	}
	else if(a[1]==a[2]){
		for(i=3;i<n&&a[i]==a[1];++i);
		ans=(i-1)*(i-2)/2;
	}
	else{
		for(i=3;i<n&a[i]==a[2];++i);
		ans=i-2;
	}
	cout<<ans<<endl;
	return 0;
}

