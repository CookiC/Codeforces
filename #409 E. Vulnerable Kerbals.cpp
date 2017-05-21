//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<vector>
#define LL long long int
#define maxn 200010
//#pragma warning(disable : 4996)
using namespace std;

bool b[maxn];
LL a[maxn],g[maxn];
vector<vector<int> > S;
vector<int> factor,dp,f,seq;

int Gcd(int a,int b){
	int t;
	while(b){
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}

void Gcd(int a,int b,int &d,int &x,int &y){
	if(!b){
		d=a;
		x=1;
		y=0;
	}
	else{
		Gcd(b,a%b,d,y,x);
		y-=x*(a/b);
	}
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j,n,m;
	cin>>n>>m;
	for(i=0;i<n;++i){
		cin>>j;
		if(j)
			b[j]=1;
		else
			b[m]=1;
	}
	
	for(i=1;i<=m;++i)
		if(m%i==0)
			factor.push_back(i);
	
	int size=factor.size();
	S.resize(size);
	dp.resize(size);
	f.resize(size,-1);
	
	int x,y,d;
	for(i=1;i<=m;++i)
		if(!b[i]){
			Gcd(i,m,d,x,y);
			j=lower_bound(factor.begin(),factor.end(),d)-factor.begin();
			S[j].push_back(i);
			y=m/d;
			a[i]=(x+y)%y;
			g[i]=d;
		}

	int u,v,ans=0,maxd;
	for(u=size-1;u>=0;--u){
		dp[u]=S[u].size();
		maxd=0;
		for(v=size-1;v>u;--v)
			if(factor[v]%factor[u]==0&&maxd<dp[v]){
				maxd=dp[v];
				f[u]=v;
			}
		dp[u]+=maxd;
		if(ans<dp[u]){
			ans=dp[u];
			i=u;
		}
	}
	
	do{
		for(j=0;j<S[i].size();++j)
			seq.push_back(S[i][j]);
		i=f[i];
	}while(i>=0);
	
	cout<<ans<<endl;
	cout<<seq[0]%m<<' ';
	for(i=1;i<seq.size();++i)
		cout<<a[seq[i-1]]*seq[i]/g[seq[i-1]]%m<<' ';
	cout<<endl;
	return 0;
}

