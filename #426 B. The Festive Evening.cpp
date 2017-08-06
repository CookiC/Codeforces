//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#include<cctype>
#define INF 0x7FFFFFFF
#define maxn 1000010
//#pragma warning(disable : 4996)
using namespace std;

int n,k;
int L[27],R[27];
char s[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
//	ios::sync_with_stdio(false);
	
	int i,j,cnt=0;
	char c;
	for(i=0;i<27;++i){
		L[i]=INF;
		R[i]=INF;
	}
	cin>>n>>k;
	for(i=0;i<n;++i){
		while(!isalpha(c=getchar()));
		c-='A';
		if(L[c]==INF)
			L[c]=i;
		R[c]=i;
	}
	sort(L,L+27);
	sort(R,R+27);
/*	for(i=0;i<27;++i)
		if(L[i]==INF)
			cout<<"INF"<<' ';
		else
			cout<<L[i]<<' ';
	cout<<endl;
	for(i=0;i<27;++i)
		if(R[i]==INF)
			cout<<"INF"<<' ';
		else
			cout<<L[i]<<' ';
	cout<<endl;*/
	i=0;j=0;
	while(L[i]!=INF){
		while(L[i]!=INF&&L[i]<=R[j]){
			++cnt;
			++i;
		}
		if(cnt>k)
			break;
		while(L[i]!=INF&&L[i]>R[j]){
			--cnt;
			++j;
		}
	}
	if(cnt<=k)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
	return 0;
}

