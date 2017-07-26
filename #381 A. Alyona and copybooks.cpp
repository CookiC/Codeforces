#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;

LL n,a,b,c;
LL d[4];

int main(){
	ios::sync_with_stdio(false);
	
	cin>>n>>a>>b>>c;
	d[0]=0;
	d[1]=min(min(a,b+c),c*3);
	d[2]=min(min(a*2,b),c*2);
	d[3]=min(min(a*3,c),a+b);
	cout<<d[(4-n%4)%4]<<endl;
	return 0;
}

