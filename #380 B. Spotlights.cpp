//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxn 1010
//#pragma warning(disable : 4996)
using namespace std;

int n,m;
bool b[maxn][maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int ans=0,i,j,sum;
	cin>>n>>m;
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			cin>>b[i][j];
	for(i=1;i<=n;++i){
		sum=0;
		for(j=1;j<=m;++j)
			if(b[i][j])
				sum=1;
			else if(sum)
				++ans;
	}
	for(i=1;i<=n;++i){
		sum=0;
		for(j=m;j>=1;--j)
			if(b[i][j])
				sum=1;
			else if(sum)
				++ans;
	}
	for(j=1;j<=m;++j){
		sum=0;
		for(i=1;i<=n;++i)
			if(b[i][j])
				sum=1;
			else if(sum)
				++ans;
	}
	for(j=1;j<=m;++j){
		sum=0;
		for(i=n;i>=1;--i)
			if(b[i][j])
				sum=1;
			else if(sum)
				++ans;
	}
	cout<<ans<<endl;
	return 0;
}

