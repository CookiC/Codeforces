//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<vector>
#include<stack>
#define INF 0x7FFFFFFF
#define maxn 400010
using namespace std;

struct Edge{
	int u,v;
	Edge(int u,int v):u(u),v(v){}
};

int n,m,clk,cnt;
int num[maxn],pre[maxn],cpt[maxn];
vector<int> G[maxn];
vector<Edge> cut;
stack<int> s;

int Dfs(int u,int f){
	int lowu=pre[u]=++clk;
	s.push(u);
	for(auto e=G[u].begin();e!=G[u].end();++e){
		int v=*e;
		if(!pre[v]){
			int lowv=Dfs(v,u);
			lowu=min(lowu,lowv);
			if(lowv>pre[u]){
				cut.push_back(Edge(u,v));
				++cnt;
				while(s.top()!=u){
					num[s.top()]=cnt;
					s.pop();
				}
			}
		}
		else if(pre[u]>pre[v]&&v!=f)
			lowu=min(lowu,pre[v]);
	}
	return lowu;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int u,v,i;
	cin>>n>>m;
	for(i=0;i<m;++i){
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	clk=0;
	cnt=0;
	for(i=1;i<=n;++i)
		if(!pre[i])
			Dfs(i,-1);
	
	for(i=1;i<=n;++i)
		++cpt[num[i]];
	
	int minn=INF;
	for(i=1;i<=cnt;++i)
		if(minn>cpt[i])
			minn=cpt[i];
	
	cout<<minn<<endl;
	return 0;
}

