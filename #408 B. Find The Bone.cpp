//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxn 1000010
//#pragma warning(disable : 4996)
using namespace std;

int n,m,k;
bool b[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,x,y;
	cin>>n>>m>>k;
	for(i=0;i<m;++i){
		cin>>x;
		b[x]=1;
	}
	int ans=1;
	for(i=0;i<k&&!b[ans];++i){
		cin>>x>>y;
		if(x==ans)
			ans=y;
		else if(y==ans)
			ans=x;
	}
	cout<<ans<<endl;
	return 0;
}

