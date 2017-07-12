//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cstring> 
#define maxn 1010
//#pragma warning(disable : 4996)
using namespace std;

bool a[maxn],b[maxn];
int n,m,cnt;
char s[maxn],t[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j,mincnt=0x7FFFFFFF;
	cin>>n>>m;
	cin>>s>>t;
	for(i=0;i+n-1<m;++i){
		cnt=0;
		for(j=0;j<n;++j)
			if(t[i+j]==s[j])
				a[j]=1;
			else{
				++cnt;
				a[j]=0;
			}
		if(cnt<mincnt){
			mincnt=cnt;
			memcpy(b,a,sizeof(bool)*n);
		}
	}
	cout<<mincnt<<endl;
	for(i=0;i<n;++i)
		if(!b[i])
			cout<<i+1<<' ';
	cout<<endl;
	return 0;
}

