//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<algorithm>
#include<iomanip>
#define LL long long int
#define maxn 100010
//#pragma warning(disable : 4996)
using namespace std;

int D[maxn];
int TN[maxn];
vector<int> G[maxn];
vector<int> T[maxn];
vector<LL> TS[maxn];
map<int,double> S[maxn];

struct Furthest{
	int s,t,x,maxl,N;
	
	void DFS1(int u,int f,int l){
		if(l>maxl){
			x=u;
			maxl=l;		
		}
		TN[u]=N;
		for(auto it=G[u].begin();it!=G[u].end();++it){
			int v=*it;
			if(v!=f)
				DFS1(v,u,l+1);
		}
	}
	
	void DFS2(int u,int f,int l){
		if(l>maxl){
			x=u;
			maxl=l;	
		}
		if(l>D[u])
			D[u]=l;
		for(auto it=G[u].begin();it!=G[u].end();++it){
			int v=*it;
			if(v!=f)
				DFS2(v,u,l+1);
		}
	}
	
	void DFS3(int u,int f,int l){
		if(l>D[u])
			D[u]=l;
		T[N].push_back(D[u]);
		for(auto it=G[u].begin();it!=G[u].end();++it){
			int v=*it;
			if(v!=f)
				DFS3(v,u,l+1);
		}
	}
	
	void Find(int u,int n){
		N=n;
		maxl=-1;
		DFS1(u,-1,0);
		s=x;
		maxl=-1;
		DFS2(s,-1,0);
		t=x;
		DFS3(t,-1,0);
		sort(T[N].begin(),T[N].end());
		TS[N].push_back(0);
		for(int i=1;i<=T[N].size();++i)
			TS[N].push_back(T[N][i-1]+TS[N][i-1]);
		if(D[t]!=D[s])
			cout<<"Wrong!"<<endl;
	}
};

Furthest fest;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int n,m,q,i,j,k,x,y,cnt,u,v;
	cin>>n>>m>>q;
	for(i=0;i<m;++i){
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	cnt=0;
	memset(D,0xFF,sizeof(D));
	for(i=1;i<=n;++i)
		if(D[i]<0)
			fest.Find(i,cnt++);
	
	
	for(i=0;i<q;++i){
		cin>>u>>v;
		x=TN[u];
		y=TN[v];
		if(x==y)
			cout<<-1<<endl;
		else{
			if(T[x].size()>T[y].size())
				swap(x,y);
			if(S[x].find(y)!=S[x].end())
				cout<<S[x][y]<<endl;
			else{
				int minv,maxl;
				double sum=0;
				for(j=0;j<T[x].size();++j){
					u=T[x][j];
					maxl=max(*T[x].rbegin(),*T[y].rbegin());
					minv=maxl-u;
					k=lower_bound(T[y].begin(),T[y].end(),minv)-T[y].begin();
					sum+=(LL)maxl*k+*TS[y].rbegin()-TS[y][k]+(T[y].size()-k)*(u+1);
				}
				sum/=T[x].size()*T[y].size();
				S[x][y]=sum;
				cout<<fixed<<setprecision(10)<<sum<<endl;
			}
		}
	}
	return 0;
}

