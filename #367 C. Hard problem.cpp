//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<string>
#include<algorithm>
#define LL long long int
#define INF 0x7FFFFFFFFFFFFFFF
#define maxn 100010n
//#pragma warning(disable : 4996)
using namespace std;

int n;
string s[maxn];
string r[maxn];
int c[maxn];
LL dp[maxn][2];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i;
	cin>>n;
	for(i=0;i<n;++i)
		cin>>c[i];
	
	for(i=0;i<n;++i){
		cin>>s[i];
		r[i]=s[i];
		reverse(r[i].begin(),r[i].end());
	}
	
	dp[0][0]=0;
	dp[0][1]=c[0];
	for(i=1;i<n;++i){
		dp[i][0]=INF;
		dp[i][1]=INF;
		if(s[i]>=s[i-1]&&dp[i][0]>dp[i-1][0])
			dp[i][0]=dp[i-1][0];
		if(s[i]>=r[i-1]&&dp[i][0]>dp[i-1][1])
			dp[i][0]=dp[i-1][1];
		
		if(r[i]>=s[i-1]&&dp[i-1][0]!=INF&&dp[i][1]>dp[i-1][0]+c[i])
			dp[i][1]=dp[i-1][0]+c[i];
		if(r[i]>=r[i-1]&&dp[i-1][1]!=INF&&dp[i][1]>dp[i-1][1]+c[i])
			dp[i][1]=dp[i-1][1]+c[i];
		if(dp[i][0]==INF&&dp[i][1]==INF)
			break;
	}
	
	if(i<n)
		cout<<-1<<endl;
	else
		cout<<min(dp[n-1][0],dp[n-1][1])<<endl;
	return 0;
}

