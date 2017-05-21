//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#define maxn 2000000
//#pragma warning(disable : 4996)
using namespace std;

bool vis[maxn];
int pi[maxn];

void sieve(int n){
	int i,j;
	int m=sqrt(n+0.5);
	memset(vis,0,sizeof(vis));
	memset(pi,0,sizeof(pi));
	for(i=2;i<=m;++i)
		if(!vis[i])
			for(j=i*i;j<=n;j+=i)
				vis[j]=1;
	for(i=2;i<=n;++i)
		pi[i]=vis[i]?pi[i-1]:pi[i-1]+1;
}

int rub(int n){
//	if(n==0)
//		return 0;
	int i,j,m,ans=0;
	int a[10];
	a[0]=0;
	for(i=0;n;++i){
		a[i]=n%10;
		n/=10;
	}
	m=i;
	j=9;
	for(i=0;i<m-1;++i){
		ans+=j;
		if(i%2)
			j*=10;
	}
	
	j=a[m-1]-1;
	for(i=1;i<=(m+1>>1)-1;++i){
		j*=10;
		if(a[m-1-i])
			j+=a[m-1-i];
	}
	ans+=j;
	int x=0,y=0;
	i=(m>>1)-1;
	if(m%2)
		j=i+2;
	else
		j=i+1;
	while(i>=0){
		x=x*10+a[i--];
		y=y*10+a[j++];
	}
	if(x>=y)
		++ans;
	return ans;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	sieve(maxn-1);
	int p,q,i;
	cin>>p>>q;
	for(i=maxn-1;q*pi[i]>p*rub(i);--i);
	cout<<i<<endl;
	return 0;
}

