//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
//#pragma warning(disable : 4996)
using namespace std;

const int maxn=3*1e5+7;

int n,m,maxs;
int C[maxn]={0};
vector<int> S[maxn];
vector<int> G[maxn];

void DFS(int u,int f){
	static set<int> s;
	
	s.clear();
	for(auto i=S[u].begin();i!=S[u].end();++i)
		if(C[*i])
			s.insert(C[*i]);
	
	int cnt=1;
	for(auto i=S[u].begin();i!=S[u].end();++i)
		if(!C[*i]){
			while(s.find(cnt)!=s.end())
				++cnt;
			C[*i]=cnt++;
		}
	
	for(auto v=G[u].begin();v!=G[u].end();++v)
		if(*v!=f)
			DFS(*v,u);
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j,t,u,v,s;
	maxs=1;
	cin>>n>>m;
	for(i=1;i<=n;++i){
		cin>>s;
		if(s>maxs)
			maxs=s;
		for(j=0;j<s;++j){
			cin>>t;
			S[i].push_back(t);
		}
	}
	for(i=0;i<n-1;++i){
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	DFS(1,-1);
	cout<<maxs<<endl;
	for(i=1;i<=m;++i)
		if(C[i])
			cout<<C[i]<<' ';
		else
			cout<<1<<' ';
	cout<<endl;
	return 0;
}

