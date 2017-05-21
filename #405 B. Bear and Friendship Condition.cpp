//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxn 150010
#define LL long long
//#pragma warning(disable : 4996)
using namespace std;

int n,m,a,b,i;
int P[maxn];
LL E[maxn],N[maxn];

int find(int x){
	return P[x]==x?x:P[x]=find(P[x]);
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	
	cin>>n>>m;
	for(i=1;i<=n;++i){
		P[i]=i;
		E[i]=0;
		N[i]=1;
	}
	
	for(i=0;i<m;++i){
		cin>>a>>b;
		int x=find(a);
		int y=find(b);
		if(x!=y){
			P[y]=x;
			N[x]+=N[y];
			E[x]+=E[y];
			N[y]=0;
			E[y]=0;
		}
		++E[x];
	}
	
	for(i=1;i<=n;++i)
		if(N[i]&&N[i]*(N[i]-1)/2>E[i])
			break;
	
	if(i<=n)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
	return 0;
}

