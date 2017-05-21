//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<vector>
#include<cstring>
#include<bitset>
#define maxn 510
#define LL long long int
using namespace std;

struct Matrix01{
	int n,m;
	bitset<maxn> a[maxn];
	
	void Resize(int x,int y){
		n=x;
		m=y;
	}
	
	bitset<maxn>& operator [] (int n) {
		return a[n];
	}
	
	void print(){
		int i;
		for(i=0;i<n;++i)
			cout<<a[i]<<endl;
	}
};

Matrix01 operator & (Matrix01 &a,Matrix01 &b){
	int i,j,k;
	Matrix01 c;
	c.Resize(a.n,b.m);
	for(i=0;i<a.n;++i){
		c[i].reset();
		for(j=0;j<b.m;++j)
			if(a[i][j])
				c[i]|=b[j];
	}
	return c;
}

int n,m;
Matrix01 a[2][61],b,c;
vector<bool> seq;

bool possible(Matrix01 &a){
	int i,j;
	for(i=0;i<a.n;++i)
		for(j=0;j<a.m;++j)
			if(a[i][j])
				return true;
	return false;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int u,v,t,i,j;
	cin>>n>>m;
	a[0][0].Resize(n,n);
	a[1][0].Resize(n,n);
	for(i=0;i<m;++i){
		cin>>u>>v>>t;
		a[t][0][u-1][v-1]=1;
	}
	for(i=1;i<61;++i){
		a[0][i]=a[0][i-1]&a[1][i-1];
		a[1][i]=a[1][i-1]&a[0][i-1];
	}
	
	LL ans=0;
	b.Resize(1,n);
	for(i=0;i<n;++i)
		b[0][i]=1;
	
	bool f=0;
	for(i=60;i>=0;--i){
		c=b&a[f][i];
		if(possible(c)){ 
			b=c;
			ans|=(LL)1<<i;
			f=!f;
		}
		if(ans>1e18){
			ans=-1;
			break;
		}
	}

	cout<<ans<<endl;
	return 0;
}

