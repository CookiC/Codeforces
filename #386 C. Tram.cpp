//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#include<cmath>
//#pragma warning(disable : 4996)
using namespace std;

int s,p1,p2,t1,t2,x,d1,d2,x1,x2;

int dis(int u,int v,int du,int dv){
	int d=u>v?-1:1;
	int cnt=0;
	if (du == d&&dv == d || u == v&&du == dv)
		return abs(u - v);
	if (du == d&&dv != d || du != d&&dv == d)
		if (du == 1)
			return s - u + s - v;
		else
			return u + v;
	if(du!=d&&dv!=d)
		if(du==1)
			return s-u+s+v;
		else
			return u+s+s-v;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>s>>p1>>x>>t2>>t1>>p2>>d2;
	d1=p1>x?-1:1;
	x1=dis(p1,x,d1,d1);
	x2=dis(p2,p1,d2,d1)+x1;
	cout<<min(x1*t1,x2*t2)<<endl;
	return 0;
}

