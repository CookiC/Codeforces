//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cstring>
#define maxn 5010
//#pragma warning(disable : 4996)
using namespace std;

int n;
bool ign[maxn],vis[maxn];
int L[maxn],R[maxn],a[maxn],sum[maxn];
int dp[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j;
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>a[i];
		if(!L[a[i]])
			L[a[i]]=i;
		R[a[i]]=i;
	}
	
	for(i=n;i>=1;--i)
		if(L[a[i]]==i){
			int Li=L[a[i]];
			int mR=R[a[i]];
			memset(vis,0,sizeof(vis));
			vis[a[i]]=1;
			sum[a[i]]=a[i];
			for(j=i+1;j<mR;++j){
				if(vis[a[j]])
					continue;
				vis[a[j]]=1;
				if(L[a[j]]<Li)
					break;
				mR=max(mR,R[a[j]]);
				sum[a[i]]^=a[j];
			}
			if(j<mR)
				ign[i]=1;
			else
				R[a[i]]=mR;
		}
		else
			ign[i]=1;
/*	for(i=1;i<=n;++i)
		if(!ign[i])
		cout<<L[a[i]]<<' '<<R[a[i]]<<' '<<sum[i]<<'\n';
	cout<<endl;*/
	
	for(i=1;i<=n;++i){
		dp[i+1]=max(dp[i],dp[i+1]);
		if(!ign[i])
			dp[R[a[i]]+1]=max(dp[R[a[i]]+1],dp[i]+sum[a[i]]);
	}
	cout<<dp[n+1]<<endl;
	return 0;
}
