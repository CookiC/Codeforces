//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cstring>
#define maxM 100010
#define maxN 100010
//#pragma warning(disable : 4996)
using namespace std;

int N,M,x,l,r,i,j,k;
int a[maxM],len[maxM],maxLen[maxN];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>N>>M;
	memset(a,0,M*sizeof(int));
	memset(len,0,M*sizeof(int));
	memset(maxLen,0,N*sizeof(int));
	
	for(i=0;i<N;++i)
		for(j=0;j<M;++j){
			cin>>x;
			if(x>=a[j])
				++len[j];
			else
				len[j]=1;
			if(len[j]>maxLen[i])
					maxLen[i]=len[j];
			a[j]=x;
		}
	
	cin>>k;
	for(i=0;i<k;++i){
		cin>>l>>r;
		--l;--r;
		if(maxLen[r]>=r-l+1)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}

