//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxn 200010
//#pragma warning(disable : 4996)
using namespace std;

int n;
bool b;
bool vis[maxn];
int p[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int ans=0,cnt=0,i,j;
	cin>>n;
	for(i=1;i<=n;++i)
		cin>>p[i];
	for(i=0;i<n;++i){
		cin>>b;
		if(b)
			++cnt;
	}
	if(cnt%2==0)
		ans=1;
	cnt=0;
	for(i=1;i<=n;++i)
		if(!vis[i]){
			j=i;
			while(!vis[j]){
				vis[j]=1;
				j=p[j];
			}
			++cnt;
		}
	if(cnt>1)
		ans+=cnt;
	cout<<ans<<endl;
	return 0;
}

