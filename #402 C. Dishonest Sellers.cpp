//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#define LL long long
//#pragma warning(disable : 4996)
using namespace std;

const int maxn=2*1e5+5;

int n,k,i,j,t;
int d[maxn];
LL sum;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n>>k;
	for(i=0;i<n;++i)
		cin>>d[i];
	for(i=0;i<n;++i){
		cin>>t;
		sum+=t;
		d[i]=d[i]-t;
	}
	
	sort(d,d+n);
	for(i=0;i<k||d[i]<0;++i)
		sum+=d[i];
	
	cout<<sum<<endl;
	return 0;
}

