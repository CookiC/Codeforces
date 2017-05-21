//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cstring>
#include<list>
#include<stack>
#include<queue>
#define LL long long
#define maxn 200010
#define maxk 5 
//#pragma warning(disable : 4996)
using namespace std;

int n,k,u,v,i,j;
bool vis[maxn];
int f[maxn];
list<int> G[maxn];
queue<int> q;
stack<int> s;
LL a[maxn][maxk],sum[maxn][maxk], ans;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	list<int>::iterator it;
	cin>>n>>k;
	for(i=0;i<n-1;++i){
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	f[1]=0;
	q.push(1);
	while(!q.empty()){
		u=q.front();
		q.pop();
		it=G[u].begin();
		while(it!=G[u].end())
			if(*it==f[u])
				G[u].erase(it++);
			else{
				f[*it]=u;
				q.push(*it++);
			}
	}
	
	ans = 0;
	s.push(1);
	while(!s.empty()){
		u=s.top();
		s.pop();
		if(!vis[u]){
			a[u][0]=1;
			for(i=1;i<k;++i)
				a[u][i]=0;
			if(G[u].size()){
				s.push(u);
				for(it=G[u].begin();it!=G[u].end();++it)
					s.push(*it);
			}
			vis[u]=true;
			continue;
		}
		else{
			for(it=G[u].begin();it!=G[u].end();++it){
				v = *it;
				for (i = 0; i < k; ++i)
					for (j = 0; j < k; ++j)
						if (a[u][i] && a[v][j])
							if (i + j + 1 <= k)
								ans += a[u][i] * a[v][j] + sum[u][i]* a[v][j] + a[u][i]*sum[v][j];
							else
								ans += 2 * a[u][i] * a[v][j] + sum[u][i]*a[v][j] + a[u][i]*sum[v][j];

				a[u][0] += a[v][k - 1];
				sum[u][0] += sum[v][k - 1] + a[v][k - 1];
				for (i = 1; i < k; ++i){
					a[u][i] += a[v][i-1];
					sum[u][i] += sum[v][i-1];
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

