//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cmath>
#define LL long long int
#define maxn 4001
//#pragma warning(disable : 4996)
using namespace std;

const int Mod=1e9+7;
 
int f[maxn];

LL PowMod(LL a,LL p,LL n){
	if(!p)
		return 1;
	LL ans=PowMod(a,p/2,n);
	ans=ans*ans%n;
	if(p%2)
		ans=ans*a%n;
	return ans;
}

LL Inv(LL a){
	return PowMod(a,Mod-2,Mod);
}

int inv[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int n,i,j;
	LL C;
	cin>>n;
	for(i=1;i<=n;++i)
		inv[i]=Inv(i);
	
	f[0]=1;
	for(i=1;i<n;++i){
		f[i]=0;
		C=1;
		for(j=0;j<i;++j){
			f[i]=(f[i]+C*f[j]%Mod)%Mod;
			C=C*(i-1-j)%Mod*inv[j+1]%Mod;	
		}
	}
	
	int ans=0;
	C=1;
	for(i=0;i<n;++i){
		ans=(ans+C*f[i]%Mod)%Mod;
		C=C*(n-i)%Mod*inv[i+1]%Mod;
	}
	cout<<ans<<endl;
	return 0;
}

