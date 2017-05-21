//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<string>
#define LL long long int
//#pragma warning(disable : 4996)
using namespace std;

LL n,x,p;
LL ans=0;
LL ten[19];
string s;
 
int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j;
	ten[0]=1;
	for(i=1;i<19;++i)
		ten[i]=ten[i-1]*10;
	
	cin>>n>>s;
	p=1;
	x=0;
	j=0;
	for(i=s.size()-1;i>=0;--i){
		if(x+(s[i]-'0')*ten[j]>=n){
			ans+=p*x;
			p*=n;
			j=0;
			do{
				++j;
			}while(i+j<s.size()&&s[i+j]=='0');
			x=(s[i]-'0')*ten[j-1];
		}
		else
			x=x+(s[i]-'0')*ten[j++];
		cout<<x<<endl;
	}
	ans+=p*x;
	cout<<ans<<endl;
	return 0;
}

