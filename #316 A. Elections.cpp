//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxn 110
using namespace std;

int a[maxn]={0};

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int n,m,i,j,k,v,maxv;
	cin>>n>>m;
	for(i=0;i<m;++i){
		maxv=-1;
		for(j=1;j<=n;++j){
			cin>>v;
			if(v>maxv){
				maxv=v;
				k=j;
			}
		}
		++a[k];
	}
	
	maxv=-1;
	for(i=1;i<=n;++i)
		if(a[i]>maxv){
			maxv=a[i];
			k=i;
		}
	
	cout<<k<<endl;
	return 0;
}

