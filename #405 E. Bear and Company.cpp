//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define INF 0x7FFFFFFF
#define maxn 80
//#pragma warning(disable : 4996)
using namespace std;

int n;
char s[maxn];
char sum[3];
int dp[maxn][maxn][maxn][3],pos[3][maxn][3];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j,k,l;
	int *p;
	cin>>n>>s;
	for(i=0;i<n;++i)
		if(s[i]=='V'){
			pos[0][sum[0]][0]=i;
			pos[0][sum[0]][1]=sum[1];
			pos[0][sum[0]++][2]=sum[2];
		}
		else if(s[i]=='K'){
			pos[1][sum[1]][0]=sum[0];
			pos[1][sum[1]][1]=i;
			pos[1][sum[1]++][2]=sum[2];
		}
		else{
			pos[2][sum[2]][0]=sum[0];
			pos[2][sum[2]][1]=sum[1];
			pos[2][sum[2]++][2]=i;
		}
	
	for(i=0;i<=sum[0];++i)
		for(j=0;j<=sum[1];++j)
			for(k=0;k<=sum[2];++k)
				for(l=0;l<=2;++l)
					dp[i][j][k][l]=INF;
	
	p=dp[0][0][0];
	p[0]=0;
	p[1]=0;
	p[2]=0;
	for(i=0;i<=sum[0];++i)
		for(j=0;j<=sum[1];++j)
			for(k=0;k<=sum[2];++k){
				p=dp[i][j][k];
				if(i){
					p[0]=min(min(dp[i-1][j][k][0],dp[i-1][j][k][1]),dp[i-1][j][k][2]);
					if(p[0]!=INF)
						p[0]+=(pos[0][i-1][1]>j?pos[0][i-1][1]-j:0)+(pos[0][i-1][2]>k?pos[0][i-1][2]-k:0);
				}
				if(j){
					p[1]=min(dp[i][j-1][k][1],dp[i][j-1][k][2]);
					if(p[1]!=INF)
						p[1]+=(pos[1][j-1][0]>i?pos[1][j-1][0]-i:0)+(pos[1][j-1][2]>k?pos[1][j-1][2]-k:0);
				}
				if(k){
					p[2]=min(min(dp[i][j][k-1][0],dp[i][j][k-1][1]),dp[i][j][k-1][2]);
					if(p[2]!=INF)
						p[2]+=(pos[2][k-1][0]>i?pos[2][k-1][0]-i:0)+(pos[2][k-1][1]>j?pos[2][k-1][1]-j:0);
				}
			}
	int ans=0x7FFFFFFF;
	p=dp[sum[0]][sum[1]][sum[2]];
	if(sum[0]&&ans>p[0])
		ans=p[0];
	if(sum[1]&&ans>p[1])
		ans=p[1];
	if(sum[2]&&ans>p[2])
		ans=p[2];
	cout<<ans<<endl;
	return 0;
}

