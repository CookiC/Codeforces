//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#define maxn 200010
//#pragma warning(disable : 4996)
using namespace std;

int n,m,k,lt;
vector<int> G[maxn],c[maxn];
bool vis[maxn];

int cnt,N;

void Dfs(int u){
	if(cnt>=lt){
		cnt=0;
		++N;
	}
	int v;
	++cnt;
	c[N].push_back(u);
	vis[u]=1;
	for(auto it=G[u].begin();it!=G[u].end();++it){
		v=*it;
		if(!vis[v]){
			Dfs(v);
			if(cnt>=lt){
				cnt=0;
				++N; 
			}
			++cnt;
			c[N].push_back(u);
		}
	}
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int u,v,i;
	cin>>n>>m>>k;
	lt=(2*n+k-1)/k;
	for(i=0;i<m;++i){
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	N=0;
	cnt=0;
	Dfs(1);
	
	for(i=0;i<k;++i)
		if(c[i].size()){
			cout<<c[i].size()<<' ';
			for(auto it=c[i].begin();it!=c[i].end();++it)
				cout<<*it<<' ';
			cout<<endl;
		}
		else
			cout<<1<<' '<<1<<endl;
	return 0;
}

