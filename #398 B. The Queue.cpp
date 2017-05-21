//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxn 100010
#define LL long long int
//#pragma warning(disable : 4996)
using namespace std;

LL ts,tf,t,n,mint=0x7FFFFFFFFFFFFFFF;
LL a[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j;
	LL rest,ans;
	cin>>ts>>tf>>t>>n;
	for(i=0;i<n;++i)
		cin>>a[i];
	
	if(n){
		rest=0;
		for(i=0;i<n&&mint;i=j){
			for(j=i+1;j<n&&a[i]==a[j];++j);
			if(i)
				rest-=a[i]-a[i-1];
			else
				rest-=a[i]-ts;
		
			if(a[i]+rest+t>tf)
				break;
			if(rest+1<mint){
				mint=rest+1<0?0:rest+1;
				ans=a[i]-1;
			}
			rest+=t*(j-i);
		}
		if(i>=n&&a[n-1]+rest+t<=tf){
			mint=0;
			ans=a[n-1]+rest;
		}
	}
	else
		ans=ts;
	
	cout<<ans<<endl;
	return 0;
}

