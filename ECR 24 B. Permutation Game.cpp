//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxn 110
//#pragma warning(disable : 4996)
using namespace std;

int n,m;
int l[maxn],a[maxn];
bool vis[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,x;
	cin>>n>>m;
	for(i=0;i<m;++i)
		cin>>l[i];
	for(i=1;i<m;++i){
		x=(l[i]-l[i-1]+n-1)%n+1;
		if(!a[l[i-1]]){
			a[l[i-1]]=x;
			if(vis[a[l[i-1]]]){
//				cout<<a[l[i-1]]<<endl;
				break;
			}
			else
				vis[a[l[i-1]]]=1;
		}
		else if(a[l[i-1]]!=x)
			break;
	}
	if(i<m)
		cout<<-1<<endl;
	else{
		int j=1;
		for(i=1;i<=n;++i)
			if(!a[i]){
				while(vis[j])
					++j;
				a[i]=j;
				vis[j]=1;
			}
		for(i=1;i<=n;++i)
			cout<<a[i]<<' ';
		cout<<endl;
	}
	return 0;
}

