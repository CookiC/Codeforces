//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<vector>
#define maxn 100010
//#pragma warning(disable : 4996)
using namespace std;

int n,i;
int a[maxn];
bool b[maxn],dup[maxn];
vector<int> c;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n;
	for(i=0;i<n;++i){
		cin>>a[i];
		if(a[i]<=n&&!b[a[i]])
			b[a[i]]=1;
		else
			dup[i]=1;
	}
	
	for(i=1;i<=n;++i)
		if(!b[i])
			c.push_back(i);
	
	int cnt=0;
	for(i=0;i<n;++i)
		if(dup[i])
			a[i]=c[cnt++];
		
	for(i=0;i<n;++i)
		cout<<a[i]<<' ';
	cout<<endl;
	return 0;
}

