//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#include<string>
#include<functional>
#define maxn 300010
//#pragma warning(disable : 4996)
using namespace std;

int n,top,ans=0;
int a[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	string s;
	int i,j,x;
	cin>>n;
	top=0;
	j=1;
	for(i=0;i<2*n;++i){
		cin>>s;
		if(s=="add"){
			cin>>x;
			a[top++]=x;
		}
		else{
			if(top)
				if(a[top-1]!=j){
					++ans;
					top=0;
				}
				else
					--top;
			++j;
		}
	}
	cout<<ans<<endl;
	return 0;
}

