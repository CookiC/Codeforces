//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<vector>
//#pragma warning(disable : 4996)
using namespace std;

char c;
int n,a,b,k;
vector<int> v;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int ans=0,i,cnt=0;
	cin>>n>>a>>b>>k;
	for(i=1;i<=n;++i){
		cin>>c;
		if(c=='0')
			++cnt;
		else
			cnt=0;
		if(cnt==b){
			++ans;
			cnt=0;
			v.push_back(i);	
		}
	}
	ans=ans-a+1;
	cout<<ans<<endl;
	for(i=0;i<ans;++i)
		cout<<v[i]<<' ';
	cout<<endl;
	return 0;
}

