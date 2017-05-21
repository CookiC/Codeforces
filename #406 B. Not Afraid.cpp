//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cstring>
#define maxn 10010
//#pragma warning(disable : 4996)
using namespace std;

bool ans;
int n,m,i,k,j;
int a[maxn];
bool vis[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n>>m;
	for(i=0;i<m;++i){
		memset(vis,0,sizeof(vis));
		ans=true;
		cin>>k;
		for(j=0;j<k;++j){
			cin>>a[j];
			if(a[j]>0)
				vis[a[j]]=1;
		}
		
		for(j=0;j<k&&ans;++j)
			if(a[j]<0&&vis[-a[j]])
				ans=false;
		
		if(ans){
			cout<<"YES"<<endl;
			break;
		}
	}
	if(!ans)
		cout<<"NO"<<endl;
	return 0;
}

