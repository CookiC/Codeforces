//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#define maxn 100010
#define LL long long
//#pragma warning(disable : 4996)
using namespace std;

int n;
LL a[maxn],sum[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j;
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	if(sum[n]&1)
		cout<<"NO"<<endl;
	else{
		for(i=1;i<=n;++i){
			j=upper_bound(sum+1,sum+i,sum[n]/2-a[i])-sum;
			if(j>1&&sum[j-1]==sum[n]/2-a[i])
				break;
			j=upper_bound(sum+i+1,sum+n+1,sum[n]/2+a[i])-sum;
			if(j>i+1&&sum[j-1]==sum[n]/2+a[i])
				break;
		}
		if(i<=n)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}

