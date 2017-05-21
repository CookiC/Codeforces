//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#define maxn 1010
using namespace std;

class TwoSAT{
private:
	const static int maxm=maxn*2;
	
	int N; 
	int S[maxm],c;
	vector<int> G[maxm];
	
	bool DFS(int u){
		if(vis[u^1])
			return false;
		if(vis[u])
			return true;
		vis[u]=1;
		S[c++]=u;
		for(auto it=G[u].begin();it!=G[u].end();++it){
			int v=*it;
			if(!DFS(v))
				return false;
		}
		return true;
	}
	
public:
	bool vis[maxm];
	
	void Clear(int n){
		N=n;
		for(int i=2;i<N*2;++i)
			G[i].clear();
		memset(vis,0,sizeof(bool)*N*2);
	}
	
	void AddClause(int x,int xv,int y,int yv){
		x=x*2+xv;
		y=y*2+yv;
		G[x^1].push_back(y);
		G[y^1].push_back(x);
	}
	
	bool Solve(){
		int i;
		for(i=2;i<N*2;i+=2)
			if(!vis[i]&&!vis[i+1]){
				c=0;
				if(!DFS(i)){
					while(c>0)
						vis[S[--c]]=0;
					if(!DFS(i+1))
						return false;
				}
			}
		return true;
	}
};

int n;
string s[maxn][2];
TwoSAT sat;
 
int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j,k,l;
	string a,b,t;
	cin>>n;
	sat.Clear(n+1);
	for(i=1;i<=n;++i){
		cin>>a>>b;
		s[i][0]=a.substr(0,3);
		s[i][1]=a.substr(0,2)+b.substr(0,1);
	}
	
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			if(i!=j){
				if(s[i][0]==s[j][0]){
					sat.AddClause(i,0^1,j,0^1);
					sat.AddClause(i,1^1,j,0^1);
					sat.AddClause(i,0^1,j,1^1);
				}
				if(s[i][1]==s[j][1]){
					sat.AddClause(i,1^1,j,1^1);
					sat.AddClause(i,0^1,j,1^1);
					sat.AddClause(i,1^1,j,0^1);
				}
				if(s[i][1]==s[j][0])
					sat.AddClause(i,1^1,j,0^1);
				if(s[i][0]==s[j][1])
					sat.AddClause(i,0^1,j,1^1);
			}
	
	if(sat.Solve()){
		cout<<"YES"<<endl; 
		for(i=1;i<=n;++i)
			if(sat.vis[i*2])
				cout<<s[i][0]<<endl;
			else
				cout<<s[i][1]<<endl; 
	}
	else
		cout<<"NO"<<endl;
	return 0;
}

