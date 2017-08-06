//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#define LL long long
#define INF 0x7FFFFFFF
#define maxn 200010
//#pragma warning(disable : 4996)
using namespace std;

LL t;
int n,k,s;
int c[maxn],v[maxn],ci[maxn],p[maxn],w[maxn],g[maxn];

bool cmpC(const int i,const int j){
	if(c[i]==c[j])
		return v[i]>v[j];
	return c[i]<c[j];
}

bool ok(int v){
	LL u=0;
	int i,x,y;
	for(i=1;i<k;++i){
		x=g[i]-g[i-1];
		if(v>=x&&u<=t){
			y=min(v-x,x);
			u+=y+(x-y)*2;
		}
		else
			break;
	}
	if(i<k||u>t)
		return false;
	return true;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j,x,y;
	cin>>n>>k>>s>>t;
	for(i=0;i<n;++i){
		cin>>c[i]>>v[i];
		ci[i]=i;
	}
	for(i=0;i<k;++i)
		cin>>g[i];
	g[k++]=0;
	g[k++]=s;
	sort(g,g+k);
	sort(ci,ci+n,cmpC);
	j=1;
	p[0]=c[ci[0]];
	w[0]=v[ci[0]];
	for(i=1;i<n;++i)
		if(v[ci[i]]>w[j-1]){
			p[j]=c[ci[i]];
			w[j]=v[ci[i]];
			++j;
		}
	n=j;
	int L=0,R=n-1,M;
	while(L<R){
		M=L+(R-L)/2;
		if(ok(w[M]))
			R=M;
		else
			L=M+1;
	}
	if(ok(w[L]))
		cout<<p[L]<<endl;
	else
		cout<<-1<<endl;
	return 0;
}

