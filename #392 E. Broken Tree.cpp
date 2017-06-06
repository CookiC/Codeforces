//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
#define LL long long int
#define maxn 200010
#define INF 0x7FFFFFFFFFFFFFFF
//#pragma warning(disable : 4996)
using namespace std;

int n;
LL w[maxn],p[maxn],sub[maxn],wr[maxn],pr[maxn],d[maxn];
vector<int> G[maxn];

bool Minimize(int u){
	sub[u]=0;
	for(auto it=G[u].begin();it!=G[u].end();++it){
		if(!Minimize(*it))
			return false;
		sub[u]+=sub[*it]+wr[*it];
	}
	
	if(p[u]>=sub[u]){
		d[u]=min(p[u]-sub[u],w[u]-1);
		wr[u]=w[u]-d[u];
		pr[u]=p[u]-d[u];
	}
	else
		return false;
//	cout<<u<<' '<<sub[u]<<' '<<d[u]<<endl;
	return true;
}

void Maximize(int u,LL &ud){
//	cout<<u<<' '<<ud<<endl;
	int v;
	for(auto it=G[u].begin();it!=G[u].end();++it){
		v=*it;
		if(ud>d[v]){
			ud-=d[v];
			pr[v]+=d[v];
			wr[v]+=d[v];
		}
		else{
			pr[v]+=ud;
			wr[v]+=ud;
			ud=0;
		}
	}
	
	LL vd,cd;
	for(auto it=G[u].begin();it!=G[u].end()&&ud;++it){
		v=*it;
		cd=min(pr[v]-sub[v],ud);
		vd=cd;
		Maximize(v,vd);
		ud-=cd-vd;
	}
}

int u[maxn],v[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int x,y,i;
	cin>>n;
	for(i=0;i<n-1;++i){
		cin>>x>>y;
		G[x].push_back(y);
		cin>>w[y]>>p[y];
		u[i]=x;
		v[i]=y;
	}
	
	p[1]=INF;
	w[1]=1;
	d[1]=0;
	if(Minimize(1)){
		LL t=INF;
		Maximize(1,t);
		cout<<n<<endl;
		for(i=0;i<n-1;++i)
			cout<<u[i]<<' '<<v[i]<<' '<<wr[v[i]]<<' '<<pr[v[i]]<<endl;
	}
	else
		cout<<-1<<endl;
	return 0;
}

