//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#define maxn 200010
#define INF 0x7FFFFFFF
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
	int ans=INF,cnt=0;
	for(i=1;i<n;++i){
		if(a[i]-a[i-1]<ans){
			ans=a[i]-a[i-1];
			cnt=1;
		}
		else if(a[i]-a[i-1]==ans)
			++cnt;
	}
	cout<<ans<<' '<<cnt<<endl;
	return 0;
}

