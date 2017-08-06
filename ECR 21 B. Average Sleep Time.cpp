//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<iomanip>
#define maxn 200010
//#pragma warning(disable : 4996)
using namespace std;

int n,k;
double a[maxn],sum[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i;
	cin>>n>>k;
	for(i=1;i<=n;++i)
		cin>>a[i];
	sum[0]=0;
	for(i=1;i<=n;++i)
		sum[i]=a[i]+sum[i-1];
	double ans=0;
	for(i=k;i<=n;++i)
		ans+=sum[i]-sum[i-k];
	cout<<setprecision(8)<<fixed<<ans/(n-k+1)<<endl;
	return 0;
}

