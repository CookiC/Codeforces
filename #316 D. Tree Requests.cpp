//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
#define maxn 500010
#define pause system("pause")
//#pragma warning(disable : 4996)
using namespace std;

vector<int> T[maxn];
vector<int> layer[maxn];
int L[maxn],R[maxn],S[maxn];
char c[maxn];
int clk;

bool cmpL (const int a,const int b){
	return L[a]<L[b];
}


bool cmpR (const int a,const int b){
	return R[a]<R[b];
};

void Dfs(int u,int f,int d){
	L[u]=clk++;
	S[u]=1<<c[u]-'a';
	if(layer[d].size())
		S[u]^=S[*layer[d].rbegin()];
	layer[d].push_back(u);
	for(auto v=T[u].begin();v!=T[u].end();++v)
		if(*v!=f)
			Dfs(*v,u,d+1);
	R[u]=clk++;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int n,m,u,v,i,h;
	cin>>n>>m;
	for(v=2;v<=n;++v){
		cin>>u;
		T[u].push_back(v);
		T[v].push_back(u);
	}
	for(i=1;i<=n;++i)
		cin>>c[i];
	
	clk=0;
	Dfs(1,-1,1);
	
	for(i=0;i<m;++i){
		cin>>v>>h;
		if(layer[h].size()){
			int x=lower_bound(layer[h].begin(),layer[h].end(),v,cmpL)-layer[h].begin();
			int y=upper_bound(layer[h].begin(),layer[h].end(),v,cmpR)-layer[h].begin();
			--y;
			//cout<<x<<' '<<y<<endl;
			if(x<=y){
				x=layer[h][x];
				y=layer[h][y];
				int ans=S[x]^1<<c[x]-'a'^S[y];
				if((ans&-ans)==ans)
					cout<<"Yes"<<endl;
				else
					cout<<"No"<<endl;
			}
			else
				cout<<"Yes"<<endl;
		}
		else
			cout<<"Yes"<<endl;
	}
	return 0;
}

