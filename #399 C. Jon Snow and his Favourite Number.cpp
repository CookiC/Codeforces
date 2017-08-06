//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#include<cstring>
#define INF 0x7FFFFFFF
#define maxa 1024
//#pragma warning(disable : 4996)
using namespace std;

int n,k,x,a;
int cnt[maxa];

void work(){
	int i,f=1;
	int t[maxa];
	memset(t,0,sizeof(t));
	for(i=0;i<maxa;++i)
		if(cnt[i]){
			t[i^x]+=f?(cnt[i]+1)/2:cnt[i]/2;
			t[i]+=f?cnt[i]/2:(cnt[i]+1)/2;
			f^=cnt[i]&1;
		}
	memcpy(cnt,t,sizeof(t));
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i;
	cin>>n>>k>>x;
	for(i=0;i<n;++i){
		cin>>a;
		++cnt[a];
	}
	for(i=0;i<k;++i)
		work();
	int Min=INF,Max=0;
	for(i=0;i<maxa;++i)
		if(cnt[i]){
			if(Min==INF)
				Min=i;
			Max=i;
		}
	cout<<Max<<' '<<Min<<endl;
	return 0;
}

