//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#define maxm 10010
#define LL long long int
//#pragma warning(disable : 4996)
using namespace std;

int n,r,l,top;
LL a[maxm];

int Gcd(int a,int b){
	int t;
	while(b){
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j,k; 
	cin>>n>>l>>r;
	if(n==1)
		cout<<r-l+1<<endl;
	else if(n==2)
		cout<<(LL)(r-l+1)*(r-l)<<endl;
	else if(n>24)
		cout<<0<<endl;
	else{
		LL t=1;
		i=1;
		top=0;
		do{
			a[top++]=t;
			++i;
			t=1;
			for(j=0;j<n-1;++j)
				t*=i;
		}while(t<=r);
		
/*		for(i=0;i<top;++i)
			cout<<a[i]<<' ';
		cout<<endl;*/
		
//		cout<<top<<endl;
		LL ans=0;
		int x,y;
		for(i=0;i<top;++i){
			x=(l+a[i]-1)/a[i];
//			cout<<x<<' ';
			for(j=i+1;j<top;++j)
				if(Gcd(i+1,j+1)==1){
					y=r/a[j];
					ans+=y>=x?y-x+1:0; 
				}
		}
		
		cout<<ans*2<<endl;
	}
	return 0;
}

