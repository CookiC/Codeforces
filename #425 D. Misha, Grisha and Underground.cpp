//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<vector>
#include<cmath>
#define maxn 100010
//#pragma warning(disable : 4996)
using namespace std;

int n; //结点的个数
vector<int> G[maxn];
int H[maxn],F[maxn][28]; //第二维为log2(maxn). 对于1e5, 17就够了

void Dfs(int u,int f) {
	for (int i = 1; (1 << i) <= H[u]; ++i)
		F[u][i] = F[F[u][i-1]][i-1];
	for (auto &v : G[u])
		if(v!=f){
			H[v]=H[u] + 1;
			F[v][0]=u;
			Dfs(v,u);
		}
}

void InitLCA(int root) {
	H[root] = 0;
	Dfs(root,-1);
}

int LCA(int u, int v) {
	if (H[u]>H[v]) swap(u, v);
	int dH = H[v] - H[u],i=0,h;
	for(i=0;dH;++i){
		if (dH&1)
			v=F[v][i];
		dH>>=1;
	}
	
	if (u==v)
		return u;
	i=0;
	for(h=H[u]>>1;h;h>>=1)
		++i;
	while(i >= 0){
		if (F[u][i] != F[v][i]) {
			u = F[u][i];
			v = F[v][i];
		}
		--i;
	}
	return F[u][0];
}

int q;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int u,v,a,b,c,x,i,y,z;
	cin>>n>>q;
	for(v=2;v<=n;++v){
		cin>>u;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	InitLCA(1);
/*	for(x=1;x<=5;++x){
		cout<<x<<": ";
		for(y=0;y<3;++y)
			cout<<F[x][y]<<' ';
		cout<<endl;
	}*/
	for(i=0;i<q;++i){
		cin>>a>>b>>c;
		x=H[a]+H[b]-2*H[LCA(a,b)];
		y=H[b]+H[c]-2*H[LCA(b,c)];
		z=H[a]+H[c]-2*H[LCA(a,c)];
//		cout<<LCA(a,b)<<' '<<LCA(b,c)<<' '<<LCA(a,c)<<endl;
//		cout<<x<<' '<<y<<' '<<z<<endl;
		cout<<max(max(x+y-z,x+z-y),y+z-x)/2+1<<endl;
	}
	return 0;
}

