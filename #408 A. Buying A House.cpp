//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxn 110
//#pragma warning(disable : 4996)
using namespace std;

int n,m,k;
int a[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,ans=0;
	cin>>n>>m>>k;
	for(i=0;i<n;++i)
		cin>>a[i];
	--m;
	for(i=1;m-i>=0||m+i<n;++i){
		if(m-i>=0&&a[m-i]&&a[m-i]<=k){
			ans=i;
			break;
		}
		if(m+i<n&&a[m+i]&&a[m+i]<=k){
			ans=i;
			break;
		}
	}
	cout<<ans*10<<endl;
	return 0;
}

