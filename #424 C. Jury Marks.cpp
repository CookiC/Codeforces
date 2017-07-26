//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<set>
#include<algorithm>
#define LL long long
#define maxn 2010
//#pragma warning(disable : 4996)
using namespace std;

int n,k;
int a[maxn],b[maxn],sum[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,x,y,z;
	cin>>n>>k;
	for(i=0;i<n;++i)
		cin>>a[i];
	sum[0]=a[0];
	for(i=1;i<n;++i)
		sum[i]=sum[i-1]+a[i];
	sort(sum,sum+n);
	n=unique(sum,sum+n)-sum;
	for(i=0;i<k;++i)
		cin>>b[i];
	sort(b,b+k);
	
	LL ans=0;
	for(i=0;i<n;++i){
		z=i;
		x=i+1;
		y=1;
		while(x<n&&y<k&&sum[x]-sum[z]<=b[y]-b[y-1]){
			if(sum[x]-sum[z]==b[y]-b[y-1]){
				++y;
				z=x;
			}
			++x;
		}
		if(y>=k)
			++ans; 
	}
	cout<<ans<<endl;
	return 0;
}

