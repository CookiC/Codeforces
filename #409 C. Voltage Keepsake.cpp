//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<iomanip>
#define LL long long int
#define maxn 100010
//#pragma warning(disable : 4996)
using namespace std;

int n,p;
int a[maxn],b[maxn];

bool ok(double t){
	int i;
	double sum=0;
	for(i=0;i<n;++i)
		if(a[i]*t>b[i])
			sum+=a[i]*t-b[i];
	if(sum>p*t)
		return false;
	else
		return true; 
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i;
	double sump=0,sums=0;
	cin>>n>>p;
	for(i=0;i<n;++i){
		cin>>a[i]>>b[i];
		sump+=a[i];
		sums+=b[i];
	}
	
	if(sump>p){
		double L=0,R=sums/(sump-p)+1,M;
		while(R-L>1e-6){
			M=L+(R-L)/2;
			if(ok(M))
				L=M;
			else
				R=M;
		}
		
		cout<<fixed<<setprecision(6)<<M<<endl;
	}
	else
		cout<<-1<<endl;
	return 0;
}

