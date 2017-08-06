//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#define LL long long
#define maxa 100010
//#pragma warning(disable : 4996)
using namespace std;

LL n,k;
vector<LL> fac;
LL ans[maxa];

void answer(LL m){
	int i;
	for(i=0;i<k-1;++i)
		ans[i]=i+1;
	ans[k-1]=m-k*(k-1)/2;
	for(i=0;i<k;++i)
		cout<<ans[i]*(n/m)<<' ';
	cout<<endl;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	LL i;
	cin>>n>>k;
	for(i=1;i<=sqrt(n+0.5);++i)
		if(n%i==0){
			fac.push_back(i);
			fac.push_back(n/i);
		}
	sort(fac.begin(),fac.end());
	fac.resize(unique(fac.begin(),fac.end())-fac.begin());
	int j=lower_bound(fac.begin(),fac.end(),(1+k)*k/2)-fac.begin();
	if(j<fac.size())
		answer(fac[j]);
	else
		cout<<-1<<endl;
	return 0;
}

