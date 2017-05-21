//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cmath>
#define LL long long
#define maxn 200010
//#pragma warning(disable : 4996)
using namespace std;

const int Mod=1e9+7;

LL powMod(int a,int p,int n){
	if(!p)
		return 1;
	LL ans=powMod(a,p/2,n);
	ans=ans*ans%n;
	if(p%2)
		ans=ans*a%n;
	return ans;
}

LL inv(int a,int n){
	return powMod(a,n-2,n);
}

int i,len;
int lcnt,rcnt[maxn];
char c;
bool str[maxn];
LL fac[maxn],facInv[maxn];

LL C(int n, int m){
	if(n<0||m<0||n-m<0)
		return 0;
    return fac[n] %Mod * facInv[n - m] % Mod * facInv[m] % Mod;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	while((c=getchar())&&(c=='('||c==')'))
		str[len++]=c=='('?0:1;
	
	fac[0]=1;
	facInv[0]=1;
	for(i=1;i<=len;++i){
		fac[i]=fac[i-1]*i%Mod;
		facInv[i]=inv(fac[i],Mod);
	}
	rcnt[len]=0;
	for(i=len-1;i>=0;--i)
		rcnt[i]=str[i]?rcnt[i+1]+1:rcnt[i+1];
	
	lcnt=0;
	int ans=0;
	for(i=0;i<len;++i)
		if(!str[i]){
			ans=(ans+C(rcnt[i]+lcnt,rcnt[i]-1))%Mod;
			++lcnt;
		}
	
	cout<<ans<<endl;
	return 0;
}

