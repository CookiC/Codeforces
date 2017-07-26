//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cstring>
#include<vector>
#define LL long long
#define maxn 100010
#define maxb 21
//#pragma warning(disable : 4996)
using namespace std;

int n;
bool vis[maxn];
int a[maxn];
LL d[maxn][maxb],c[maxn],res[maxb];
vector<int> G[maxn];

void DToB(int x,LL *a){
	int i=0;
	while(x){
		if(x&1)
			a[i]=1;
		x>>=1;
		++i;
	}
}

LL BToD(LL *a){
	LL ans=0,p=1;
	for(int i=0;i<maxb;++i){
		ans+=p*a[i];
		p<<=1;
	}
	return ans;
}

void Dfs(int u,int f){
	int i;
	LL b[maxb]={0};
	DToB(a[u],b);
	c[u]=1;
	memcpy(d[u],b,sizeof(b));
	for(i=0;i<maxb;++i)
		res[i]+=b[i];
	for(auto &v:G[u])
		if(v!=f){
			Dfs(v,u);
			for(i=0;i<maxb;++i)
				res[i]+=d[u][i]*(c[v]-d[v][i])+(c[u]-d[u][i])*d[v][i];
			for(i=0;i<maxb;++i)
				d[u][i]+=b[i]?c[v]-d[v][i]:d[v][i];
			c[u]+=c[v];
		}
	vis[u]=1;
//	cout<<u<<' '<<c[u]<<endl;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,u,v;
	cin>>n;
	for(i=1;i<=n;++i)
		cin>>a[i];
	for(i=0;i<n-1;++i){
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
//	cout<<"--------------\n";
	Dfs(1,-1);
/*	for(i=1;i<=n;++i){
		for(int j=0;j<maxb;++j)
			cout<<d[i][j]<<' ';
		cout<<endl;
	}*/
	cout<<BToD(res)<<endl;
	return 0;
}

