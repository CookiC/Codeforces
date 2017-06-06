//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxn 100010
#define LL long long int
//#pragma warning(disable : 4996)
using namespace std;

int n,t,k,i;
bool d[maxn]={0};
LL c[maxn];
LL ans=0,sum=0,sumd=0,a;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n>>k;
	for(i=0;i<n;++i){
		cin>>c[i];
		sum+=c[i];
	}
	
	for(i=0;i<k;++i){
		cin>>t;
		d[--t]=1;
		sumd+=c[t];
	}
	
	for(i=0;i<n-1;++i)
		
	
	for(i=0;i<n-1;++i){
		if(i)
			a=c[i+1];
		else if(i<n-1)
			a=c[i+1]+c[n-1];
		else
			a=0;
		
		sum-=c[i];
		if(d[i]){
			sumd-=c[i];
			a+=sum-c[i+1];
			if(!i)
				a-=c[n-1];
		}
		else{
			a+=sumd;
			if(d[i+1])
				a-=c[i+1];
			if(!i&&d[n-1])
				a-=c[n-1];
		}
		ans+=c[i]*a;
	}
	
	cout<<ans<<endl;
	return 0;
}

