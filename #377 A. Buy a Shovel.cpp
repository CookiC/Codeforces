#include<iostream>
using namespace std;

int i,k,r,sum;

int main(){
	ios::sync_with_stdio(false);
	cin>>k>>r;
	i=0;
	sum=0;
	do{
		++i;
		sum+=k;
	}while(sum%10!=r&&sum%10!=0);
	cout<<i<<endl;
	return 0;
}

