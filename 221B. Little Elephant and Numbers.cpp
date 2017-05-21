#include<iostream>
#include<cmath>
using namespace std;

long long int i,j,x,Max;
unsigned cnt=0;
unsigned n[10]={0};

int main(){
	cin>>x;
	for(i=x;i;i/=10)
		n[i%10]=1;
	Max=sqrt(x);
	for(i=1;i<=Max;++i)
		if(x%i==0){
			for(j=i;j;j/=10)
				if(n[j%10]){
					++cnt;
					break;
				}
			j=x/i;
			if(j!=i)
				while(j){
					if(n[j%10]){
						++cnt;
						break;
					}
					j/=10;
				}
		}
	cout<<cnt<<endl;
	return 0;
}

