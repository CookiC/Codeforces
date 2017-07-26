//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#define LL long long
#define maxn 300010
//#pragma warning(disable : 4996)
using namespace std;

const LL M=1e9+7;
LL n;
LL a[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i;
	cin>>n;
	for(i=0;i<n;++i)
		cin>>a[i];
	sort(a,a+n);
	LL sum=0,ans=0,p=2;
	for(i=1;i<n;++i){
		sum=sum*2%M;
		sum=(sum+(a[i]-a[i-1])*(p-1)%M)%M;
//		cout<<sum<<' ';
		p=p*2%M;
		ans=(ans+sum)%M;
	}
//	cout<<endl;
	cout<<ans<<endl;
	return 0;
}

