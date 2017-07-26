//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define INF 0x7FFFFFFF
#define maxn 1510
//#pragma warning(disable : 4996)
using namespace std;

int n,q;
char s[maxn];
int d[maxn],c[26][maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j,k;
	cin>>n>>s;
	for(i=0;i<26;++i)
		for(j=0;j<n;++j){
			if(s[j]==i+'a')
				d[0]=0;
			else
				d[0]=1;
			c[i][d[0]]=max(c[i][d[0]],1);
			for(k=1;k+j<n;++k){
				d[k]=s[j+k]==i+'a'?d[k-1]:d[k-1]+1;
				c[i][d[k]]=max(c[i][d[k]],k+1);
			}
		}
	for(i=0;i<26;++i)
		for(j=1;j<=n;++j)
			if(!c[i][j])
				c[i][j]=min(c[i][j-1]+1,n);
	cin>>q;
	int m;
	char ci;
	for(i=0;i<q;++i){
		cin>>m>>ci;
		cout<<c[ci-'a'][m]<<endl;
	}
	return 0;
}

