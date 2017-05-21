//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#define INF 0x7FFFFFFF
#define maxn 1010
//#pragma warning(disable : 4996)
using namespace std;

int a[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int n,m,u,v,w;
	int i,maxi,maxq=0,q;
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>q;
		if(maxq<q){
			maxq=q;
			maxi=i;
		}
		a[i]=INF;
	}
	a[maxi]=0;
	
	cin>>m;
	for(i=0;i<m;++i){
		cin>>u>>v>>w;
		if(a[v]>w)
			a[v]=w;
	}
	
	int ans=0;
	for(i=1;i<=n;++i){
		if(a[i]==INF){
			ans=-1;
			break;
		}
		ans+=a[i];
	}
	cout<<ans<<endl;
	return 0;
}

