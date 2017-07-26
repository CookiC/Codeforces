//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#define maxn 1010
//#pragma warning(disable : 4996)
using namespace std;

int n,k;
int a[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i;
	cin>>n>>k;
	for(i=0;i<n;++i)
		cin>>a[i];
	sort(a,a+n);
	for(i=0;i<n&&a[i]<=k;++i);
	int ans=0;
	while(i<n){
		while(a[i]>k*2){
			k*=2;
			++ans;
		}
		k=a[i];
		++i;
	}
	cout<<ans<<endl;
	return 0;
}

