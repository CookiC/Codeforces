//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#define maxn 110
//#pragma warning(disable : 4996)
using namespace std;

int n,w;
int a[maxn],b[maxn],ai[maxn];

bool cmpA(const int x,const int y){
	return a[x]>a[y];
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j;
	cin>>n>>w;
	for(i=0;i<n;++i){
		cin>>a[i];
		b[i]=(a[i]+1)/2;
		w-=b[i];
	}
	if(w<0)
		cout<<-1<<endl;
	else{
		for(i=0;i<n;++i)
			ai[i]=i;
		sort(ai,ai+n,cmpA);
		for(i=0;i<n&&w;++i){
			j=min(w,a[ai[i]]/2);
			w-=j;
			b[ai[i]]+=j;
		}
		for(i=0;i<n;++i)
			cout<<b[i]<<' ';
		cout<<endl;
	}
	return 0;
}

