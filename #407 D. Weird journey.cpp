//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxn 1000010
#define LL long long
//#pragma warning(disable : 4996)
using namespace std;

bool vis[maxn];
int n,m,u,v,i;
int cnt[maxn];
LL ans,t1,t2;
int p[maxn];

int find(int x){
	return p[x]==x?x:p[x]=find(p[x]);
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	bool b;
	int x,y;
	cin>>n>>m;
	for(i=1;i<=n;++i)
		p[i]=i;
	
	for(i=0;i<m;++i){
		cin>>u>>v;
		vis[u]=vis[v]=1;
		x=find(u);
		y=find(v);
		p[y]=x;
		if(u==v)
			++t1;
		else{
			++cnt[u];
			++cnt[v];
			++t2;
		}
	}
	
	b=true;
	for(i=1;i<=n&&!vis[i];++i);
	x=find(i);
	for(++i;i<=n&&b;++i)
		if(vis[i]&&find(i)!=x)
			b=false;

	if(b){
		ans=0;
		for(i=1;i<=n;++i)
			if(cnt[i])
				ans+=(LL)cnt[i]*(cnt[i]-1)/2;
		ans+=t1*t2+t1*(t1-1)/2;
		cout<<ans<<endl;
	}
	else
		cout<<0<<endl;
	return 0;
}

