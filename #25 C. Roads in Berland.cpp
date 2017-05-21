//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxn 310
#define LL long long int
//#pragma warning(disable : 4996)
using namespace std;

int n,k,i,j,K;
int d[maxn][maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n;
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			cin>>d[i][j];
	
	int u,v,w;
	LL sum;
	cin>>K;
	for(i=0;i<K;++i){
		cin>>u>>v>>w;
		if(d[u][v]>w){
			d[u][v]=d[v][u]=w;
			for(j=1;j<=n;++j)
				for(k=j+1;k<=n;++k){
					if(d[j][k]>d[j][u]+d[u][v]+d[v][k]){
						d[j][k]=d[j][u]+d[u][v]+d[v][k];
						d[k][j]=d[j][k];
					}
					if(d[j][k]>d[j][v]+d[v][u]+d[u][k]){
						d[j][k]=d[j][v]+d[v][u]+d[u][k];
						d[k][j]=d[j][k];
					}
				}
		}
		
		sum=0;
		for(j=1;j<=n;++j)
			for(k=j+1;k<=n;++k)
				sum+=d[j][k];
		cout<<sum<<endl;
	}
	return 0;
}

