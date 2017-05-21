//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cmath>
#include<iomanip>
#define maxn 1010
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

double Cross(Vector &a,Vector &b){
	return a.x*b.y-a.y*b.x;
}

double DistanceToLine(Point P,Point A,Point B){
	Vector V1=B-A,V2=P-A;
	return fabs(Cross(V1,V2))/Len(V1);
}

int n;
Point p[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j;
	double ans=1e10;
	cin>>n;
	for(i=0;i<n;++i)
		cin>>p[i].x>>p[i].y;
	
	for(i=0;i<n;++i)
		for(j=i+1;j<n;++j)
			if(ans>Len(p[i]-p[j]))
				ans=Len(p[i]-p[j]);
	
	double d;
	for(i=1;i<n+1;++i){
		d=DistanceToLine(p[i%n],p[(i-1)%n],p[(i+1)%n])/2;
		if(ans>d)
			ans=d;
	}
	cout<<fixed<<setprecision(10)<<ans<<endl;
	return 0;
}

