#include<iostream>
#include<vector>
#define maxn 200010
using namespace std;

int n,x,len;
int f[maxn],d[maxn];
vector<int> G[maxn];

void Dfs1(int u){
	for(auto &v:G[u])
		if(v!=f[u]){
			f[v]=u;
			d[v]=d[u]+1;
			Dfs1(v);
		}
}

int Dfs2(){
}

int main(){
	ios::sync_with_stdio(false);
	
	int i,j;
	cin>>n>>x;
	for(i=0;i<n-1;++i){
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	f[1]=-1;
	d[1]=0;
	Dfs1(1);
	j=x;
	for(i=0;i<len/2;++i)
		j=f[j];
	Dfs2(j);
	return 0;
}

