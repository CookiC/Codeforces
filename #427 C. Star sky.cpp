//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cstring>
#define maxc 15
#define maxx 110
#define maxy 110
#define maxn 100010
//#pragma warning(disable : 4996)
using namespace std;

int n,q,c;
int x[maxn],y[maxn],s[maxn];
int rec[maxx][maxy],sum[maxc][maxx][maxy];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j,k,t,x1,y1,x2,y2;
	cin>>n>>q>>c;
	++c;
	for(i=0;i<n;++i)
		cin>>x[i]>>y[i]>>s[i];
	for(k=0;k<c;++k){
		memset(rec,0,sizeof(rec));
		for(i=0;i<n;++i)
			rec[x[i]][y[i]]+=(s[i]+k)%c;
		for(i=1;i<maxx;++i){
			sum[k][i][0]=0;
			for(j=1;j<maxy;++j)
				sum[k][i][j]=sum[k][i][j-1]+rec[i][j];
		}
	}
	int ans;
	for(i=0;i<q;++i){
		cin>>t>>x1>>y1>>x2>>y2;
		ans=0;
		k=t%c;
		for(j=x1;j<=x2;++j)
			ans+=sum[k][j][y2]-sum[k][j][y1-1];
		cout<<ans<<endl;
	}
	return 0;
}

