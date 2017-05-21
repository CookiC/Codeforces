//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<vector>
#define maxn 1000010
//#pragma warning(disable : 4996)
using namespace std;

int ave,ans;
int w[maxn];
vector<int> G[maxn];

int DFS(int u){
	int sum=w[u],x;
	for(auto it=G[u].begin();it!=G[u].end();++it){
		int &v=*it;
		if(v){
			x=DFS(v);
			if(!ans)
				if(x==ave){
					ans=v;
					v=0;
				}
				else
					sum+=x;
			else
				break;
		}
	}
	return sum;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int n,u,v,sum,root,i;
	cin>>n;
	sum=0;
	for(i=1;i<=n;++i){
		cin>>u>>w[i];
		if(u)
			G[u].push_back(i);
		else
			root=i;
		sum+=w[i];
	}
	
	if(sum%3)
		cout<<-1<<endl;
	else{
		int a,b;
		ave=sum/3;
		ans=0;
		DFS(root);
		if(ans){
			a=ans;
			ans=0;
			DFS(root);
			if(ans){
				b=ans;
				cout<<a<<' '<<b<<endl;
			}
			else
				cout<<-1<<endl;
		}
		else
			cout<<-1<<endl;
	}
	return 0;
}

