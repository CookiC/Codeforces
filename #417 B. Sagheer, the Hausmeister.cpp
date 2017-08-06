//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#define maxn 30
#define maxm 110
//#pragma warning(disable : 4996)
using namespace std;

int n,m;
int L[maxn],R[maxn],dp[maxn][2];
char s[maxn][maxm];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j;
	cin>>n>>m;
	for(i=n-1;i>=0;--i)
		cin>>s[i];
	for(i=0;i<n;++i)
		for(j=1;j<m+1;++j)
			if(s[i][j]=='1'){
				if(!L[i])
					L[i]=j;
				R[i]=j;
			}
	while(n>0&&!L[n-1])
		--n;
	if(n==0)
		cout<<0<<endl;
	else if(n==1)
		cout<<R[0]<<endl;
	else{
		if(L[0])
			dp[0][0]=R[0]*2;
		else
			dp[0][0]=0;
		dp[0][1]=m+1;
		for(i=1;i<n-1;++i)
			if(L[i]){
				dp[i][0]=min(dp[i-1][0]+R[i]*2,dp[i-1][1]+m+1)+1;
				dp[i][1]=min(dp[i-1][0]+m+1,dp[i-1][1]+(m+1-L[i])*2)+1;
			}
			else{
				dp[i][0]=dp[i-1][0]+1;
				dp[i][1]=dp[i-1][1]+1;
			}
		cout<<min(dp[n-2][0]+R[n-1],dp[n-2][1]+m+1-L[n-1])+1<<endl;
	}
	return 0;
}

