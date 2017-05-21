//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<cstring>
#define LL long long int
#define maxn 100010
//#pragma warning(disable : 4996)
using namespace std;

LL PowMod(LL a,LL p,LL n){
	if(!p)
		return 1;
	LL ans=PowMod(a,p/2,n);
	ans=ans*ans%n;
	if(p%2)
		ans=ans*a%n;
	return ans;
}

LL Inv(LL a,LL n){
	return PowMod(a,n-2,n);
}

LL n,m,sum1=0,sum2=0,sum3;
LL a[maxn];
bool vis[maxn];
set<int> st;

bool ok(int i,int d){
	int cnt=0,k;
	memset(vis,0,sizeof(vis));
	while((k=lower_bound(a,a+n,i)-a)<n&&a[k]==i&&!vis[k]){
		vis[k]=1;
		i=(i+d)%m;
		++cnt;
	}
	if(cnt==n)
		return true;
	return false;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	LL d;
	int i;
	cin>>m>>n;
	for(i=0;i<n;++i){
		cin>>a[i];
		sum1=(sum1+a[i])%m;
		sum2=(sum2+a[i]*a[i]%m)%m;
		st.insert(a[i]);
	}
	sort(a,a+n);
	
	if(n<m){
		LL b=Inv(n*(n-1)%m,m),c=Inv(6%m,m);
		for(i=0;i<n;++i){
			d=(2*(sum1-n*a[i])%m*b%m+m)%m;
			sum3=(n*a[i]%m*a[i]%m+n*(n-1)%m*(2*n-1)%m*d%m*d%m*c%m+n*(n-1)%m*d%m*a[i]%m)%m;
			if(sum2==sum3&&ok(a[i],d)){
				cout<<a[i]<<' '<<d<<endl;
				break;
			}
		}
		if(i>=n)
			cout<<-1<<endl;
	}
	else if(ok(a[0],1))
		cout<<a[0]<<' '<<1<<endl;
	else if(ok(a[0],0))
		cout<<a[0]<<' '<<0<<endl;
	else
		cout<<-1<<endl;
	return 0;
}

