//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxn 5010
//#pragma warning(disable : 4996)
using namespace std;

int n;
int L[maxn],R[maxn];
int a[maxn],sum[maxn];
int dp[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i;
	cin>>n;
	sum[0]=0;
	for(i=1;i<=n;++i){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		if(!L[a[i]])
			L[a[i]]=i;
		R[a[i]]=i;
	}
	
	int comf;
	dp[1]=0;
	for(i=1;i<=n;++i){
		if(L[a[i]]==i){
			comf=sum[R[a[i]]]^sum[L[a[i]]];
			dp[R[a[i]]]
		}
		dp[i+1]=max(dp[i],dp[i+1])
	}
	cout<<dp[n+1]<<endl;
	return 0;
}

