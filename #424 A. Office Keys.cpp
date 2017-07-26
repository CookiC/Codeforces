//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#define INF 0x7FFFFFFF 
#define maxn 2010
//#pragma warning(disable : 4996)
using namespace std;

int n,k,p,L,R;
int a[maxn],b[maxn];

bool reach(int t){
	int i=0,j;
	for(j=0;j<k&&i<n;++j)
		if(abs(a[i]-b[j])+abs(b[j]-p)<=t)
			++i;
	if(i>=n)
		return true;
	return false;
}

int binary(){
	int L=0,R=INF,M;
	while(L<R){
		M=L+(R-L)/2;
		if(reach(M))
			R=M;
		else
			L=M+1;
	}
	return L;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i;
	cin>>n>>k>>p;
	for(i=0;i<n;++i)
		cin>>a[i];
	sort(a,a+n);
	for(i=0;i<k;++i)
		cin>>b[i];
	sort(b,b+k);
	cout<<binary()<<endl;
	return 0;
}

