//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#define maxn 100010
//#pragma warning(disable : 4996)
using namespace std;

int n;
int a[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i;
	cin>>n;
	for(i=0;i<n;++i)
		cin>>a[i];
	sort(a,a+n);

	int q,m,ans;
	cin>>q;
	for(i=0;i<q;++i){
		cin>>m;
		ans=upper_bound(a,a+n,m)-a;
		cout<<ans<<endl;
	}
	return 0;
}

