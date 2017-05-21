//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<queue>
#define maxn 1010
//#pragma warning(disable : 4996)
using namespace std;

int n,k,t,m,i,j;
int type[maxn];
int a[2010];
bool b[maxn];
queue<int> q;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n>>k;
	for(i=0;i<k;++i){
		cin>>t;
		b[t]=1;
	}
	for(i=0,m=0;i<maxn;++i)
		if(b[i])
			type[m++]=n-i;
	
	a[1000]=0;
	q.push(1000);
	while(!q.empty()){
		j=q.front();
		q.pop();
		for(i=0;i<m;++i){
			t=j+type[i];
			if(0<=t&&t<=2000&&!a[t]){
				a[t]=a[j]+1;
				q.push(t);
			}
		}
	}
	
	if(a[1000])
		cout<<a[1000]<<endl;
	else
		cout<<-1<<endl;
	return 0;
}

