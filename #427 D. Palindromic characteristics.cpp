//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<vector>
#include<cstring>
#define maxn 5010
#define LL long long
//#pragma warning(disable : 4996)
using namespace std;

int n;
int ans[maxn];
char s[maxn];
int d[maxn][maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j;
	cin>>s;
	n=strlen(s);
	for(i=0;i<n;++i){
		d[i][1]=1;
		++ans[1];
		for(j=1;i-j>=0&&i+j<n&&s[i-j]==s[i+j];++j){
			d[i][j*2+1]=d[(i-1+i-j)/2][j]+1;
			++ans[d[i][j*2+1]];
		}
		for(j=1;i-j+1>=0&&i+j<n&&s[i-j+1]==s[i+j];++j){
			d[i][j*2]=d[(i+i-j+1)/2][j]+1;
			++ans[d[i][j*2]];
		}
	}
	for(i=n-1;i>=1;--i)
		ans[i]+=ans[i+1];
	for(i=1;i<=n;++i)
		cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}

