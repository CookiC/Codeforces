//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<iomanip>
#include<cmath>
//#pragma warning(disable : 4996)
using namespace std;

struct Point{
	double x, y;

	Point(){};

	Point(double x, double y) :x(x), y(y){}

	Point operator - (const Point &b) const{
		return Point(x - b.x, y - b.y);
	}

	Point operator + (const Point &b) const{
		return Point(x + b.x, y + b.y);
	}

	Point operator * (const double k) const{
		return Point(k*x, k*y);
	}

	Point operator / (const double k) const{
		return Point(x / k, y / k);
	}

	double Slope(){
		return y / x;
	}
};

typedef Point Vector;

double Len(Vector V){
	return sqrt(V.x*V.x+V.y*V.y);
}

Point a,b;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int n,i;
	double v,t,mint=0x7FFFFFF;
	cin>>a.x>>a.y;
	cin>>n;
	for(i=0;i<n;++i){
		cin>>b.x>>b.y>>v;
		t=Len(a-b)/v;
		if(mint>t)
			mint=t;
	}
	cout<<fixed<<setprecision(10)<<mint<<endl;
	return 0;
}

