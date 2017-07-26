//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#define maxn 110
//#pragma warning(disable : 4996)
using namespace std;

int n,m;
char s[maxn][maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j,k,t,x,y,a,b;
	cin>>n>>m;
	for(i=0;i<n;++i)
		cin>>s[i];
	
	x=0;
	for(i=0;i<n;++i)
		for(j=0;j<m;++j)
			if(s[i][j]=='B')
				++x;
	
	int l;
	bool f=1;
	t=min(n,m);
	for(k=1;k<=t&&f;++k)
		for(i=0;i+k-1<n&&f;++i)
			for(j=0;j+k-1<m&&f;++j){
				y=0;
				for(a=0;a<k;++a)
					for(b=0;b<k;++b)
						if(s[i+a][j+b]=='B')
							++y;
				if(x==y){
					f=0;
					l=k;
				}
			}
	if(f)
		cout<<-1<<endl;
	else
		cout<<l*l-x<<endl;
	return 0;
}

