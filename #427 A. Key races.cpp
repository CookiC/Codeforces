//Author:CookiC
//#include"stdafx.h"
#include<iostream>
//#pragma warning(disable : 4996)
using namespace std;

int s,v1,v2,t1,t2;
int sum1,sum2;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>s>>v1>>v2>>t1>>t2;
	sum1=2*t1+s*v1;
	sum2=2*t2+s*v2;
	if(sum1==sum2)
		cout<<"Friendship"<<endl;
	else if(sum1<sum2)
		cout<<"First"<<endl;
	else
		cout<<"Second"<<endl;
	return 0;
}

