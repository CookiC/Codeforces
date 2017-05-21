//Author:CookiC
//#include"stdafx.h"
#include<iostream>
//#pragma warning(disable : 4996)
#define maxn 100010
#define LL long long int
using namespace std;

int n,i;
int a[maxn];

LL maxF(int *a,int n){
	LL maxf=0;
	LL sum=0;
	for(int i=0;i<n;++i)
		if(sum+a[i]>0){
			sum+=a[i];
			if(sum>maxf)
				maxf=sum;
		}
		else
			sum=0;
	return maxf;
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n;
	for(i=0;i<n;++i)
		cin>>a[i];
	for(i=0;i<n-1;++i)
		a[i]=abs(a[i]-a[i+1]);
	for(i=1;i<n-1;i+=2)
		a[i]=-a[i];
	LL x=maxF(a,n-1);
	for(i=0;i<n-1;++i)
		a[i]=-a[i];
	LL y=maxF(a,n-1);
	if(x>y)
		cout<<x<<endl;
	else
		cout<<y<<endl;
	return 0;
}

