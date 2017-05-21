//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<vector>
#define maxn 200010
//#pragma warning(disable : 4996)
using namespace std;

int n,k;
int F[maxn],C[maxn];
vector<int> G[maxn];

void Dfs(int u){
	int v,cnt=1;
	for(auto it=G[u].begin();it!=G[u].end();++it){
		v=*it;
		if(v!=F[u]){
			F[v]=u;
			while(cnt==C[u]||cnt==C[F[u]]) ++cnt;
			C[v]=cnt++;
		}
	}
	if(cnt-1>k)
		k=cnt-1;
	for(auto it=G[u].begin();it!=G[u].end();++it){
		v=*it;
		if(v!=F[u])
			Dfs(v);
	}
	
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int u,v,i;
	cin>>n;
	for(i=0;i<n-1;++i){
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	F[1]=0;
	C[1]=1;
	C[0]=0;
	k=0;
	Dfs(1);
	cout<<k<<endl;
	for(i=1;i<=n;++i)
		cout<<C[i]<<' ';
	cout<<endl; 
	return 0;
}

