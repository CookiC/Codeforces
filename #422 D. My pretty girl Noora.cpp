//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cstring>
#include<cmath>
#define maxn 5000010
#define LL long long
//#pragma warning(disable : 4996)
using namespace std;

const LL M=1e9+7;

LL f[maxn];
LL fac[maxn];

void Sieve(LL n){
	LL i,j;
	memset(fac,0,sizeof(fac));
	fac[1]=1;
	for(i=2;i<=n;++i)
		if(!fac[i]){
			fac[i]=i;
			for(j=i*i;j<=n;j+=i)
				if(!fac[j])
					fac[j]=i;
		}
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	LL i;
	int t,l,r;
	cin>>t>>l>>r;
	Sieve(r);
	for(i=1;i<=r;++i){
		if(fac[i]==i)
			f[i]=i*(i-1)/2%M;
		else
			f[i]=(f[fac[i]]*i/fac[i]+f[i/fac[i]])%M;
//		cout<<fac[i]<<' '<<f[i]<<endl;
	}
//	cout<<endl;
	
	LL sum=0,p=1;
	for(i=0;i+l<=r;++i){
		sum=(sum+p*f[i+l]%M)%M;
		p=(p*t)%M;
	}
	cout<<sum<<endl;
	return 0;
}

