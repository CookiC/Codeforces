//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#define LL long long
#define maxn 100010
//#pragma warning(disable : 4996)
using namespace std;

LL ans;
int n,f;
int a[maxn],b[maxn],c[maxn],ci[maxn];

bool cmpC(const int &a,const int &b){
	return c[a]>c[b];
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i;
	cin>>n>>f;
	for(i=0;i<n;++i){
		cin>>a[i]>>b[i];
		ans+=min(a[i],b[i]);
		c[i]=min(a[i]*2,b[i])-min(a[i],b[i]);
		ci[i]=i;
	}
	sort(ci,ci+n,cmpC);
	for(i=0;i<f;++i){
		ans+=c[ci[i]];
//		cout<<ci[i]<<' '<<c[ci[i]]<<endl; 
	}
	cout<<ans<<endl;
	return 0;
}

