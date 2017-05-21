//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cmath>
#include<iomanip>
#define INF 0x7FFFFFFF
#define maxn 60010
//#pragma warning(disable : 4996)
using namespace std;

int n;
int x[maxn],v[maxn];

double Mint(double y){
	double t,mint=0;
	for(int i=0;i<n;++i){
		t=fabs(x[i]-y)/v[i];
		if(mint<t)
			mint=t;
	}
	return mint;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int maxx=0,i;
	cin>>n;
	for(i=0;i<n;++i){
		cin>>x[i];
		if(maxx<x[i])
			maxx=x[i];
	}
	for(i=0;i<n;++i)
		cin>>v[i];
	
	double L=0,R=maxx,M,LM,RM,mint=INF;
	while(R-L>1e-9){
		M=L+(R-L)/2;
		if((Mint(M+1e-10)-Mint(M))/1e-10>0)
			R=M;
		else
			L=M;
	}
	cout<<fixed<<setprecision(10)<<Mint(L)<<endl;
	return 0;
}

