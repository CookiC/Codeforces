//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cstring>
#define maxn 200010
//#pragma warning(disable : 4996)
using namespace std;

int n,D,R,sumD,sumR;
char s[maxn];
bool vis[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i;
	cin>>n>>s;
	sumD=0;
	sumR=0;
	for(i=0;i<n;++i)
		if(s[i]=='D')
			++sumD;
		else
			++sumR;
	i=0;
	while(sumD&&sumR){
		if(!vis[i]){
			if(s[i]=='D')
				if(D){
					vis[i]=1;
					--D;
					--sumD;
				}
				else
					++R;
			else
				if(R){
					vis[i]=1;
					--R;
					--sumR;
				}
				else
					++D;
		}
		++i;
		i=i%n;
	}
	if(sumD)
		cout<<'D'<<endl;
	else
		cout<<'R'<<endl;
	return 0;
}

