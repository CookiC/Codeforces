//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cstring>
#define maxn 110
//#pragma warning(disable : 4996)
using namespace std;

int n;
char s[maxn],ans[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j;
	cin>>n>>s;
	i=0;
	j=0;
	while(i<n){
		while(i<n-2&&s[i]=='o'&&s[i+1]=='g'&&s[i+2]=='o'){
			ans[j++]='*';
			ans[j++]='*';
			ans[j++]='*';
			++i;
			while(i<n-1&&s[i]=='g'&&s[i+1]=='o')
				i+=2;
		}
		ans[j++]=s[i];
		++i;
	}
	cout<<ans<<endl;
	return 0;
}

