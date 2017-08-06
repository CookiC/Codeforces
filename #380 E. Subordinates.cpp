//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxn 200010
//#pragma warning(disable : 4996)
using namespace std;

int n,s;
int a[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int ans=0,y,j,i,x;
	cin>>n>>s;
	for(i=1;i<=n;++i){
		cin>>x;
		if(i!=s){
			++a[x];
			if(x==0)
				++y;
		}
		else if(x!=0)
			++ans;
	}
	a[0]=1;
	ans+=y;
	for(i=0;i<n&&y;++i)
		if(a[i]==0){
			a[i]=1;
			--y;
		}
	for(j=n-1;a[j]==0;--j);
	for(i=0;i<j;++i)
		if(a[i]==0){
			--a[j];
			a[i]=1;
			while(a[j]==0)
				--j;
			++ans;
		}
	cout<<ans<<endl;
	return 0;
}

