//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxn 110
#define INF 0x7FFFFFFF
//#pragma warning(disable : 4996)
using namespace std;

int n,m;
int r[maxn],c[maxn];
int a[maxn][maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j;
	cin>>n>>m;
	for(i=0;i<n;++i)
		r[i]=INF;
	for(i=0;i<m;++i)
		c[i]=INF;
	for(i=0;i<n;++i)
		for(j=0;j<m;++j){
			cin>>a[i][j];
			if(n>m)
				c[j]=min(c[j],a[i][j]);
			else
				r[i]=min(r[i],a[i][j]);
		}
	
	if(n>m)
		for(i=0;i<n;++i)
			r[i]=a[i][0]-c[0];
	else
		for(i=0;i<m;++i)
			c[i]=a[0][i]-r[0];
	
	bool b=1;
	for(i=0;i<n&&b;++i)
		for(j=0;j<m&&b;++j)
			if(r[i]+c[j]!=a[i][j])
				b=0;
	
	if(b){
		int ans=0;
		for(i=0;i<n;++i)
			ans+=r[i];
		for(i=0;i<m;++i)
			ans+=c[i];
		cout<<ans<<endl;
		for(i=0;i<n;++i)
			while(r[i]--)
				cout<<"row "<<i+1<<endl;
		for(i=0;i<m;++i)
			while(c[i]--)
				cout<<"col "<<i+1<<endl;
	}
	else
		cout<<-1<<endl;
	return 0;
}

