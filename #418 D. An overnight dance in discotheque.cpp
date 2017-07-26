//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<vector>
#include<iomanip>
#define PI 3.14159265358979323846
#define maxn 1010
//#pragma warning(disable : 4996)
using namespace std;

int n;
int f[maxn];
double x[maxn],y[maxn],r[maxn],d[maxn][2][2]={0};
vector<int> G[maxn];

double dp(int u,bool a,bool b){
	if(d[u][a][b]!=0)
		return d[u][a][b];
	double ans;
	if(a==1)
		ans=r[u]*r[u];
	else
		ans=-r[u]*r[u];
	if(a==b)
		for(auto &v:G[u])
			ans+=dp(v,!a,b);
	else{
		double suma=0,sumb=0;
		for(auto &v:G[u])
			suma+=dp(v,!a,b);
		for(auto &v:G[u])
			sumb+=dp(v,!b,a);
		ans+=max(suma,sumb);
	}
	return d[u][a][b]=ans;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j;
	cin>>n;
	for(i=1;i<=n;++i) 
		cin>>x[i]>>y[i]>>r[i]; 
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			if(i!=j&&r[i]<r[j]&&(r[j]-r[i])*(r[j]-r[i])>=(x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i])&&(!f[i]||r[j]<r[f[i]]))
				f[i]=j;
	for(i=1;i<=n;++i)
		G[f[i]].push_back(i);
	cout<<setprecision(12)<<dp(0,0,0)*PI<<endl;
	return 0;
}

