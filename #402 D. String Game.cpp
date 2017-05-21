//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cstring>
#include<vector>
#define maxn 200010
//#pragma warning(disable : 4996)
using namespace std;

int n,m;
int o[maxn];
char t[maxn],p[maxn];
bool vis[maxn];

bool find(){
	int i,j;
	for(i=0,j=0;i<n;++i)
		if(!vis[i]&&t[i]==p[j]){
			if(j==m-1)
				break;
			++j;
		}
	
	if(i<n)
		return true;
	else
		return false;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>t>>p;
	n=strlen(t);
	m=strlen(p);
	
	int i;
	for(i=0;i<n;++i){
		cin>>o[i];
		--o[i];
	}
	
	
	int M;
	int L=0;
	int R=n-1;
	int l=0;
	int r=L+(R-L)/2;
	while(L<R){
		for(i=l;i<=r;++i)
			vis[o[i]]=!vis[o[i]];
		
		M=L+(R-L)/2;
		if(find()){
			L=M+1;
			l=M+1;
			r=L+(R-L)/2;
		}
		else{
			R=M;
			l=L+(R-L)/2+1;
			r=R;
		}
	}
	cout<<R<<endl;
	return 0;
}

