//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<vector>
#define maxn 100010 
//#pragma warning(disable : 4996)
using namespace std;

int n,u,v;
int c[maxn];
int P[maxn],cnt[maxn];
vector<int> G[maxn];

int find(int x){
	return P[x]==x?x:P[x]=find(P[x]);
}

bool valid(int u){
	int x=find(u);
	int sum=cnt[x];
	int i,v,y;
	for(i=0;i<G[u].size();++i){
		v=G[u][i];
		y=find(v);
		if(c[x]!=c[y])
			sum+=cnt[y];
	}
	
	if(sum==n)
		return true;
	return false;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j;
	cin>>n;
	for(i=0;i<n-1;++i){
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	for(i=1;i<=n;++i){
		cin>>c[i];
		cnt[i]=1;
		P[i]=i;	
	}
	
	int x,y;
	for(i=1;i<n;++i){
		for(j=0;j<G[i].size();++j){
			int &u=i;
			int &v=G[i][j];
			if(u<v&&c[u]==c[v]){
				x=find(u);
				y=find(v);
				if(x!=y){
					P[y]=x;
					cnt[x]+=cnt[y];
				}
			}
		}
	}
	
	for(i=1;i<=n;++i)
		if(valid(i)){
			cout<<"YES"<<endl;
			cout<<i<<endl;
			break;
		}
	
	if(i>n)
		cout<<"NO"<<endl;
	return 0;
}

