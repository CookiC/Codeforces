//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxn 1010
//#pragma warning(disable : 4996)
using namespace std;

int n;
bool vis[maxn];
int a[maxn],b[maxn],c[maxn],ci[2];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i;
	cin>>n;
	for(i=0;i<n;++i)
		cin>>a[i];
	for(i=0;i<n;++i)
		cin>>b[i];
	int cnt=0;
	for(i=0;i<n;++i)
		if(a[i]!=b[i])
			ci[cnt++]=i;
		else{
			vis[a[i]]=1;
			c[i]=a[i];
		}
	if(cnt==1){
		for(i=1;i<=n;++i)
			if(!vis[i]){
				c[ci[0]]=i;
				break;
			}
	}
	else{
		if(a[ci[0]]!=a[ci[1]]&&!vis[a[ci[0]]]&&!vis[a[ci[1]]]){
			c[ci[0]]=a[ci[0]];
			c[ci[1]]=a[ci[1]];
		}
		else if(a[ci[0]]!=b[ci[1]]&&!vis[a[ci[0]]]&&!vis[b[ci[1]]]){
			c[ci[0]]=a[ci[0]];
			c[ci[1]]=b[ci[1]];
		}
		else if(b[ci[0]]!=a[ci[1]]&&!vis[b[ci[0]]]&&!vis[a[ci[1]]]){
			c[ci[0]]=b[ci[0]];
			c[ci[1]]=a[ci[1]];
		}
		else{
			c[ci[0]]=b[ci[0]];
			c[ci[1]]=b[ci[1]];
		}
	}
	for(i=0;i<n;++i)
		cout<<c[i]<<' ';
	cout<<endl;
	return 0;
}

