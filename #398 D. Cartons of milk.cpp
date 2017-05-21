//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#define maxn 1000010
//#pragma warning(disable : 4996)
using namespace std;

int top;
int f[maxn],s[maxn],id[maxn],milk[maxn];

bool cmp (const int a,const int b){
	return s[a]<s[b];
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int n,m,k,i,j,l;
	cin>>n>>m>>k;
	for(i=0;i<n;++i)
		cin>>f[i];
	for(i=0;i<m;++i){
		cin>>s[i];
		id[i]=i;
	}
		
	sort(f,f+n);
	sort(id,id+m,cmp);
	
	int sum;
	sum=0;
	j=n-1;
	l=m-1;
	for(i=max(f[n-1],s[id[m-1]]);i>=0;--i){
		while(j>=0&&f[j]==i){
			++sum;
			--j;
		}
		while(sum<k&&l>=0&&s[id[l]]>=i){
			milk[top++]=id[l]+1;
			++sum;
			--l;
		}
		sum=sum>k?sum-k:0;
	}
	
	if(sum)
		cout<<-1<<endl;
	else{
		cout<<top<<endl;
		while(top--)
			cout<<milk[top]<<' ';
		cout<<endl;
	}
	return 0;
}

