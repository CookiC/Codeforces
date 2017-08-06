//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxn 110
//#pragma warning(disable : 4996)
using namespace std;

int n,k;
bool a[maxn][maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j;
	cin>>n>>k;
	if(k>n*n)
		cout<<-1<<endl;
	else{
		for(i=0;i<n;++i)
			for(j=i;j<n;++j)
				if(i==j&&k){
					a[i][j]=1;
					--k;
				}
				else if(k>1){
					a[i][j]=a[j][i]=1;
					k-=2;
				}
		for(i=0;i<n;++i){
			for(j=0;j<n;++j)
				cout<<a[i][j]<<' ';
			cout<<endl;
		}
	}
	return 0;
}

