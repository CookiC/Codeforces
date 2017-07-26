//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxn 60
//#pragma warning(disable : 4996)
using namespace std;

int n;
int a[maxn][maxn];

bool ok(int x,int y){
	int i,j;
	for(i=0;i<n;++i)
		for(j=0;j<n;++j)
			if(!(x==i&&y==j)&&a[x][j]+a[i][y]==a[x][y])
				return true;
	return false;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j;
	cin>>n;
	for(i=0;i<n;++i)
		for(j=0;j<n;++j)
			cin>>a[i][j];
			
	bool ans=1;
	for(i=0;i<n&&ans;++i)
		for(j=0;j<n&&ans;++j)
			if(a[i][j]!=1&&!ok(i,j))
				ans=0;
	if(ans)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}

